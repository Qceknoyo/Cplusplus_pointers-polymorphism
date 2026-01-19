// Transport.h 
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#pragma once

class Transport {
protected:
    double weight;
    double power;
    double max_speed;

public:
    Transport(double w, double p, double s) : weight(w), power(p), max_speed(s) {}
    virtual ~Transport() = default;
    virtual void Set() = 0;
    virtual void ShowInfo() = 0;

    double GetWeight() const { return weight; }
    double GetPower() const { return power; }
    double GetMaxSpeed() const { return max_speed; }

    virtual void SetWeight() = 0;
    virtual void SetPower() = 0;
    virtual void SetMaxSpeed() = 0;
};

