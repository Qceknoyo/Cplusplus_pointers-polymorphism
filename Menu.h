// Menu.h
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#pragma once
#include <vector>
#include "memory"
#include "Transport.h"
using namespace std;

void MainInfo();
void ChoiceInfo();
int InputChoiceMenu();
void Menu(vector<unique_ptr<Transport>>& transportContainer);
