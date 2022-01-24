#pragma once

#include <list>
#include <iostream>

#include "device.h"
#include "abstract_sensor.h"

template <class T>
class Sensor : public Abstract_Sensor
{
public:
    Sensor(const std::string &name);

    const T &getValue() const;
    void setValue(const T &newValue);

    struct CONDITION {
        Device &device;
        T value;
        Device::OPERATOR op;
    };

    void addConditionOn(CONDITION cond);
    void addConditionOff(CONDITION cond);

    void clearConditionOn();
    void clearConditionOff();
    void clearConditionAll();

    virtual void printData() const override;

private:
    virtual void checkConditions() override;

    T value;

    std::list<CONDITION> _condOff;
    std::list<CONDITION> _condOn;
};

template<class T>
Sensor<T>::Sensor(const std::string &name) : Abstract_Sensor(name)
{

}

template<class T>
const T &Sensor<T>::getValue() const
{
    return value;
}

template<class T>
inline void Sensor<T>::setValue(const T &newValue)
{
    value = newValue;
    checkConditions();
}

template<class T>
void Sensor<T>::addConditionOff(CONDITION cond)
{
    _condOff.push_back(cond);
}

template<class T>
void Sensor<T>::addConditionOn(CONDITION cond)
{
    _condOn.push_back(cond);
}

template<class T>
void Sensor<T>::checkConditions()
{
    for(auto const &cond : _condOn)
    {
        switch (cond.op)
        {
        case Device::OPERATOR::LT:
            if(getValue() < cond.value)
                cond.device.enable();
            break;
        case Device::OPERATOR::LE:
            if(getValue() <= cond.value)
                cond.device.enable();
            break;
        case Device::OPERATOR::GT:
            if(getValue() > cond.value)
                cond.device.enable();
            break;
        case Device::OPERATOR::GE:
            if(getValue() >= cond.value)
                cond.device.enable();
            break;
        case Device::OPERATOR::EQ:
            if(getValue() == cond.value)
                cond.device.enable();
            break;
        case Device::OPERATOR::NE:
            if(getValue() != cond.value)
                cond.device.enable();
            break;
        }
    }

    for(auto const &cond : _condOff)
    {
        switch (cond.op)
        {
        case Device::OPERATOR::LT:
            if(getValue() < cond.value)
                cond.device.disable();
            break;
        case Device::OPERATOR::LE:
            if(getValue() <= cond.value)
                cond.device.disable();
            break;
        case Device::OPERATOR::GT:
            if(getValue() > cond.value)
                cond.device.disable();
            break;
        case Device::OPERATOR::GE:
            if(getValue() >= cond.value)
                cond.device.disable();
            break;
        case Device::OPERATOR::EQ:
            if(getValue() == cond.value)
                cond.device.disable();
            break;
        case Device::OPERATOR::NE:
            if(getValue() != cond.value)
                cond.device.disable();
            break;
        }
    }
}

template<class T>
void Sensor<T>::clearConditionOn()
{
    _condOn.clear();
}

template<class T>
void Sensor<T>::clearConditionOff()
{
    _condOff.clear();
}

template<class T>
void Sensor<T>::clearConditionAll()
{
    clearConditionOn();
    clearConditionOff();
}

template<class T>
void Sensor<T>::printData() const
{
    std::cout << getValue();
}
