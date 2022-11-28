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
}