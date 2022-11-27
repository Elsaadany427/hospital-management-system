//
// Created by elsaadany on 26/11/22.
//

#include "H03_03_DOCTOR.h"
#include "H00_00_GLOBAL.h"
#include "H04_04_HOSPITAL.h"

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
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctors.csv", std::ios::in);
        std::string copyDataFromFileDoctor;
        //skipping the first row containing column headers;
        getline(f >> std::ws, copyDataFromFileDoctor);
        //analyzing each entry afterwards;
        while (getline(f >> std::ws, copyDataFromFileDoctor)) {
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
            hospitalStd::Hospital::m_doctorsList[d.m_id] = d;
        }
        f.close();
        return;
    }
    void Doctor::saveMap() {
        std::fstream f;
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", std::ios::out);
        // `le first line containing column headers:
        f << "doctorId,firstName,lastName,gender,age,mobNumber,address,type,appointmentsBooked\n";

        for (const auto &i: hospitalStd::Hospital::m_doctorsList)
            f << i.second.m_id << "," << i.second.m_firstName << "," << i.second.m_lastName << "," << i.second.m_gender
              << "," << i.second.m_age << "," << i.second.m_mobNumber << "," << i.second.m_address.encryptAddress()
              << "," << i.second.m_type << "," << i.second.m_appointmentBooked << "\n";
        f.close();

        remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctors.csv");
        rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctors.csv");

        return;
    }
    void Doctor::addPerson() {
        if (hospitalStd::Hospital::m_doctorsList.size() == hospitalStd::Hospital::m_doctorsLimit) {
            std::cout << "\n\nDoctors limit reached, can't add more!\n\n";
            return;
        }
        //18 and 65 are the age limits for registration of a new doctor;
        personStd::Person::addPerson(18, 65);
        if ((m_age < 18) || (m_age > 65))
            return;
        std::cout << "\nEnter the type of the doctor: \n";
        getline(std::cin >> std::ws, m_type);
        // debug
        if (hospitalStd::Hospital::m_doctorsList.rbegin() != hospitalStd::Hospital::m_doctorsList.rend())
            m_id = ((hospitalStd::Hospital::m_doctorsList.rbegin())->first) + 1;
        else
            m_id = 1;
        hospitalStd::Hospital::m_doctorsList[m_id] = *this;

        //creating an f stream object to read/write from/to files;
        std::fstream f;
        //creating a record in doctorsHistory.csv;
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctorsHistory.csv", std::ios::app);
        f << m_firstName << "," << m_lastName << "," << m_gender << "," << m_age << "," << m_mobNumber << "," << m_address.encryptAddress() << "," << m_type << ",N,NA"
          << "\n";
        f.close();

        std::cout << "\n"
                  << m_firstName << " " << m_lastName << " registered successfully!\n";
        std::cout << "Their ID is: " << m_id << "\n";
    }
    void Doctor::printDetails() {
        personStd::Person::printDetails();
        std::cout << "Type            : " << m_type << "\n";
        std::cout << "Appointments    : " << m_appointmentBooked << "/8 (appointments booked today)\n";
        return;
    }
    void Doctor::printDetailsFromHistory() {
        personStd::Person::printDetailsFromHistory();
        std::cout << "Type            : " << m_type << "\n";
        // will continue with this method soon
    }
    void Doctor::getDetails(int t_rec) {
        int options = 0;
        std::cout << "\nOPTIONS:\n[1]: Filter by ID\n[2]: Filter by Name\n[3]: Filter by Type\n\n";
        std::cin >> options;
        while (options != 1 && options != 2 && options != 3)
            std::cout << "option 1, 2 or 3?\n", std::cin >> options;

        // Filter by ID
        if (options == 1) {
            int reqId = 0;
            std::cin >> reqId;
            if (hospitalStd::Hospital::m_doctorsList.find(reqId) != hospitalStd::Hospital::m_doctorsList.end())
                *this = hospitalStd::Hospital::m_doctorsList[reqId];
            else
                std::cout << "\nNo matching record found!\n";
        }
    }
    void Doctor::getDetailsFromHistory() {}
    void Doctor::removePerson() {}

}// namespace doctorStd