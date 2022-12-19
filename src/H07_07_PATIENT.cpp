//
// Created by elsaadany on 28/11/22.
//

#include "H07_07_PATIENT.h"
#include "H00_00_GLOBAL.h"
#include "H04_04_HOSPITAL.h"

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
        p.m_id = strToNum(patientId);
        p.m_gender = gender[0];
        p.m_age = {(int16_t) (strToNum(age))};
        p.m_address.decryptAddress(address);
        p.m_height = strToNum(height);
        p.m_weight = strToNum(weight);
        p.m_hospitalized = (hospitalized == "Y");
        p.m_alive = (alive == "Y");
        Hospital::m_patientsList[p.m_id] = p;
    }
    f.close();
}
void Patient::saveMap() {
    std::fstream f;
    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", std::ios::out);
    // `le first line containing column headers:
    f << "patientId,firstName,lastName,gender,age,mobNumber,address,height,weight,wasHospitalized?,stillAlive(ifHospitalized)?\n";

    for (const auto &i: Hospital::m_patientsList)
        f << i.second.m_id << "," << i.second.m_firstName << "," << i.second.m_lastName << "," << i.second.m_gender
          << "," << i.second.m_age << "," << i.second.m_mobNumber << "," << i.second.m_address.encryptAddress()
          << "," << i.second.m_height << "," << i.second.m_weight << ","
          << (i.second.m_hospitalized ? 'Y' : 'N') << "," << (i.second.m_alive ? 'Y' : 'N') << "\n";
    f.close();

    remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/patients.csv");
    rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/patients.csv");
}
void Patient::addPerson() {
    //18 and 65 are the age limits for registration of a new doctor;
    Person::addPerson();
    std::cout << "\nEnter the height of the patient (in cms):\n";
    std::cin >> m_height;
    std::cout << "\nEnter the weight of the patient (in pounds):\n";
    std::cin >> m_weight;
    char selection;
    std::cout << "\nIs the patient being hospitalized? (Y = Yes || N = No)\n";
    std::cin >> selection;
    while (selection != 'Y' && selection != 'N')
        std::cout << "Y or N?\n", std::cin >> selection;
    m_hospitalized = (selection == 'Y');

    if (Hospital::m_patientsList.rbegin() != Hospital::m_patientsList.rend())
        m_id = ((Hospital::m_patientsList.rbegin())->first) + 1;
    else
        m_id = 1;
    Hospital::m_patientsList[m_id] = *this;

    //creating an f stream object to read/write from/to files;
    std::fstream f;
    //creating a record in doctorsHistory.csv;
    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/patientsHistory.csv", std::ios::app);
    f << m_firstName << "," << m_lastName << "," << m_gender << "," << m_age << "," << m_mobNumber << "," << m_address.encryptAddress() << "," << m_height << ","
      << m_weight << "," << ((m_hospitalized) ? "Y" : "N") << ","
      << "Y"
      << ","
      << "N"
      << "\n";
    f.close();

    std::cout << "\n"
              << m_firstName << " " << m_lastName << " registered successfully!\n";
    std::cout << "Their ID is: " << m_id << "\n";
}
void Patient::printDetails() {
    Person::printDetails();
    std::cout << "Height (cms)    : " << m_height << "\n";
    std::cout << "Weight (pounds) : " << m_weight << "\n";
    std::cout << "Was Hospitalized? " << ((m_hospitalized) ? "Y" : "N") << "\n";
    std::cout << "Alive?          : " << ((m_alive) ? "Y" : "N") << "\n";
}
void Patient::printDetailsFromHistory() {
    Person::printDetailsFromHistory();
    std::cout << "Height (cms)    : " << m_height << "\n";
    std::cout << "Weight (pounds) : " << m_weight << "\n";
    std::cout << "Was Hospitalized? " << ((m_hospitalized) ? "Y" : "N") << "\n";
    std::cout << "Alive?          : " << ((m_alive) ? "Y" : "N") << "\n";
    // will continue with this method soon
}
void Patient::getDetails(int t_rec) {
    int options = 0;
    std::cout << "\nOPTIONS:\n[1]: Filter by ID\n[2]: Filter by Name\n\n";
    std::cin >> options;
    while (options != 1 && options != 2)
        std::cout << "option 1 or 2?\n", std::cin >> options;

    // Filter by ID
    if (options == 1) {
        int reqId = 0;
        std::cout << "Please enter the ID \n";
        std::cin >> reqId;
        if (Hospital::m_patientsList.find(reqId) != Hospital::m_patientsList.end())
            *this = Hospital::m_patientsList[reqId];
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
        std::vector<Patient> matchingRecords;
        for (const auto &i: Hospital::m_patientsList) {
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
                std::cout << "\nEnter the ID of the required patient: ";
                std::cin >> reqId;
                if (Hospital::m_patientsList.find(reqId) != Hospital::m_patientsList.end())
                    *this = Hospital::m_patientsList[reqId];
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
void Patient::getDetailsFromHistory() {
    // will implement soon
}
void Patient::hospitalize() {
    std::cout << "\nSearch for the patient.\n";
    getDetails();
    if (m_id == -1)
        return;
    // it will be saved in csv when saveMap called
    Hospital::m_patientsList[m_id].m_hospitalized = true;

    std::string currentS, temp, corrected;
    std::stringstream copyS;
    std::fstream f, fout;
    copyS << m_firstName << "," << m_lastName
          << "," << m_gender << "," << m_age << "," << m_mobNumber << "," << m_address.encryptAddress()
          << "," << m_height << "," << m_weight << "," << ((m_hospitalized) ? "Y" : "N")
          << ","
          << ((m_alive) ? "Y" : "N")
          << ",N"
          << "\n";
    getline(copyS >> std::ws, currentS);

    copyS << m_firstName << "," << m_lastName
          << "," << m_gender << "," << m_age << "," << m_mobNumber << "," << m_address.encryptAddress()
          << "," << m_height << "," << m_weight << ","
          << "Y,"
          << ((m_alive) ? "Y,N\n" : "N,N\n");
    getline(copyS >> std::ws, corrected);
    // search in patientsHistory to change row
    f.open("./data/patientsHistory.csv", std::ios::in);
    fout.open("./data/temp.csv", std::ios::out);
    while (getline(f, temp)) {
        if (temp == currentS)
            fout << corrected << "\n";
        else
            fout << temp << "\n";
    }
    f.close();
    fout.close();
    currentS.erase();
    temp.erase();
    remove("./data/patientsHistory.csv");
    rename("./data/temp.csv", "./data/patientsHistory.csv");
    std::cout << m_firstName << " " << m_lastName << " hospitalized successfully!\n";
}
void Patient::reportADeath() {
    std::cout << "\nSearch for the patient.\n";
    getDetails();
    if (m_id == -1)
        return;
    // it will be saved in csv when saveMap called
    Hospital::m_patientsList[m_id].m_alive = false;

    std::string currentS, temp, corrected;
    std::stringstream copyS;
    std::fstream f, fout;
    copyS << m_firstName << "," << m_lastName
          << "," << m_gender << "," << m_age << "," << m_mobNumber << "," << m_address.encryptAddress()
          << "," << m_height << "," << m_weight << "," << ((m_hospitalized) ? "Y" : "N")
          << ","
          << ((m_alive) ? "Y" : "N")
          << ",N"
          << "\n";
    getline(copyS >> std::ws, currentS);

    copyS << m_firstName << "," << m_lastName
          << "," << m_gender << "," << m_age << "," << m_mobNumber << "," << m_address.encryptAddress()
          << "," << m_height << "," << m_weight << "," << ((m_hospitalized) ? "Y,N,N\n" : "N,N,N\n");
    getline(copyS >> std::ws, corrected);
    // search in patientsHistory to change row
    f.open("./data/patientsHistory.csv", std::ios::in);
    fout.open("./data/temp.csv", std::ios::out);
    while (getline(f, temp)) {
        if (temp == currentS)
            fout << corrected << "\n";
        else
            fout << temp << "\n";
    }
    f.close();
    fout.close();
    currentS.erase();
    temp.erase();
    remove("./data/patientsHistory.csv");
    rename("./data/temp.csv", "./data/patientsHistory.csv");
    std::cout << m_firstName << " " << m_lastName << " hospitalized successfully!\n";
}
void Patient::removePerson() {
    std::cout << "\nSearch for the patient you want to remove.\n";
    getDetails();
    if (m_id == -1)
        return;
    if (!m_hospitalized) {
        std::cout << "\nPatient wasn't hospitalized, can't be discharged!\n\n";
        return;
    }
    Hospital::m_patientsList.erase(m_id);

    std::string currentS, temp;
    std::stringstream str;
    std::fstream f, fOut;

    str << m_firstName << "," << m_lastName << "," << m_gender << "," << m_age
        << "," << m_mobNumber << "," << m_address.encryptAddress() << "," << m_height << "," << m_weight << ","
        << "Y"
        << ","
        << ((m_alive) ? "Y" : "N")
        << ",N"
        << "\n";
    getline(str, currentS);

    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/patientsHistory.csv", std::ios::in);
    fOut.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", std::ios::out);

    while (getline(f, temp)) {
        if (temp == currentS) {
            fOut << m_firstName << "," << m_lastName << "," << m_gender << "," << m_age
                 << "," << m_mobNumber << "," << m_address.encryptAddress() << "," << m_height << "," << m_weight << ","
                 << "Y"
                 << ","
                 << ((m_alive) ? "Y" : "N")
                 << ",Y"
                 << "\n";
        } else
            fOut << temp << "\n";
    }
    f.close();
    fOut.close();
    currentS.erase();
    temp.erase();
    remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/patientsHistory.csv");
    rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/patientsHistory.csv");
    std::cout << m_firstName << " " << m_lastName << " removed successfully!\n";
}
