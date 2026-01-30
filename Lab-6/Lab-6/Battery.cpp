#include "Battery.h"
#include <iostream>
#include <limits>

BatteryManager::BatteryManager() {
    count = 0;
}

BatteryManager::~BatteryManager() {}

bool BatteryManager::isValidCapacity(int cap) const {
    return cap > 0 && cap <= 20000;
}

bool BatteryManager::isValidVoltage(double volt) const {
    return volt > 0 && volt <= 100;
}

void BatteryManager::input() {
    int n;

    while (true) {
        std::cout << "Enter number of batteries (max " << SIZE << "): ";
        if (std::cin >> n && n > 0 && n <= SIZE)
            break;
        std::cout << "Invalid value. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < n; i++) {
        int cap;
        double volt;
        std::string type;

        while (true) {
            std::cout << "Enter capacity (mAh): ";
            if (std::cin >> cap && isValidCapacity(cap))
                break;
            std::cout << "Incorrect capacity value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        while (true) {
            std::cout << "Enter voltage (V): ";
            if (std::cin >> volt && isValidVoltage(volt))
                break;
            std::cout << "Incorrect voltage value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter material type: ";
        std::cin.ignore();
        std::getline(std::cin, type);

        batteries[i].capacity = cap;
        batteries[i].voltage = volt;
        batteries[i].materialType = type;
        count++;
    }
}

void BatteryManager::display() const {
    if (count == 0) {
        std::cout << "No data available.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        std::cout << "Capacity: " << batteries[i].capacity << " mAh, ";
        std::cout << "Voltage: " << batteries[i].voltage << " V, ";
        std::cout << "Material: " << batteries[i].materialType << std::endl;
    }
}
