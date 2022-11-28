//
// Created by elsaadany on 28/11/22.
//

#include "H06_06_DRIVER.h"
#include "H00_00_GLOBAL.h"
#include "H04_04_HOSPITAL.h"
namespace driverStd {
    Driver::Driver() {
        m_id = -1;
        m_licenceNumber = "";
        m_idle = true;
        m_category = 4;
        m_catType = "driver";
    }
    void Driver::fillMap() {
        std::fstream f;
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/drivers.csv", std::ios::in);
        std::string copyDataFromFileDriver;
        //skipping the first row containing column headers;
        getline(f >> std::ws, copyDataFromFileDriver);
        //analyzing each entry afterwards;
        while (getline(f >> std::ws, copyDataFromFileDriver)) {
            Driver d;
            //creating a string stream object to read from string 'temp';
            std::stringstream s(copyDataFromFileDriver);
            std::string driverId, gender, age, address, idle;
            //reading from the string stream object 's';
            getline(s, driverId, ',');
            getline(s, d.m_firstName, ',');
            getline(s, d.m_lastName, ',');
            getline(s, gender, ',');
            getline(s, age, ',');
            getline(s, d.m_mobNumber, ',');
            getline(s, address, ',');
            getline(s, d.m_licenceNumber, ',');
            getline(s, idle, ',');

            d.m_id = globalStd::strToNum(driverId);
            d.m_gender = gender[0];
            d.m_age = {(int16_t) (globalStd::strToNum(age))};
            d.m_address.decryptAddress(address);
            d.m_idle = (idle == "Y");
            hospitalStd::Hospital::m_driversList[d.m_id] = d;
        }
        f.close();
    }
    void Driver::saveMap() {
        std::fstream f;
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", std::ios::out);
        // `le first line containing column headers:
        f << "driverId,firstName,lastName,gender,age,mobNumber,address,licenceNumber,idle?\n";

        for (const auto &i: hospitalStd::Hospital::m_driversList)
            f << i.second.m_id << "," << i.second.m_firstName << "," << i.second.m_lastName << "," << i.second.m_gender
              << "," << i.second.m_age << "," << i.second.m_mobNumber << "," << i.second.m_address.encryptAddress()
              << "," << i.second.m_licenceNumber << "," << (i.second.m_idle ? 'Y' : 'N') << "\n";
        f.close();

        remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/drivers.csv");
        rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/drivers.csv");
    }

    void Driver::addPerson() {
        if (hospitalStd::Hospital::m_driversList.size() == hospitalStd::Hospital::m_driversLimit) {
            std::cout << "\n\nDriver limit reached, can't add more!\n\n";
            return;
        }
        //18 and 65 are the age limits for registration of a new doctor;
        personStd::Person::addPerson(18, 65);
        if ((m_age < 18) || (m_age > 65))
            return;
        std::cout << "\nEnter the license number of the driver: \n";
        getline(std::cin >> std::ws, m_licenceNumber);
        // debug
        if (hospitalStd::Hospital::m_driversList.rbegin() != hospitalStd::Hospital::m_driversList.rend())
            m_id = ((hospitalStd::Hospital::m_driversList.rbegin())->first) + 1;
        else
            m_id = 1;
        hospitalStd::Hospital::m_driversList[m_id] = *this;

        //creating an f stream object to read/write from/to files;
        std::fstream f;
        //creating a record in doctorsHistory.csv;
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/driversHistory.csv", std::ios::app);
        f << m_firstName << "," << m_lastName << "," << m_gender << "," << m_age << "," << m_mobNumber << "," << m_address.encryptAddress() << "," << m_licenceNumber << ",N,NA"
          << "\n";
        f.close();

        std::cout << "\n"
                  << m_firstName << " " << m_lastName << " registered successfully!\n";
        std::cout << "Their ID is: " << m_id << "\n";
    }

    void Driver::printDetails() {
        personStd::Person::printDetails();
        std::cout << "License Number  : " << m_licenceNumber << "\n";
        std::cout << "Idle?           : " << (m_idle ? "Y\n" : "N\n");
    }
    void Driver::printDetailsFromHistory() {
        personStd::Person::printDetailsFromHistory();
        std::cout << "License Number  : " << m_licenceNumber << "\n";
        std::cout << "Idle?           : " << (m_idle ? "Y\n" : "N\n");
        // will continue with this method soon
    }
}