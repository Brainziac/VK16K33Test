/* VK16K33Test --- write messages on the 14-segment I2C display               2025-06-15 */

#include <Wire.h>


#define VK16K33_CMD_RAM     0x00
#define VK16K33_CMD_OSC     0x20
#define VK16K33_CMD_SETUP   0x80
#define VK16K33_CMD_DIMMING 0xE0

#define VK16K33_OSC_OFF     0x00
#define VK16K33_OSC_ON      0x01

#define VK16K33_DISPLAY_OFF 0x00
#define VK16K33_DISPLAY_ON  0x01
#define VK16K33_BLINK_OFF   0x00
#define VK16K33_BLINK_2HZ   0x02
#define VK16K33_BLINK_1HZ   0x04
#define VK16K33_BLINK_0HZ5  0x06

#define VK16K33_ADDR  (0x70)  // I2C address with all address jumpers open

#define VK16K33_NDIGITS  (4)

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

// Segment names according to Wikipedia
#define A  (1 <<  0)
#define B  (1 <<  1)
#define C  (1 <<  2)
#define D  (1 <<  3)
#define E  (1 <<  4)
#define F  (1 <<  5)
#define G1 (1 <<  6)
#define G2 (1 <<  7)
#define H  (1 <<  8)
#define I  (1 <<  9)
#define J  (1 << 10)
#define K  (1 << 11)
#define L  (1 << 12)
#define M  (1 << 13)
#define DP (1 << 14)

// Hex digits 0-9, A-F
#define DIG0 (A | B | C | D | E | F)
#define DIG1 (B | C)
#define DIG2 (A | B | D | E | G1 | G2)
#define DIG3 (A | B | C | D | G1 | G2)
#define DIG4 (B | C | F | G1 | G2)
#define DIG5 (A | C | D | F | G1 | G2)
#define DIG6 (A | C | D | E | F | G1 | G2)
#define DIG7 (A | B | C)
#define DIG8 (A | B | C | D | E | F | G1 | G2)
#define DIG9 (A | B | C | D | F | G1 | G2)
#define DIGA (A | B | C | E | F | G1 | G2)
#define DIGB (A | B | C | D | G2 | I | L)
#define DIGC (A | D | E | F)
#define DIGD (A | B | C | D | I | L)
#define DIGE (A | D | E | F | G1)
#define DIGF (A | E | F | G1)

#define LETA (A | B | C | E | F | G1 | G2)
#define LETB (A | B | C | D | G2 | I | L)
#define LETC (A | D | E | F)
#define LETD (A | B | C | D | I | L)
#define LETE (A | D | E | F | G1)
#define LETF (A | E | F | G1)
#define LETH (B | C | E | F | G1 | G2)
#define LETI (A | D | I | L)
#define LETJ (B | C | D)
#define LETK (E | F | G1 | J | M)
#define LETL (D | E | F)
#define LETM (B | C | E | F | H | J)
#define LETO (A | B | C | D | E | F)
#define LETR (A | B | E | F | G1 | G2 | M)
#define LETS (A | C | D | F | G1 | G2)
#define LETT (A | I | L)
#define LETU (B | C | D | E | F)
#define LETZ (A | D | J | K)


uint16_t Buf[VK16K33_NDIGITS];


void update(void)
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
  Wire.begin();
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
  update();

  delay(2500);
  
  Buf[0] = LETA;
  Buf[1] = LETR;
  Buf[2] = LETS;
  Buf[3] = LETE;
  update();

  delay(2500);

  Buf[0] = 0;
  Buf[1] = 0;
  Buf[2] = 0;
  Buf[3] = 0;
  update();

  delay(1000);
  
  Buf[0] = LETD;
  Buf[1] = LETI;
  Buf[2] = LETC;
  Buf[3] = LETK;
  update();

  delay(2500);
  
  Buf[0] = LETH;
  Buf[1] = LETE;
  Buf[2] = LETA;
  Buf[3] = LETD;
  update();

  delay(2500);

  Buf[0] = 0;
  Buf[1] = 0;
  Buf[2] = 0;
  Buf[3] = 0;
  update();

  delay(1000);
}
