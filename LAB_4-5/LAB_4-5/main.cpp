#include <iostream>
#include <string>
#include <vector>
#include <limits>

class Battery {
private:
    int capacity;
    double voltage;
    std::string materialType;

public:
    Battery() {
        capacity = 0;
        voltage = 0.0;
        materialType = "Unknown";
    }

    Battery(int cap, double volt, const std::string& type) {
        setCapacity(cap);
        setVoltage(volt);
        setMaterialType(type);
    }

    ~Battery() {}

    void setCapacity(int cap) {
        if (cap > 0)
            capacity = cap;
        else
            capacity = 0;
    }

    void setVoltage(double volt) {
        if (volt > 0)
            voltage = volt;
        else
            voltage = 0.0;
    }

    void setMaterialType(const std::string& type) {
        if (!type.empty())
            materialType = type;
        else
            materialType = "Unknown";
    }

    int getCapacity() const {
        return capacity;
    }

    void input() {
        int cap;
        double volt;
        std::string type;

        while (true) {
            std::cout << "Enter capacity (mAh): ";
            if (std::cin >> cap && cap > 0)
                break;
            std::cout << "Invalid value. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        while (true) {
            std::cout << "Enter voltage (V): ";
            if (std::cin >> volt && volt > 0)
                break;
            std::cout << "Invalid value. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter material type: ";
        std::cin.ignore();
        std::getline(std::cin, type);

        setCapacity(cap);
        setVoltage(volt);
        setMaterialType(type);
    }

    void display() const {
        std::cout << "Capacity: " << capacity << " mAh, ";
        std::cout << "Voltage: " << voltage << " V, ";
        std::cout << "Material: " << materialType << std::endl;
    }
};

int main() {
    int n;
    std::vector<Battery> batteries;

    while (true) {
        std::cout << "Enter number of batteries: ";
        if (std::cin >> n && n > 0)
            break;
        std::cout << "Invalid value. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < n; i++) {
        Battery b;
        b.input();
        batteries.push_back(b);
    }

    int minCapacity;
    while (true) {
        std::cout << "Enter minimum capacity for filtering: ";
        if (std::cin >> minCapacity && minCapacity > 0)
            break;
        std::cout << "Invalid value. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool found = false;

    for (const auto& b : batteries) {
        if (b.getCapacity() >= minCapacity) {
            b.display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No batteries found with given criteria." << std::endl;
    }

    return 0;
}
