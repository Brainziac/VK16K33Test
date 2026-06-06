//
// file      : mdm.c
// author    : Ian Forse
// date      : 06-APR-2004
// purpose   : MDM-1 display driver
// includes  : None
// notes     :
// compiler  : CCS PCW 3.187
//
// Copyright (C) 2004 Ian Forse
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
// USA

// ----------------------------------------------------------------------------
// Channel A segment lookup table
// ----------------------------------------------------------------------------


const unsigned char tablea [] = {
//	  bafcdejo	    hex    dec   char
	0b00000000,	//  0x00   000   blank
	0b11100010,	//  0x01   001   o (degree)
	0b00011110,	//  0x02   002   o (lower case o)
	0b01000010,	//  0x03   003   ohm
	0b00011100,	//  0x04   004   u
	0b01001010,	//  0x05   005   # (pound)
	0b00010110,	//  0x06   006   m
	0b00000000,	//  0x07   007   blank
	0b00000000,	//  0x08   008   blank
	0b00000000,	//  0x09   009   blank
	0b00000000,	//  0x0A   010   blank
	0b00000000,	//  0x0B   011   blank
	0b00000000,	//  0x0C   012   blank
	0b00000000,	//  0x0D   013   blank
	0b00000000,	//  0x0E   014   blank
	0b00000000,	//  0x0F   015   blank
	0b00000000,	//  0x10   016   blank
	0b00000000,	//  0x11   017   blank
	0b00000000,	//  0x12   018   blank
	0b00000000,	//  0x13   019   blank
	0b00000000,	//  0x14   020   blank
	0b00000000,	//  0x15   021   blank
	0b00000000,	//  0x16   022   blank
	0b00000000,	//  0x17   023   blank
	0b00000000,	//  0x18   024   blank
	0b00000000,	//  0x19   025   blank
	0b00000000,	//  0x1A   026   blank
	0b00000000,	//  0x1B   027   blank
	0b00000000,	//  0x1C   028   blank
	0b00000000,	//  0x1D   029   blank
	0b00000000,	//  0x1E   030   blank
	0b00000000,	//  0x1F   031   blank
	0b00000000,	//  0x20   032   space
	0b00001000,	//  0x21   033   !
	0b00100000,	//  0x22   034   "
	0b00110010,	//  0x23   035   #
	0b01111010,	//  0x24   036   $
	0b00110010,	//  0x25   037   %
	0b00101110,	//  0x26   038   &
	0b00000000,	//  0x27   039   '
	0b00000000,	//  0x28   040   (
	0b00000000,	//  0x29   041   )
	0b00000010,	//  0x2A   042   *
	0b00000010,	//  0x2B   043   +
	0b00000000,	//  0x2C   044   , (clears dots)
	0b00000010,	//  0x2D   045   -
	0b00000001,	//  0x2E   046   .
	0b00000000,	//  0x2F   047   /
	0b11111100,	//  0x30   048   0
	0b10010000,	//  0x31   049   1
	0b11001110,	//  0x32   050   2
	0b11011000,	//  0x33   051   3
	0b10110010,	//  0x34   052   4
	0b01111010,	//  0x35   053   5
	0b01111110,	//  0x36   054   6
	0b11010000,	//  0x37   055   7
	0b11111110,	//  0x38   056   8
	0b11111010,	//  0x39   057   9
	0b00000000,	//  0x3A   058   :
	0b00000001,	//  0x3B   059   ;
	0b00000000,	//  0x3C   060   <
	0b00001010,	//  0x3D   061   =
	0b00000000,	//  0x3E   062   >
	0b11100001,	//  0x3F   063   ?
	0b11101100,	//  0x40   064   @
	0b11110110,	//  0x41   065   A
	0b11011000,	//  0x42   066   B
	0b01101100,	//  0x43   067   C
	0b11011000,	//  0x44   068   D
	0b01101110,	//  0x45   069   E
	0b01100110,	//  0x46   070   F
	0b01111100,	//  0x47   071   G
	0b10110110,	//  0x48   072   H
	0b01001000,	//  0x49   073   I
	0b10011100,	//  0x4A   074   J
	0b00100110,	//  0x4B   075   K
	0b00101100,	//  0x4C   076   L
	0b10110100,	//  0x4D   077   M
	0b10110100,	//  0x4E   078   N
	0b11111100,	//  0x4F   079   O
	0b11100110,	//  0x50   080   P
	0b11111100,	//  0x51   081   Q
	0b11100110,	//  0x52   082   R
	0b01111010,	//  0x53   083   S
	0b01000000,	//  0x54   084   T
	0b10111100,	//  0x55   085   U
	0b00100100,	//  0x56   086   V
	0b10111100,	//  0x57   087   W
	0b00000000,	//  0x58   088   X
	0b00000000,	//  0x59   089   Y
	0b01001000,	//  0x5A   090   Z
	0b01101100,	//  0x5B   091   [
	0b00000000,	//  0x5C   092   \
	0b11011000,	//  0x5D   093   ]
	0b00000000,	//  0x5E   094   ^
	0b00001000,	//  0x5F   095   _
	0b00000000,	//  0x60   096   `
	0b11110110,	//  0x61   097   a
	0b00111110,	//  0x62   098   b
	0b00001110,	//  0x63   099   c
	0b10011110,	//  0x64   100   d
	0b11101110,	//  0x65   101   e
	0b01100110,	//  0x66   102   f
	0b11111010,	//  0x67   103   g
	0b00100110,	//  0x68   104   h
	0b00001010,	//  0x69   105   i
	0b10011000,	//  0x6A   106   j
	0b00100110,	//  0x6B   107   k
	0b00100100,	//  0x6C   108   l
	0b00010110,	//  0x6D   109   m
	0b00000110,	//  0x6E   110   n
	0b00011110,	//  0x6F   111   o
	0b11100110,	//  0x70   112   p
	0b11110010,	//  0x71   113   q
	0b00000000,	//  0x72   114   r
	0b00001000,	//  0x73   115   s
	0b00101110,	//  0x74   116   t
	0b00011100,	//  0x75   117   u
	0b00000100,	//  0x76   118   v
	0b00010100,	//  0x77   119   w
	0b00000000,	//  0x78   120   x
	0b10010000,	//  0x79   121   y
	0b00001010,	//  0x7A   122   z
	0b00000010,	//  0x7B   123   {
	0b00000000,	//  0x7C   124   |
	0b00000000,	//  0x7D   125   }
	0b00110000,	//  0x7E   126   ~
	0b11111111};	//  0x7F   127   (del)


