/*************************************************************************
**  lisem_bmi_test — minimal native BMI driver for OpenLISEM
**
**  Drives the model purely through the bmi::Bmi surface, equivalent to
**  running  ./Lisem -ni -bmistep <runfile>.
**
**  Usage:
**      lisem_bmi_test <path/to/runfile>
**
**  TWorld is a QObject, so a QCoreApplication must exist for the duration
**  of the run (event loop is not started; we drive the loop ourselves).
*************************************************************************/

#include <iostream>
#include <stdexcept>
#include <vector>

#include <QCoreApplication>

#include "BmiLisem.h"
#include "model.h"      // TWorld, MapTotal, WH, Real
#include "pcrtypes.h"   // pcr::isMV — skip masked cells when summing

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "usage: lisem_bmi_test <runfile>\n";
        return 1;
    }

    QCoreApplication app(argc, argv);  // required: TWorld is a QObject

    BmiLisem m;
    try {
        m.Initialize(argv[1]);

        std::cout << "component : " << m.GetComponentName() << "\n";
        std::cout << "start time: " << m.GetStartTime() << " " << m.GetTimeUnits() << "\n";
        std::cout << "end time  : " << m.GetEndTime()   << " " << m.GetTimeUnits() << "\n";
        std::cout << "time step : " << m.GetTimeStep()  << " " << m.GetTimeUnits() << "\n";

        while (m.GetCurrentTime() < m.GetEndTime())
            m.Update();

        // --- B2 sanity check: GetValue() vs the engine's own MapTotal() ---
        // Pull WH through the BMI surface, sum non-MV cells, and compare with
        // MapTotal(*WH). They must match (same underlying raster, no copy drift).
        {
            const std::string var = "land_surface_water__depth";
            const int n = m.GetGridSize(0);
            std::vector<Real> buf(static_cast<size_t>(n));
            m.GetValue(var, buf.data());

            double bmi_sum = 0.0;
            for (int i = 0; i < n; ++i)
                if (!pcr::isMV(buf[i]))
                    bmi_sum += buf[i];

            TWorld *w = m.debugModel();
            double map_total = w->MapTotal(*w->WH);

            std::cout << "\n[check] GetValue(\"" << var << "\") sum = " << bmi_sum << "\n";
            std::cout << "[check] MapTotal(*WH)              = " << map_total << "\n";
            std::cout << "[check] match: "
                      << (bmi_sum == map_total ? "YES" : "NO") << "\n";
        }

        m.Finalize();
    }
    catch (const std::exception &e) {
        std::cerr << "\nBMI run FAILED: " << e.what() << "\n";
        return 2;
    }

    std::cout << "\nBMI run completed.\n";
    return 0;
}
