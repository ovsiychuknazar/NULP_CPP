#include <iostream>
#include "Battery.h"

int main() {
    Battery battery;
    int addCapacity;
    double newVoltage;

    battery.input();

    std::cout << "\nInitial battery data:\n";
    battery.display();

    std::cout << "\nEnter value to increase capacity: ";
    std::cin >> addCapacity;
    increaseCapacity(battery, addCapacity);

    std::cout << "\nAfter capacity change:\n";
    battery.display();

    std::cout << "\nEnter new voltage value: ";
    std::cin >> newVoltage;
    changeVoltage(battery, newVoltage);

    std::cout << "\nAfter voltage change:\n";
    battery.display();

    return 0;
}
