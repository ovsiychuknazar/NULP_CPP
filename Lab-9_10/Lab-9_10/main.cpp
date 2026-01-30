#include <iostream>
#include <vector>
#include "Battery.h"

int main() {
    std::vector<Battery*> batteries;
    int n;
    int type;

    std::cout << "Enter number of batteries: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Choose type (1 - Lithium, 2 - NiMH): ";
        std::cin >> type;

        Battery* b = nullptr;

        if (type == 1)
            b = new LithiumBattery();
        else
            b = new NiMHBattery();

        b->input();
        batteries.push_back(b);
    }

    std::cout << "\nBattery list:\n";

    for (const auto& b : batteries) {
        b->display();
    }

    for (auto b : batteries) {
        delete b;
    }

    batteries.clear();

    return 0;
}