const unsigned char tableb[] = {
//    ihgnmlkr	    hex   dec   char
	0b00000000,	//  0x00   000   blank
	0b11100010,	//  0x01   001   o (degree)
	0b00011110,	//  0x02   002   o (lower case o)
	0b01000010,	//  0x03   003   ohm
	0b00011100,	//  0x04   004   u
	0b01001010,	//  0x05   005   # (pound)
	0b00010110,	//  0x06   006   m
	0b00000000,	//  0x07   007   blank
	0b00000000,	//  0x08   008   blank
	0b00000000,	//  0x09   009   blank
	0b00000000,	//  0x0A   010   blank
	0b00000000,	//  0x0B   011   blank
	0b00000000,	//  0x0C   012   blank
	0b00000000,	//  0x0D   013   blank
	0b00000000,	//  0x0E   014   blank
	0b00000000,	//  0x0F   015   blank
	0b00000000,	//  0x10   016   blank
	0b00000000,	//  0x11   017   blank
	0b00000000,	//  0x12   018   blank
	0b00000000,	//  0x13   019   blank
	0b00000000,	//  0x14   020   blank
	0b00000000,	//  0x15   021   blank
	0b00000000,	//  0x16   022   blank
	0b00000000,	//  0x17   023   blank
	0b00000000,	//  0x18   024   blank
	0b00000000,	//  0x19   025   blank
	0b00000000,	//  0x1A   026   blank
	0b00000000,	//  0x1B   027   blank
	0b00000000,	//  0x1C   028   blank
	0b00000000,	//  0x1D   029   blank
	0b00000000,	//  0x1E   030   blank
	0b00000000,	//  0x1F   031   blank
	0b00000000,	//  0x20   032   space
	0b01001000,	//  0x21   033   !
	0b01000000,	//  0x22   034   "
	0b01001010,	//  0x23   035   #
	0b01001010,	//  0x24   036   $
	0b11001110,	//  0x25   037   %
	0b01001000,	//  0x26   038   &
	0b01000000,	//  0x27   039   '
	0b10010000,	//  0x28   040   (
	0b00100100,	//  0x29   041   )
	0b11111110,	//  0x2A   042   *
	0b01001010,	//  0x2B   043   +
	0b00000000,	//  0x2C   044   , clears dots)
	0b00000010,	//  0x2D   045   -
	0b00000000,	//  0x2E   046   .
	0b10000100,	//  0x2F   047   /
	0b00000000,	//  0x30   048   0
	0b00000000,	//  0x31   049   1
	0b00000010,	//  0x32   050   2
	0b00000010,	//  0x33   051   3
	0b00000010,	//  0x34   052   4
	0b00000010,	//  0x35   053   5
	0b00000010,	//  0x36   054   6
	0b00000000,	//  0x37   055   7
	0b00000010,	//  0x38   056   8
	0b00000010,	//  0x39   057   9
	0b00000001,	//  0x3A   058   :
	0b00000001,	//  0x3B   059   ;
	0b10010000,	//  0x3C   060   <
	0b00000010,	//  0x3D   061   =
	0b00100100,	//  0x3E   062   >
	0b00001010,	//  0x3F   063   ?
	0b01000010,	//  0x40   064   @
	0b00000010,	//  0x41   065   A
	0b01001010,	//  0x42   066   B
	0b00000000,	//  0x43   067   C
	0b01001000,	//  0x44   068   D
	0b00000000,	//  0x45   069   E
	0b00000000,	//  0x46   070   F
	0b00000010,	//  0x47   071   G
	0b00000010,	//  0x48   072   H
	0b01001000,	//  0x49   073   I
	0b00000000,	//  0x4A   074   J
	0b10010000,	//  0x4B   075   K
	0b00000000,	//  0x4C   076   L
	0b10100000,	//  0x4D   077   M
	0b00110000,	//  0x4E   078   N
	0b00000000,	//  0x4F   079   O
	0b00000010,	//  0x50   080   P
	0b00010000,	//  0x51   081   Q
	0b00010010,	//  0x52   082   R
	0b00000010,	//  0x53   083   S
	0b01001000,	//  0x54   084   T
	0b00000000,	//  0x55   085   U
	0b10000100,	//  0x56   086   V
	0b00001000,	//  0x57   087   W
	0b10110100,	//  0x58   088   X
	0b10101000,	//  0x59   089   Y
	0b10000100,	//  0x5A   090   Z
	0b00000000,	//  0x5B   091   [
	0b00110000,	//  0x5C   092   \
	0b00000000,	//  0x5D   093   ]
	0b10100000,	//  0x5E   094   ^
	0b00000000,	//  0x5F   095   _
	0b00100000,	//  0x60   096   `
	0b00000010,	//  0x61   097   a
	0b00000010,	//  0x62   098   b
	0b00000010,	//  0x63   099   c
	0b00000010,	//  0x64   100   d
	0b00000010,	//  0x65   101   e
	0b00000000,	//  0x66   102   f
	0b00000010,	//  0x67   103   g
	0b00001000,	//  0x68   104   h
	0b00001010,	//  0x69   105   i
	0b00000000,	//  0x6A   106   j
	0b00010010,	//  0x6B   107   k
	0b00000000,	//  0x6C   108   l
	0b00001010,	//  0x6D   109   m
	0b00001000,	//  0x6E   110   n
	0b00000010,	//  0x6F   111   o
	0b00000010,	//  0x70   112   p
	0b00000010,	//  0x71   113   q
	0b00001010,	//  0x72   114   r
	0b00010010,	//  0x73   115   s
	0b00000000,	//  0x74   116   t
	0b00000000,	//  0x75   117   u
	0b00000100,	//  0x76   118   v
	0b00010100,	//  0x77   119   w
	0b10110100,	//  0x78   120   x
	0b01000010,	//  0x79   121   y
	0b00000100,	//  0x7A   122   z
	0b10010000,	//  0x7B   123   {
	0b01001000,	//  0x7C   124   |
	0b00100110,	//  0x7D   125   }
	0b00110000,	//  0x7E   126   ~
	0b11111111};	//  0x7F   127   (del)



