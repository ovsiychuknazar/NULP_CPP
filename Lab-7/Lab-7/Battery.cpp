#include "Battery.h"
#include <iostream>
#include <limits>

BatteryManager::BatteryManager() {}

BatteryManager::~BatteryManager() {}

bool BatteryManager::isValidCapacity(int cap) const {
    return cap > 0 && cap <= 20000;
}

bool BatteryManager::isValidVoltage(double volt) const {
    return volt > 0 && volt <= 100;
}

void BatteryManager::add() {
    BatteryData b;
    int cap;
    double volt;

    while (true) {
        std::cout << "Enter capacity (mAh): ";
        if (std::cin >> cap && isValidCapacity(cap))
            break;
        std::cout << "Invalid value. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        std::cout << "Enter voltage (V): ";
        if (std::cin >> volt && isValidVoltage(volt))
            break;
        std::cout << "Invalid value. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter material type: ";
    std::cin.ignore();
    std::getline(std::cin, b.materialType);

    b.capacity = cap;
    b.voltage = volt;

    batteries.push_back(b);
}

void BatteryManager::display() const {
    if (batteries.empty()) {
        std::cout << "No data available.\n";
        return;
    }

    for (size_t i = 0; i < batteries.size(); i++) {
        std::cout << "Capacity: " << batteries[i].capacity << " mAh, ";
        std::cout << "Voltage: " << batteries[i].voltage << " V, ";
        std::cout << "Material: " << batteries[i].materialType << std::endl;
    }
}

void BatteryManager::clear() {
    batteries.clear();
}
