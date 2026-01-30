#ifndef BATTERY_H
#define BATTERY_H

#include <string>

class Battery {
private:
    int capacity;
    double voltage;
    std::string materialType;

public:
    Battery();
    Battery(int cap, double volt, const std::string& type);
    ~Battery();

    bool setCapacity(int cap);
    bool setVoltage(double volt);
    void setMaterialType(const std::string& type);

    int getCapacity() const;
    double getVoltage() const;
    std::string getMaterialType() const;

    void input();
    void display() const;
};

void increaseCapacity(Battery& b, int value);
void changeVoltage(Battery& b, double value);

#endif
