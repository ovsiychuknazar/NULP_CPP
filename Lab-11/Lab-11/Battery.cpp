#include "Battery.h"
#include <iostream>
#include <limits>

Battery::Battery() {
    capacity = 0;
    voltage = 0.0;
    materialType = "Unknown";
}

Battery::Battery(int cap, double volt, const std::string& type) {
    capacity = cap;
    voltage = volt;
    materialType = type;
}

Battery::~Battery() {}

void Battery::input() {
    while (true) {
        std::cout << "Enter capacity (mAh): ";
        if (std::cin >> capacity && capacity > 0)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        std::cout << "Enter voltage (V): ";
        if (std::cin >> voltage && voltage > 0)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter material type: ";
    std::cin.ignore();
    std::getline(std::cin, materialType);
}

void Battery::display() const {
    std::cout << "Capacity: " << capacity << " mAh, ";
    std::cout << "Voltage: " << voltage << " V, ";
    std::cout << "Material: " << materialType << std::endl;
}

void BatteryInspector::compareCapacity(const Battery& b1, const Battery& b2) {
    if (b1.capacity > b2.capacity)
        std::cout << "First battery has larger capacity\n";
    else if (b1.capacity < b2.capacity)
        std::cout << "Second battery has larger capacity\n";
    else
        std::cout << "Batteries have equal capacity\n";
}

void BatteryInspector::showPrivateData(const Battery& b) {
    std::cout << "Inspector access -> ";
    std::cout << b.capacity << " mAh, ";
    std::cout << b.voltage << " V, ";
    std::cout << b.materialType << std::endl;
}
