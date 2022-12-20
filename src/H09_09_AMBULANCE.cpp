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
        if (!a.m_idle) {
            a.m_address.decryptAddress(address);
            a.m_driver = Hospital::m_driversList[strToNum(driverId)];
        }
        Hospital::m_ambulanceList[a.m_id] = a;
    }
    f.close();
}
void Ambulance::saveMap() {
    std::fstream f;
    f.open("./data/temp.csv", std::ios::out);
    // Skip first line containing column headers:
    f << "ambulanceId,model,industrialist,arn,idle?,headedTowards(ifNotIdle),driverID(ifNotIdle)\n";
    for (const auto &i: Hospital::m_ambulanceList) {
        f << i.second.m_id << "," << i.second.m_model << "," << i.second.m_industrialist << "," << i.second.m_arn
          << "," << (i.second.m_idle ? ("Y,NA,NA\n") : ("N," + i.second.m_address.encryptAddress() + ","));
        if (!(i.second.m_idle)) {
            f << i.second.m_driver.m_id << std::endl;
        }
    }
    f.close();
    remove("./data/ambulances.csv");
    rename("./data/temp.csv", "./data/ambulances.csv");
}
void Ambulance::addAmbulance() {
    if (Hospital::m_ambulanceList.size() == Hospital::m_ambulanceLimit) {
        std::cout << "\n\nAmbulances limit reached, can't add more!\n\n";
        return;
    }
    //getting the basic details of the ambulance from the user side;
    std::cout << "\nEnter Model of the ambulance:\n";
    getline(std::cin >> std::ws, m_model);
    std::cout << "\nEnter Manufacturer Name of the ambulance:\n";
    getline(std::cin >> std::ws, m_industrialist);
    std::cout << "\nEnter Vehicle Registration Number of the ambulance:\n";
    getline(std::cin >> std::ws, m_arn);
    if (Hospital::m_ambulanceList.rbegin() != Hospital::m_ambulanceList.rend())
        m_id = ((Hospital::m_ambulanceList.rbegin())->first) + 1;
    else
        m_id = 1;
    Hospital::m_ambulanceList[m_id] = *this;

    //creating a fstream object to read/write from/to files;
    std::fstream f;
    //creating a record in ambulancesHistory.csv;
    f.open("./data/ambulancesHistory.csv", std::ios::app);
    f << m_model << "," << m_industrialist << "," << m_arn << ",Y" << std::endl;
    f.close();

    std::cout << "\n"
              << m_model << " by " << m_industrialist << " added successfully!\n";
    std::cout << "Its ID is: " << m_id << "\n";
}
void Ambulance::printDetails() {
    if (m_id == -1)
        return;
    std::cout << "Details:\n";
    std::cout << "ID              : " << m_id << "\n";
    std::cout << "Manufacturer    : " << m_industrialist << "\n";
    std::cout << "Model           : " << m_model << "\n";
    std::cout << "Reg Number      : " << m_arn << "\n";
    std::cout << "Idle?           : " << ((m_idle) ? "Y" : "N") << "\n";
    if (!m_idle) {
        std::cout << "Going to Address: ";
        m_address.printAddress();
        std::cout << "Driver ID       : " << m_driver.m_id << "\n";
    }
}
void Ambulance::printDetailsFromHistory(std::string t_extraDetails) {
    if (m_id == -1) {
        return;
    }
    if (t_extraDetails.empty()) {
        std::fstream f;
        f.open("./data/driversHistory.csv", std::ios::in);
        std::string copyDataFromFileDriver;
        //skipping the first row containing column headers;
        getline(f >> std::ws, copyDataFromFileDriver);
        //analyzing each entry afterwards;
        while (getline(f >> std::ws, copyDataFromFileDriver)) {
            Ambulance a;
            //creating a string stream object to read from string 'temp';
            std::stringstream s(copyDataFromFileDriver);
            std::string arn;
            //reading from the string stream object 's';
            getline(s, a.m_model, ',');
            getline(s, a.m_industrialist, ',');
            getline(s, arn, ',');

            if (m_arn == arn) {
                getline(s, t_extraDetails, ',');
            }
        }
        f.close();
    }
    std::cout << "Model           : " << m_model << "\n";
    std::cout << "Manufacturer    : " << m_industrialist << "\n";
    std::cout << "Reg. Number     : " << m_arn << "\n";
    std::cout << "Still owned?    : " << t_extraDetails << "\n";
}