// digit segments values
unsigned char mdm_segments_1a, mdm_segments_1b;
unsigned char mdm_segments_2a, mdm_segments_2b;
unsigned char mdm_segments_3a, mdm_segments_3b;
unsigned char mdm_segments_4a, mdm_segments_4b;
unsigned char mdm_segments_5a, mdm_segments_5b;

// current position for mdm_write()
// static unsigned char mdm_cursor_position;

// LOAD,DATA & CLOCK use Portb,2,4,5 respectively
/*
#define mdm_pin_load PIN_B2
#define mdm_pin_data PIN_B4
#define mdm_pin_clock PIN_B5
*/
// ----------------------------------------------------------------------------
// Shift byte x out to the display as serial.  n is number of bits (5 x 8) +
// (1 * 3).  Note range is from 0 i.e. 8 is from 0 to 7.
// ----------------------------------------------------------------------------

void mdm_output_byte( unsigned char n, unsigned char x )
{
	signed char i;
		for(i=n; i>=0; i--)
		{
			if ((x>>i)&0x01)
			{
            output_high(mdm_pin_data);
			}
			else
			{
            output_low(mdm_pin_data);
			}
         output_high(mdm_pin_clock);
         output_low(mdm_pin_clock);
		}
}

// ----------------------------------------------------------------------------
// Update the display from the segment values.
// ----------------------------------------------------------------------------

