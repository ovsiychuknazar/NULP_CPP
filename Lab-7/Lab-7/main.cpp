#include <iostream>
#include "Battery.h"

int main() {
    BatteryManager manager;
    int choice;

    do {
        std::cout << "\n1 - Add battery\n";
        std::cout << "2 - Display batteries\n";
        std::cout << "3 - Clear data\n";
        std::cout << "0 - Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manager.add();
                break;
            case 2:
                manager.display();
                break;
            case 3:
                manager.clear();
                break;
        }
    } while (choice != 0);

    return 0;
}
