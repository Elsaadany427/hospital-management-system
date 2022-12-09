
//
// Created by elsaadany on 09/12/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H08_08_APPOINTMENT_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H08_08_APPOINTMENT_H
#include "H01_01_PERSON.h"
#include "H03_03_DOCTOR.h"
#include "H07_07_PATIENT.h"
#include <bits/stdc++.h>

namespace appointmentStd {
    class Appointment : public personStd::Person {
    private:
        int id;
        doctorStd::Doctor doctor;
        patientStd::Patient patient;
        int hh;
    public:
        Appointment();
        ~Appointment();
        void fillMap() override;
        void saveMap() override;
        void printDetails() override;
        void getDetails() override;
        void book();
        void fillDetails();
    };
}
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H08_08_APPOINTMENT_H
