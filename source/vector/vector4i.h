/*============================================================================*/
/*              Vector Operators, 4 Component, Integer Type                   */
/*                                                                            */
/* Dominik Deak                                                               */
/*============================================================================*/

/*---------------------------------------------------------------------------
   Don't include this file if it's already defined.   
  ---------------------------------------------------------------------------*/
#ifndef __VECTOR4I_H__
#define __VECTOR4I_H__


/*---------------------------------------------------------------------------
   Include libraries and other source files needed in this file.
  ---------------------------------------------------------------------------*/
#include "../common/common.h"


/*---------------------------------------------------------------------------
  The vector4i union class.
  ---------------------------------------------------------------------------*/
union vector4i
   {
   /*---- Member Data --------------------------------------------------------*/
   public:

   struct {int X, Y, Z, t;};
   struct {int U, V, S, T;};
   struct {int R, G, B, A;};
   int Comp[4];


   /*---- Member Functions ---------------------------------------------------*/
   inline vector4i(void);
   inline ~vector4i(void);
   
   inline vector4i(const int k);
   inline vector4i(const int Comp0, const int Comp1, const int Comp2, const int Comp3);
   inline vector4i(const vector4i &Vector);

   inline vector4i  Abs(void);
   inline vector4i &operator += (const vector4i &Vector);
   inline vector4i &operator += (const int k);
   inline vector4i  operator +  (const vector4i &Vector);
   inline vector4i  operator +  (const int k);

   inline vector4i  operator -  (void);
   inline vector4i &operator -= (const vector4i &Vector);
   inline vector4i &operator -= (const int k);
   inline vector4i  operator -  (const vector4i &Vector);
   inline vector4i  operator -  (int k);

   inline vector4i &operator *= (const vector4i &Vector);
   inline vector4i &operator *= (const int k);
   inline vector4i  operator *  (const vector4i &Vector);
   inline vector4i  operator *  (const int k);

   inline vector4i &operator /= (const vector4i &Vector);
   inline vector4i &operator /= (const int k);
   inline vector4i  operator /  (const vector4i &Vector);
   inline vector4i  operator /  (const int k);

   inline vector4i &operator %= (const vector4i &Vector);
   inline vector4i &operator %= (const int k);
   inline vector4i  operator %  (const vector4i &Vector);
   inline vector4i  operator %  (const int k);

   inline vector4i  operator ~  (void);

   inline vector4i &operator <<= (const vector4i &Vector);
   inline vector4i &operator <<= (const int k);
   inline vector4i  operator <<  (const vector4i &Vector);
   inline vector4i  operator <<  (const int k);

   inline vector4i &operator >>= (const vector4i &Vector);
   inline vector4i &operator >>= (const int k);
   inline vector4i  operator >>  (const vector4i &Vector);
   inline vector4i  operator >>  (const int k);

   inline vector4i &operator &= (const vector4i &Vector);
   inline vector4i &operator &= (const int k);
   inline vector4i  operator &  (const vector4i &Vector);
   inline vector4i  operator &  (const int k);

   inline vector4i &operator |= (const vector4i &Vector);
   inline vector4i &operator |= (const int k);
   inline vector4i  operator |  (const vector4i &Vector);
   inline vector4i  operator |  (const int k);

   inline vector4i &operator ^= (const vector4i &Vector);
   inline vector4i &operator ^= (const int k);
   inline vector4i  operator ^  (const vector4i &Vector);
   inline vector4i  operator ^  (const int k);

   inline vector4i  RotLeft(int k);
   inline vector4i  RotRight(int k);

   inline vector4i  Minimum(const vector4i &Vector);
   inline vector4i  Maximum(const vector4i &Vector);
   inline vector4i  Saturate(const int Min, const int Max);
   inline vector4i  Saturate(const vector4i &Min, const vector4i &Max);
   };


/*-------------------------------------------------------------------------
   Default constructor and destructor.
  -------------------------------------------------------------------------*/
inline vector4i::vector4i(void) {}
inline vector4i::~vector4i(void) {}

/*-------------------------------------------------------------------------
   Copy constant constructor.
  -------------------------------------------------------------------------*/
inline vector4i::vector4i(const int k)
   {
   Comp[0] = Comp[1] = Comp[2] = Comp[3] = k;
   }

/*-------------------------------------------------------------------------
   Copy [C0, C1, C2, C3] constructor.
  -------------------------------------------------------------------------*/
inline vector4i::vector4i(const int Comp0, const int Comp1, const int Comp2, const int Comp3)
   {
   Comp[0] = Comp0;
   Comp[1] = Comp1;
   Comp[2] = Comp2;
   Comp[3] = Comp3;
   }

