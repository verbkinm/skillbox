#pragma once

#include "Sensor.h"
#include "smart_light.h"

#include <memory>
#include <iostream>

class Smart_Home
{
private:
    std::list<std::unique_ptr<Device>> _devices;
    std::list<std::unique_ptr<Abstract_Sensor>> _sensors;
public:
    enum class OPERATOR { LT, GT, EQ };

    Smart_Home() = default;

    //Симуляция
    void readConfig();
    void sensorsEvent();

    void debugPrint() const;

};



