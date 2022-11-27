//
// Created by elsaadany on 26/11/22.
//

#include "H04_04_HOSPITAL.h"
#include "H03_03_DOCTOR.h"
namespace hospitalStd {
    std::map<int, doctorStd::Doctor> Hospital::m_doctorsList;
    const int Hospital::m_doctorsLimit = 30;

    //defining declared methods;
    void Hospital::printDoctors()
    {
        for (auto i : m_doctorsList)
            i.second.printDetails(), std::cout << "\n";
        return;
    }
}