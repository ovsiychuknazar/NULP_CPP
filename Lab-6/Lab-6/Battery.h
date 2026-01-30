#ifndef BATTERY_H
#define BATTERY_H

#include <array>
#include <string>

constexpr int SIZE = 5;

struct BatteryData {
    int capacity;
    double voltage;
    std::string materialType;
};

class BatteryManager {
private:
    std::array<BatteryData, SIZE> batteries;
    int count;

    bool isValidCapacity(int cap) const;
    bool isValidVoltage(double volt) const;

public:
    BatteryManager();
    ~BatteryManager();

    void input();
    void display() const;
};

#endif
