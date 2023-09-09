/*
Умный дом

    Надо разработать упрощённую модель умного дома для дачи. Есть несколько датчиков: датчик температуры снаружи, датчик температуры внутри дома. В доме расположен электронный “умный” щиток с автоматами. Каждый автомат отвечает за включение и отключение определённых устройств или групп устройств. Первый автомат - это отключение и включение питания всего дома, второй - основные розетки дома, третий - свет внутри дома, четвёртый - наружный свет в саду, пятый - отопление в помещении, шестой - отопление водопровода идущего из скважины с насосом, шестой - кондиционер в помещении.
    Есть несколько условий по включению/отключению техники в доме и вне его.
    Как только температура снаружи падает ниже 0, надо включить систему обогрева водопровода и отключить её, если температура снаружи поднялась выше 5 градусов.
    Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, то необходимо включить садовое освещение. Если движения нет или время не вечернее - света снаружи быть не должно.
    При условии, что температура в помещении упала ниже 22 градусов, должно включится отопление. Как только температура поднимается выше или равно 25-и градусам, отопление автоматически отключается.
    Если температура в помещении поднялась до 30 градусов, включается кондиционер. Как только температура становится 25 градусов - кондиционер отключается.
    Всё освещение в доме также “умное” и поддерживает настройку цветовой температуры для комфортного нахождения. Каждый день начиная с 16:00 и до 20:00, температура цвета должна плавно изменяться с 5000K до 2700К. Разумеется, это изменение должно происходить в случае, если свет сейчас включен. В 0:00 температура сбрасывается до 5000К.
    Все события по отключению и включению устройств должны выводится в консоль явным образом. Если устройство не изменило своего состояния (осталось включенным или выключенным) события генерироваться не должно! Если свет в доме включен, должна отображаться текущая цветовая температура.
    Программа выполняется следующим образом. Каждый час пользователь сообщает состояние всех основных датчиков и света: температура снаружи, температура внутри, есть ли движение снаружи, включен ли свет в доме. Данные параметры вводятся разом в одну строку, через пробел, а потом парсятся в переменные из строкового буфера stringstream. Информация о движении выводится в формате yes/no. Включение и отключение света происходит с помощью on/off. Стартовое время для симуляции умного дома - это 0:00. Требуется осуществить симуляцию на протяжении двух дней.
*/

#include "smart_home.h"

int main()
{
    std::cout << "Starting simulation." << std::endl << std::endl;
    
    Smart_Home smart_home;
    smart_home.readConfig();
    smart_home.debugPrint();

    Emulated_system::set_system_time({0, 0});

    for(uint8_t i = 0; i < 48; i++)
        smart_home.sensorsEvent();

    return 0;
}
