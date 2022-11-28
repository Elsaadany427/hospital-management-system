//
// Created by elsaadany on 28/11/22.
//

#include "H07_07_PATIENT.h"

namespace patientStd{
    Patient::Patient() {
        m_id = -1;
        m_category = 2;
        m_hospitalized = false;
        alive = true;
        m_weight = 0;
        m_height = 0;
        m_catType = "patient";
    }
}