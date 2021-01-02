#include <DallasTemperature.h>
#include "ThermometerModule.hpp"

ThermometerModule::ThermometerModule(int analogueInputPin)
        : analogueInputPin{analogueInputPin}, oneWire{analogueInputPin}, thermometer{&oneWire} {
    pinMode(analogueInputPin, INPUT);
}

void ThermometerModule::init(){
    thermometer.begin();
}

double ThermometerModule::readTemperatureInCelsius(){
    thermometer.requestTemperatures();
    return thermometer.getTempCByIndex(0);
}

double ThermometerModule::readTemperatureInFahrenheit(){
    return (9.f/5.f) * readTemperatureInCelsius() + 32;
}