/*-------------------------------------------------------------------------
   Copy vector4i constructor.
  -------------------------------------------------------------------------*/
inline vector4i::vector4i(const vector4i &Vector)
   {
   *this = Vector;
   }

/*-------------------------------------------------------------------------
   Return the absolute value.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::Abs(void)
   {
   return vector4i((int)labs(Comp[0]), (int)labs(Comp[1]), (int)labs(Comp[2]), (int)labs(Comp[3]));
   }

/*-------------------------------------------------------------------------
   Increment.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator += (const vector4i &Vector)
   {               
   Comp[0] += Vector.Comp[0];
   Comp[1] += Vector.Comp[1];
   Comp[2] += Vector.Comp[2];
   Comp[3] += Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Increment by a constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator += (const int k)
   {               
   Comp[0] += k;
   Comp[1] += k;
   Comp[2] += k;
   Comp[3] += k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Addition.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator + (const vector4i &Vector)
   {
   return vector4i(Comp[0] + Vector.Comp[0], Comp[1] + Vector.Comp[1], Comp[2] + Vector.Comp[2], Comp[3] + Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Add constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator + (const int k)
   {
   return vector4i(Comp[0] + k, Comp[1] + k, Comp[2] + k, Comp[3] + k);
   }

/*-------------------------------------------------------------------------
   Negate.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator - (void)
   {
   return vector4i(-Comp[0], -Comp[1], -Comp[2], -Comp[3]);
   }

/*-------------------------------------------------------------------------
   Decrement.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator -= (const vector4i &Vector)
   {
   Comp[0] -= Vector.Comp[0]; 
   Comp[1] -= Vector.Comp[1]; 
   Comp[2] -= Vector.Comp[2];
   Comp[3] -= Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Decrement by a constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator -= (const int k)
   {
   Comp[0] -= k; 
   Comp[1] -= k; 
   Comp[2] -= k;
   Comp[3] -= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Subtraction.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator - (const vector4i &Vector)
   {
   return vector4i(Comp[0] - Vector.Comp[0], Comp[1] - Vector.Comp[1], Comp[2] - Vector.Comp[2], Comp[3] - Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Subtraction by a constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator - (int k)
   {
   return vector4i(Comp[0] - k, Comp[1] - k, Comp[2] - k, Comp[3] - k);
   }

/*-------------------------------------------------------------------------
   Self multiply.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator *= (const vector4i &Vector)
   {
   Comp[0] *= Vector.Comp[0]; 
   Comp[1] *= Vector.Comp[1]; 
   Comp[2] *= Vector.Comp[2];
   Comp[3] *= Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Self multiply with constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator *= (const int k)
   {
   Comp[0] *= k; 
   Comp[1] *= k; 
   Comp[2] *= k;
   Comp[3] *= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Multiply.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator * (const vector4i &Vector)
   {
   return vector4i(Comp[0] * Vector.Comp[0], Comp[1] * Vector.Comp[1], Comp[2] * Vector.Comp[2], Comp[3] * Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Multiply with constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator * (const int k)
   {
   return vector4i(Comp[0] * k, Comp[1] * k, Comp[2] * k, Comp[3] * k);
   }

/*-------------------------------------------------------------------------
   Self divide.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator /= (const vector4i &Vector)
   {
   Comp[0] /= Vector.Comp[0]; 
   Comp[1] /= Vector.Comp[1]; 
   Comp[2] /= Vector.Comp[2];
   Comp[3] /= Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Self divide by a constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator /= (const int k)
   {
   Comp[0] /= k;
   Comp[1] /= k;
   Comp[2] /= k;
   Comp[3] /= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Divide.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator / (const vector4i &Vector)
   {
   return vector4i(Comp[0] / Vector.Comp[0], Comp[1] / Vector.Comp[1], Comp[2] / Vector.Comp[2], Comp[3] / Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Divide by a constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator / (const int k)
   {
   return vector4i(Comp[0] / k, Comp[1] / k, Comp[2] / k, Comp[3] / k);
   }

/*-------------------------------------------------------------------------
   Self modulus.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator %= (const vector4i &Vector)
   {
   Comp[0] %= Vector.Comp[0]; 
   Comp[1] %= Vector.Comp[1]; 
   Comp[2] %= Vector.Comp[2];
   Comp[3] %= Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Self modulus by a constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator %= (const int k)
   {
   Comp[0] %= k;
   Comp[1] %= k;
   Comp[2] %= k;
   Comp[3] %= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Modulus.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator % (const vector4i &Vector)
   {
   return vector4i(Comp[0] % Vector.Comp[0], Comp[1] % Vector.Comp[1], Comp[2] % Vector.Comp[2], Comp[3] % Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Modulus by a constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator % (const int k)
   {
   return vector4i(Comp[0] % k, Comp[1] % k, Comp[2] % k, Comp[3] % k);
   }

/*-------------------------------------------------------------------------
   Bitwise NOT.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator ~ (void)
   {
   return vector4i(~Comp[0], ~Comp[1], ~Comp[2], ~Comp[3]);
   }

/*-------------------------------------------------------------------------
   Self shift left.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator <<= (const vector4i &Vector)
   {
   Comp[0] <<= Vector.Comp[0]; 
   Comp[1] <<= Vector.Comp[1]; 
   Comp[2] <<= Vector.Comp[2];
   Comp[3] <<= Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Self shift left by a constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator <<= (const int k)
   {
   Comp[0] <<= k;
   Comp[1] <<= k;
   Comp[2] <<= k;
   Comp[3] <<= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Shift left.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator << (const vector4i &Vector)
   {
   return vector4i(Comp[0] << Vector.Comp[0], Comp[1] << Vector.Comp[1], Comp[2] << Vector.Comp[2], Comp[3] << Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Shift left by a constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator << (const int k)
   {
   return vector4i(Comp[0] << k, Comp[1] << k, Comp[2] << k, Comp[3] << k);
   }

/*-------------------------------------------------------------------------
   Self shift right.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator >>= (const vector4i &Vector)
   {
   Comp[0] >>= Vector.Comp[0]; 
   Comp[1] >>= Vector.Comp[1]; 
   Comp[2] >>= Vector.Comp[2];
   Comp[3] >>= Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Self shift right by a constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator >>= (const int k)
   {
   Comp[0] >>= k;
   Comp[1] >>= k;
   Comp[2] >>= k;
   Comp[3] >>= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Shift right.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator >> (const vector4i &Vector)
   {
   return vector4i(Comp[0] >> Vector.Comp[0], Comp[1] >> Vector.Comp[1], Comp[2] >> Vector.Comp[2], Comp[3] >> Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Shift right by a constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator >> (const int k)
   {
   return vector4i(Comp[0] >> k, Comp[1] >> k, Comp[2] >> k, Comp[3] >> k);
   }

/*-------------------------------------------------------------------------
   Self bitwise AND.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator &= (const vector4i &Vector)
   {
   Comp[0] &= Vector.Comp[0]; 
   Comp[1] &= Vector.Comp[1]; 
   Comp[2] &= Vector.Comp[2];
   Comp[3] &= Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Self bitwise AND by a constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator &= (const int k)
   {
   Comp[0] &= k;
   Comp[1] &= k;
   Comp[2] &= k;
   Comp[3] &= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Bitwise AND.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator & (const vector4i &Vector)
   {
   return vector4i(Comp[0] & Vector.Comp[0], Comp[1] & Vector.Comp[1], Comp[2] & Vector.Comp[2], Comp[3] & Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Bitwise AND by a constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator & (const int k)
   {
   return vector4i(Comp[0] & k, Comp[1] & k, Comp[2] & k, Comp[3] & k);
   }

/*-------------------------------------------------------------------------
   Self bitwise OR.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator |= (const vector4i &Vector)
   {
   Comp[0] |= Vector.Comp[0]; 
   Comp[1] |= Vector.Comp[1]; 
   Comp[2] |= Vector.Comp[2];
   Comp[3] |= Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Self bitwise OR by a constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator |= (const int k)
   {
   Comp[0] |= k;
   Comp[1] |= k;
   Comp[2] |= k;
   Comp[3] |= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Bitwise OR.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator | (const vector4i &Vector)
   {
   return vector4i(Comp[0] | Vector.Comp[0], Comp[1] | Vector.Comp[1], Comp[2] | Vector.Comp[2], Comp[3] | Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Bitwise OR by a constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator | (const int k)
   {
   return vector4i(Comp[0] | k, Comp[1] | k, Comp[2] | k, Comp[3] | k);
   }

/*-------------------------------------------------------------------------
   Self bitwise XOR.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator ^= (const vector4i &Vector)
   {
   Comp[0] ^= Vector.Comp[0]; 
   Comp[1] ^= Vector.Comp[1]; 
   Comp[2] ^= Vector.Comp[2];
   Comp[3] ^= Vector.Comp[3];
   return *this;
   }

/*-------------------------------------------------------------------------
   Self bitwise XOR by a constant.
  -------------------------------------------------------------------------*/
