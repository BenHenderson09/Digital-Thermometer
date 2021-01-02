#include <Arduino.h>
#include "TemperatureUnitToggle.hpp"

TemperatureUnitToggle::TemperatureUnitToggle(int digitalInputPin)
        : digitalInputPin{digitalInputPin} {
    pinMode(digitalInputPin, INPUT);
}

void TemperatureUnitToggle::updateState(){
    // Reading the unit toggle pin will result in either a one or zero depending on
    // the position of the switch.
    temperatureUnitSetting = digitalRead(digitalInputPin) ? celsius : fahrenheit;
}

TemperatureUnit TemperatureUnitToggle::getTemperatureUnitSetting(){
    return temperatureUnitSetting;
}