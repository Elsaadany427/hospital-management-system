//
// Created by elsaadany on 28/11/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H06_06_DRIVER_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H06_06_DRIVER_H
#include "H01_01_PERSON.h"
#include <bits/stdc++.h>

namespace driverStd {
    class Driver : public personStd::Person {
    private:
        std::string licenceNumber;
        bool idle;

    public:
        Driver();
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
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H06_06_DRIVER_H
