/*
Спидометр

    Надо реализовать цифровой спидометр автомобиля. Сама модель автомобиля, которую
    нужно будет воссоздать весьма проста. Начальная скорость - 0 км/ч. Пользователь
    вводит в стандартный ввод разницу (дельту) в скорости и результирующая скорость
    показывается на спидометре в стандартный вывод. Так происходит до той поры, пока
    машина снова не остановится, т.е. пока скорость не станет меньше или равна нулю
    (сравнение должно происходить с дельтой в 0.01). Диапазон возможных значений
    скорости машины от 0 до 150 км/ч. Сам показатель спидометра, вместе с единицами
    измерения, требуется записывать в отдельную строку-буфер, которая потом и будет
    показываться на экране. Точность отображения скорость до 0.1 км/ч.
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>

double discardN(double digit, uint8_t n)
{
    n = pow(10, n);
    digit = (digit * n);
    digit = static_cast<int>(digit);
    digit /= n;

    return digit;
}

int main()
{
    double speed = 0.0;
    double delta;

    do
    {
        std::string str;
        std::stringstream stream(str);

        stream << "Current speed: " << std::setprecision(1) << std::fixed << discardN(speed, 1);
        str = stream.str();

        std::cout << str << std::endl;
        std::cout << "Input delta: ";
        std::cin >> delta;

        speed += discardN(delta, 2);

        if(speed > 150.0)
            speed = 150.0;
    }
    while (speed > 0);


    return 0;
}
