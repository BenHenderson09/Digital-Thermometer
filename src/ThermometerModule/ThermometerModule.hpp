#ifndef THERMOMETER_MODULE_HPP
#define THERMOMETER_MODULE_HPP

#include <DallasTemperature.h>

class ThermometerModule {
    public:
        ThermometerModule(int analogueInputPin);
        void init();
        double readTemperatureInCelsius();
        double readTemperatureInFahrenheit();

    private:
        const int analogueInputPin;
        OneWire oneWire;
        DallasTemperature thermometer;
};

#endif