/*============================================================================*/
/*                 Mathematics Related Constants and Macros                   */
/*                                                                            */
/* Dominik Deak                                                               */
/*============================================================================*/

/*---------------------------------------------------------------------------
   Don't include this file if it's already defined.   
  ---------------------------------------------------------------------------*/
#ifndef __MATH_H__
#define __MATH_H__


/*---------------------------------------------------------------------------
   Include libraries and other source files needed in this file.
  ---------------------------------------------------------------------------*/
#include "../common/common.h"


/*----------------------------------------------------------------------------
  Extreme values for various data types.   
  ----------------------------------------------------------------------------*/
#define float_MIN       (float)-3.4e38
#define float_MAX       (float) 3.4e38

#define double_MIN      (double)-1.7e380
#define double_MAX      (double) 1.7e380

#define uint_MIN        (unsigned int)0x00000000
#define uint_MAX        (unsigned int)(~uint_MIN)
#define int_MIN         (int)(1 << (sizeof(int)*8 - 1))
#define int_MAX         (int)(~int_MIN)

#define uint8_MIN       (uint8)0x00
#define uint8_MAX       (uint8)0xFF
#define int8_MIN        (int8) 0x80
#define int8_MAX        (int8) 0x7F

#define uint16_MIN      (uint16)0x0000
#define uint16_MAX      (uint16)0xFFFF
#define int16_MIN       (int16) 0x8000
#define int16_MAX       (int16) 0x7FFF

#define uint32_MIN      (uint32)0x00000000
#define uint32_MAX      (uint32)0xFFFFFFFF
#define int32_MIN       (int32) 0x80000000
#define int32_MAX       (int32) 0x7FFFFFFF

#define uint64_MIN      (uint64)0x0000000000000000
#define uint64_MAX      (uint64)0xFFFFFFFFFFFFFFFF
#define int64_MIN       (int64) 0x8000000000000000
#define int64_MAX       (int64) 0x7FFFFFFFFFFFFFFF


/*----------------------------------------------------------------------------
  General purpose constants
  ----------------------------------------------------------------------------*/
const union {int i; float f;} _NaN = {0x7FC00000};
float  const _3inv         = 1.0f / 3.0f;
float  const _15inv        = 1.0f / 15.0f;
float  const _16inv        = 1.0f / 16.0f;
float  const _63inv        = 1.0f / 63.0f;
float  const _64inv        = 1.0f / 64.0f;
float  const _127inv       = 1.0f / 127.0f;
float  const _128inv       = 1.0f / 128.0f;
float  const _180inv       = 1.0f / 180.0f;
float  const _255inv       = 1.0f / 255.0f;
float  const _256inv       = 1.0f / 256.0f;
float  const _511inv       = 1.0f / 511.0f;
float  const _512inv       = 1.0f / 512.0f;
float  const _1023inv      = 1.0f / 1023.0f;
float  const _1024inv      = 1.0f / 1024.0f;
float  const _2047inv      = 1.0f / 2047.0f;
float  const _2048inv      = 1.0f / 2048.0f;
float  const _4095inv      = 1.0f / 4095.0f;
float  const _4096inv      = 1.0f / 4096.0f;
float  const _65535inv     = 1.0f / 65535.0f;
float  const _65536inv     = 1.0f / 65536.0f;

double const _pi           = acos(-1.0);
double const _pi_inv       = 1.0f / _pi;
float  const _ln2          = (float)log(2.0f);
float  const _ln2inv       = 1.0f / _ln2;
float  const _180_div_pi   = 180.0f * (float)_pi_inv;
float  const _pi_div_180   = (float)_pi * _180inv;


/*----------------------------------------------------------------------------
  Fixed point arithmetic macros
  ----------------------------------------------------------------------------*/
#define int_to_fix16(A)    ((A) << 16)                //Convert integer to .16 fixed point format
#define float_to_fix16(A)  ((int)((A) * 65536.0f))    //Convert float to .16 fixed point format
#define fix16_to_int(A)    ((A) >> 16)                //.16 fixed point format to integer
#define fix16_to_float(A)  ((float)(A) * _65536inv)   //.16 fixed point format to float
#define norm16(A)          ((A) >> 16)                //Post multiply normalize to .16 fixed point format 
#define inorm16(A)         ((A) << 16)                //Inverse normalize, mainly used before division 

#define int_to_fix12(A)    ((A) << 12)                //Convert integer to .12 fixed point format
#define float_to_fix12(A)  ((int)((A) * 4096.0f))     //Convert float to .12 fixed point format
#define fix12_to_int(A)    ((A) >> 12)                //.12 fixed point format to integer
#define fix12_to_float(A)  ((float)(A) * _4096inv)    //.12 fixed point format to float
#define norm12(A)          ((A) >> 12)                //Post multiply normalize to .12 fixed point format 
#define inorm12(A)         ((A) << 12)                //Inverse normalize, mainly used before division 

