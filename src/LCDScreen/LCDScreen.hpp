#ifndef LCD_SCREEN_HPP
#define LCD_SCREEN_HPP

#include <LiquidCrystal.h>
#include "../TemperatureUnit/TemperatureUnit.hpp"
#include "../ThermometerModule/ThermometerModule.hpp"

class LCDScreen {
    public:
        LCDScreen();
        void init();
        void printThermometerReading(ThermometerModule& thermometerModule);

        TemperatureUnit temperatureUnitToDisplay{celsius};

    private:
        void printReadingLabel();
        void printReadingValueAndTemperatureUnit(ThermometerModule& thermometerModule);

        LiquidCrystal lcd;
};

#endif