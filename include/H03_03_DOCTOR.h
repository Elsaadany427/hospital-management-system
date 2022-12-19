//
// Created by elsaadany on 26/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H03_03_DOCTOR_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H03_03_DOCTOR_H
#include "H01_01_PERSON.h"
#include <bits/stdc++.h>

class Appointment;

//namespace doctorStd {
class Doctor : public Person {
private:
    std::string m_type;
    int m_appointmentBooked;
    friend class Appointment;

public:
    Doctor();
    void fillMap() override;
    void saveMap() override;
    void addPerson() override;
    void printDetails() override;
    void printDetailsFromHistory() override;
    void getDetails(int t_rec) override;
    void getDetails() override { getDetails(0); };
    void getDetailsFromHistory() override;
    void removePerson() override;
};
//}
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H03_03_DOCTOR_H
