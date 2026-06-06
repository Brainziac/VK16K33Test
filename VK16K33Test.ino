/* VK16K33Test --- write messages on the 14-segment I2C display               2025-06-15 */

#include <Wire.h>
#define VK16K33_DATA  02			//ESP8266ex-01s
#define VK16K33_CLK   00			//ESP8266ex-01s

#define VK16K33_ADDR  (0x70)		// I2C address with all address jumpers open

#define VK16K33_NDIGITS  (4)		// number of digits
#define VK16K33_RXBUFF   (8)		// number of digits

#include "VK16K33.h"				// header file for address assignments 

#include "VK16K33ascii.h"			// header file for ascii files

uint16_t TxBuf[VK16K33_NDIGITS];	// setup TxBuffer for digits

uint16_t RxBuff[VK16K33_RXBUFF];	// setup RxBuffer for digits

//=======================================================================================

void VK16K33_update(void)
{
	int digit;

	Wire.beginTransmission(VK16K33_ADDR);
	Wire.write(VK16K33_DISP_RAM);

	for (digit = 0; digit < VK16K33_NDIGITS; digit++)
	{
		Wire.write((TxBuf[digit]) & 0xFF);    //byte 1 lo 2222222211111111
		Wire.write((TxBuf[digit]) >> 8);      //byte 2 hi >>>>>>>>22222222
		//Serial.print((TxBuf[digit]) & 0xFF);
		//Serial.print("/");
		//Serial.println((TxBuf[digit]) >> 8);
	}

	Wire.endTransmission();
}
//=======================================================================================

void I2C_TX(int addr, int data)
{
	Wire.beginTransmission(addr);
	Wire.write(data);
	Wire.endTransmission();
}
//=======================================================================================

/*
void I2C_TX(int addr, int reg, int data)
{
	Wire.beginTransmission(addr);	// START + Device Address (e.g., 0x50) + Write bit
	Wire.write(reg);				// Send internal Register Address
	Wire.write(data);				// Send Data byte
	Wire.endTransmission();			// STOP
}
//======================================================================================
*/

// --- 2. READ SYNTAX ---
int I2C_RX(int addr, int reg, int count = 1)
{
	int a = 0;
	memset(RxBuff, 0, VK16K33_RXBUFF);		// Clear the receive buffer
	Wire.beginTransmission(addr);			// START + Device Address + Write bit
	Wire.write(reg);						// Send Register Address to point at
	Wire.endTransmission(false);			// Send REPEATED START instead of STOP

	Wire.requestFrom(addr | 0x01, count, 1);    // Address + Read bit, request  byte
	if (Wire.available()) {
		RxBuff[a] = Wire.read();			// Read the data
		a++;
	}
	a--;
	Wire.flush();							// Clear the I2C buffer
	return a;
}

//=======================================================================================

void setup(void)
{
	//Serial.begin(115200);

	Wire.begin(VK16K33_DATA, VK16K33_CLK);                 // set pins for I2C data and clock

	I2C_TX(VK16K33_ADDR, VK16K33_SYS_SET | VK16K33_OSC_ON);

	I2C_TX(VK16K33_ADDR, VK16K33_CMD_DIMMING | 8);         // set dimming value

	I2C_TX(VK16K33_ADDR, VK16K33_DISP_SET | VK16K33_DISPLAY_ON | VK16K33_BLINK_OFF);   //
}

//=======================================================================================

void loop(void)
{
	TxBuf[0] = tablea['0'];
	TxBuf[1] = tablea['1'];
	TxBuf[2] = tablea['2'];
	TxBuf[3] = tablea['3'];
	VK16K33_update();

	delay(2500);

	TxBuf[0] = tablea['4'];
	TxBuf[1] = tablea['5'];
	TxBuf[2] = tablea['6'];
	TxBuf[3] = tablea['7'];
	VK16K33_update();

	delay(2500);

	TxBuf[0] = 0;
	TxBuf[1] = 0;
	TxBuf[2] = 0;
	TxBuf[3] = 0;
	VK16K33_update();

	delay(1000);

	TxBuf[0] = tablea['M'];
	TxBuf[1] = tablea['a'];
	TxBuf[2] = tablea['r'];
	TxBuf[3] = tablea['k'];
	VK16K33_update();

	delay(2500);

	TxBuf[0] = tablea['a'];
	TxBuf[1] = tablea['b'];
	TxBuf[2] = tablea['c'];
	TxBuf[3] = tablea['d'];
	VK16K33_update();

	delay(2500);

	TxBuf[0] = 0;
	TxBuf[1] = 0;
	TxBuf[2] = 0;
	TxBuf[3] = 0;
	VK16K33_update();

	delay(1000);
}
