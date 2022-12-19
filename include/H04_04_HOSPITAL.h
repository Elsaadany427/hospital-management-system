//
// Created by elsaadany on 26/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#include "H03_03_DOCTOR.h"
#include "H05_05_NURSE.h"
#include "H06_06_DRIVER.h"
#include "H07_07_PATIENT.h"
#include <bits/stdc++.h>

//namespace hospitalStd {
class Hospital {
private:
    //map<id, object>
    static std::map<int, Doctor> m_doctorsList;
    static std::map<int, Nurse> m_nursesList;
    static std::map<int, Driver> m_driversList;
    static std::map<int, Patient> m_patientsList;

    // Limits
    static const int m_doctorsLimit;
    static const int m_nursesLimit;
    static const int m_driversLimit;
    static const int m_patientsLimit;

    // Friend classes
    friend class Doctor;
    friend class Nurse;
    friend class Driver;
    friend class Patient;

public:
    static void printDoctors();
    static void printNurses();
    static void printDrivers();
    static void printPatients();
};

//}
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
