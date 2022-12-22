//
// Created by elsaadany on 25/11/22.
//
//وَمَا رَمَيْتَ إِذْ رَمَيْتَ وَلَٰكِنَّ اللَّهَ رَمَىٰ ۚ

#include "H03_03_DOCTOR.h"
#include "H04_04_HOSPITAL.h"
#include "H08_08_APPOINTMENT.h"
#include "H00_00_GLOBAL.h"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

typedef long long ll;
const int MAX_N = 1e5 + 12;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

void doctorMenu(Doctor &d) {
    bool exist = false;
    do {
        int choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/DOCTORS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new doctor\n";
        cout << "[02] : Get doctor details\n";
        cout << "[03] : Remove a doctor\n";
        cout << "[04] : Fetch doctor details from history\n";
        cout << "[05] : Get details of all registered doctors\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                d.addPerson();
                break;
            case 2:
                d.getDetails(1);
                break;
            case 3:
                d.removePerson();
                break;
            case 4:
                // Not working yet
                d.getDetailsFromHistory();
                cout << "// Not working yet\n";
                break;
            case 5:
                Hospital::printDoctors();
                break;
            case -1:
                exist = true;
                break;
            default:
                cout << "Invalid choice!\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    } while (!exist);
}
void nursesMenu(Nurse &n) {
    bool exist = false;
    do {
        int choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/NURSES\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new nurse\n";
        cout << "[02] : Get nurse details\n";
        cout << "[03] : Remove a nurse\n";
        cout << "[04] : Fetch nurse details from history\n";
        cout << "[05] : Get details of all registered nurses\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                n.addPerson();
                break;
            case 2:
                n.getDetails(1);
                break;
            case 3:
                n.removePerson();
                break;
            case 4:
                // Not working yet
                n.getDetailsFromHistory();
                cout << "// Not working yet\n";
                break;
            case 5:
                Hospital::printNurses();
                break;
            case -1:
                exist = true;
                break;
            default:
                cout << "Invalid choice!\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    } while (!exist);
}
void driversMenu(Driver &d) {
    bool exist = false;
    do {
        int choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/DRIVERS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new driver\n";
        cout << "[02] : Get driver details\n";
        cout << "[03] : Remove a driver\n";
        cout << "[04] : Fetch driver details from history\n";
        cout << "[05] : Get details of all registered drivers\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                d.addPerson();
                break;
            case 2:
                d.getDetails(1);
                break;
            case 3:
                d.removePerson();
                break;
            case 4:
                // Not working yet
                d.getDetailsFromHistory();
                cout << "// Not working yet\n";
                break;
            case 5:
                Hospital::printDrivers();
                break;
            case -1:
                exist = true;
                break;
            default:
                cout << "Invalid choice!\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    } while (!exist);
}
void patientsMenu(Patient &p) {
    bool exist = false;
    do {
        int choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/PATIENTS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new patient\n";
        cout << "[02] : Get patient details\n";
        cout << "[03] : Hospitalize a registered patient\n";
        cout << "[04] : Report a patient's death\n";
        cout << "[05] : Discharge a patient or their body\n";
        cout << "[06] : Fetch patient details from history\n";
        cout << "[07] : Get details of all registered patients\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.addPerson();
                break;
            case 2:
                p.getDetails(1);
                break;
            case 3:
                p.hospitalize();
                break;
            case 4:
                p.reportADeath();
                break;
            case 5:
                p.removePerson();
                break;
            case 6:
                // Not working yet
                p.getDetailsFromHistory();
                cout << "// Not working yet\n";
                break;
            case 7:
                Hospital::printPatients();
                break;
            case -1:
                exist = true;
                break;
            default:
                cout << "Invalid choice!\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    } while (!exist);
}
void ambulancesMenu(Ambulance &a) {
    bool exist = false;
    do {
        int choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/AMBULANCES\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Add an ambulance\n";
        cout << "[02] : Send an ambulance\n";
        cout << "[03] : Get ambulance details\n";
        cout << "[04] : Report ambulance arrival\n";
        cout << "[05] : Remove an ambulance\n";
        cout << "[06] : Fetch ambulance details from history\n";
        cout << "[07] : Get details of all registered ambulances\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                a.addAmbulance();
                break;
            case 2:
                a.sendAmbulance();
                break;
            case 3:
                a.getDetails(1);
                break;
            case 4:
                a.reportArrival();
                break;
            case 5:
                a.removeAmbulance();
                break;
            case 6:
                // Not working yet
                a.getDetailsFromHistory();
                cout << "// Not working yet\n";
                break;
            case 7:
                Hospital::printAmbulances();
                break;
            case -1:
                exist = true;
                break;
            default:
                cout << "Invalid choice!\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    } while (!exist);
}
void appointmentsMenu(Appointment &a) {
    bool exist = false;
    do {
        int choice;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/APPOINTMENTS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Book an appointment\n";
        cout << "[02] : Get appointment details\n";
        cout << "[03] : Show all appointments\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                a.book();
                break;
            case 2:
                a.getDetails();
                break;
            case 3:
                Hospital::printAppointments();
                break;
            case -1:
                exist = true;
                break;
            default:
                cout << "Invalid choice!\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');// clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    } while (!exist);
}
void lastUsageDate(){
    fstream f;
    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/appointments.csv", ios::in);
    string dataInsideFile, date, header;
    // header => appointmentId,date(YYYYMMDD),doctorId,patientId,startTime(in 24-hr format)
    getline(f, header);
    getline(f, dataInsideFile);
    f.close();
    stringstream str(dataInsideFile);
    getline(str, date, ',');
    getline(str, date, ',');
    int dd, mm, yyyy;
    if (!date.empty())
        cout << "\n\n\nLast usage date (DD-MM-YYYY) : " << date.substr(6, 2) + "-" + date.substr(4, 2) + "-" + date.substr(0, 4) + "\n";
    cout << "\nPlease Enter Today's Date (DD-MM-YYYY) :\n\nEnter Day: ";
    cin >> dd;
    while (dd < 1 || dd > 31) {
        cout << "Invalid Day! Please enter a valid day: ";
        cin >> dd;
    }
    cout << "Enter Month: ";
    cin >> mm;
    while (mm < 1 || mm > 12) {
        cout << "Invalid Month! Please enter a valid month: ";
        cin >> mm;
    }
    cout << "Enter Year (YYYY): ";
    cin >> yyyy;
    // update yyymmdd inside global
    yyyymmdd = yyyy * 10000 + mm * 100 + dd;
    if ((date.empty())  || stoi(date) < yyyymmdd)
    {
        // remove all past appointments that booked
        f.open("./data/temp.csv", ios::out);
        f << header << "\n";
        f.close();
        remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/appointments.csv");
        rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/appointments.csv");
        // Update all appointmentbooked = zero in doctors columns
        fstream fout("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", ios::out);
        f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctors.csv", ios::in);
        getline(f, header);
        fout << header << endl;
        while (getline(f, dataInsideFile))
        {
            if (!dataInsideFile.empty())
                dataInsideFile[dataInsideFile.size() - 1] = '0';
            fout << dataInsideFile << endl;
        }
        f.close();
        fout.close();
        remove("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctors.csv");
        rename("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/temp.csv", "/media/elsaadany/Data/OOP/Example/hospital-management-system/data/doctors.csv");
    }
    else if (stoi(date) > yyyymmdd && !date.empty())
    {
        cout << "\nEntered date detected wrong!\nToday's date can't be older than the last usage date, which is : "
             << date.substr(6, 2) + "-" + date.substr(4, 2) + "-" + date.substr(0, 4) + "\n";
        return;
    }
}
int main() {
    lastUsageDate();
}
