//
// Created by elsaadany on 28/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H07_07_PATIENT_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H07_07_PATIENT_H
#include "H01_01_PERSON.h"
#include <bits/stdc++.h>

namespace patientStd{
    class Patient : public personStd::Person{
    private:
        int m_height;
        int m_weight;
        bool m_hospitalized;
        bool m_alive;

    public:
        Patient();
        void fillMap() override;
        void saveMap() override;
        void addPerson() override;
        void printDetails() override;
        void printDetailsFromHistory() override;
        void getDetails(int t_rec) override;
        void getDetails() override {getDetails(0);};
        void getDetailsFromHistory() override;
        void removePerson() override;
        void hospitalize();
        void reportADeath();
    };
}
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H07_07_PATIENT_H
