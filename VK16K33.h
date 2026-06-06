
//Byte assign for command codes ===========================
//Display register
#define VK16K33_DISP_RAM	0x00	// DISPLAY MEM
// lo nibble
#define VK16K33_DIG_1		0x00	// COM0
#define VK16K33_DIG_2		0x02	// COM1
#define VK16K33_DIG_3		0x04	// COM2
#define VK16K33_DIG_4		0x06	// COM3
#define VK16K33_DIG_5		0x08	// COM4
#define VK16K33_DIG_6		0x0A	// COM5
#define VK16K33_DIG_7		0x0C	// COM6
#define VK16K33_DIG_8		0x0E	// COM7


//System Setup register
// high nibble
#define VK16K33_SYS_SET		0x20
// lo nibble
#define VK16K33_OSC_OFF		0x00	// standby mode
#define VK16K33_OSC_ON		0x01	// normal operation


//Key data register
// high nibble
#define VK16K33_KEY_ADD		0x40
// lo nibble key address
#define VK16K33_K0			0x01	// COM1
#define VK16K33_K1			0x02	// COM2
#define VK16K33_K2			0x04	// COM3


//INT flag address pointer
// high nibble
#define VK16K33_INT			0x60
// lo nibble 


//Display setup register 
// high nibble
#define VK16K33_DISP_SET	0x80
// lo nibble
#define VK16K33_DISPLAY_OFF	0x00
#define VK16K33_DISPLAY_ON	0x01
#define VK16K33_BLINK_OFF	0x00
#define VK16K33_BLINK_2HZ	0x02
#define VK16K33_BLINK_1HZ	0x04
#define VK16K33_BLINK_0HZ5	0x06


//ROW/INT set
// high nibble
#define VK16K33_ROW_INT		0xA0
// lo nibble
#define VK16K33_ROW			0x00
#define VK16K33_INT_LO		0x01
#define VK16K33_INT_HI		0x03


//Display dimming duty 
//high nibble
#define VK16K33_CMD_DIMMING	0xE0
// lo nibble 1/16 duty


//Testmode
//HOLTEK use only?
#define VK16K33_TESTMODE	0xD9

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

