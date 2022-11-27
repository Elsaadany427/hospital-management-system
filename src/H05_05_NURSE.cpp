//
// Created by elsaadany on 27/11/22.
//

#include "H05_05_NURSE.h"
#include "H00_00_GLOBAL.h"
#include "H03_03_DOCTOR.h"
#include "H04_04_HOSPITAL.h"


namespace nurseStd {
    Nurse::Nurse() {
        m_id = -1;
        m_type = "";
        m_category = 3;
        m_catType = "nurse";
    }
    void Nurse::fillMap() {
        std::fstream f;
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/nurses.csv", std::ios::in);
        std::string copyDataFromFileNurse;
        //skipping the first row containing column headers;
        getline(f >> std::ws, copyDataFromFileNurse);
        //analyzing each entry afterwards;
        while (getline(f >> std::ws, copyDataFromFileNurse)) {
            Nurse n;
            //creating a string stream object to read from string 'temp';
            std::stringstream s(copyDataFromFileNurse);
            std::string nurseId, gender, age, address;
            //reading from the string stream object 's';
            getline(s, nurseId, ',');
            getline(s, n.m_firstName, ',');
            getline(s, n.m_lastName, ',');
            getline(s, gender, ',');
            getline(s, age, ',');
            getline(s, n.m_mobNumber, ',');
            getline(s, address, ',');
            getline(s, n.m_type, ',');
            n.m_id = globalStd::strToNum(doctorId);
            n.m_gender = gender[0];
            n.m_age = {(int16_t) (globalStd::strToNum(age))};
            n.m_address.decryptAddress(address);
            hospitalStd::Hospital::m_nursesList[n.m_id] = n;
        }
        f.close();
    }
    void Nurse::saveMap() {
        std::fstream f;
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", std::ios::out);
        // `le first line containing column headers:
        f << "nurseId,firstName,lastName,gender,age,mobNumber,address,type\n";

        for (const auto &i: hospitalStd::Hospital::m_nursesList)
            f << i.second.m_id << "," << i.second.m_firstName << "," << i.second.m_lastName << "," << i.second.m_gender
              << "," << i.second.m_age << "," << i.second.m_mobNumber << "," << i.second.m_address.encryptAddress()
              << "," << i.second.m_type << "\n";
        f.close();

        remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/nurses.csv");
        rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/nurses.csv");
    }
}// namespace nurseStd
