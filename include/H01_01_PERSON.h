//
// Created by elsaadany on 25/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H01_01_PERSON_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H01_01_PERSON_H
#include "H02_02_ADDRESS.h"
#include <bits/stdc++.h>

class Person {
protected:
    int m_id;
    std::string m_firstName, m_lastName;
    char m_gender;
    int16_t m_age;
    Address m_address;
    std::string m_mobNumber;
    std::string m_catType;// "doctor"; patient; nurse; driver;
    int m_category;       // 1 2 3 4

public:
    Person();
    virtual void fillMap() = 0;
    virtual void saveMap() = 0;
    virtual void addPerson(int16_t t_minAge, int16_t t_maxAge);
    virtual void addPerson() { addPerson(0, 1000); };
    virtual void printDetails();
    virtual void printDetailsFromHistory();
    virtual void getDetails(int t_rec) = 0;
    virtual void getDetails() { getDetails(0); };
    virtual void getDetailsFromHistory() = 0;
    virtual void removePerson() = 0;
};
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H01_01_PERSON_H
