#include "Battery.h"
#include <iostream>
#include <limits>

Battery::Battery() {
    capacity = 0;
    voltage = 0.0;
}

Battery::Battery(int cap, double volt) {
    capacity = cap;
    voltage = volt;
}

Battery::~Battery() {}

LithiumBattery::LithiumBattery() : Battery() {
    materialType = "Unknown";
}

void LithiumBattery::input() {
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

void LithiumBattery::display() const {
    std::cout << "Lithium battery -> ";
    std::cout << "Capacity: " << capacity << " mAh, ";
    std::cout << "Voltage: " << voltage << " V, ";
    std::cout << "Material: " << materialType << std::endl;
}

NiMHBattery::NiMHBattery() : Battery() {
    cycleCount = 0;
}

void NiMHBattery::input() {
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

    while (true) {
        std::cout << "Enter cycle count: ";
        if (std::cin >> cycleCount && cycleCount >= 0)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void NiMHBattery::display() const {
    std::cout << "NiMH battery -> ";
    std::cout << "Capacity: " << capacity << " mAh, ";
    std::cout << "Voltage: " << voltage << " V, ";
    std::cout << "Cycles: " << cycleCount << std::endl;
}
