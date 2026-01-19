// function.cpp
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#include <string>
#include "check.h"
#include "Transport.h"
#include "SportCar.h"
#include "Truck.h"
#include "Car.h"
#include <iostream>
#include <vector>


using namespace std;

int getInt() {
    int x = 0;
    string input;

    while (true) {
        getline(cin, input);

        try {
            x = stoi(input);
            break;
        }
        catch (const invalid_argument&) {
            cout << "Ошибка ввода: неверный формат числа. Пожалуйста, повторите ввод.\n";
        }
        catch (const out_of_range&) {
            cout << "Ошибка ввода: число слишком большое или маленькое. Пожалуйста, повторите ввод.\n";
        }
    }
    return x;
}

double getDouble() {
    double x = 0;
    string input;

    while (true) {
        getline(cin, input);

        try {
            x = stod(input);
            break;
        }
        catch (const invalid_argument&) {
            cout << "Ошибка ввода: неверный формат числа. Пожалуйста, повторите ввод.\n";
        }
        catch (const out_of_range&) {
            cout << "Ошибка ввода: число слишком большое или маленькое. Пожалуйста, повторите ввод.\n";
        }
    }
    return x;
}

string getString(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!input.empty()) {
            return input;
        }
        cout << "Ошибка: ввод не может быть пустым.\n";
    }
}

