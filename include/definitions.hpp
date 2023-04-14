#pragma once

// The version of this firmware in the YYYY.MDD.PATCH format. (e.g. 2022.1219.2 for the 2nd release on the 19th december 2022)
#define FIRMWARE_VERSION "2023.410.1"

// ┌───────────────────────────────────────────────────────────────────────────────────────────────────┐
// │                                                                                                   │
// │                                           !!!WARNING!!!                                           │
// │                                                                                                   │
// │      DO NOT CHANGE UNLESS ADVISED. MODIFIED VALUES MAY CAUSE AN INCONSISTENT KEYPAD BEHAVIOR      │
// │   THAT VIOLATES OSU'S RULES. CHANGING THIS MAY LEAD TO INCORRECT KEY PRESSES AND A RESTRICTION.   │
// │                                                                                                   │
// └───────────────────────────────────────────────────────────────────────────────────────────────────┘

// The minimum difference between the lower and upper hysteresis. This is important to not have the key continuously
// actuate if you do very very slight movements or if the fluctuation is simply too high. It also defines the gap there
// has to be between the defined TRAVEL_DISTANCE_IN_0_01MM and the upper hysteresis so the actuation logic cannot
// possibly get stuck if you press the key down but happen to not be able to get back up enough.
#define HYSTERESIS_TOLERANCE 10

// The minimum value for the rapid trigger sensitivities. This is important to not have the key continuously
// continuously actuate if you do very very slight movements or if the fluctuation is simply too high.
#define RAPID_TRIGGER_TOLERANCE 10

// The threshold when a key is considered fully released. 10 would mean if the key is <0.1mm pressed.
// This value is important to reset the rapid trigger state properly with continuous rapid trigger.
#define CONTINUOUS_RAPID_TRIGGER_THRESHOLD 10

// Size of the array which the serial buffer is copied to
#define INPUT_BUFF_SIZE 64

// The resolution for the ADCs on the RP2040. The maximum compatible value on it is 12 bit.
#define ANALOG_RESOLUTION 12

// The exponent for the amount of samples for the SMA filter. This filter reduces fluctuation of analog values.
// A value too high may cause unresponsiveness. 1 = 1 sample, 2 = 4 samples, 3 = 8 samples, 4 = 16 samples, ...
#define SMA_FILTER_SAMPLE_EXPONENT 4

// The travel distance of the switches, where 1 unit equals 0.01mm. This is used to map the values properly to
// guarantee that the unit for the numbers used across the firmware actually matches the milimeter metric.
#define TRAVEL_DISTANCE_IN_0_01MM 400

// Define the ports used for the HE sensors.
#if KEYS == 3
#define HE_PINS    \
    {              \
        A2, A1, A0 \
    }
#elif KEYS == 2
#define HE_PINS \
    {           \
        A1, A0  \
    }
#else
#error The firmware only supports 2 or 3 keys.
#endif
