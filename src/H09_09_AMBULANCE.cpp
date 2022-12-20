//
// Created by elsaadany on 20/12/22.
//

#include "H09_09_AMBULANCE.h"
#include "H00_00_GLOBAL.h"
#include "H04_04_HOSPITAL.h"

Ambulance::Ambulance() {
    m_id = -1;
    m_driver.m_id = -1;
}
void Ambulance::fillMap() {
    std::fstream f;
    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/ambulances.csv", std::ios::in);
    std::string copyDataFromFileAmbulances;
    //skipping the first row containing column headers;
    getline(f >> std::ws, copyDataFromFileAmbulances);
    //analyzing each entry afterwards;
    while (getline(f >> std::ws, copyDataFromFileAmbulances)) {
        Ambulance a;
        //creating a string stream object to read from string 'temp';
        std::stringstream s(copyDataFromFileAmbulances);
        std::string ambulanceId, idle, address, driverId;
        //reading from the string stream object 's';
        getline(s, ambulanceId, ',');
        getline(s, a.m_model, ',');
        getline(s, a.m_industrialist, ',');
        getline(s, a.m_arn, ',');
        getline(s, idle, ',');
        getline(s, address, ',');
        getline(s, driverId, ',');
        a.m_id = strToNum(ambulanceId);
        a.m_idle = (idle == "Y");
        // Not idle
        if(!a.m_idle){
            a.m_address.decryptAddress(address);
            a.m_driver = Hospital::m_driversList[strToNum(driverId)];
        }
        Hospital::m_ambulanceList[a.m_id] = a;
    }
    f.close();
}