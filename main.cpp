//
// Created by elsaadany on 25/11/22.
//
//وَمَا رَمَيْتَ إِذْ رَمَيْتَ وَلَٰكِنَّ اللَّهَ رَمَىٰ ۚ

#include<bits/stdc++.h>
#include "H01_01_PERSON.h"
#include "H03_03_DOCTOR.h"
//using namespace std;

#define pb push_back

typedef long long ll;
const int MAX_N = 1e5 + 12;
const int N = 2e5+ 5;
const int MOD = 1e9 + 7;


void solve(){
    doctorStd::Doctor d;
    d.fillMap();
    d.addPerson();
    d.saveMap();
    d.printDetails();
}
int main(){

    solve();

}
