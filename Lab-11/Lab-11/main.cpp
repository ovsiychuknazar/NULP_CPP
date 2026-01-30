#include <iostream>
#include "Battery.h"

int main() {
    Battery b1;
    Battery b2;

    std::cout << "Enter first battery:\n";
    b1.input();

    std::cout << "\nEnter second battery:\n";
    b2.input();

    std::cout << "\nBattery 1:\n";
    b1.display();

    std::cout << "Battery 2:\n";
    b2.display();

    std::cout << "\nComparison:\n";
    BatteryInspector::compareCapacity(b1, b2);

    std::cout << "\nInspector access demonstration:\n";
    BatteryInspector::showPrivateData(b1);

    return 0;
}
