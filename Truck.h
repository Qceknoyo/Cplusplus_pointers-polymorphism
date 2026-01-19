// Truck.h
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#pragma once
#include "Car.h"
#include <string>
#include <iostream>
#include "function.h"


class Truck : public Car {
protected:
    string type = "Truck";
    double cargoCapacity;
    int axleCount;

public:
    Truck() : Car(), cargoCapacity(0), axleCount(0) {}
    Truck(double w, double p, double s, const string& b, const string& m, int y, string& c, string& plate, double capacity, int axles)
        : Car(w, p, s, b, m, y, c, plate), cargoCapacity(capacity), axleCount(axles) {}

    void Set() override {
        cout << "Марка: ";
        brand = SetString();
        cout << "Модель: ";
        model = SetStringWithNumber();
        year = SetterYear();
        cout << "Цвет: ";
        color = SetString();
        plateNumber = InputNumber();
        weight = SetterWeight4Truck();
        power = SetterPower4Truck();
        max_speed = SetterMaxSpeed4Truck();
        cargoCapacity = SetterCargoCapacity();
        axleCount = SetterAxleCount();
    }

    double GetCargoCapacity() const { return cargoCapacity; }
    int GetAxleCount() const { return axleCount; }

    void SetCargoCapacity() {
        cargoCapacity = SetterCargoCapacity();
    }

    void SetAxleCount() {
        axleCount = SetterAxleCount();
    }

    void SetWeight() override {
        weight = SetterWeight4Truck();
    }

    void SetPower() override {
        power = SetterPower4Truck();
    }

    void SetMaxSpeed() override {
        max_speed = SetterMaxSpeed4Truck();
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
        cout << "Грузоподъемность: " << cargoCapacity << " кг\n"
            << "Количество осей: " << axleCount << "\n";
    }
};