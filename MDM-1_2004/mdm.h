//
// file      : mdm.h
// author    : Ian Forse
// date      : 06-APR-2004
// purpose   : Display driver header file
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

extern unsigned char mdm_cursor_position;

extern void mdm_output_byte( unsigned char , unsigned char  );

extern void mdm_update_from_segments(void);

extern void mdm_all( unsigned char );

extern void mdm_write_p ( unsigned char , unsigned char  );

extern void mdm_clear(void);

extern void mdm_write(  unsigned char  );

extern void mdm_init (void);





