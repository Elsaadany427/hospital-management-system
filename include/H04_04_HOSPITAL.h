//
// Created by elsaadany on 26/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
#include "H03_03_DOCTOR.h"
#include "H05_05_NURSE.h"
#include "H06_06_DRIVER.h"
#include "H07_07_PATIENT.h"
#include "H08_08_APPOINTMENT.h"
#include "H09_09_AMBULANCE.h"
#include <bits/stdc++.h>

class Hospital {
private:
    //map<id, object>
    static std::map<int, Doctor> m_doctorsList;
    static std::map<int, Nurse> m_nursesList;
    static std::map<int, Driver> m_driversList;
    static std::map<int, Patient> m_patientsList;
    static std::map<int, Appointment> m_appointmentList;
    static std::map<int, Ambulance> m_ambulanceList;

    // Limits
    static const int m_doctorsLimit;
    static const int m_nursesLimit;
    static const int m_driversLimit;
    static const int m_patientsLimit;
    static const int m_appointmentLimit;
    static const int m_ambulanceLimit;

    // Friend classes
    friend class Doctor;
    friend class Nurse;
    friend class Driver;
    friend class Patient;
    friend class Appointment;
    friend class Ambulance;

public:
    static void printDoctors();
    static void printNurses();
    static void printDrivers();
    static void printPatients();
    static void printAppointments();
    static void printAmbulances();
};
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H04_04_HOSPITAL_H
