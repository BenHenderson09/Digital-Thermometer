#include "src/LCDScreen/LCDScreen.hpp"
#include "src/ThermometerModule/ThermometerModule.hpp"
#include "src/TemperatureUnit/TemperatureUnit.hpp"
#include "src/TemperatureUnitToggle/TemperatureUnitToggle.hpp"
#include "constants/PinConstants.hpp"

LCDScreen LCDScreen;
ThermometerModule thermometerModule{PinConstants::thermometerAnalogueInputPin};
TemperatureUnitToggle temperatureUnitToggle{PinConstants::temperatureUnitToggleAnalogueInputPin};

void setup() {
    thermometerModule.init();
    LCDScreen.init();
}

void loop() {
    temperatureUnitToggle.updateState();
    LCDScreen.temperatureUnitToDisplay = temperatureUnitToggle.getTemperatureUnitSetting();
    LCDScreen.printThermometerReading(thermometerModule);
}