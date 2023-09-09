TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Emulated_system.cpp \
        abstract_sensor.cpp \
        device.cpp \
        main.cpp \
        smart_home.cpp \
        smart_light.cpp \
        time_of_day.cpp

HEADERS += \
    Sensor.h \
    abstract_sensor.h \
    device.h \
    smart_home.h \
    Emulated_system.h \
    smart_light.h \
    time_of_day.h
