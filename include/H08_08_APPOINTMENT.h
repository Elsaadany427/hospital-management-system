
//
// Created by elsaadany on 09/12/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H08_08_APPOINTMENT_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H08_08_APPOINTMENT_H
#include "H03_03_DOCTOR.h"
#include "H07_07_PATIENT.h"
#include <bits/stdc++.h>

class Appointment {
private:
    int m_id;
    Doctor m_doctor;
    Patient m_patient;
    int m_hours{};// hours -> start hour in 24-hour format;

public:
    Appointment();
    ~Appointment();
    static void fillMap() ;
    static void saveMap() ;
    void printDetails() ;
    void getDetails() ;
    void book();
    void fillDetails();
};
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H08_08_APPOINTMENT_H
