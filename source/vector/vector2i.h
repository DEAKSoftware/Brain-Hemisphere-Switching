/*============================================================================*/
/*              Vector Operators, 2 Component, Integer Type                   */
/*                                                                            */
/* Dominik Deak                                                               */
/*============================================================================*/

/*---------------------------------------------------------------------------
   Don't include this file if it's already defined.   
  ---------------------------------------------------------------------------*/
#ifndef __VECTOR2I_H__
#define __VECTOR2I_H__


/*---------------------------------------------------------------------------
   Include libraries and other source files needed in this file.
  ---------------------------------------------------------------------------*/
#include "../common/common.h"


/*---------------------------------------------------------------------------
  The vector2i union class.
  ---------------------------------------------------------------------------*/
union vector2i
   {
   /*---- Member Data --------------------------------------------------------*/
   public:

   struct {int X, Y;};
   struct {int U, V;};
   int Comp[2];


   /*---- Member Functions ---------------------------------------------------*/
   inline vector2i(void);
   inline ~vector2i(void);
   
   inline vector2i(const int k);
   inline vector2i(const int Comp0, const int Comp1);
   inline vector2i(const vector2i &Vector);

   inline vector2i  Abs(void);
   inline vector2i &operator += (const vector2i &Vector);
   inline vector2i &operator += (const int k);
   inline vector2i  operator +  (const vector2i &Vector);
   inline vector2i  operator +  (const int k);

   inline vector2i  operator -  (void);
   inline vector2i &operator -= (const vector2i &Vector);
   inline vector2i &operator -= (const int k);
   inline vector2i  operator -  (const vector2i &Vector);
   inline vector2i  operator -  (int k);

   inline vector2i &operator *= (const vector2i &Vector);
   inline vector2i &operator *= (const int k);
   inline vector2i  operator *  (const vector2i &Vector);
   inline vector2i  operator *  (const int k);

   inline vector2i &operator /= (const vector2i &Vector);
   inline vector2i &operator /= (const int k);
   inline vector2i  operator /  (const vector2i &Vector);
   inline vector2i  operator /  (const int k);

   inline vector2i &operator %= (const vector2i &Vector);
   inline vector2i &operator %= (const int k);
   inline vector2i  operator %  (const vector2i &Vector);
   inline vector2i  operator %  (const int k);

   inline vector2i  operator ~  (void);

   inline vector2i &operator <<= (const vector2i &Vector);
   inline vector2i &operator <<= (const int k);
   inline vector2i  operator <<  (const vector2i &Vector);
   inline vector2i  operator <<  (const int k);

   inline vector2i &operator >>= (const vector2i &Vector);
   inline vector2i &operator >>= (const int k);
   inline vector2i  operator >>  (const vector2i &Vector);
   inline vector2i  operator >>  (const int k);

   inline vector2i &operator &= (const vector2i &Vector);
   inline vector2i &operator &= (const int k);
   inline vector2i  operator &  (const vector2i &Vector);
   inline vector2i  operator &  (const int k);

   inline vector2i &operator |= (const vector2i &Vector);
   inline vector2i &operator |= (const int k);
   inline vector2i  operator |  (const vector2i &Vector);
   inline vector2i  operator |  (const int k);

   inline vector2i &operator ^= (const vector2i &Vector);
   inline vector2i &operator ^= (const int k);
   inline vector2i  operator ^  (const vector2i &Vector);
   inline vector2i  operator ^  (const int k);

   inline vector2i  RotLeft(int k);
   inline vector2i  RotRight(int k);

   inline vector2i  Minimum(const vector2i &Vector);
   inline vector2i  Maximum(const vector2i &Vector);
   inline vector2i  Saturate(const int Min, const int Max);
   inline vector2i  Saturate(const vector2i &Min, const vector2i &Max);
   };


/*-------------------------------------------------------------------------
   Default constructor and destructor.
  -------------------------------------------------------------------------*/
inline vector2i::vector2i(void) {}
inline vector2i::~vector2i(void) {}

/*-------------------------------------------------------------------------
   Copy constant constructor.
  -------------------------------------------------------------------------*/
inline vector2i::vector2i(const int k)
   {
   Comp[0] = Comp[1] = k;
   }

/*-------------------------------------------------------------------------
   Copy [C0, C1] constructor.
  -------------------------------------------------------------------------*/
inline vector2i::vector2i(const int Comp0, const int Comp1)
   {
   Comp[0] = Comp0;
   Comp[1] = Comp1;
   }

/*-------------------------------------------------------------------------
   Copy vector2i constructor.
  -------------------------------------------------------------------------*/
