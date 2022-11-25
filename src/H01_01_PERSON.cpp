//
// Created by elsaadany on 25/11/22.
//

#include "../include/H01_01_PERSON.h"
#include <bits/stdc++.h>
namespace personStd {
    // Initialized Constructor
    Person::Person() {
        m_id = -1;
    }
    // Adding person
    void Person::addPerson(int16_t t_minAge, int16_t t_maxAge) {
        // Getting user details from user side
        // Getting name of user
        std::cout << "\nEnter name: \nFirst name:\n";
        getline(std::cin >> std::ws, m_firstName);

        std::cout << "\nLast name:\n";
        getline(std::cin, m_lastName);

        // getting Age
        std::cout << "\nEnter age: \n";
        std::cin >> m_age;

        // checking the age
        while (m_age <= 0) {
            std::cout << "Was that supposed to make any kind of sense?\nEnter again!\n", std::cin >> m_age;
        }
        // checking the ages of all staff except patient(category 2)
        if (m_category != 2) {
            if (m_age < t_minAge)
                return void(std::cout << "Sorry, person should be at least " << t_minAge << " years old to be registered as a " << m_catType << ".\n");
            else if (m_age > t_maxAge)
                return void(std::cout << "Sorry, we can't register a person older than " << t_maxAge << " years as a " << m_catType << ".\n");
        }
        // Getting gender
        std::cout << "\nGender (M = Male || F = Female): \n";
        std::cin >> m_gender;
        // Checking gender
        while (m_gender != 'M' && m_gender != 'F')
            std::cout << "M or F?\n", std::cin >> m_gender;
        // Getting phone number
        std::cout << "\nEnter mobile number (with country code): \n";
        getline(std::cin >> std::ws, m_mobNumber);

        return;
    }
    void Person::printDetails() {
        if (m_id == -1)
            return;

        std::cout << "\nDetails:\n";
        std::cout << "ID              : " << m_id << "\n";
        std::cout << "Full Name       : " << m_firstName << " " << m_lastName << "\n";
        std::cout << "Gender          : " << m_gender << "\n";
        std::cout << "Age             : " << m_age << "\n";
        std::cout << "Mobile          : " << m_mobNumber << "\n";
        return;
    }
    void Person::printDetailsFromHistory() {
        if (m_id == -1)
            return;

        std::cout << "\nDetails:\n";
        std::cout << "ID              : " << m_id << "\n";
        std::cout << "Full Name       : " << m_firstName << " " << m_lastName << "\n";
        std::cout << "Gender          : " << m_gender << "\n";
        std::cout << "Age             : " << m_age << "\n";
        std::cout << "Mobile          : " << m_mobNumber << "\n";
        return;
    }
}// namespace personStd