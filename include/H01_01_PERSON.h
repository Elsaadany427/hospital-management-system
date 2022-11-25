//
// Created by elsaadany on 25/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H01_01_PERSON_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H01_01_PERSON_H
#include <bits/stdc++.h>

namespace personStd {
    class Person {
    private:
        int m_id;
        std::string m_firstName;
        char m_gender;
        int16_t m_age;
        std::string m_mobNumber;
        std::string m_catType;// "doctor"; patient; nurse; driver;
        int m_category;       // 1 2 3 4

    public:
        Person();
        virtual void fillMap() = 0;
        virtual void saveMap() = 0;
        virtual void addPerson(int16_t t_minAge = 0, int16_t t_maxAge = 1000);
        virtual void printDetails();
        virtual void printDetailsFromHistory();
        virtual void getDetails(int t_rec = 0) = 0;
        virtual void getDetailsFromHistory() = 0;
        virtual void removePerson() = 0;
    };
}// namespace personStd
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H01_01_PERSON_H
