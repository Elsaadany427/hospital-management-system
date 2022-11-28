//
// Created by elsaadany on 26/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#include <bits/stdc++.h>
#include "H03_03_DOCTOR.h"
#include "H05_05_NURSE.h"
#include "H06_06_DRIVER.h"
#include "H07_07_PATIENT.h"

namespace hospitalStd {
    class Hospital{
    private:
        //map<id, object>
        static std::map<int, doctorStd::Doctor> m_doctorsList;
        static std::map<int, nurseStd::Nurse> m_nursesList;
        static std::map<int, driverStd::Driver> m_driversList;
        static std::map<int, patientStd::Patient> m_patientsList;

        // Limits
        static const int m_doctorsLimit;
        static const int m_nursesLimit;
        static const int m_driversLimit;
        static const int m_patientsLimit;

        // Friend classes
        friend class doctorStd::Doctor;
        friend class nurseStd::Nurse;
        friend class driverStd::Driver;
        friend class patientStd::Patient;

    public:
        static void printDoctors();
        static void printNurses();
        static void printDrivers();
        static void printPatients();
    };

}
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
