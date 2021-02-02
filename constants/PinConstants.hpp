#ifndef PIN_CONSTANTS_HPP
#define PIN_CONSTANTS_HPP

namespace PinConstants {
    // Thermometer module
    const int thermometerAnalogueInputPin{PA1};

    // Temperature unit toggle
    const int temperatureUnitToggleAnalogueInputPin{PA7};

    // LCD screen
    const int registerSelectPin{PB11},
        enablePin{PB10},
        d4Pin{PB0},
        d5Pin{PB1},
        d6Pin{PC13},
        d7Pin{PC14};
}

#endif
