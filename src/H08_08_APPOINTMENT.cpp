//
// Created by elsaadany on 09/12/22.
//

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
