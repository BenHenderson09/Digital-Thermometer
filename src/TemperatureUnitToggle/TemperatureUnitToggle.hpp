#ifndef TEMPERATURE_UNIT_TOGGLE_HPP
#define TEMPERATURE_UNIT_TOGGLE_HPP

#include "../TemperatureUnit/TemperatureUnit.hpp"

class TemperatureUnitToggle {
    public:
        TemperatureUnitToggle(int digitalInputPin);
        void updateState();
        TemperatureUnit getTemperatureUnitSetting();

    private:
        const int digitalInputPin;
        TemperatureUnit temperatureUnitSetting{celsius};
};

#endif