//
// Created by elsaadany on 28/11/22.
//

#include "H07_07_PATIENT.h"
#include "H00_00_GLOBAL.h"

namespace patientStd{
    Patient::Patient() {
        m_id = -1;
        m_category = 2;
        m_hospitalized = false;
        m_alive = true;
        m_weight = 0;
        m_height = 0;
        m_catType = "patient";
    }
    void Patient::fillMap() {
        std::fstream f;
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/patients.csv", std::ios::in);
        std::string copyDataFromFilePatient;
        //skipping the first row containing column headers;
        getline(f >> std::ws, copyDataFromFilePatient);
        //analyzing each entry afterwards;
        while (getline(f >> std::ws, copyDataFromFilePatient)) {
            Patient p;
            //creating a string stream object to read from string 'temp';
            std::stringstream s(copyDataFromFilePatient);
            std::string patientId, gender, age, address, height, weight, hospitalized, alive;
            //reading from the string stream object 's';
            getline(s, patientId, ',');
            getline(s, p.m_firstName, ',');
            getline(s, p.m_lastName, ',');
            getline(s, gender, ',');
            getline(s, age, ',');
            getline(s, p.m_mobNumber, ',');
            getline(s, address, ',');
            getline(s, height, ',');
            getline(s, weight, ',');
            getline(s, hospitalized, ',');
            getline(s, alive, ',');
            p.m_id = globalStd::strToNum(patientId);
            p.m_gender = gender[0];
            p.m_age = {(int16_t) (globalStd::strToNum(age))};
            p.m_address.decryptAddress(address);
            p.m_height = globalStd::strToNum(height);
            p.m_weight = globalStd::strToNum(weight);
            p.m_hospitalized = (hospitalized == "Y");
            p.m_alive = (alive == "Y");
        }
        f.close();
    }
}