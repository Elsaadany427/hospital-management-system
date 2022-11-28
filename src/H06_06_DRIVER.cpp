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
    void Driver::getDetails(int t_rec) {
        int options = 0;
        std::cout << "\nOPTIONS:\n[1]: Filter by ID\n[2]: Filter by Name\n[3]: Filter by License Number\n\n";
        std::cin >> options;
        while (options != 1 && options != 2 && options != 3)
            std::cout << "option 1, 2 or 3?\n", std::cin >> options;

        // Filter by ID
        if (options == 1) {
            int reqId = 0;
            std::cout << "Please enter the ID \n";
            std::cin >> reqId;
            if (hospitalStd::Hospital::m_driversList.find(reqId) != hospitalStd::Hospital::m_driversList.end())
                *this = hospitalStd::Hospital::m_driversList[reqId];
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
            std::vector<Driver> matchingRecords;
            for (const auto &i: hospitalStd::Hospital::m_driversList) {
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
                    std::cout << "\nEnter the ID of the required driver: ";
                    std::cin >> reqId;
                    if (hospitalStd::Hospital::m_driversList.find(reqId) != hospitalStd::Hospital::m_driversList.end())
                        *this = hospitalStd::Hospital::m_driversList[reqId];
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
            std::string reqLicenceNum;
            std::cout << "Enter the License Number of driver required:\n";
            getline(std::cin >> std::ws, reqLicenceNum);
            std::vector<Driver> matchingRecords;
            for (const auto &i: hospitalStd::Hospital::m_driversList) {
                if (i.second.m_licenceNumber == reqLicenceNum)
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
                    std::cout << "\nEnter the ID of the required driver: ";
                    std::cin >> reqId;
                    if (hospitalStd::Hospital::m_driversList.find(reqId) != hospitalStd::Hospital::m_driversList.end())
                        *this = hospitalStd::Hospital::m_driversList[reqId];
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
    void Driver::getDetailsFromHistory() {
        // will implement soon
    }
}