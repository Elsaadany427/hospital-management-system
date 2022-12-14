//
// Created by elsaadany on 20/12/22.
//

#ifndef HOSPITAL_MANAGEMENT_SYSTEM_H09_09_AMBULANCE_H
#define HOSPITAL_MANAGEMENT_SYSTEM_H09_09_AMBULANCE_H
#include "H06_06_DRIVER.h"
#include "H02_02_ADDRESS.h"

class Ambulance {
private:
    int m_id;
    std::string m_model;
    std::string m_industrialist;
    std::string m_arn;// Ambulance registration number;
    bool m_idle{};
    Address m_address;
    Driver m_driver;

public:
    Ambulance();
    static void fillMap();
    static void saveMap();
    void addAmbulance();
    void printDetails();
    void printDetailsFromHistory(std::string t_extraDetails);
    void printDetailsFromHistory(){printDetailsFromHistory("");};
    void getDetails(int t_rec);
    void getDetails() { getDetails(0); };
    void getDetailsFromHistory();
    void sendAmbulance();
    void reportArrival();
    void removeAmbulance();
};
#endif//HOSPITAL_MANAGEMENT_SYSTEM_H09_09_AMBULANCE_H
