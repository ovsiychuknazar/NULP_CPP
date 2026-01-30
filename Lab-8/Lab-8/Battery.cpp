#include "Battery.h"
#include <iostream>
#include <limits>

Battery::Battery() {
    capacity = 0;
    voltage = 0.0;
    materialType = "Unknown";
}

Battery::Battery(int cap, double volt, const std::string& type) {
    setCapacity(cap);
    setVoltage(volt);
    setMaterialType(type);
}

Battery::~Battery() {}

bool Battery::setCapacity(int cap) {
    if (cap > 0) {
        capacity = cap;
        return true;
    }
    return false;
}

bool Battery::setVoltage(double volt) {
    if (volt > 0) {
        voltage = volt;
        return true;
    }
    return false;
}

void Battery::setMaterialType(const std::string& type) {
    materialType = type;
}

int Battery::getCapacity() const {
    return capacity;
}

double Battery::getVoltage() const {
    return voltage;
}

std::string Battery::getMaterialType() const {
    return materialType;
}

void Battery::input() {
    int cap;
    double volt;
    std::string type;

    while (true) {
        std::cout << "Enter capacity (mAh): ";
        if (std::cin >> cap && setCapacity(cap))
            break;
        std::cout << "Invalid value\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    while (true) {
        std::cout << "Enter voltage (V): ";
        if (std::cin >> volt && setVoltage(volt))
            break;
        std::cout << "Invalid value\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter material type: ";
    std::cin.ignore();
    std::getline(std::cin, type);

    setMaterialType(type);
}

void Battery::display() const {
    std::cout << "Capacity: " << capacity << " mAh, ";
    std::cout << "Voltage: " << voltage << " V, ";
    std::cout << "Material: " << materialType << std::endl;
}

void increaseCapacity(Battery& b, int value) {
    if (value > 0)
        b.setCapacity(b.getCapacity() + value);
}

void changeVoltage(Battery& b, double value) {
    if (value > 0)
        b.setVoltage(value);
}