#define int_to_fix11(A)    ((A) << 11)                //Convert integer to .11 fixed point format
#define float_to_fix11(A)  ((int)((A) * 2048.0f))     //Convert float to .11 fixed point format
#define fix11_to_int(A)    ((A) >> 11)                //.11 fixed point format to integer
#define fix11_to_float(A)  ((float)(A) * _2048inv)    //.11 fixed point format to float
#define norm11(A)          ((A) >> 11)                //Post multiply normalize to .11 fixed point format 
#define inorm11(A)         ((A) << 11)                //Inverse normalize, mainly used before division 

#define int_to_fix10(A)    ((A) << 10)                //Convert integer to .10 fixed point format
#define float_to_fix10(A)  ((int)((A) * 1024.0f))     //Convert float to .10 fixed point format
#define fix10_to_int(A)    ((A) >> 10)                //.10 fixed point format to integer
#define fix10_to_float(A)  ((float)(A) * _1024inv)    //.10 fixed point format to float
#define norm10(A)          ((A) >> 10)                //Post multiply normalize to .10 fixed point format 
#define inorm10(A)         ((A) << 10)                //Inverse normalize, mainly used before division 

#define int_to_fix9(A)     ((A) << 9)                 //Convert integer to .9 fixed point format
#define float_to_fix9(A)   ((int)((A) * 512.0f))      //Convert float to .9 fixed point format
#define fix9_to_int(A)     ((A) >> 9)                 //.9 fixed point format to integer
#define fix9_to_float(A)   ((float)(A) * _512inv)     //.9 fixed point format to float
#define norm9(A)           ((A) >> 9)                 //Post multiply normalize to .9 fixed point format 
#define inorm9(A)          ((A) << 9)                 //Inverse normalize, mainly used before division 

#define int_to_fix8(A)     ((A) << 8)                 //Convert integer to .8 fixed point format
#define float_to_fix8(A)   ((int)((A) * 256.0f))      //Convert float to .8 fixed point format
#define fix8_to_int(A)     ((A) >> 8)                 //.8 fixed point format to integer
#define fix8_to_float(A)   ((float)(A) * _256inv)     //.8 fixed point format to float
#define norm8(A)           ((A) >> 8)                 //Post multiply normalize to .8 fixed point format 
#define inorm8(A)          ((A) << 8)                 //Inverse normalize, mainly used before division 

#define int_to_fix7(A)     ((A) << 7)                 //Convert integer to .7 fixed point format
#define float_to_fix7(A)   ((int)((A) * 128.0f))      //Convert float to .7 fixed point format
#define fix7_to_int(A)     ((A) >> 7)                 //.7 fixed point format to integer
#define fix7_to_float(A)   ((float)(A) * _128inv)     //.7 fixed point format to float
#define norm7(A)           ((A) >> 7)                 //Post multiply normalize to .7 fixed point format 
#define inorm7(A)          ((A) << 7)                 //Inverse normalize, mainly used before division 

#define int_to_fix6(A)     ((A) << 6)                 //Convert integer to .6 fixed point format
#define float_to_fix6(A)   ((int)((A) * 64.0f))       //Convert float to .6 fixed point format
#define fix6_to_int(A)     ((A) >> 6)                 //.6 fixed point format to integer
#define fix6_to_float(A)   ((float)(A) * _64inv)      //.6 fixed point format to float
#define norm6(A)           ((A) >> 6)                 //Post multiply normalize to .6 fixed point format 
#define inorm6(A)          ((A) << 6)                 //Inverse normalize, mainly used before division 

#define int_to_fix4(A)     ((A) << 4)                 //Convert integer to .4 fixed point format
#define float_to_fix4(A)   ((int)((A) * 16.0f))       //Convert float to .4 fixed point format
#define fix4_to_int(A)     ((A) >> 4)                 //.4 fixed point format to integer
#define fix4_to_float(A)   ((float)(A) * _16inv)      //.4 fixed point format to float
#define norm4(A)           ((A) >> 4)                 //Post multiply normalize to .4 fixed point format 
#define inorm4(A)          ((A) << 4)                 //Inverse normalize, mainly used before division 
                           

/*----------------------------------------------------------------------------
   Arithmetic stuff
  ----------------------------------------------------------------------------*/
#define sqr(A) ((A) * (A))
#define ln log

#define rad2deg(Rad) (_180_div_pi * (Rad))            //Radians to degrees
#define deg2rad(Deg) (_pi_div_180 * (Deg))            //Degrees to radians

#define test_2pN(A)  (((A) & ((A)-1)) == 0)           //Test if A is a 2^N number


/*----------------------------------------------------------------------------
   Functions
  ----------------------------------------------------------------------------*/


/*==== End of file ===========================================================*/
#endif
