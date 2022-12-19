//
// Created by elsaadany on 26/11/22.
//

#include "H04_04_HOSPITAL.h"
#include "H03_03_DOCTOR.h"

//map<id, object>
std::map<int, Doctor> Hospital::m_doctorsList;
std::map<int, Nurse> Hospital::m_nursesList;
std::map<int, Driver> Hospital::m_driversList;
std::map<int, Patient> Hospital::m_patientsList;

// Limits
const int Hospital::m_doctorsLimit = 30;
const int Hospital::m_nursesLimit = 50;
const int Hospital::m_driversLimit = 50;
const int Hospital::m_patientsLimit = 50;

//defining declared methods;
void Hospital::printDoctors() {
    for (auto i: m_doctorsList)
        i.second.printDetails(), std::cout << "\n";
}

void Hospital::printNurses() {
    for (auto i: m_nursesList)
        i.second.printDetails(), std::cout << "\n";
}

void Hospital::printDrivers() {
    for (auto i: m_driversList)
        i.second.printDetails(), std::cout << "\n";
}

void Hospital::printPatients() {
    for (auto i: m_patientsList)
        i.second.printDetails(), std::cout << "\n";
}
