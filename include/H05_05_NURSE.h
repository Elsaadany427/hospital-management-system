//
// Created by elsaadany on 27/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H05_05_NURSE_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H05_05_NURSE_H
#include "H01_01_PERSON.h"
#include <bits/stdc++.h>

namespace nurseStd {
    class Nurse : public personStd::Person{
    private:
        std::string m_type;

    public:
        void fillMap() override;
        void saveMap() override;
        void addPerson() override;
        void printDetails() override;
        void printDetailsFromHistory() override;
        void getDetails(int t_rec) override;
        void getDetails() override {getDetails(0);};
        void getDetailsFromHistory() override;
        void removePerson() override;
    };

}
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H05_05_NURSE_H
