// function.h
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "check.h"
#include "Transport.h"

using namespace std;

int getInt();
double getDouble();
string getString(const string& prompt);
string SetStringWithNumber();
string SetString();
string InputNumber();
double SetterPower4Car();
double SetterWeight4Car();
double SetterMaxSpeed4Car();
double SetterPower4SportCar();
double SetterWeight4SportCar();
int SetterAxleCount();
double SetterCargoCapacity();
double SetterMaxSpeed4SportCar();
double SetterAcceleration();
string SetterDriveType();
double SetterPower4Truck();
double SetterWeight4Truck();
double SetterMaxSpeed4Truck();
int SetterYear();
void FillTransportContainer(vector<unique_ptr<Transport>>& container);
void ShowTransportList(const vector<unique_ptr<Transport>>& container);
