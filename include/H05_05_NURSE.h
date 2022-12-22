//
// Created by elsaadany on 27/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H05_05_NURSE_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H05_05_NURSE_H
#include "H01_01_PERSON.h"
#include <bits/stdc++.h>

class Nurse : public Person {
private:
    std::string m_type;

public:
    Nurse();
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

#endif//HOSPITAL_MANAGEMENT_SYSTEM_H05_05_NURSE_H
