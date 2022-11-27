//
// Created by elsaadany on 26/11/22.
//

#include "H04_04_HOSPITAL.h"
#include "H03_03_DOCTOR.h"
namespace hospitalStd {
    //map<id, object>
    std::map<int, doctorStd::Doctor> Hospital::m_doctorsList;
    std::map<int, nurseStd::Nurse> Hospital::m_nursesList;

    // Limits
    const int Hospital::m_doctorsLimit = 30;
    const int Hospital::m_nursesLimit = 50;

    //defining declared methods;
    void Hospital::printDoctors()
    {
        for (auto i : m_doctorsList)
            i.second.printDetails(), std::cout << "\n";
    }

    void Hospital::printNurses()
    {
        for (auto i : m_nursesList)
            i.second.printDetails(), std::cout << "\n";
    }
}