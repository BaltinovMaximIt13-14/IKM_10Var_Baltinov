#ifndef HEADER_H
#define HEADER_H

#include <string>
using namespace std;

// функция для деления большого числа на 16, используя строки
string delenie16(const std::string& number, int& ostatok);

// функция для перевода числа в шестнадцатеричную систему
string perevodToHex(const std::string& number);

// функция для ввода чисел с проверкой на корректность
string inputNumber();

#endif // HEADER_H
