//
// Created by elsaadany on 25/11/22.
//
//وَمَا رَمَيْتَ إِذْ رَمَيْتَ وَلَٰكِنَّ اللَّهَ رَمَىٰ ۚ

#include "H03_03_DOCTOR.h"
#include "H04_04_HOSPITAL.h"
#include "H08_08_APPOINTMENT.h"
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
};
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
};
int main() {
    Doctor d1;
    //    Nurse n1;
    //    Driver dr;
    Patient p;
    //    Ambulance a;
    Appointment a;
    d1.fillMap();
    //    n1.fillMap();
    //    dr.fillMap();
    p.fillMap();
    //    Ambulance::fillMap();
    Appointment::fillMap();
    //    doctorMenu(d1);
    //    nursesMenu(n1);
    //    driversMenu(dr);
    //    patientsMenu(p);
    //    ambulancesMenu(a);
    appointmentsMenu(a);
    //    d1.saveMap();
    //    n1.saveMap();
    //    dr.saveMap();
    //    p.saveMap();
    //    Ambulance::saveMap();
    Appointment::saveMap();
    d1.saveMap();
    p.saveMap();
}
