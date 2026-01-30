#ifndef BATTERY_H
#define BATTERY_H

#include <string>

class BatteryInspector;

class Battery {
private:
    int capacity;
    double voltage;
    std::string materialType;

public:
    Battery();
    Battery(int cap, double volt, const std::string& type);
    ~Battery();

    void input();
    void display() const;

    friend class BatteryInspector;
};

class BatteryInspector {
public:
    static void compareCapacity(const Battery& b1, const Battery& b2);
    static void showPrivateData(const Battery& b);
};

#endif
