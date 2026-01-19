// FileWork.cpp
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#include <string>
#include <vector>
#include <iostream>
#include "Transport.h"
#include <fstream>
#include <sstream>
#include "function.h"
#include "Car.h"
#include "Truck.h"
#include "SportCar.h"
#include <memory> // для уникальных указателей
using namespace std;

enum FileWorkMode { Overwrite = 1, Append, ChangeFile };
enum FileCreateMode { CreateNew = 1, DontCreate };


bool CheckFile(const string& path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}


void SaveInfo(const vector<unique_ptr<Transport>>& container) {
    if (container.empty()) {
        cout << "Нет данных для сохранения.\n";
        return;
    }

    string path;
    ofstream fout;
    int choice1 = 0, choice2 = 0;

    do {
        cout << "Введите путь к файлу: ";
        getline(cin, path);

        if (CheckFile(path)) {
            cout << "Файл найден.\n";
            do {
                cout << "Выберите режим записи:\n";
                cout << "1 - Перезаписать файл\n";
                cout << "2 - Дописать в конец файла\n";
                cout << "3 - Выбрать другой файл\n";
                choice1 = getInt();

                switch (choice1) {
                case Overwrite:
                    fout.open(path);
                    if (!fout.is_open()) {
                        cout << "Ошибка открытия файла для записи.\n";
                        choice1 = ChangeFile;
                    }
                    break;
                case Append:
                    fout.open(path, ios::app);
                    if (!fout.is_open()) {
                        cout << "Ошибка открытия файла для дозаписи.\n";
                        choice1 = ChangeFile;
                    }
                    fout << '\n';
                    break;
                case ChangeFile:
                    break;
                default:
                    cout << "Неверный выбор.\n";
                }
            } while (choice1 != Overwrite && choice1 != Append && choice1 != ChangeFile);
        }
        else {
            cout << "Файл не найден.\n";
            do {
                cout << "1 - Создать новый файл\n";
                cout << "2 - Выбрать другой файл\n";
                choice2 = getInt();

                switch (choice2) {
                case CreateNew:
                    fout.open(path);
                    if (CheckFile(path))
                        cout << "Файл создан.\n";
                    else
                        cout << "Не удалось создать файл.\n";
                    break;
                case DontCreate:
                    break;
                default:
                    cout << "Неверный выбор.\n";
                }
            } while (choice2 != CreateNew && choice2 != DontCreate);
        }
    } while (choice1 != Overwrite && choice1 != Append && choice2 != CreateNew);

    if (fout.is_open()) {
        for (size_t i = 0; i < container.size(); ++i) {
            Car* car = dynamic_cast<Car*>(container[i].get());
            if (!car) continue;

            if (dynamic_cast<SportsCar*>(container[i].get())) {
                fout << "SportsCar ";
            }
            else if (dynamic_cast<Truck*>(container[i].get())) {
                fout << "Truck ";
            }
            else {
                fout << "Car ";
            }

            fout << car->GetBrand() << ' '
                << car->GetModel() << ' '
                << car->GetYear() << ' '
                << car->GetColor() << ' '
                << car->GetPlateNumber() << ' '
                << car->GetWeight() << ' '
                << car->GetPower() << ' '
                << car->GetMaxSpeed() << ' ';

            if (auto sportCar = dynamic_cast<SportsCar*>(container[i].get())) {
                fout << sportCar->GetAcceleration() << ' '
                    << sportCar->GetDriveType() << ' ';
            }
            else if (auto truck = dynamic_cast<Truck*>(container[i].get())) {
                fout << truck->GetCargoCapacity() << ' '
                    << truck->GetAxleCount() << ' ';
            }

            if (i != container.size() - 1) {
                fout << '\n';
            }
        }
        cout << "Данные успешно сохранены.\n";
        fout.close();
    }
}

void InputInfo(vector<unique_ptr<Transport>>& container) {
    string path;
    cout << "Введите путь к файлу: ";
    getline(cin, path);

    ifstream fin(path);
    if (!fin.is_open()) {
        cout << "Ошибка открытия файла.\n";
        return;
    }

    int loadedCount = 0;
    string line;

    while (getline(fin, line)) {
        istringstream iss(line);
        string type;
        iss >> type;

        string brand, model, color, plateNumber;
        int year;
        double weight, power, maxSpeed;

        iss >> brand >> model >> year >> color >> plateNumber >> weight >> power >> maxSpeed;

        unique_ptr<Transport> vehicle;

        if (type == "Car") {
            vehicle = make_unique<Car>(weight, power, maxSpeed, brand, model, year, color, plateNumber);
        }
        else if (type == "SportsCar") {
            double acceleration;
            string driveType;
            iss >> acceleration >> driveType;
            vehicle = make_unique<SportsCar>(weight, power, maxSpeed, brand, model, year, color, plateNumber, acceleration, driveType);
        }
        else if (type == "Truck") {
            double cargoCapacity;
            int axleCount;
            iss >> cargoCapacity >> axleCount;
            vehicle = make_unique<Truck>(weight, power, maxSpeed, brand, model, year, color, plateNumber, cargoCapacity, axleCount);
        }

        if (vehicle) {
            container.push_back(move(vehicle));
            loadedCount++;
        }
    }

    fin.close();
    cout << "Загружено " << loadedCount << " транспортных средств.\n";
}