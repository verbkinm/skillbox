/*
Калькулятор
    Требуется создать небольшую программу для вычисления простых действий с числами.
    При запуске программа ожидает пользовательского ввода во временную переменную строку.
    После ввода строки, она распарсивается на отдельные члены. Строка записывается в форме “<число-1><действие><число-2>”
    (без пробелов). Оба числа - это значения с плавающей точкой, повышенной точности (double).
    Действие может быть одним из: +, -, /, *. Результат действия выводится в стандартный вывод cout.
*/

#include <iostream>
#include <string>
#include <sstream>

double calculate(const std::string &str)
{
    std::stringstream stream(str);

    double first_digit, second_digit, result = 0.0;
    char operation;

    stream >> first_digit >> operation >> second_digit;

    switch (operation)
    {
    case '+':
        result = first_digit + second_digit;
        break;
    case '-':
        result = first_digit - second_digit;
        break;
    case '*':
        result = first_digit * second_digit;
        break;
    case '/':
        result = first_digit / second_digit;
        break;
    }

    return result;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::cout << calculate(str) << std::endl;

    return 0;
}
