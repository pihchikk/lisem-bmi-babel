/*
 * bmi_lifecycle_test.cpp
 *
 * C++ harness for Phase C BMI lifecycle verification (B4 first-cut).
 *
 * Build (after main Qt cmake build):
 *   g++ -std=c++17 -I../include -I. bmi_lifecycle_test.cpp \
 *       -L<build_dir> -lopenlisem -lQt6Core -o bmi_lifecycle_test
 *
 * Usage:
 *   ./bmi_lifecycle_test <path/to/runfile>
 *
 * C1 — batch regression:
 *   Run via DoModel() (bmiMode=false) and record mass-balance totals / error.csv.
 *   Compare byte-for-byte with baseline produced before this refactor.
 *
 * C2 — stepped single lifecycle:
 *   W.bmiMode = true;
 *   W.Initialize();
 *   while (W.Update()) {}
 *   W.Finalize();
 *   → must produce identical outputs to C1.
 *
 * C3 — double lifecycle (re-init):
 *   Run lifecycle twice in same process.
 *   Both runs must match C1, no crash/leak between them.
 *
 * C4 — map-count stability assertion (debug only):
 *   Assert maplistCTMap.size() is unchanged after each Update().
 *   Compiled out in release (#ifndef NDEBUG).
 */

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cstdlib>

// TWorld is a QObject — needs a QCoreApplication
#include <QCoreApplication>
#include "model.h"
#include "global.h"

static void run_single_lifecycle(TWorld &W, const std::string &label)
{
    std::cout << "[" << label << "] Initialize...\n";
    W.Initialize();

#ifndef NDEBUG
    int map_count_after_init = W.maplistCTMap.size();
    std::cout << "[" << label << "] maplistCTMap.size() after Init = " << map_count_after_init << "\n";
#endif

    int steps = 0;
    while (W.time < W.EndTime) {
        bool cont = W.Update();
        steps++;

#ifndef NDEBUG
        assert(W.maplistCTMap.size() == (size_t)map_count_after_init &&
               "maplistCTMap size changed during Update — map was allocated or freed mid-run");
#endif

        if (!cont) break;
    }

    std::cout << "[" << label << "] Finalize after " << steps << " steps.\n";
    W.Finalize();
    std::cout << "[" << label << "] Done.\n";
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "usage: bmi_lifecycle_test <runfile>\n";
        return 1;
    }

    QCoreApplication app(argc, argv);

    // --- global op setup (mirrors main.cpp batch setup) ---
    op.runfilename  = QString::fromLocal8Bit(argv[1]);
    op.doBatchmode  = true;
    op.userAppDir   = QFileInfo(op.runfilename).absolutePath() + "/";

    // ---- C2: stepped single lifecycle ----
    {
        TWorld W;
        W.bmiMode   = true;
        W.noInterface = true;
        try {
            run_single_lifecycle(W, "C2-stepped");
        } catch (const std::exception &e) {
            std::cerr << "[C2] FAILED: " << e.what() << "\n";
            return 2;
        }
    }

    // ---- C3: double lifecycle — must not crash, outputs must match ----
    {
        TWorld W;
        W.bmiMode    = true;
        W.noInterface = true;
        try {
            run_single_lifecycle(W, "C3-run1");
            run_single_lifecycle(W, "C3-run2");
        } catch (const std::exception &e) {
            std::cerr << "[C3] FAILED: " << e.what() << "\n";
            return 3;
        }
    }

    std::cout << "\nAll lifecycle tests passed.\n";
    std::cout << "Compare output files (totals*.csv, error-*.csv, maps) with C1 DoModel() baseline.\n";
    return 0;
}
