#include <LiquidCrystal.h>
#include "LCDScreen.hpp"
#include "../ThermometerModule/ThermometerModule.hpp"
#include "../../constants/PinConstants.hpp"
#include "../../constants/LCDScreenConstants.hpp"

LCDScreen::LCDScreen() : 
        lcd {
            PinConstants::registerSelectPin,
            PinConstants::enablePin,
            PinConstants::d4Pin,
            PinConstants::d5Pin,
            PinConstants::d6Pin,
            PinConstants::d7Pin
        } {}

void LCDScreen::init(){
    lcd.begin(LCDScreenConstants::columns, LCDScreenConstants::rows);
}

void LCDScreen::printThermometerReading(ThermometerModule& thermometerModule){
    printReadingLabel();
    printReadingValueAndTemperatureUnit(thermometerModule);
}

void LCDScreen::printReadingLabel(){
    lcd.setCursor(0, 0);
    lcd.print(" Temperature at ");
    lcd.setCursor(0, 1);
    lcd.print(" probe: ");
}

void LCDScreen::printReadingValueAndTemperatureUnit(ThermometerModule& thermometerModule){
    if (temperatureUnitToDisplay == celsius){
        lcd.print(thermometerModule.readTemperatureInCelsius());
        lcd.print(" C ");
    }
    else {
        lcd.print(thermometerModule.readTemperatureInFahrenheit());
        lcd.print(" F ");
    }
}