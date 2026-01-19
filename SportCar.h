// SportCar.h
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#pragma once

#include "Car.h"
#include <string>
#include <iostream>
#include "function.h"

using namespace std;

class SportsCar : public Car {
protected:
    string type = "Sportcar";
    double acceleration0to100;
    string driveType;

public:
    SportsCar() : Car(), acceleration0to100(0), driveType("") {}
    SportsCar(double w, double p, double s, const string& b, const string& m, int y, string& c, string& plate, double accel, const string& drive)
        : Car(w, p, s, b, m, y, c, plate), acceleration0to100(accel), driveType(drive) {}


    void Set() override {
        cout << "Марка: ";
        brand = SetString();
        cout << "Модель: ";
        model = SetStringWithNumber();
        year = SetterYear();
        cout << "Цвет: ";
        color = SetString();
        plateNumber = InputNumber();
        weight = SetterWeight4SportCar();
        power = SetterPower4SportCar();
        max_speed = SetterMaxSpeed4SportCar();
        acceleration0to100 = SetterAcceleration();
        driveType = SetterDriveType();
    }

    string GetDriveType() const { return driveType; }
    double GetAcceleration() const { return acceleration0to100; }

    void SetWeight() override {
        weight = SetterWeight4SportCar();
    }

    void SetPower() override {
        power = SetterPower4SportCar();
    }

    void SetMaxSpeed() override {
        max_speed = SetterMaxSpeed4SportCar();
    }

    void SetAcceleration() {
        acceleration0to100 = SetterAcceleration();
    }

    void SetDriveType() {
        driveType = SetterDriveType();
    }

    void ShowInfo() override {
        cout << "Тип: " << type << "\n"
            << "Марка: " << brand << "\n"
            << "Модель: " << model << "\n"
            << "Год выпуска: " << year << "\n"
            << "Цвет: " << color << "\n"
            << "Вес: " << weight << " кг\n"
            << "Мощность: " << power << " л.с.\n"
            << "Макс. скорость: " << max_speed << " км/ч\n";
        cout << "Разгон 0-100: " << acceleration0to100 << " сек\n"
            << "Привод: " << driveType << "\n";
    }
};