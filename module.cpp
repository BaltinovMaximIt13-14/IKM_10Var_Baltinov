#include <iostream>
#include <string>
#include <algorithm>
#include "Header.h"

using namespace std;

// функция для деления большого числа на 16, используя строки
string delenie16(const string& number, int& ostatok) {
    string result;
    ostatok = 0;

    for (char digit : number) {
        int current = ostatok * 10 + (digit - '0'); // складываем остаток от предыдущего деления и новую цифру
        result += (current / 16) + '0'; // записываем целую часть деления
        ostatok = current % 16; // оставляем остаток
    }
    // убираем ведущие нули
    while (result.length() > 1 && result[0] == '0') { // если число равно 0, то ее не удаляем
        result.erase(0, 1);
    }

    return result;
}

// функция для перевода числа в шестнадцатеричную систему
string perevodToHex(const string& number) {
    string hexResult;
    string FullPart = number;
    int ostatok;

    while (FullPart != "0") {
        // делим на 16, находим остаток и целую часть 
        FullPart = delenie16(FullPart, ostatok);

        // определяем шестнадцатеричное представление остатка
        if (ostatok < 10) {
            hexResult += (ostatok + '0'); // для цифр 0-9
        }
        else {
            hexResult += (ostatok - 10 + 'A'); // для цифр 10-15 (A-F)
        }
    }

    // переворачиваем строку для получения корректного результата
    reverse(hexResult.begin(), hexResult.end());
    return hexResult; 
}

// функция для ввода чисел с проверкой на корректность
string inputNumber() {
    string number;
    while (true) {
        cout << "Введите многозначное число (без пробелов и недопустимых символов): ";
        cin >> number;

        // проверка на корректность: все символы должны быть цифрами
        bool proverka = true;
        for (char c : number) { // проходим по каждой цифре
            if (!isdigit(c)) {
                proverka = false;
                break;
            }
        }

        if (proverka) {
            return number; // возвращаем корректное число
        }
        else {
            cout << "Некорректный ввод. Пожалуйста, введите число, состоящее только из цифр." << endl;
        }
    }
}
