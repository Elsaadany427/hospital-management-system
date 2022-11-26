//
// Created by elsaadany on 26/11/22.
//

#include "H03_03_DOCTOR.h"
#include "H00_00_GLOBAL.h"

namespace doctorStd {
    Doctor::Doctor() {
        m_id = -1;
        m_type = "";
        m_appointmentBooked = 0;
        m_category = 1;
        m_catType = "doctor";
    }
    void Doctor::fillMap() {
        std::fstream f;
        f.open("./data/doctors.csv", std::ios::in);
        std::string copyDataFromFileDoctor;
        //skipping the first row containing column headers;
        getline(f >> std::ws, copyDataFromFileDoctor);
        //analyzing each entry afterwards;
        while (getline(f >> std::ws, copyDataFromFileDoctor))
        {
            Doctor d;
            //creating a string stream object to read from string 'temp';
            std::stringstream s(copyDataFromFileDoctor);
            std::string doctorId, gender, age, address, appointmentsBooked;
            //reading from the string stream object 's';
            getline(s, doctorId, ',');
            getline(s, d.m_firstName, ',');
            getline(s, d.m_lastName, ',');
            getline(s, gender, ',');
            getline(s, age, ',');
            getline(s, d.m_mobNumber, ',');
            getline(s, address, ',');
            getline(s, d.m_type, ',');
            getline(s, appointmentsBooked, ',');
            d.m_id = globalStd::strToNum(doctorId);
            d.m_gender = gender[0];
            d.m_age = globalStd::strToNum(age);
            d.m_address.decryptAddress(address);
            d.m_appointmentBooked = globalStd::strToNum(appointmentsBooked);
        }
        f.close();
        return;
    }
}