// filework.h
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#pragma once
#include "Transport.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

bool CheckFile(const string& path);
void SaveInfo(const vector<unique_ptr<Transport>>& container);
void InputInfo(vector<unique_ptr<Transport>>& container);