void mdm_update_from_segments(void)
{
	mdm_output_byte( 7, mdm_segments_5a );
	mdm_output_byte( 7, mdm_segments_4a );
	mdm_output_byte( 7, mdm_segments_3a );
	mdm_output_byte( 7, mdm_segments_2a );
	mdm_output_byte( 7, mdm_segments_1a );
	mdm_output_byte( 2, 0x00 );
   output_high(mdm_pin_load);
   output_low(mdm_pin_load);

	mdm_output_byte( 7, mdm_segments_5b );
	mdm_output_byte( 7, mdm_segments_4b );
	mdm_output_byte( 7, mdm_segments_3b );
	mdm_output_byte( 7, mdm_segments_2b );
	mdm_output_byte( 7, mdm_segments_1b );
	mdm_output_byte( 2, 0x01 );
   output_high(mdm_pin_load);
   output_low(mdm_pin_load);
}


// ----------------------------------------------------------------------------
// Adjust segment values to either all on or all off.  Could be dropped if code
// space was tight.
// ----------------------------------------------------------------------------

void mdm_all( unsigned char x)
{
	unsigned char v;
	if (x)
	{
		v = 0b11111111;
	}
	else
	{
		v = 0b00000000;
	}
	mdm_segments_1a = v;	mdm_segments_1b = v;
	mdm_segments_2a = v;	mdm_segments_2b = v;
	mdm_segments_3a = v;	mdm_segments_3b = v;
	mdm_segments_4a = v;	mdm_segments_4b = v;
	mdm_segments_5a = v;	mdm_segments_5b = v;
	mdm_update_from_segments();
}


// ----------------------------------------------------------------------------
// write ascii character c to position p.
// ----------------------------------------------------------------------------

void mdm_write_p ( unsigned char p, unsigned char c )
{
	unsigned char segments_a, segments_b, a, b;
	if (p == 1)
	{
		segments_a = mdm_segments_1a;		segments_b = mdm_segments_1b;
	}
	else if (p == 2)
	{
		segments_a = mdm_segments_2a;		segments_b = mdm_segments_2b;
	}
	else if (p == 3)
	{
		segments_a = mdm_segments_3a;		segments_b = mdm_segments_3b;
	}
	else if (p == 4)
	{
		segments_a = mdm_segments_4a;		segments_b = mdm_segments_4b;
	}
	else if (p == 5)
	{
		segments_a = mdm_segments_5a;		segments_b = mdm_segments_5b;
	}

	if (c == ',')			// look for ',' == clear dots
	{
		segments_a = segments_a & ! 0b00000001;
		segments_b = segments_b & ! 0b00000001;
	}
	else
	{
		c = c & 0b01111111;	// tables are 128 entries only, so clear highest bit
		a =  tablea[c];		// lookup channel a
		b =  tableb[c];		// lookup channel b
	}

	if (( ( a | b ) & 0b00000001 ) == 0)	// don't shift when writing the dots
	{
		mdm_cursor_position = mdm_cursor_position + 1;
	}

	segments_a = ( segments_a & 0b00000001 ) | a;	// don't overwrite the dots
	segments_b = ( segments_b & 0b00000001 ) | b;

	if (p == 1)
	{
		mdm_segments_1a = segments_a;		mdm_segments_1b = segments_b;
	}
	else if (p == 2)
	{
		mdm_segments_2a = segments_a;		mdm_segments_2b = segments_b;
	}
	else if (p == 3)
	{
		mdm_segments_3a = segments_a;		mdm_segments_3b = segments_b;
	}
	else if (p == 4)
	{
		mdm_segments_4a = segments_a;		mdm_segments_4b = segments_b;
	}
	else if (p == 5)
	{
		mdm_segments_5a = segments_a;		mdm_segments_5b = segments_b;
	}

	mdm_update_from_segments();
}


// ----------------------------------------------------------------------------
// clear the display, set cursor position to 1
// ----------------------------------------------------------------------------

void mdm_clear(void)
{
	mdm_all( 0 );
	mdm_cursor_position = 1;
}


// ----------------------------------------------------------------------------
// write acii character c to cursor position, reset by mdm_clear.  Allows TTY
// style message to move scroll
// ----------------------------------------------------------------------------

void mdm_write(  unsigned char c )
{
	if (mdm_cursor_position > 5)
	{
		mdm_segments_1a = mdm_segments_2a;
		mdm_segments_1b = mdm_segments_2b;
		mdm_segments_2a = mdm_segments_3a;
		mdm_segments_2b = mdm_segments_3b;
		mdm_segments_3a = mdm_segments_4a;
		mdm_segments_3b = mdm_segments_4b;
		mdm_segments_4a = mdm_segments_5a;
		mdm_segments_4b = mdm_segments_5b;
		mdm_cursor_position = 5;
	}
	mdm_write_p( mdm_cursor_position, c );
}


// ----------------------------------------------------------------------------
// initialise the pin directions
// ----------------------------------------------------------------------------

void mdm_init(void)
{
   output_low(mdm_pin_load);
   output_low(mdm_pin_data);
   output_low(mdm_pin_clock);
}


