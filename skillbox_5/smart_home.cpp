#include "smart_home.h"

Smart_Home::Smart_Home()
{

}

// Эмулируем чтение конфигурационного файла
void Smart_Home::readConfig()
{
    _devices.clear();
    _sensors.clear();

    std::unique_ptr<Device> power = std::make_unique<Device>("All power"); // 1
    std::unique_ptr<Smart_Light> home_light = std::make_unique<Smart_Light>("Home light"); // 3
    std::unique_ptr<Device> yard_ligth = std::make_unique<Device>("Yard light"); // 4
    std::unique_ptr<Device> home_heating = std::make_unique<Device>("Home heating"); // 5
    std::unique_ptr<Device> yard_water = std::make_unique<Device>("Water supply heating system"); // 6
    std::unique_ptr<Device> conditioner = std::make_unique<Device>("Conditioner"); // 7

    std::unique_ptr<Sensor<int>> thermometer_1 = std::make_unique<Sensor<int>>("Thermometer in street");
    std::unique_ptr<Sensor<int>> thermometer_2 = std::make_unique<Sensor<int>>("Thermometer in home");
    std::unique_ptr<Sensor<bool>> outdoor_motion = std::make_unique<Sensor<bool>>("Outdoor motion sensor");

    power->enable();
    home_light->addIntervalColor({{16, 0}, {20, 0}, 5000, 2700});
    home_light->addIntervalColor({{20, 0}, {0, 0}, 2700, 2700});
    home_light->addIntervalColor({{0, 0}, {16, 0}, 5000, 5000});

    yard_ligth->setWorkTime({16, 1}, {5, 0});

    thermometer_1->addConditionOn({*yard_water, 0, Device::OPERATOR::LT});
    thermometer_1->addConditionOff({*yard_water, 5, Device::OPERATOR::GT});

    thermometer_2->addConditionOn({*home_heating, 22, Device::OPERATOR::LT});
    thermometer_2->addConditionOn({*conditioner, 30, Device::OPERATOR::GE});

    thermometer_2->addConditionOff({*home_heating, 25, Device::OPERATOR::GE});
    thermometer_2->addConditionOff({*conditioner, 25, Device::OPERATOR::LE});

    outdoor_motion->addConditionOn({*yard_ligth, true, Device::OPERATOR::EQ});
    outdoor_motion->addConditionOff({*yard_ligth, false, Device::OPERATOR::EQ});

    _devices.push_back(std::move(power));
    _devices.push_back(std::move(home_light));
    _devices.push_back(std::move(yard_ligth));
    _devices.push_back(std::move(home_heating));
    _devices.push_back(std::move(yard_water));
    _devices.push_back(std::move(conditioner));

    _sensors.push_back(std::move(thermometer_1));
    _sensors.push_back(std::move(thermometer_2));
    _sensors.push_back(std::move(outdoor_motion));
}

void Smart_Home::readSensors()
{
    std::string input;

    double t1 = 0, t2 = 0;
    std::string motion = "no", ligth = "off";

    int h = 0, m = 0;
    char d;

    std::cout << "Input data (time, temperature1, temperature2, motion, light)." << std::endl
              << "Example: 16:35 20.2 -5 yes on" << std::endl;
    getline(std::cin, input);

    std::stringstream stream(input);
    stream >> h >> d >> m >> t1 >> t2 >> motion >> ligth;

    Emulated_system::set_system_time({h, m});

}

void Smart_Home::debugPrint() const
{
    std::cout << "==============================" << std::endl;

    std::cout << "Device state: " << std::endl;
    for (auto const &dev : _devices)
    {
        std::cout << "\tName: " << dev.get()->name() << std::endl;
        std::cout << "\tState: " << std::boolalpha << dev.get()->state() << std::endl << std::endl;
    }

    std::cout << "Sensor value: " << std::endl;
    for (auto const &sensor : _sensors)
    {
        std::cout << "\tName: " << sensor.get()->name() << std::endl;
        std::cout << "\tValue: ";
        sensor.get()->printData();
        std::cout << std::endl << std::endl;
    }


    std::cout << "==============================" << std::endl;
}
