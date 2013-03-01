///
/// @file       util.c
/// @author     Kyeong Soo (Joseph) Kim <k.s.kim@swansea.ac.uk>
/// @date       2012-02-21
///
/// @brief      Implements utility and miscellaneous functions.
///
/// @remarks    This program is based on Dr Tim Davies' assembly version of
///             micro mouse program and the C port of it by Mr Gareth Evans.
///
/// @copyright  Copyright (C) 2012 Swansea University. All rights reserved.
///
/// @copyright  This software is written and distributed under the GNU General
///             Public License Version 2 (http://www.gnu.org/licenses/gpl-2.0.html).
///             You must not remove this notice, or any other, from this software.
///


#include "mouse.h"	// for the declaration of types, constants, variables and functions


//------------------------------------------------------------------------------
// Functions for bit handling
//------------------------------------------------------------------------------
// function to set a specific bit of an unsigned 8-bit integer
byte BitSet(byte Bit_position, byte Var_old)
{
    byte Var_new;
    Var_new = Var_old | (byte)(1<<Bit_position);
    return Var_new;
}


// function to clear a specific bit of an unsigned 8-bit integer
byte BitClear(byte Bit_position, byte Var_old)
{
    byte Var_new;
    Var_new = Var_old & (~(byte)(1<<Bit_position));
    return Var_new;
}


//--------------------------------------------------------
// Misc. functions
//--------------------------------------------------------
void Delay(int a)
{
    int b=0,c=0;
    for (b=0;b<a;b++){
        for(c=0;c<100;c++);
    }
}

//--------------------------------------------------------
// adc/ldr functions
//--------------------------------------------------------

// function to convert analog to digital
byte ADC(byte channel)
{
  byte res=0;
  ADC1SC1  = channel;
	while( ADC1SC1_COCO	== 0)
  {
  }
	res = ADC1RL;
	return res;
	}
// function to compare wlfl to threshold voltage and set the result  
byte WL1(void)
{
  byte res,wlfl;  
  res=ADC(0);	
  if (res>50)
  {
	    wlfl = 1 ;
	}
	else 
	{
	  wlfl = 0; 
	}
	
	return wlfl;
}

// function to compare wlil to threshold voltage and set the result
byte WL2(void)
{
  byte res,wlil;  
  res=ADC(1);	
  if (res>50)
  {
	    wlil = 1 ;
	}
	else 
	{
	  wlil = 0; 
	}
	
	return wlil;
}

// function to compare wlir to threshold voltage and set the result
byte WL3(void)
{
  byte res,wlir;  
  res=ADC(2);	
  if (res>50)
  {
	    wlir = 1;
	}
	else 
	{
	  wlir = 0; 
	}
	
	return wlir;
}

// function to compare wlfr to threshold voltage and set the result
byte WL4(void)
{
  byte res,wlfr;  
  res=ADC(3);	
  if (res>50)
  {
	    wlfr = 1 ;
	}
	else 
	{
	  wlfr = 0; 
	}
	
	return wlfr;
} 
	
