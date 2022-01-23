/*
Сшиватель дробных чисел

    Надо написать небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит пользователь
    надо составить новое число с плавающей точкой (типа double) и вывести это число обратно в консоль, для проверки.
    Целая часть - это та, часть числа, которая находится до точки (запятой), дробная - после.

*/

#include <iostream>

double Stapler(int integer_part, int fractional_part)
{
    double tmp = std::abs(fractional_part);
    while(tmp > 1)
        tmp /= 10;

    tmp = std::abs(integer_part) + std::abs(tmp);

    if(integer_part < 0 || fractional_part < 0)
        return -tmp;

    return tmp;
}

int main()
{
    int int_part, frac_part;
    std::cout << "Input integer part: ";
    std::cin >> int_part;
    std::cout << "Input fractional part: ";
    std::cin >> frac_part;

    std::cout << Stapler(int_part, frac_part) << std::endl;
    return 0;
}
