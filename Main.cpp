#include <iostream>
#include <string>
#include <algorithm>
#include "Header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    string number = inputNumber(); // ввод числа с проверкой

    string hexNumber = perevodToHex(number); // переводим в шестнадцатеричное
    cout << "Число "<<number<<" в шестнадцатеричной системе: " << hexNumber << endl;

    return 0;
}
