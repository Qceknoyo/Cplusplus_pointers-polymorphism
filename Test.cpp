// Test.cpp
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#include <iostream>
#include <memory>
#include "Transport.h"
#include <vector>
#include "Car.h"
#include "Truck.h"
#include "SportCar.h"
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

void TestTransportSystem() {
    cout << "\n=== НАЧАЛО ТЕСТИРОВАНИЯ ===" << endl;

    vector<unique_ptr<Transport>> testContainer;

    string color1 = "Красный";
    string plate1 = "A123BC";
    testContainer.push_back(make_unique<Car>(1500, 120, 180, "Toyota", "Camry", 2015, color1, plate1));

    string color2 = "Желтый";
    string plate2 = "X999XX";
    testContainer.push_back(make_unique<SportsCar>(1200, 350, 300, "Ferrari", "F40", 1990, color2, plate2, 3.8, "Задний"));

    string color3 = "Синий";
    string plate3 = "M555MM";
    testContainer.push_back(make_unique<Truck>(5000, 450, 120, "MAN", "TGX", 2020, color3, plate3, 20000, 3));

    const string testFileName = "transport_test.txt";
    {
        ofstream fout(testFileName);
        if (!fout) {
            cerr << "Ошибка создания тестового файла!" << endl;
            return;
        }

        for (const auto& transport : testContainer) {
            if (auto car = dynamic_cast<Car*>(transport.get())) {
                fout << "Car ";
                fout << car->GetBrand() << ' ' << car->GetModel() << ' '
                    << car->GetYear() << ' ' << car->GetColor() << ' '
                    << car->GetPlateNumber() << ' ' << car->GetWeight() << ' '
                    << car->GetPower() << ' ' << car->GetMaxSpeed();

                if (auto sportCar = dynamic_cast<SportsCar*>(transport.get())) {
                    fout << ' ' << sportCar->GetAcceleration() << ' ' << sportCar->GetDriveType();
                }
                else if (auto truck = dynamic_cast<Truck*>(transport.get())) {
                    fout << ' ' << truck->GetCargoCapacity() << ' ' << truck->GetAxleCount();
                }
                fout << '\n';
            }
        }
        cout << "Тестовые данные сохранены в файл: " << testFileName << endl;
    }

    vector<unique_ptr<Transport>> loadedContainer;
    ifstream fin(testFileName);
    string line;

    while (getline(fin, line)) {
        istringstream iss(line);
        string type;
        iss >> type;

        string brand, model, color, plateNumber;
        int year;
        double weight, power, maxSpeed;

        iss >> brand >> model >> year >> color >> plateNumber >> weight >> power >> maxSpeed;

        if (type == "Car") {
            if (line.find("Ferrari") != string::npos) {
                double acceleration;
                string driveType;
                iss >> acceleration >> driveType;
                loadedContainer.push_back(
                    make_unique<SportsCar>(weight, power, maxSpeed, brand, model,
                        year, color, plateNumber, acceleration, driveType));
            }
            else if (line.find("MAN") != string::npos) {
                double cargoCapacity;
                int axleCount;
                iss >> cargoCapacity >> axleCount;
                loadedContainer.push_back(
                    make_unique<Truck>(weight, power, maxSpeed, brand, model,
                        year, color, plateNumber, cargoCapacity, axleCount));
            }
            else {
                loadedContainer.push_back(
                    make_unique<Car>(weight, power, maxSpeed, brand, model,
                        year, color, plateNumber));
            }
        }
    }
    cout << "Данные успешно загружены из файла" << endl;

    assert(testContainer.size() == loadedContainer.size() && "Ошибка: количество записанных и загруженных объектов не совпадает!");

    for (size_t i = 0; i < testContainer.size(); ++i) {
        auto original = dynamic_cast<Car*>(testContainer[i].get());
        auto loaded = dynamic_cast<Car*>(loadedContainer[i].get());

        assert(original->GetBrand() == loaded->GetBrand() && "Ошибка: бренды не совпадают!");
        assert(original->GetModel() == loaded->GetModel() && "Ошибка: модели не совпадают!");
        assert(original->GetYear() == loaded->GetYear() && "Ошибка: годы не совпадают!");

        if (auto origSport = dynamic_cast<SportsCar*>(testContainer[i].get())) {
            auto loadedSport = dynamic_cast<SportsCar*>(loadedContainer[i].get());
            assert(origSport->GetAcceleration() == loadedSport->GetAcceleration() && "Ошибка: разгон не совпадает!");
        }
        else if (auto origTruck = dynamic_cast<Truck*>(testContainer[i].get())) {
            auto loadedTruck = dynamic_cast<Truck*>(loadedContainer[i].get());
            assert(origTruck->GetCargoCapacity() == loadedTruck->GetCargoCapacity() && "Ошибка: грузоподъемность не совпадает!");
        }
    }
    
    cout << "=== ТЕСТИРОВАНИЕ УСПЕШНО ЗАВЕРШЕНО ===" << endl;
    cout << "\033[2J\033[1;1H" << endl;
    cout << "Все тесты пройдены! Система работает корректно!" << endl;
}