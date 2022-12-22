//
// Created by elsaadany on 28/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H06_06_DRIVER_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H06_06_DRIVER_H
#include "H01_01_PERSON.h"
#include <bits/stdc++.h>

class Ambulance;
class Driver : public Person {
private:
    std::string m_licenceNumber;
    bool m_idle;
    friend class Ambulance;
public:
    Driver();
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
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H06_06_DRIVER_H
