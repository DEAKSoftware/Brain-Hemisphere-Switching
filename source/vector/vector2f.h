/*============================================================================*/
/*            Vector Operators, 2 Component, Floating Point Type              */
/*                                                                            */
/* Dominik Deak                                                               */
/*============================================================================*/

/*---------------------------------------------------------------------------
   Don't include this file if it's already defined.   
  ---------------------------------------------------------------------------*/
#ifndef __VECTOR2F_H__
#define __VECTOR2F_H__


/*---------------------------------------------------------------------------
   Include libraries and other source files needed in this file.
  ---------------------------------------------------------------------------*/
#include "../common/common.h"


/*---------------------------------------------------------------------------
  The vector2f union class.
  ---------------------------------------------------------------------------*/
union vector2f
   {
   /*---- Member Data --------------------------------------------------------*/
   public:

   struct {float X, Y;};
   struct {float U, V;};
   float Comp[2];


   /*---- Member Functions ---------------------------------------------------*/
   inline vector2f(void);
   inline ~vector2f(void);
   
   inline vector2f(const float k);
   inline vector2f(const float Comp0, const float Comp1);
   inline vector2f(const vector2f &Vector);

   inline vector2f  Abs(void);
   inline vector2f &operator += (const vector2f &Vector);
   inline vector2f &operator += (const float k);
   inline vector2f  operator +  (const vector2f &Vector);
   inline vector2f  operator +  (const float k);

   inline vector2f  operator -  (void);
   inline vector2f &operator -= (const vector2f &Vector);
   inline vector2f &operator -= (const float k);
   inline vector2f  operator -  (const vector2f &Vector);
   inline vector2f  operator -  (float k);

   inline vector2f &operator *= (const vector2f &Vector);
   inline vector2f &operator *= (const float k);
   inline vector2f  operator *  (const vector2f &Vector);
   inline vector2f  operator *  (const float k);

   inline vector2f &operator /= (const vector2f &Vector);
   inline vector2f &operator /= (const float k);
   inline vector2f  operator /  (const vector2f &Vector);
   inline vector2f  operator /  (const float k);

   inline vector2f &operator %= (const vector2f &Vector);
   inline vector2f &operator %= (const float k);
   inline vector2f  operator %  (const vector2f &Vector);
   inline vector2f  operator %  (const float k);

   inline vector2f  Minimum(const vector2f &Vector);
   inline vector2f  Maximum(const vector2f &Vector);
   inline vector2f  Saturate(const float Min, const float Max);
   inline vector2f  Saturate(const vector2f &Min, const vector2f &Max);
  
   inline float     MagSqr(void) const;
   inline float     Mag(void) const;
   inline vector2f  Unit(void);
   inline float     Dot(const vector2f &Vector);

   inline float     COS(const vector2f &Vector);
   inline float     AngleCOS(const vector2f &Vector);
   inline float     AngleDot(const vector2f &Vector);
   inline vector2f  Rotate(const vector2f &Rad);
   inline vector2f  Rotate(const vector2f &Rad, const vector2f &Center);
   };


/*-------------------------------------------------------------------------
   Default constructor and destructor.
  -------------------------------------------------------------------------*/
inline vector2f::vector2f(void) {}
inline vector2f::~vector2f(void) {}

/*-------------------------------------------------------------------------
   Copy constant constructor.
  -------------------------------------------------------------------------*/
inline vector2f::vector2f(const float k)
   {
   Comp[0] = Comp[1] = k;
   }

/*-------------------------------------------------------------------------
   Copy [C0, C1, C2, C3] constructor.
  -------------------------------------------------------------------------*/
inline vector2f::vector2f(const float Comp0, const float Comp1)
   {
   Comp[0] = Comp0;
   Comp[1] = Comp1;
   }

/*-------------------------------------------------------------------------
   Copy vector2f constructor.
  -------------------------------------------------------------------------*/
inline vector2f::vector2f(const vector2f &Vector)
   {
   *this = Vector;
   }

