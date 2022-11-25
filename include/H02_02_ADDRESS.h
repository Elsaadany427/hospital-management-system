//
// Created by elsaadany on 25/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H02_02_ADDRESS_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H02_02_ADDRESS_H
#include <bits/stdc++.h>

namespace addressStd {
    class Address {
    private:
        std::string m_line1, m_line2;
        std::string m_city;
        std::string m_state;
        std::string m_pinCode;
        std::string m_country;

    public:
        Address();
        void takeAddress();
        void printAddress();
        std::string addToStr();
        void strToAdd(std::string t_str);
    };
}// namespace addressStd
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H02_02_ADDRESS_H
