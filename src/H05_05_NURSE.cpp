//
// Created by elsaadany on 27/11/22.
//

#include "H05_05_NURSE.h"
#include "H00_00_GLOBAL.h"
#include "H04_04_HOSPITAL.h"


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
        n.m_id = strToNum(nurseId);
        n.m_gender = gender[0];
        n.m_age = {(int16_t) (strToNum(age))};
        n.m_address.decryptAddress(address);
        Hospital::m_nursesList[n.m_id] = n;
    }
    f.close();
}
void Nurse::saveMap() {
    std::fstream f;
    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", std::ios::out);
    // `le first line containing column headers:
    f << "nurseId,firstName,lastName,gender,age,mobNumber,address,type\n";

    for (const auto &i: Hospital::m_nursesList)
        f << i.second.m_id << "," << i.second.m_firstName << "," << i.second.m_lastName << "," << i.second.m_gender
          << "," << i.second.m_age << "," << i.second.m_mobNumber << "," << i.second.m_address.encryptAddress()
          << "," << i.second.m_type << "\n";
    f.close();

    remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/nurses.csv");
    rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/nurses.csv");
}
void Nurse::addPerson() {
    if (Hospital::m_nursesList.size() == Hospital::m_nursesLimit) {
        std::cout << "\n\nNurses limit reached, can't add more!\n\n";
        return;
    }
    //18 and 65 are the age limits for registration of a new doctor;
    Person::addPerson(18, 65);
    if ((m_age < 18) || (m_age > 65))
        return;
    std::cout << "\nEnter the type of the nurse: \n";
    getline(std::cin >> std::ws, m_type);
    // debug
    if (Hospital::m_nursesList.rbegin() != Hospital::m_nursesList.rend())
        m_id = ((Hospital::m_nursesList.rbegin())->first) + 1;
    else
        m_id = 1;
    Hospital::m_nursesList[m_id] = *this;

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
    Person::printDetails();
    std::cout << "Type            : " << m_type << "\n";
}
void Nurse::printDetailsFromHistory() {
    Person::printDetailsFromHistory();
    std::cout << "Type            : " << m_type << "\n";
    // will continue with this method soon
}
void Nurse::getDetails(int t_rec) {
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
        if (Hospital::m_nursesList.find(reqId) != Hospital::m_nursesList.end()) {
            *this = Hospital::m_nursesList[reqId];
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
        std::vector<Nurse> matchingRecords;
        for (const auto &i: Hospital::m_nursesList) {
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
                std::cout << "\nEnter the ID of the required nurse: ";
                std::cin >> reqId;
                if (Hospital::m_nursesList.find(reqId) != Hospital::m_nursesList.end())
                    *this = Hospital::m_nursesList[reqId];
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
        std::vector<Nurse> matchingRecords;
        for (const auto &i: Hospital::m_nursesList) {
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
                std::cout << "\nEnter the ID of the required nurse: ";
                std::cin >> reqId;
                if (Hospital::m_nursesList.find(reqId) != Hospital::m_nursesList.end())
                    *this = Hospital::m_nursesList[reqId];
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
void Nurse::getDetailsFromHistory() {
    // will implement soon
}
void Nurse::removePerson() {
    std::cout << "\nSearch for the nurse you want to remove.\n";
    getDetails();
    if (m_id == -1)
        return;
    Hospital::m_nursesList.erase(m_id);

    std::string currentS, temp;
    std::stringstream str;
    std::fstream f, fOut;
    std::string reason;
    std::cout << "\nReason?\n";

    getline(std::cin >> std::ws, reason);
    str << m_firstName << "," << m_lastName << "," << m_gender << "," << m_age
        << "," << m_mobNumber << "," << m_address.encryptAddress() << "," << m_type << ",N,NA\n";
    getline(str, currentS);

    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/nursesHistory.csv", std::ios::in);
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
    remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/nursesHistory.csv");
    rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/nursesHistory.csv");
    std::cout << m_firstName << " " << m_lastName << " removed successfully!\n";
}