inline vector2i::vector2i(const vector2i &Vector)
   {
   *this = Vector;
   }

/*-------------------------------------------------------------------------
   Return the absolute value.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::Abs(void)
   {
   return vector2i((int)labs(Comp[0]), (int)labs(Comp[1]));
   }

/*-------------------------------------------------------------------------
   Increment.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator += (const vector2i &Vector)
   {               
   Comp[0] += Vector.Comp[0];
   Comp[1] += Vector.Comp[1];
   return *this;
   }

/*-------------------------------------------------------------------------
   Increment by a constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator += (const int k)
   {               
   Comp[0] += k;
   Comp[1] += k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Addition.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator + (const vector2i &Vector)
   {
   return vector2i(Comp[0] + Vector.Comp[0], Comp[1] + Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Add constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator + (const int k)
   {
   return vector2i(Comp[0] + k, Comp[1] + k);
   }

/*-------------------------------------------------------------------------
   Negate.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator - (void)
   {
   return vector2i(-Comp[0], -Comp[1]);
   }

/*-------------------------------------------------------------------------
   Decrement.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator -= (const vector2i &Vector)
   {
   Comp[0] -= Vector.Comp[0]; 
   Comp[1] -= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Decrement by a constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator -= (const int k)
   {
   Comp[0] -= k; 
   Comp[1] -= k; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Subtraction.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator - (const vector2i &Vector)
   {
   return vector2i(Comp[0] - Vector.Comp[0], Comp[1] - Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Subtraction by a constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator - (int k)
   {
   return vector2i(Comp[0] - k, Comp[1] - k);
   }

/*-------------------------------------------------------------------------
   Self multiply.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator *= (const vector2i &Vector)
   {
   Comp[0] *= Vector.Comp[0]; 
   Comp[1] *= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self multiply with constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator *= (const int k)
   {
   Comp[0] *= k; 
   Comp[1] *= k; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Multiply.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator * (const vector2i &Vector)
   {
   return vector2i(Comp[0] * Vector.Comp[0], Comp[1] * Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Multiply with constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator * (const int k)
   {
   return vector2i(Comp[0] * k, Comp[1] * k);
   }

/*-------------------------------------------------------------------------
   Self divide.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator /= (const vector2i &Vector)
   {
   Comp[0] /= Vector.Comp[0]; 
   Comp[1] /= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self divide by a constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator /= (const int k)
   {
   Comp[0] /= k;
   Comp[1] /= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Divide.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator / (const vector2i &Vector)
   {
   return vector2i(Comp[0] / Vector.Comp[0], Comp[1] / Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Divide by a constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator / (const int k)
   {
   return vector2i(Comp[0] / k, Comp[1] / k);
   }

/*-------------------------------------------------------------------------
   Self modulus.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator %= (const vector2i &Vector)
   {
   Comp[0] %= Vector.Comp[0]; 
   Comp[1] %= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self modulus by a constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator %= (const int k)
   {
   Comp[0] %= k;
   Comp[1] %= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Modulus.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator % (const vector2i &Vector)
   {
   return vector2i(Comp[0] % Vector.Comp[0], Comp[1] % Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Modulus by a constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator % (const int k)
   {
   return vector2i(Comp[0] % k, Comp[1] % k);
   }

/*-------------------------------------------------------------------------
   Bitwise NOT.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator ~ (void)
   {
   return vector2i(~Comp[0], ~Comp[1]);
   }

/*-------------------------------------------------------------------------
   Self shift left.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator <<= (const vector2i &Vector)
   {
   Comp[0] <<= Vector.Comp[0]; 
   Comp[1] <<= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self shift left by a constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator <<= (const int k)
   {
   Comp[0] <<= k;
   Comp[1] <<= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Shift left.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator << (const vector2i &Vector)
   {
   return vector2i(Comp[0] << Vector.Comp[0], Comp[1] << Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Shift left by a constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator << (const int k)
   {
   return vector2i(Comp[0] << k, Comp[1] << k);
   }

/*-------------------------------------------------------------------------
   Self shift right.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator >>= (const vector2i &Vector)
   {
   Comp[0] >>= Vector.Comp[0]; 
   Comp[1] >>= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self shift right by a constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator >>= (const int k)
   {
   Comp[0] >>= k;
   Comp[1] >>= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Shift right.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator >> (const vector2i &Vector)
   {
   return vector2i(Comp[0] >> Vector.Comp[0], Comp[1] >> Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Shift right by a constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator >> (const int k)
   {
   return vector2i(Comp[0] >> k, Comp[1] >> k);
   }

/*-------------------------------------------------------------------------
   Self bitwise AND.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator &= (const vector2i &Vector)
   {
   Comp[0] &= Vector.Comp[0]; 
   Comp[1] &= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self bitwise AND by a constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator &= (const int k)
   {
   Comp[0] &= k;
   Comp[1] &= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Bitwise AND.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator & (const vector2i &Vector)
   {
   return vector2i(Comp[0] & Vector.Comp[0], Comp[1] & Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Bitwise AND by a constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator & (const int k)
   {
   return vector2i(Comp[0] & k, Comp[1] & k);
   }

/*-------------------------------------------------------------------------
   Self bitwise OR.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator |= (const vector2i &Vector)
   {
   Comp[0] |= Vector.Comp[0]; 
   Comp[1] |= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self bitwise OR by a constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator |= (const int k)
   {
   Comp[0] |= k;
   Comp[1] |= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Bitwise OR.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator | (const vector2i &Vector)
   {
   return vector2i(Comp[0] | Vector.Comp[0], Comp[1] | Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Bitwise OR by a constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator | (const int k)
   {
   return vector2i(Comp[0] | k, Comp[1] | k);
   }

/*-------------------------------------------------------------------------
   Self bitwise XOR.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator ^= (const vector2i &Vector)
   {
   Comp[0] ^= Vector.Comp[0]; 
   Comp[1] ^= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self bitwise XOR by a constant.
  -------------------------------------------------------------------------*/
