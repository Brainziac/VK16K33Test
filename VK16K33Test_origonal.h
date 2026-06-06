/* VK16K33Test --- write messages on the 14-segment I2C display               2025-06-15 */

#include <Wire.h>
#define VK16K33_DATA  02  //ESP8266ex-01s
#define VK16K33_CLK   00  //ESP8266ex-01s

#define VK16K33_ADDR  (0x70)  // I2C address with all address jumpers open

#define VK16K33_NDIGITS  (4)

//Byte assign for command codes ===========================

//System Setup register
// high nibble
#define VK16K33_CMD_OSC     0x20 
// lo nibble
#define VK16K33_OSC_OFF     0x00 // standby mode
#define VK16K33_OSC_ON      0x01 // normal operation

//Display setup register 
// high nibble
#define VK16K33_CMD_SETUP   0x80 
// lo nibble
#define VK16K33_DISPLAY_OFF 0x00 
#define VK16K33_DISPLAY_ON  0x01
#define VK16K33_BLINK_OFF   0x00
#define VK16K33_BLINK_2HZ   0x02
#define VK16K33_BLINK_1HZ   0x04
#define VK16K33_BLINK_0HZ5  0x06

//Display dimming duty 
//high nibble
#define VK16K33_CMD_DIMMING 0xE0
// lo nibble 1/16 duty

#define VK16K33_CMD_RAM     0x00

//===============================================


// Segment layout on VK16K33 display
// ----0----
// |\  |  /|
// 5 8 9 101
// |  \|/  |
// -6-- --7-
// |  /|\  |
// 41112 132
// |/  |  \|
// ----3---- 14

// ----A----
// |\  |  /|
// F H I J B
// |  \|/  |
// -G1- -G2-
// |  /|\  |
// E K L M C
// |/  |  \|
// ----D---- DP

 
// Segment names according to Wikipedia
#define SEGA  (1 <<  0)
#define SEGB  (1 <<  1)
#define SEGC  (1 <<  2)
#define SEGD  (1 <<  3)
#define SEGE  (1 <<  4)
#define SEGF  (1 <<  5)
#define SEGG1 (1 <<  6)
#define SEGG2 (1 <<  7)
#define SEGH  (1 <<  8)
#define SEGI  (1 <<  9)
#define SEGJ  (1 << 10)
#define SEGK  (1 << 11)
#define SEGL  (1 << 12)
#define SEGM  (1 << 13)
#define SEGDP (1 << 14)

// Hex digits 0-9, A-F
#define DIG0 (SEGA | SEGB | SEGC | SEGD | SEGE | SEGF)
#define DIG1 (SEGB | SEGC)
#define DIG2 (SEGA | SEGB | SEGD | SEGE | SEGG1 | SEGG2)
#define DIG3 (SEGA | SEGB | SEGC | SEGD | SEGG1 | SEGG2)
#define DIG4 (SEGB | SEGC | SEGF | SEGG1 | SEGG2)
#define DIG5 (SEGA | SEGC | SEGD | SEGF | SEGG1 | SEGG2)
#define DIG6 (SEGA | SEGC | SEGD | SEGE | SEGF | SEGG1 | SEGG2)
#define DIG7 (SEGA | SEGB | SEGC)
#define DIG8 (SEGA | SEGB | SEGC | SEGD | SEGE | SEGF | SEGG1 | SEGG2)
#define DIG9 (SEGA | SEGB | SEGC | SEGD | SEGF | SEGG1 | SEGG2)
#define DIGA (SEGA | SEGB | SEGC | SEGE | SEGF | SEGG1 | SEGG2)
#define DIGB (SEGA | SEGB | SEGC | SEGD | SEGG2 | SEGI | SEGL)
#define DIGC (SEGA | SEGD | SEGE | SEGF)
#define DIGD (SEGA | SEGB | SEGC | SEGD | SEGI | SEGL)
#define DIGE (SEGA | SEGD | SEGE | SEGF | SEGG1)
#define DIGF (SEGA | SEGE | SEGF | SEGG1)

