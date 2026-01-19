// Main.cpp
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#include <windows.h>
#include <locale>
#include <vector>
#include "Transport.h"
#include "Menu.h"

using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<unique_ptr<Transport>> transportContainer;


    Menu(transportContainer);
}