/*-------------------------------------------------------------------------
   Return the absolute value.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::Abs(void)
   {
   return vector2f((float)fabs(Comp[0]), (float)fabs(Comp[1]));
   }

/*-------------------------------------------------------------------------
   Increment.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator += (const vector2f &Vector)
   {               
   Comp[0] += Vector.Comp[0];
   Comp[1] += Vector.Comp[1];
   return *this;
   }

/*-------------------------------------------------------------------------
   Increment by a constant.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator += (const float k)
   {               
   Comp[0] += k;
   Comp[1] += k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Addition.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator + (const vector2f &Vector)
   {
   return vector2f(Comp[0] + Vector.Comp[0], Comp[1] + Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Add constant.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator + (const float k)
   {
   return vector2f(Comp[0] + k, Comp[1] + k);
   }

/*-------------------------------------------------------------------------
   Negate.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator - (void)
   {
   return vector2f(-Comp[0], -Comp[1]);
   }

/*-------------------------------------------------------------------------
   Decrement.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator -= (const vector2f &Vector)
   {
   Comp[0] -= Vector.Comp[0]; 
   Comp[1] -= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Decrement by a constant.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator -= (const float k)
   {
   Comp[0] -= k; 
   Comp[1] -= k; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Subtraction.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator - (const vector2f &Vector)
   {
   return vector2f(Comp[0] - Vector.Comp[0], Comp[1] - Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Subtraction by a constant.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator - (float k)
   {
   return vector2f(Comp[0] - k, Comp[1] - k);
   }

/*-------------------------------------------------------------------------
   Self multiply.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator *= (const vector2f &Vector)
   {
   Comp[0] *= Vector.Comp[0]; 
   Comp[1] *= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self multiply with constant.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator *= (const float k)
   {
   Comp[0] *= k; 
   Comp[1] *= k; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Multiply.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator * (const vector2f &Vector)
   {
   return vector2f(Comp[0] * Vector.Comp[0], Comp[1] * Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Multiply with constant.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator * (const float k)
   {
   return vector2f(Comp[0] * k, Comp[1] * k);
   }

/*-------------------------------------------------------------------------
   Self divide.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator /= (const vector2f &Vector)
   {
   Comp[0] /= Vector.Comp[0]; 
   Comp[1] /= Vector.Comp[1]; 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self divide by a constant.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator /= (const float k)
   {
   Comp[0] /= k;
   Comp[1] /= k;
   return *this;
   }

/*-------------------------------------------------------------------------
   Divide.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator / (const vector2f &Vector)
   {
   return vector2f(Comp[0] / Vector.Comp[0], Comp[1] / Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Divide by a constant.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator / (const float k)
   {
   return vector2f(Comp[0] / k, Comp[1] / k);
   }

/*-------------------------------------------------------------------------
   Self modulus.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator %= (const vector2f &Vector)
   {
   Comp[0] = (float)fmod(Comp[0], Vector.Comp[0]); 
   Comp[1] = (float)fmod(Comp[1], Vector.Comp[1]); 
   return *this;
   }

/*-------------------------------------------------------------------------
   Self modulus by a constant.
  -------------------------------------------------------------------------*/
inline vector2f &vector2f::operator %= (const float k)
   {
   Comp[0] = (float)fmod(Comp[0], k); 
   Comp[1] = (float)fmod(Comp[1], k); 
   return *this;
   }

