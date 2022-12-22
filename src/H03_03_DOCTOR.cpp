//
// Created by elsaadany on 26/11/22.
//

#include "H03_03_DOCTOR.h"
#include "H00_00_GLOBAL.h"
#include "H04_04_HOSPITAL.h"

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
        d.m_id = strToNum(doctorId);
        d.m_gender = gender[0];
        d.m_age = {(int16_t) (strToNum(age))};
        d.m_address.decryptAddress(address);
        d.m_appointmentBooked = strToNum(appointmentsBooked);
        Hospital::m_doctorsList[d.m_id] = d;
    }
    f.close();
}
void Doctor::saveMap() {
    std::fstream f;
    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", std::ios::out);
    // `le first line containing column headers:
    f << "doctorId,firstName,lastName,gender,age,mobNumber,address,type,appointmentsBooked\n";

    for (const auto &i: Hospital::m_doctorsList)
        f << i.second.m_id << "," << i.second.m_firstName << "," << i.second.m_lastName << "," << i.second.m_gender
          << "," << i.second.m_age << "," << i.second.m_mobNumber << "," << i.second.m_address.encryptAddress()
          << "," << i.second.m_type << "," << i.second.m_appointmentBooked << "\n";
    f.close();

    remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctors.csv");
    rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctors.csv");
}
void Doctor::addPerson() {
    if (Hospital::m_doctorsList.size() == Hospital::m_doctorsLimit) {
        std::cout << "\n\nDoctors limit reached, can't add more!\n\n";
        return;
    }
    //18 and 65 are the age limits for registration of a new doctor;
    Person::addPerson(18, 65);
    if ((m_age < 18) || (m_age > 65))
        return;
    std::cout << "\nEnter the type of the doctor: \n";
    getline(std::cin >> std::ws, m_type);
    // debug
    if (Hospital::m_doctorsList.rbegin() != Hospital::m_doctorsList.rend())
        m_id = ((Hospital::m_doctorsList.rbegin())->first) + 1;
    else
        m_id = 1;
    Hospital::m_doctorsList[m_id] = *this;

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
    Person::printDetails();
    std::cout << "Type            : " << m_type << "\n";
    std::cout << "Appointments    : " << m_appointmentBooked << "/8 (appointments booked today)\n";
}
void Doctor::printDetailsFromHistory() {
    Person::printDetailsFromHistory();
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
        std::cout << "Please enter the ID \n";
        std::cin >> reqId;
        if (Hospital::m_doctorsList.find(reqId) != Hospital::m_doctorsList.end()) {
            *this = Hospital::m_doctorsList[reqId];
            printDetails();
        }
        else
            std::cout << "\nNo matching record found!\n";
    }
    // Filter by name
    else if (options == 2) {
        std::string fName, lName;
        std::cout << "First Name:\n";
        getline(std::cin >> std::ws, fName);
        std::cout << "\nLast Name:\n";
        getline(std::cin, lName);

        // vector for storing matched records
        std::vector<Doctor> matchingRecords;
        for (const auto &i: Hospital::m_doctorsList) {
            if (i.second.m_firstName == fName && i.second.m_lastName == lName)
                matchingRecords.push_back(i.second);
        }
        std::cout << "\n";
        std::cout << matchingRecords.size() << " matching record(s) found!\n";
        for (auto i: matchingRecords)
            i.printDetails();
        char selection = 'N';
        if (matchingRecords.size() > t_rec) {
            do {
                int reqId;
                std::cout << "\nEnter the ID of the required doctor: ";
                std::cin >> reqId;
                if (Hospital::m_doctorsList.find(reqId) != Hospital::m_doctorsList.end())
                    *this = Hospital::m_doctorsList[reqId];
                else {
                    std::cout << "\nInvalid ID!\nTry again? (Y = Yes || N = No)\n";
                    std::cin >> selection;
                    while (selection != 'Y' || selection != 'N')
                        std::cout << "Y or N?\n", std::cin >> selection;
                }
            } while (selection == 'Y');
        }
    }
    // Filter by type
    else if (options == 3) {
        std::string reqType;
        std::cout << "Enter the type of doctor required:\n";
        getline(std::cin >> std::ws, reqType);
        std::vector<Doctor> matchingRecords;
        for (const auto &i: Hospital::m_doctorsList) {
            if (i.second.m_type == reqType)
                matchingRecords.push_back(i.second);
        }
        std::cout << "\n";
        std::cout << matchingRecords.size() << " matching record(s) found!\n";
        for (auto i: matchingRecords)
            i.printDetails();
        char selection = 'N';
        if (matchingRecords.size() > t_rec) {
            do {
                int reqId;
                std::cout << "\nEnter the ID of the required doctor: ";
                std::cin >> reqId;
                if (Hospital::m_doctorsList.find(reqId) != Hospital::m_doctorsList.end())
                    *this = Hospital::m_doctorsList[reqId];
                else {
                    std::cout << "\nInvalid ID!\nTry again? (Y = Yes || N = No)\n";
                    std::cin >> selection;
                    while (selection != 'Y' || selection != 'N')
                        std::cout << "Y or N?\n", std::cin >> selection;
                }
            } while (selection == 'Y');
        }
    }
}
void Doctor::getDetailsFromHistory() {
    // will implement soon
}
void Doctor::removePerson() {
    std::cout << "\nSearch for the doctor you want to remove.\n";
    getDetails();
    if (m_id == -1)
        return;
    if (m_appointmentBooked > 0) {
        std::cout << "\nSelected doctor has appointments booked for today, can't be removed.\n\n";
        return;
    }
    Hospital::m_doctorsList.erase(m_id);

    std::string currentS, temp;
    std::stringstream str;
    std::fstream f, fOut;
    std::string reason;
    std::cout << "\nReason?\n";

    getline(std::cin >> std::ws, reason);
    str << m_firstName << "," << m_lastName << "," << m_gender << "," << m_age
        << "," << m_mobNumber << "," << m_address.encryptAddress() << "," << m_type << ",N,NA\n";
    getline(str, currentS);

    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctorsHistory.csv", std::ios::in);
    fOut.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", std::ios::out);

    while (getline(f, temp)) {
        if (temp == currentS) {
            fOut << m_firstName << "," << m_lastName << "," << m_gender << "," << m_age
                 << "," << m_mobNumber << "," << m_address.encryptAddress() << "," << m_type << ",Y," << reason << "\n";
        } else
            fOut << temp << "\n";
    }
    f.close();
    fOut.close();
    currentS.erase();
    temp.erase();
    remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctorsHistory.csv");
    rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctorsHistory.csv");
    std::cout << m_firstName << " " << m_lastName << " removed successfully!\n";
}