#define LETA (SEGA | SEGB | SEGC | SEGE | SEGF | SEGG1 | SEGG2)
#define LETB (SEGA | SEGB | SEGC | SEGD | SEGG2 | SEGI | SEGL)
#define LETC (SEGA | SEGD | SEGE | SEGF)
#define LETD (SEGA | SEGB | SEGC | SEGD | SEGI | SEGL)
#define LETE (SEGA | SEGD | SEGE | SEGF | SEGG1)
#define LETF (SEGA | SEGE | SEGF | SEGG1)
#define LETH (SEGB | SEGC | SEGE | SEGF | SEGG1 | SEGG2)
#define LETI (SEGA | SEGD | SEGI | SEGL)
#define LETJ (SEGB | SEGC | SEGD)
#define LETK (SEGE | SEGF | SEGG1 | SEGJ | SEGM)
#define LETL (SEGD | SEGE | SEGF)
#define LETM (SEGB | SEGC | SEGE | SEGF | SEGH | SEGJ)
#define LETO (SEGA | SEGB | SEGC | SEGD | SEGE | SEGF)
#define LETR (SEGA | SEGB | SEGE | SEGF | SEGG1 | SEGG2 | SEGM)
#define LETS (SEGA | SEGC | SEGD | SEGF | SEGG1 | SEGG2)
#define LETT (SEGA | SEGI | SEGL)
#define LETU (SEGB | SEGC | SEGD | SEGE | SEGF)
#define LETZ (SEGA | SEGD | SEGJ | SEGK)


uint16_t Buf[VK16K33_NDIGITS];


void VK16K33_update(void)
{
  int digit;

  Wire.beginTransmission(VK16K33_ADDR);
  Wire.write(VK16K33_CMD_RAM);
  
  for (digit = 0; digit < VK16K33_NDIGITS; digit++)
  {
    Wire.write(Buf[digit] & 0xFF);
    Wire.write(Buf[digit] >> 8);
  }
  
  Wire.endTransmission();
}


void setup(void)
{
  Wire.begin(VK16K33_DATA,VK16K33_CLK);
  Wire.beginTransmission(VK16K33_ADDR);
  Wire.write(VK16K33_CMD_OSC | VK16K33_OSC_ON);
  Wire.endTransmission();

  Wire.beginTransmission(VK16K33_ADDR);
  Wire.write(VK16K33_CMD_DIMMING | 8);
  Wire.endTransmission();

  Wire.beginTransmission(VK16K33_ADDR);
  Wire.write(VK16K33_CMD_SETUP | VK16K33_DISPLAY_ON | VK16K33_BLINK_OFF);
  Wire.endTransmission();
}


void loop(void)
{
  Buf[0] = LETF;
  Buf[1] = LETA;
  Buf[2] = LETR;
  Buf[3] = LETT;
  VK16K33_update();

  delay(2500);
  
  Buf[0] = LETA;
  Buf[1] = LETR;
  Buf[2] = LETS;
  Buf[3] = LETE;
  VK16K33_update();

  delay(2500);

  Buf[0] = 0;
  Buf[1] = 0;
  Buf[2] = 0;
  Buf[3] = 0;
  VK16K33_update();

  delay(1000);
  
  Buf[0] = LETD;
  Buf[1] = LETI;
  Buf[2] = LETC;
  Buf[3] = LETK;
  VK16K33_update();

  delay(2500);
  
  Buf[0] = LETH;
  Buf[1] = LETE;
  Buf[2] = LETA;
  Buf[3] = LETD;
  VK16K33_update();

  delay(2500);

  Buf[0] = 0;
  Buf[1] = 0;
  Buf[2] = 0;
  Buf[3] = 0;
  VK16K33_update();

  delay(1000);
}
