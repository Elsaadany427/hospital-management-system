//
// Created by elsaadany on 26/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#include <bits/stdc++.h>
#include "H03_03_DOCTOR.h"
#include "H05_05_NURSE.h"

namespace hospitalStd {
    class Hospital{
    private:
        //map<id, object>
        static std::map<int, doctorStd::Doctor> m_doctorsList;
        static std::map<int, nurseStd::Nurse> m_nursesList;

        // Limits
        static const int m_doctorsLimit;
        static const int m_nursesLimit;

        // Friend classes
        friend class doctorStd::Doctor;
        friend class nurseStd::Nurse;

    public:
        static void printDoctors();
        static void printNurses();
    };

}
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
