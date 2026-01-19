// Menu.cpp 
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#include <iostream>
#include "function.h"
#include "filework.h"
#include "test.h"

using namespace std;
enum MENU { input = 1, InputFile, Save, Clear, Show, StartTest, Quit };

void MainInfo() {
    cout << "Здравствуйте" << endl;
    cout << "Программу написал Соколов Артём Алексеевич" << endl;
    cout << "Наследование. Средства передвижения" << endl
        << "Реализовать заполнение контейнера указателями на базовый класс с возможностью получения списка внесенных объектов:" << endl;
}

void ChoiceInfo() {
    cout << "1 - Создать объект вручную" << endl
        << "2 - Ввести объекты из файла" << endl;
    cout << "3 - Сохранение введённых данных в файл " << endl
        << "4 - Удалить введённые в программу данные и создать новый вектор" << endl;
    cout << "5 - Показать введённые данные" << endl;
    cout << "6 - Запустить тесты функций" << endl;
    cout << "7 - Выход из программы" << endl;
}

int InputChoiceMenu() {
    int choice = 0;
    cout << "Выберите нужное действие:" << endl;
    ChoiceInfo();
    choice = getInt();
    return choice;
}

void Menu(vector<unique_ptr<Transport>>& transportContainer) {
    TestTransportSystem();

    int choice = 0;
    MainInfo();
    choice = InputChoiceMenu();
    do {
        switch (choice) {
        case (input):
            FillTransportContainer(transportContainer);
            choice = InputChoiceMenu();
            break;
        case(InputFile):
            InputInfo(transportContainer);
            choice = InputChoiceMenu();
            break;
        case(Save):
            SaveInfo(transportContainer);
            choice = InputChoiceMenu();
            break;
        case(Clear):
            transportContainer.clear();
            cout << "Машины в программе удалены" << endl;
            choice = InputChoiceMenu();
            break;
        case(Show):
            ShowTransportList(transportContainer);
            choice = InputChoiceMenu();
            break;
        case(StartTest):
            TestTransportSystem();
            choice = InputChoiceMenu();
            break;
        case(Quit):
            break;
        default:
            cout << "Такого варианта нет, пожалуйста выберите из представленных" << endl;
            ChoiceInfo();
            choice = getInt();
        }
    } while (choice != Quit);
    cout << "Спасибо, что используете нашу программу" << endl;
}

