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
#include <stdio.h>
#include <limits>

void print(double value)
{
    const auto digits = std::numeric_limits<double>::digits10;
    std::cout << std::setfill(' ') << std::setw(digits + 4);
    std::cout << std::fixed << std::setprecision(digits) << value << std::endl;
}

int main()
{
    double speed = 0.0;
    double delta;

    std::cout.precision(2);
    std::cout.setf(std::ios::fixed);
    do
    {
        std::cout << "Current speed: " << speed << " km/h" << std::endl;
        std::cout << "Input delta: ";
        std::cin >> delta;

        delta = (delta * 100);
        delta = static_cast<int>(delta);
        delta /= 100;
        speed += delta;

        if(speed > 150.0)
            speed = 150.0;
    }
    while (speed > 0);


    return 0;
}
