#ifndef BATTERY_H
#define BATTERY_H

#include <string>

class Battery {
protected:
    int capacity;
    double voltage;

public:
    Battery();
    Battery(int cap, double volt);
    virtual ~Battery();

    virtual void input() = 0;
    virtual void display() const = 0;
};

class LithiumBattery : public Battery {
private:
    std::string materialType;

public:
    LithiumBattery();
    void input() override;
    void display() const override;
};

class NiMHBattery : public Battery {
private:
    int cycleCount;

public:
    NiMHBattery();
    void input() override;
    void display() const override;
};

#endif
