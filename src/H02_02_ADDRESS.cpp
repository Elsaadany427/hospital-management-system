//
// Created by elsaadany on 25/11/22.
//

#include "H02_02_ADDRESS.h"
namespace addressStd {
    // Initialized Constructor
    Address::Address() {
        m_line1 = "";
        m_line2 = "";
        m_city = "";
        m_state = "";
        m_country = "";
        m_pinCode = "";
    }
    // Taking Address from user
    void Address::takeAddress() {
        std::cout << "\nEnter address:\n";
        std::cout << "\nLine 1:\n";
        getline(std::cin >> std::ws, m_line1);
        std::cout << "\nLine 2 (optional):\n";
        getline(std::cin, m_line2);
        std::cout << "\nCity:\n";
        getline(std::cin >> std::ws, m_city);
        std::cout << "\nState:\n";
        getline(std::cin >> std::ws, m_state);
        std::cout << "\nPin Code:\n";
        getline(std::cin >> std::ws, m_pinCode);
        std::cout << "\nCountry:\n";
        getline(std::cin >> std::ws, m_country);
        return;
    }
}