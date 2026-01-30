#ifndef BATTERY_H
#define BATTERY_H

#include <vector>
#include <string>

struct BatteryData {
    int capacity;
    double voltage;
    std::string materialType;
};

class BatteryManager {
private:
    std::vector<BatteryData> batteries;

    bool isValidCapacity(int cap) const;
    bool isValidVoltage(double volt) const;

public:
    BatteryManager();
    ~BatteryManager();

    void add();
    void display() const;
    void clear();
};

#endif
