![Static Badge](https://img.shields.io/badge/MCU-ATmega328-green "MCU:ATmega328")
![Static Badge](https://img.shields.io/badge/BOARD-Arduino-green "BOARD:Arduino")
![Static Badge](https://img.shields.io/badge/DISPLAY-VK16K33-green "DISPLAY:VK16K33")

# VK16K33Test #

Demo sketch for the VK16K33 14-segment I2C LED display.
The VK16K33 is a driver chip for up to 16 segments and 8 digits.
It is available from inexpensive suppliers in the form of a module,
with the chip connected to a four-digit 14-segment LED display.

The sketch writes some slighty rude four-letter words to the display.
It cannot (as yet) write arbitrary text.

## Pinout ##

| Arduino | Signal | VK16K33   |
|---------|--------|-----------|
| A4      | SDA    | SDA       |
| A5      | SCL    | SCL       |
| 5V      | 5V     | VCC, VI2C |
| GND     | GND    | GND       |

I2C pull-up resistors are included on the display module,
although this is not really good practice if the I2C bus
is connected to multiple displays.

The solder jumpers for I2C address on the module (A0, A1, A2)
are all open.

