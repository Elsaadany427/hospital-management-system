//
// Created by elsaadany on 26/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#include <bits/stdc++.h>
#include "H03_03_DOCTOR.h"

namespace hospitalStd {
    class Hospital{
    private:
        //map<id, object>
        static std::map<int, doctorStd::Doctor> m_doctorsList;
        static const int m_doctorsLimit;
        friend class Doctor;

    public:
        static void printDoctors();
    };

}
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
