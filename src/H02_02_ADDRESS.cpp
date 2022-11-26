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
    // Print Address
    void Address::printAddress() {
        std::cout << "Line 1: " << m_line1 << "\n";
        if (!m_line2.empty())
            std::cout << "                  "
                      << "Line 2: " << m_line2 << "\n";
        std::cout << "                  ";
        std::cout << "City: " << m_city << "\n";
        std::cout << "                  ";
        std::cout << "State: " << m_state << "\n";
        std::cout << "                  ";
        std::cout << "Pin Code: " << m_pinCode << "\n";
        std::cout << "                  ";
        std::cout << "Country: " << m_country << "\n";
        return;
    }
    // Encrypt Address
    std::string Address::encryptAddress() {
        std::stringstream sObj;
        sObj << m_line1 << "/" << m_line2 << "/" << m_city << "/" << m_state << "/" << m_pinCode << "/" << m_country;
        std::string encryptedAddress;
        getline(sObj, encryptedAddress);
        for (auto &i: encryptedAddress)
            if (i == ',')
                i = '~';
        return encryptedAddress;
    }
    void Address::decryptAddress(std::string t_encryptedAddress) {
        std::stringstream s(t_encryptedAddress);

        getline(s, m_line1, '/');
        for (auto &i: m_line1)
            if (i == '~')
                i = ',';

        getline(s, m_line2, '/');
        for (auto &i: m_line2)
            if (i == '~')
                i = ',';

        getline(s, m_city, '/');
        getline(s, m_state, '/');
        getline(s, m_pinCode, '/');
        getline(s, m_country, '/');
        return;
    }
}// namespace addressStd