string SetStringWithNumber() {
    string brand;
    getline(cin, brand);
    while (!(check_stringwnumber(brand))) {
        cout << "Ошибка: строка может содержать только буквы, цифры и пробелы. (Попробуйте ввести с большой буквы)" << '\n';
        cin >> brand;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
    return brand;
}

string SetString() {
    string brand;
    getline(cin, brand);
    while (!(check_string(brand))) {
        cout << "Ошибка: строка может содержать только буквы и пробелы. (Попробуйте ввести с большой буквы)" << '\n';
        cin >> brand;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
    return brand;
}

string InputNumber() {
    string number;
    cout << "Введите номер авто: ";
    cin >> number;
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    while (!(check_number(number))) {
        cout << "Вы ввели неподходящее значение, пожалуйста введите номер в формате \"T000TT\": ";
        cin >> number;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
    return number;
}

double SetterPower4Car() {
    double power;
    while (true) {
        cout << "Введите мощность для обычной легковой машины: " << endl;
        power = getDouble();
        if (CheckPower4Car(power)) {
            break;
        }
        cout << "Ошибка: легковой автомобиль должен имеет мощность мотора от 20 до 1500 л.с.\n";
    }
    return power;
}

double SetterWeight4Car() {
    double weight;
    while (true) {
        cout << "Введите вес для обычной легковой машины: " << endl;
        weight = getDouble();
        if (CheckWeight4Car(weight)) {
            break;
        }
        cout << "Ошибка: легковой автомобиль должен весить от 700 до 3500 кг\n";
    }
    return weight;
}

double SetterMaxSpeed4Car() {
    double max_speed;
    while (true) {
        cout << "Введите максимальную скорость для обычной легковой машины: " << endl;
        max_speed = getDouble();
        if (CheckMaxSpeed4Car(max_speed)) {
            break;
        }
        cout << "Ошибка: легковой автомобиль должен уметь разгоняться от 60 до 300км/ч\n";
    }
    return max_speed;
}

double SetterPower4SportCar() {
    double power;
    while (true) {
        cout << "Введите мощность двигателя для спортивной машины: " << endl;
        power = getDouble();
        if (CheckPower4SportCar(power)) {
            break;
        }
        cout << "Ошибка: спортивной автомобиль должен имеет мощность мотора от 20 до 1800 л.с.\n";
    }
    return power;
}

double SetterWeight4SportCar() {
    double weight;
    while (true) {
        cout << "Введите вес для спортивной машины: " << endl;
        weight = getDouble();
        if (CheckWeight4SportCar(weight)) {
            break;
        }
        cout << "Ошибка: спортивный автомобиль должен весить от 700 до 2500 кг\n";
    }
    return weight;
}

int SetterAxleCount() {
    int axleCount;
    while (true) {
        cout << "Введите количество осей грузоподъёмного автомобиля: " << endl;
        axleCount = getInt();
        if (CheckAxleCount(axleCount)) {
            break;
        }
        cout << "Ошибка: грузовой автомобиль должен иметь от 3 до 8 осей\n";
    }
    return axleCount;
}

double SetterCargoCapacity() {
    double cargoCapacity;
    while (true) {
        cout << "Введите максимальную грузоподъёмность автомобиля: " << endl;
        cargoCapacity = getDouble();
        if (CheckCargoCapacity(cargoCapacity)) {
            break;
        }
        cout << "Ошибка: грузовой автомобиль должен иметь грузоподъёмность от 50 до 760000 кг\n";
    }
    return cargoCapacity;
}

double SetterMaxSpeed4SportCar() {
    double max_speed;
    while (true) {
        cout << "Введите максимальную скорость для спортивной машины: " << endl;
        max_speed = getDouble();
        if (CheckMaxSpeed4SportCar(max_speed)) {
            break;
        }
        cout << "Ошибка: спортивный автомобиль должен уметь разгоняться от 60 до 500км/ч\n";
    }
    return max_speed;
}

double SetterAcceleration() {
    double acceleration0to100;
    while (true) {
        cout << "Введите время разгона спортивной машины от нуля до 100км/x: " << endl;
        acceleration0to100 = getDouble();
        if (CheckAcceleration(acceleration0to100)) {
            break;
        }
        cout << "Ошибка: спортивный автомобиль должен уметь разгоняться от 1.8 до 10 секунд\n";
    }
    return acceleration0to100;
}

string SetterDriveType() {
    string driveType;
    while (true) {
        cout << "Введите тип привода у машины (\"Передний\", \"Задний\", \"Полный\"): " << endl;
        driveType = SetString();
        if (CheckDriveType(driveType)) {
            break;
        }
        cout << "Ошибка: введите один из допустимых типов привода\n";
    }
    return driveType;
}

double SetterPower4Truck() {
    double power;
    while (true) {
        cout << "Введите мощность для грузовой машины: " << endl;
        power = getDouble();
        if (CheckPower4Truck(power)) {
            break;
        }
        cout << "Ошибка: грузовой автомобиль должен имеет мощность мотора от 100 до 2330 л.с.\n";
    }
    return power;
}

double SetterWeight4Truck() {
    double weight;
    while (true) {
        cout << "Введите вес для грузовой машины: " << endl;
        weight = getDouble();
        if (CheckWeight4Truck(weight)) {
            break;
        }
        cout << "Ошибка: грузовой автомобиль должен весить от 1500 до 810000 кг\n";
    }
    return weight;
}

double SetterMaxSpeed4Truck() {
    double max_speed;
    while (true) {
        cout << "Введите максимальную скорость для грузовой машины: " << endl;
        max_speed = getDouble();
        if (CheckMaxSpeed4Truck(max_speed)) {
            break;
        }
        cout << "Ошибка: легковой автомобиль должен уметь разгоняться от 60 до 160 км/ч\n";
    }
    return max_speed;
}

int SetterYear() {
    int year;
    while (true) {
        cout << "Введите год выпуска (гггг): " << endl;
        year = getInt();
        if (CheckYear(year))
            break;
        cout << "Ошибка: год должен содержать быть реалистичным.\n";
    }
    return year;
}

void FillTransportContainer(vector<unique_ptr<Transport>>& container) {
    int choice;
    while (true) {
        cout << "\nВыберите тип транспортного средства:\n";
        cout << "1 - Обычный автомобиль\n2 - Спортивный автомобиль\n3 - Грузовой\n0 - Выход\n";
        choice = getInt();

        if (choice == 0) break;

        unique_ptr<Transport> vehicle;

        switch (choice) {
        case 1:
            vehicle = make_unique<Car>();
            break;
        case 2:
            vehicle = make_unique<SportsCar>();
            break;
        case 3:
            vehicle = make_unique<Truck>();
            break;
        default:
            cout << "Неверный выбор!\n";
            continue;
        }

        vehicle->Set();
        container.push_back(move(vehicle));
        cout << "Транспорт добавлен!\n";
    }
}

void ShowTransportList(const vector<unique_ptr<Transport>>& container) {
    if (container.empty()) {
        cout << "Список пуст.\n";
        return;
    }

    cout << "\nСписок транспортных средств:\n";
    cout << "---------------------------\n";
    for (size_t i = 0; i < container.size(); ++i) {
        cout << "Транспорт #" << i + 1 << ":\n";
        container[i]->ShowInfo();
        cout << "---------------------------\n";
    }
}