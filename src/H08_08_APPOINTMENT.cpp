//
// Created by elsaadany on 09/12/22.
//

#include "H00_00_GLOBAL.h"
#include "H04_04_HOSPITAL.h"
#include "H08_08_APPOINTMENT.h"

Appointment::Appointment() {
    m_id = -1;
    m_patient.m_id = -1;
    m_doctor.m_id = -1;
}
Appointment::~Appointment() {
    m_id = -1;
    m_patient.m_id = -1;
    m_doctor.m_id = -1;
}
void Appointment::fillMap() {
    std::fstream f;
    f.open("/media/elsaadany/Data/OOP/Example/hospital-management-system/data/appointments.csv", std::ios::in);
    std::string copyDataFromFileAppointment;
    //skipping the first row containing column headers;
    getline(f >> std::ws, copyDataFromFileAppointment );
    //analyzing each entry afterwards;
    while (getline(f >> std::ws, copyDataFromFileAppointment)) {
        Appointment a;
        //creating a string stream object to read from string 'temp';
        std::stringstream s(copyDataFromFileAppointment);
        std::string appointmentId, date, doctorId, patientId, startTime;
        //reading from the string stream object 's';
        getline(s, appointmentId, ',');
        getline(s, date, ',');
        getline(s, doctorId, ',');
        getline(s, patientId, ',');
        getline(s, startTime, ',');
        a.m_id = strToNum(doctorId);
        a.m_doctor = Hospital::m_doctorsList[0];
        a.m_patient = Hospital::m_patientsList[0];
        a.m_hours = strToNum(startTime);
        Hospital::m_appointmentList[a.m_id] = a;
    }
    f.close();
}