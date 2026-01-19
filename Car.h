// Car.h
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#pragma once
#include "Transport.h"
#include <string>
#include <iostream>
#include "function.h"

using namespace std;


class Car : public Transport {
protected:
    string type = "Car";
    string brand;
    string model;
    int year;
    string color;
    string plateNumber;

public:
    Car() : Transport(0, 0, 0), brand(""), model(""), year(0), color(""), plateNumber("") {}
    Car(double w, double p, double s, const string& b, const string& m, int y, string& c, string& plate)
        : Transport(w, p, s), brand(b), model(m), year(y), color(c), plateNumber(plate) {}

    void Set() override {
        cout << "Марка: ";
        brand = SetString();
        cout << "Модель: ";
        model = SetStringWithNumber();
        year = SetterYear();
        cout << "Цвет: ";
        color = SetString();
        plateNumber = InputNumber();
        weight = SetterWeight4Car();
        power = SetterPower4Car();
        max_speed = SetterMaxSpeed4Car();
    }

    string GetBrand() const { return brand; }
    string GetModel() const { return model; }
    int GetYear() const { return year; }
    string GetColor() const { return color; }
    string GetPlateNumber() const { return plateNumber; }
    string GetType() const { return type; }

    void SetBrand() {
        brand = SetString();
    }

    void SetModel() {
        model = SetString();
    }

    void SetYear() {
        year = SetterYear();
    }

    void SetColor() {
        color = SetString();
    }

    void SetPlateNumber() {
        plateNumber = InputNumber();
    }

    void SetWeight() override {
        weight = SetterWeight4Car();
    }

    void SetPower() override {
        power = SetterPower4Car();
    }

    void SetMaxSpeed() override {
        max_speed = SetterMaxSpeed4Car();
    }

    void ShowInfo()  override {
        cout << "Тип: " << type << "\n"
            << "Марка: " << brand << "\n"
            << "Модель: " << model << "\n"
            << "Год выпуска: " << year << "\n"
            << "Цвет: " << color << "\n"
            << "Вес: " << weight << " кг\n"
            << "Мощность: " << power << " л.с.\n"
            << "Макс. скорость: " << max_speed << " км/ч\n";
    }
};