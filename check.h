// check.h
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#pragma once
#include <string>
using namespace std;

int check_symbol(char symbol);
bool check_number(string number);
bool check_string(string word);
int check_symbolwnumber(char symbol);
bool check_stringwnumber(string word);
bool CheckYear(int year);
bool CheckWeight4Car(double weight);
bool CheckPower4Car(double power);
bool CheckMaxSpeed4Car(double max_speed);
bool CheckWeight4SportCar(double weight);
bool CheckPower4SportCar(double power);
bool CheckAxleCount(int axleCount);
bool CheckCargoCapacity(double cargoCapacity);
bool CheckMaxSpeed4SportCar(double max_speed);
bool CheckAcceleration(double acceleration0to100);
bool CheckDriveType(string driveType);
bool CheckWeight4Truck(double weight);
bool CheckPower4Truck(double power);
bool CheckMaxSpeed4Truck(double max_speed);