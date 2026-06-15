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

#include <QCoreApplication>

#include "BmiLisem.h"

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

        m.Finalize();
    }
    catch (const std::exception &e) {
        std::cerr << "\nBMI run FAILED: " << e.what() << "\n";
        return 2;
    }

    std::cout << "\nBMI run completed.\n";
    return 0;
}