inline vector2i &vector2i::operator ^= (const int k)
   {
   Comp[0] ^= k;
   Comp[1] ^= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Bitwise XOR.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator ^ (const vector2i &Vector)
   {
   return vector2i(Comp[0] ^ Vector.Comp[0], Comp[1] ^ Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Bitwise XOR by a constant.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::operator ^ (const int k)
   {
   return vector2i(Comp[0] ^ k, Comp[1] ^ k);
   }

/*-------------------------------------------------------------------------
   Bit rotate left by k.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::RotLeft(int k)
   {
   #if defined (WIN32) || defined (WIN64)
      return vector2i(_rotl(Comp[0], k), _rotl(Comp[1], k));
   #else
      register int ik = sizeof(int)*8 - k;
      return vector2i(((unsigned int)Comp[0] >> ik) | (Comp[0] << k), 
                      ((unsigned int)Comp[1] >> ik) | (Comp[1] << k));
   #endif
   }

/*-------------------------------------------------------------------------
   Bit rotate right by k.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::RotRight(int k)
   {
   #if defined (WIN32) || defined (WIN64)
      return vector2i(_rotr(Comp[0], k), _rotr(Comp[1], k));
   #else
      register int ik = sizeof(int)*8 - k;
      return vector2i((Comp[0] << ik) | ((unsigned int)Comp[0] >> k), 
                      (Comp[1] << ik) | ((unsigned int)Comp[1] >> k));
   #endif
   }

/*-------------------------------------------------------------------------
   Returns the minimum.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::Minimum(const vector2i &Vector)
   {
   return vector2i(((Comp[0] < Vector.Comp[0]) ? Comp[0] : Vector.Comp[0]),
                   ((Comp[1] < Vector.Comp[1]) ? Comp[1] : Vector.Comp[1]));
   }

/*-------------------------------------------------------------------------
   Returns the maximum.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::Maximum(const vector2i &Vector)
   {
   return vector2i(((Comp[0] > Vector.Comp[0]) ? Comp[0] : Vector.Comp[0]),
                   ((Comp[1] > Vector.Comp[1]) ? Comp[1] : Vector.Comp[1]));
   }

/*-------------------------------------------------------------------------
   Saturate the values by a constants.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::Saturate(const int Min, const int Max)
   {
   return vector2i((Comp[0] > Max) ? Max : ((Comp[0] < Min) ? Min : Comp[0]),
                   (Comp[1] > Max) ? Max : ((Comp[1] < Min) ? Min : Comp[1]));
   }

/*-------------------------------------------------------------------------
   Saturate the values.
  -------------------------------------------------------------------------*/
inline vector2i vector2i::Saturate(const vector2i &Min, const vector2i &Max)
   {
   return vector2i((Comp[0] > Max.Comp[0]) ? Max.Comp[0] : ((Comp[0] < Min.Comp[0]) ? Min.Comp[0] : Comp[0]),
                   (Comp[1] > Max.Comp[1]) ? Max.Comp[1] : ((Comp[1] < Min.Comp[1]) ? Min.Comp[1] : Comp[1]));
   }


/*==== End of file ===========================================================*/
#endif
