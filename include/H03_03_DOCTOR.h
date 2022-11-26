//
// Created by elsaadany on 26/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H03_03_DOCTOR_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H03_03_DOCTOR_H
#include "H01_01_PERSON.h"
#include <bits/stdc++.h>

namespace doctorStd {
    class Doctor : public personStd::Person {
    private:
        std::string type;
        int appointmentBooked;

    public:
        Doctor();
        void fillMap();
        void saveMap();
        void addPerson();
        void printDetails();
        void printDetailsFromHistory();
        void getDetails(int t_rec = 0) = 0;
        void getDetailsFromHistory();
        void removePerson();
    };
}// namespace doctorStd
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H03_03_DOCTOR_H
