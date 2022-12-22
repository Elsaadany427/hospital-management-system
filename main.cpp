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

void doctorMenu(Doctor d) {
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
                d.printDetails();
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
void nursesMenu(Nurse n){
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
                n.printDetails();
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
int main() {
    Doctor d1;
    d1.fillMap();
    doctorMenu(d1);
    d1.saveMap();
}