inline vector4i &vector4i::operator ^= (const int k)
   {
   Comp[0] ^= k;
   Comp[1] ^= k;
   Comp[2] ^= k;
   Comp[3] ^= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Bitwise XOR.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator ^ (const vector4i &Vector)
   {
   return vector4i(Comp[0] ^ Vector.Comp[0], Comp[1] ^ Vector.Comp[1], Comp[2] ^ Vector.Comp[2], Comp[3] ^ Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Bitwise XOR by a constant.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::operator ^ (const int k)
   {
   return vector4i(Comp[0] ^ k, Comp[1] ^ k, Comp[2] ^ k, Comp[3] ^ k);
   }

/*-------------------------------------------------------------------------
   Bit rotate left by k.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::RotLeft(int k)
   {
   #if defined (WIN32) || defined (WIN64)
      return vector4i(_rotl(Comp[0], k), _rotl(Comp[1], k), _rotl(Comp[2], k), _rotl(Comp[3], k));
   #else
      register int ik = sizeof(int)*8 - k;
      return vector4i(((unsigned int)Comp[0] >> ik) | (Comp[0] << k), 
                      ((unsigned int)Comp[1] >> ik) | (Comp[1] << k),
                      ((unsigned int)Comp[2] >> ik) | (Comp[2] << k),
                      ((unsigned int)Comp[3] >> ik) | (Comp[3] << k));
   #endif
   }

/*-------------------------------------------------------------------------
   Bit rotate right by k.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::RotRight(int k)
   {
   #if defined (WIN32) || defined (WIN64)
      return vector4i(_rotr(Comp[0], k), _rotr(Comp[1], k), _rotr(Comp[2], k), _rotr(Comp[3], k));
   #else
      register int ik = sizeof(int)*8 - k;
      return vector4i((Comp[0] << ik) | ((unsigned int)Comp[0] >> k), 
                      (Comp[1] << ik) | ((unsigned int)Comp[1] >> k),
                      (Comp[2] << ik) | ((unsigned int)Comp[2] >> k),
                      (Comp[3] << ik) | ((unsigned int)Comp[3] >> k));
   #endif
   }

/*-------------------------------------------------------------------------
   Returns the minimum.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::Minimum(const vector4i &Vector)
   {
   return vector4i(((Comp[0] < Vector.Comp[0]) ? Comp[0] : Vector.Comp[0]),
                   ((Comp[1] < Vector.Comp[1]) ? Comp[1] : Vector.Comp[1]),  
                   ((Comp[2] < Vector.Comp[2]) ? Comp[2] : Vector.Comp[2]),  
                   ((Comp[3] < Vector.Comp[3]) ? Comp[3] : Vector.Comp[3]));
   }

/*-------------------------------------------------------------------------
   Returns the maximum.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::Maximum(const vector4i &Vector)
   {
   return vector4i(((Comp[0] > Vector.Comp[0]) ? Comp[0] : Vector.Comp[0]),
                   ((Comp[1] > Vector.Comp[1]) ? Comp[1] : Vector.Comp[1]),  
                   ((Comp[2] > Vector.Comp[2]) ? Comp[2] : Vector.Comp[2]),  
                   ((Comp[3] > Vector.Comp[3]) ? Comp[3] : Vector.Comp[3]));
   }

/*-------------------------------------------------------------------------
   Saturate the values by a constants.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::Saturate(const int Min, const int Max)
   {
   return vector4i((Comp[0] > Max) ? Max : ((Comp[0] < Min) ? Min : Comp[0]),
                   (Comp[1] > Max) ? Max : ((Comp[1] < Min) ? Min : Comp[1]),
                   (Comp[2] > Max) ? Max : ((Comp[2] < Min) ? Min : Comp[2]),
                   (Comp[3] > Max) ? Max : ((Comp[3] < Min) ? Min : Comp[3]));
   }

/*-------------------------------------------------------------------------
   Saturate the values.
  -------------------------------------------------------------------------*/
inline vector4i vector4i::Saturate(const vector4i &Min, const vector4i &Max)
   {
   return vector4i((Comp[0] > Max.Comp[0]) ? Max.Comp[0] : ((Comp[0] < Min.Comp[0]) ? Min.Comp[0] : Comp[0]),
                   (Comp[1] > Max.Comp[1]) ? Max.Comp[1] : ((Comp[1] < Min.Comp[1]) ? Min.Comp[1] : Comp[1]),
                   (Comp[2] > Max.Comp[2]) ? Max.Comp[2] : ((Comp[2] < Min.Comp[2]) ? Min.Comp[2] : Comp[2]),
                   (Comp[3] > Max.Comp[3]) ? Max.Comp[3] : ((Comp[3] < Min.Comp[3]) ? Min.Comp[3] : Comp[3]));
   }


/*==== End of file ===========================================================*/
#endif
