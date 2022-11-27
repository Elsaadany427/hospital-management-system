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
            n.m_id = globalStd::strToNum(nurseId);
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
    void Nurse::addPerson() {
        if (hospitalStd::Hospital::m_nursesList.size() == hospitalStd::Hospital::m_nursesLimit) {
            std::cout << "\n\nNurses limit reached, can't add more!\n\n";
            return;
        }
        //18 and 65 are the age limits for registration of a new doctor;
        personStd::Person::addPerson(18, 65);
        if ((m_age < 18) || (m_age > 65))
            return;
        std::cout << "\nEnter the type of the nurse: \n";
        getline(std::cin >> std::ws, m_type);
        // debug
        if (hospitalStd::Hospital::m_nursesList.rbegin() != hospitalStd::Hospital::m_nursesList.rend())
            m_id = ((hospitalStd::Hospital::m_nursesList.rbegin())->first) + 1;
        else
            m_id = 1;
        hospitalStd::Hospital::m_nursesList[m_id] = *this;

        //creating an f stream object to read/write from/to files;
        std::fstream f;
        //creating a record in doctorsHistory.csv;
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/nursesHistory.csv", std::ios::app);
        f << m_firstName << "," << m_lastName << "," << m_gender << "," << m_age << "," << m_mobNumber << "," << m_address.encryptAddress() << "," << m_type << ",N,NA"
          << "\n";
        f.close();

        std::cout << "\n"
                  << m_firstName << " " << m_lastName << " registered successfully!\n";
        std::cout << "Their ID is: " << m_id << "\n";
    }
    void Nurse::printDetails() {
        personStd::Person::printDetails();
        std::cout << "Type            : " << m_type << "\n";
    }
    void Nurse::printDetailsFromHistory() {
        personStd::Person::printDetailsFromHistory();
        std::cout << "Type            : " << m_type << "\n";
        // will continue with this method soon
    }
}// namespace nurseStd