/*-------------------------------------------------------------------------
   Modulus.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator % (const vector2f &Vector)
   {
   return vector2f((float)fmod(Comp[0], Vector.Comp[0]), 
                   (float)fmod(Comp[1], Vector.Comp[1]));
   }

/*-------------------------------------------------------------------------
   Modulus by a constant.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::operator % (const float k)
   {
   return vector2f((float)fmod(Comp[0], k), (float)fmod(Comp[1], k));
   }

/*-------------------------------------------------------------------------
   Returns the minimum.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::Minimum(const vector2f &Vector)
   {
   return vector2f(((Comp[0] < Vector.Comp[0]) ? Comp[0] : Vector.Comp[0]),
                   ((Comp[1] < Vector.Comp[1]) ? Comp[1] : Vector.Comp[1]));
   }

/*-------------------------------------------------------------------------
   Returns the maximum.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::Maximum(const vector2f &Vector)
   {
   return vector2f(((Comp[0] > Vector.Comp[0]) ? Comp[0] : Vector.Comp[0]),
                   ((Comp[1] > Vector.Comp[1]) ? Comp[1] : Vector.Comp[1]));
   }

/*-------------------------------------------------------------------------
   Saturate the values by a constants.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::Saturate(const float Min, const float Max)
   {
   return vector2f((Comp[0] > Max) ? Max : ((Comp[0] < Min) ? Min : Comp[0]),
                   (Comp[1] > Max) ? Max : ((Comp[1] < Min) ? Min : Comp[1]));
   }

/*-------------------------------------------------------------------------
   Saturate the values.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::Saturate(const vector2f &Min, const vector2f &Max)
   {
   return vector2f((Comp[0] > Max.Comp[0]) ? Max.Comp[0] : ((Comp[0] < Min.Comp[0]) ? Min.Comp[0] : Comp[0]),
                   (Comp[1] > Max.Comp[1]) ? Max.Comp[1] : ((Comp[1] < Min.Comp[1]) ? Min.Comp[1] : Comp[1]));
   }

/*-------------------------------------------------------------------------
   Find the 2D magnitude squared.
  -------------------------------------------------------------------------*/
inline float vector2f::MagSqr(void) const
   {
   return (Comp[0]*Comp[0] + Comp[1]*Comp[1]);
   }

/*-------------------------------------------------------------------------
   Find the 2D magnitude.
  -------------------------------------------------------------------------*/
inline float vector2f::Mag(void) const
   {
   return (float)sqrt(Comp[0]*Comp[0] + Comp[1]*Comp[1]);
   }

/*-------------------------------------------------------------------------
   Find the 2D unit vector.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::Unit(void)
   {
   CACHE_ALIGN_16 register float Magnitude = this->Mag();
   return (Magnitude != 0.0) ? (*this * (1.0f / Magnitude)) : *this;
   }

/*-------------------------------------------------------------------------
   Returns the 2D dot product of *this and Vector.
  -------------------------------------------------------------------------*/
inline float vector2f::Dot(const vector2f &Vector)
   {
   return (Comp[0]*Vector.Comp[0] + Comp[1]*Vector.Comp[1]);
   }

/*-------------------------------------------------------------------------
   Returns the cosine value between the 2D vectors *this and Vector. To 
   find the angle, the inverse of COS must be applied on this function's 
   result.
  -------------------------------------------------------------------------*/
inline float vector2f::COS(const vector2f &Vector)
   {
   return (this->Dot(Vector) / (this->Mag() * Vector.Mag()));
   }

/*-------------------------------------------------------------------------
   Returns the angle (in radians) between the 2D vectors *this and Vector.
  -------------------------------------------------------------------------*/
inline float vector2f::AngleCOS(const vector2f &Vector)
   {
   return (float)acos(this->COS(Vector));
   }

/*-------------------------------------------------------------------------
   Returns the angle (in radians) between the 2D vectors *this and Point. 
   It uses the dot product to calculate the angle, and therefore operator
   will work only on unit vectors.
  -------------------------------------------------------------------------*/
inline float vector2f::AngleDot(const vector2f &Vector)
   {
   return (float)acos(this->Dot(Vector));
   }

/*-------------------------------------------------------------------------
   Rotates *this 2D point by Rad (in radians) around the point [0, 0]. 
  -------------------------------------------------------------------------*/
inline vector2f vector2f::Rotate(const vector2f &Rad)
   {

/*** fix ***/

   return *this;
   }

/*-------------------------------------------------------------------------
   Rotates *this 3D point by Rad (in radians) around the point C.
  -------------------------------------------------------------------------*/
inline vector2f vector2f::Rotate(const vector2f &Rad, const vector2f &Center)
   {
   *this -= Center;
   return this->Rotate(Rad) + Center;
   }


/*==== End of file ===========================================================*/
#endif
