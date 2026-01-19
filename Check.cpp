// Check.cpp
// Использование языка С++ для создания простейших классов
// Наследование
// Соколов Артём Алексеевич. 2025 год
#include <regex>
#include <iostream>
#include <string>

using namespace std;
enum symbols { other_symbol, upper_letter, lower_letter, numeral };

int check_symbol(char symbol) {
    if (isdigit(static_cast<unsigned char>(symbol)))
        return numeral;
    else if (isupper(static_cast<unsigned char>(symbol)) || (symbol >= 'А' && symbol <= 'Я') || (symbol >= 'A' && symbol <= 'Z') || symbol == 'Ё')
        return upper_letter;
    else if (islower(static_cast<unsigned char>(symbol)) || (symbol >= 'а' && symbol <= 'я') || (symbol >= 'a' && symbol <= 'z') || symbol == 'ё' || symbol == '-' || symbol == ' ')
        return lower_letter;
    else
        return other_symbol;
}

bool check_number(string number) {
    if (number.length() != 6) return false;
    if (check_symbol(number[0]) == upper_letter && check_symbol(number[1]) == numeral &&
        check_symbol(number[2]) == numeral && check_symbol(number[3]) == numeral &&
        check_symbol(number[4]) == upper_letter && check_symbol(number[5]) == upper_letter)
        return true;
    else
        return false;
}

bool check_string(string word) {
    if (!(check_symbol(word[0]) == upper_letter))
        return false;
    for (size_t i = 1; i < word.length(); ++i) {
        if (!((word[i - 1] == ' ' || word[i - 1] == '-') && check_symbol(word[i]) == upper_letter)) {
            if (check_symbol(word[i]) != lower_letter && check_symbol(word[i]) != upper_letter) {
                return false;
            }
        }
    }
    return true;
}

int check_symbolwnumber(char symbol) {
    if (isdigit(static_cast<unsigned char>(symbol)))
        return numeral;
    else if (isupper(static_cast<unsigned char>(symbol)) || (symbol >= 'А' && symbol <= 'Я') || (symbol >= 'A' && symbol <= 'Z') || symbol == 'Ё')
        return upper_letter;
    else if (islower(static_cast<unsigned char>(symbol)) || (symbol >= 'а' && symbol <= 'я') || (symbol >= 'a' && symbol <= 'z') || symbol == 'ё' || symbol == '-' || symbol == ' ')
        return lower_letter;
    else
        return other_symbol;
}

bool check_stringwnumber(string word) {
    if (!(check_symbolwnumber(word[0]) == upper_letter))
        return false;

    for (size_t i = 1; i < word.length(); ++i) {
        if ((word[i - 1] == ' ' || word[i - 1] == '-') && check_symbolwnumber(word[i]) == upper_letter) {
            continue;
        }
        if ((check_symbolwnumber(word[i]) != lower_letter && check_symbolwnumber(word[i]) != upper_letter) && check_symbolwnumber(word[i]) != numeral) {
            return false;
        }
    }
    return true;
}


bool CheckYear(int year) {
    if (1884 < year && year <= 2025)
        return true;
    else
        return false;
}

bool CheckWeight4Car(double weight) {
    if (700 < weight && weight < 3500) return true;
    else return false;
}

bool CheckPower4Car(double power) {
    if (20 < power && power < 1500) return true;
    else return false;
}

bool CheckMaxSpeed4Car(double max_speed) {
    if (60 < max_speed && max_speed < 300) return true;
    else return false;
}

bool CheckWeight4SportCar(double weight) {
    if (700 <= weight && weight <= 2500) return true;
    else return false;
}

bool CheckPower4SportCar(double power) {
    if (20 <= power && power <= 1801) return true;
    else return false;
}

bool CheckAxleCount(int axleCount) {
    if (2 <= axleCount && axleCount <= 9) return true;
    else return false;
}

bool CheckCargoCapacity(double cargoCapacity) {
    if (60 < cargoCapacity && cargoCapacity < 760001) return true;
    else return false;
}

bool CheckMaxSpeed4SportCar(double max_speed) {
    if (60 < max_speed && max_speed < 501) return true;
    else return false;
}

bool CheckAcceleration(double acceleration0to100) {
    if (1 < acceleration0to100 && acceleration0to100 < 11) return true;
    else return false;
}

bool CheckDriveType(string driveType) {
    if ((driveType == "Задний") || (driveType == "Передний") || (driveType == "Полный"))
        return true;
    else return false;
}

bool CheckWeight4Truck(double weight) {
    if (1499 < weight && weight < 811000) return true;
    else return false;
}

bool CheckPower4Truck(double power) {
    if (100 < power && power < 2331) return true;
    else return false;
}

bool CheckMaxSpeed4Truck(double max_speed) {
    if (60 < max_speed && max_speed < 160) return true;
    else return false;
}