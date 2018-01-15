/*============================================================================*/
/*            Vector Operators, 4 Component, Floating Point Type              */
/*                                                                            */
/* Dominik Deak                                                               */
/*============================================================================*/

/*---------------------------------------------------------------------------
   Don't include this file if it's already defined.   
  ---------------------------------------------------------------------------*/
#ifndef __VECTOR4F_H__
#define __VECTOR4F_H__


/*---------------------------------------------------------------------------
   Include libraries and other source files needed in this file.
  ---------------------------------------------------------------------------*/
#include "../common/common.h"


/*---------------------------------------------------------------------------
  The vector4f union class.
  ---------------------------------------------------------------------------*/
union vector4f
   {
   /*---- Member Data --------------------------------------------------------*/
   public:

   struct {float X, Y, Z, t;};
   struct {float U, V, S, T;};
   struct {float R, G, B, A;};
   float Comp[4];


   /*---- Member Functions ---------------------------------------------------*/
   inline vector4f(void);
   inline ~vector4f(void);
   
   inline vector4f(const float k);
   inline vector4f(const float Comp0, const float Comp1, const float Comp2, const float Comp3);
   inline vector4f(const vector4f &Vector);

   inline vector4f  Abs(void);
   inline vector4f &operator += (const vector4f &Vector);
   inline vector4f &operator += (const float k);
   inline vector4f  operator +  (const vector4f &Vector);
   inline vector4f  operator +  (const float k);

   inline vector4f  operator -  (void);
   inline vector4f &operator -= (const vector4f &Vector);
   inline vector4f &operator -= (const float k);
   inline vector4f  operator -  (const vector4f &Vector);
   inline vector4f  operator -  (float k);

   inline vector4f &operator *= (const vector4f &Vector);
   inline vector4f &operator *= (const float k);
   inline vector4f  operator *  (const vector4f &Vector);
   inline vector4f  operator *  (const float k);

   inline vector4f &operator /= (const vector4f &Vector);
   inline vector4f &operator /= (const float k);
   inline vector4f  operator /  (const vector4f &Vector);
   inline vector4f  operator /  (const float k);

   inline vector4f &operator %= (const vector4f &Vector);
   inline vector4f &operator %= (const float k);
   inline vector4f  operator %  (const vector4f &Vector);
   inline vector4f  operator %  (const float k);

   inline vector4f  Minimum(const vector4f &Vector);
   inline vector4f  Maximum(const vector4f &Vector);
   inline vector4f  Saturate(const float Min, const float Max);
   inline vector4f  Saturate(const vector4f &Min, const vector4f &Max);
  
   //Note: The remaining functions are 3D operators
   inline float     MagSqr(void) const;
   inline float     Mag(void) const;
   inline vector4f  Unit(void);
   inline float     Dot(const vector4f &Vector);
   inline vector4f  Cross(const vector4f &Vector);

   inline float     COS(const vector4f &Vector);
   inline float     AngleCOS(const vector4f &Vector);
   inline float     AngleDot(const vector4f &Vector);
   inline vector4f  Rotate(const vector4f &Rad);
   inline vector4f  Rotate(const vector4f &Rad, const vector4f &Center);
   };


/*-------------------------------------------------------------------------
   Default constructor and destructor.
  -------------------------------------------------------------------------*/
inline vector4f::vector4f(void) {}
inline vector4f::~vector4f(void) {}

/*-------------------------------------------------------------------------
   Copy constant constructor.
  -------------------------------------------------------------------------*/
inline vector4f::vector4f(const float k)
   {
   Comp[0] = Comp[1] = Comp[2] = Comp[3] = k;
   }

/*-------------------------------------------------------------------------
   Copy [C0, C1, C2, C3] constructor.
  -------------------------------------------------------------------------*/
inline vector4f::vector4f(const float Comp0, const float Comp1, const float Comp2, const float Comp3)
   {
   Comp[0] = Comp0;
   Comp[1] = Comp1;
   Comp[2] = Comp2;
   Comp[3] = Comp3;
   }

/*-------------------------------------------------------------------------
   Copy vector4f constructor.
  -------------------------------------------------------------------------*/
inline vector4f::vector4f(const vector4f &Vector)
   {
   *this = Vector;
   }

/*-------------------------------------------------------------------------
   Return the absolute value.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::Abs(void)
   {
   return vector4f((float)fabs(Comp[0]), (float)fabs(Comp[1]), (float)fabs(Comp[2]), (float)fabs(Comp[3]));
   }

/*-------------------------------------------------------------------------
   Increment.
  -------------------------------------------------------------------------*/
inline vector4f &vector4f::operator += (const vector4f &Vector)
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
inline vector4f &vector4f::operator += (const float k)
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
inline vector4f vector4f::operator + (const vector4f &Vector)
   {
   return vector4f(Comp[0] + Vector.Comp[0], Comp[1] + Vector.Comp[1], Comp[2] + Vector.Comp[2], Comp[3] + Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Add constant.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::operator + (const float k)
   {
   return vector4f(Comp[0] + k, Comp[1] + k, Comp[2] + k, Comp[3] + k);
   }

/*-------------------------------------------------------------------------
   Negate.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::operator - (void)
   {
   return vector4f(-Comp[0], -Comp[1], -Comp[2], -Comp[3]);
   }

/*-------------------------------------------------------------------------
   Decrement.
  -------------------------------------------------------------------------*/
inline vector4f &vector4f::operator -= (const vector4f &Vector)
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
inline vector4f &vector4f::operator -= (const float k)
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
inline vector4f vector4f::operator - (const vector4f &Vector)
   {
   return vector4f(Comp[0] - Vector.Comp[0], Comp[1] - Vector.Comp[1], Comp[2] - Vector.Comp[2], Comp[3] - Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Subtraction by a constant.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::operator - (float k)
   {
   return vector4f(Comp[0] - k, Comp[1] - k, Comp[2] - k, Comp[3] - k);
   }

/*-------------------------------------------------------------------------
   Self multiply.
  -------------------------------------------------------------------------*/
inline vector4f &vector4f::operator *= (const vector4f &Vector)
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
inline vector4f &vector4f::operator *= (const float k)
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
inline vector4f vector4f::operator * (const vector4f &Vector)
   {
   return vector4f(Comp[0] * Vector.Comp[0], Comp[1] * Vector.Comp[1], Comp[2] * Vector.Comp[2], Comp[3] * Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Multiply with constant.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::operator * (const float k)
   {
   return vector4f(Comp[0] * k, Comp[1] * k, Comp[2] * k, Comp[3] * k);
   }

/*-------------------------------------------------------------------------
   Self divide.
  -------------------------------------------------------------------------*/
inline vector4f &vector4f::operator /= (const vector4f &Vector)
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
inline vector4f &vector4f::operator /= (const float k)
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
inline vector4f vector4f::operator / (const vector4f &Vector)
   {
   return vector4f(Comp[0] / Vector.Comp[0], Comp[1] / Vector.Comp[1], Comp[2] / Vector.Comp[2], Comp[3] / Vector.Comp[3]);
   }

/*-------------------------------------------------------------------------
   Divide by a constant.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::operator / (const float k)
   {
   return vector4f(Comp[0] / k, Comp[1] / k, Comp[2] / k, Comp[3] / k);
   }

/*-------------------------------------------------------------------------
   Self modulus.
  -------------------------------------------------------------------------*/
inline vector4f &vector4f::operator %= (const vector4f &Vector)
   {
   Comp[0] = (float)fmod(Comp[0], Vector.Comp[0]); 
   Comp[1] = (float)fmod(Comp[1], Vector.Comp[1]); 
   Comp[2] = (float)fmod(Comp[2], Vector.Comp[2]);
   Comp[3] = (float)fmod(Comp[3], Vector.Comp[3]);
   return *this;
   }

/*-------------------------------------------------------------------------
   Self modulus by a constant.
  -------------------------------------------------------------------------*/
inline vector4f &vector4f::operator %= (const float k)
   {
   Comp[0] = (float)fmod(Comp[0], k); 
   Comp[1] = (float)fmod(Comp[1], k); 
   Comp[2] = (float)fmod(Comp[2], k);
   Comp[3] = (float)fmod(Comp[3], k);
   return *this;
   }

/*-------------------------------------------------------------------------
   Modulus.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::operator % (const vector4f &Vector)
   {
   return vector4f((float)fmod(Comp[0], Vector.Comp[0]), 
                   (float)fmod(Comp[1], Vector.Comp[1]), 
                   (float)fmod(Comp[2], Vector.Comp[2]), 
                   (float)fmod(Comp[3], Vector.Comp[3]));
   }

/*-------------------------------------------------------------------------
   Modulus by a constant.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::operator % (const float k)
   {
   return vector4f((float)fmod(Comp[0], k), (float)fmod(Comp[1], k), (float)fmod(Comp[2], k), (float)fmod(Comp[3], k));
   }

/*-------------------------------------------------------------------------
   Returns the minimum.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::Minimum(const vector4f &Vector)
   {
   return vector4f(((Comp[0] < Vector.Comp[0]) ? Comp[0] : Vector.Comp[0]),
                   ((Comp[1] < Vector.Comp[1]) ? Comp[1] : Vector.Comp[1]),  
                   ((Comp[2] < Vector.Comp[2]) ? Comp[2] : Vector.Comp[2]),  
                   ((Comp[3] < Vector.Comp[3]) ? Comp[3] : Vector.Comp[3]));
   }

/*-------------------------------------------------------------------------
   Returns the maximum.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::Maximum(const vector4f &Vector)
   {
   return vector4f(((Comp[0] > Vector.Comp[0]) ? Comp[0] : Vector.Comp[0]),
                   ((Comp[1] > Vector.Comp[1]) ? Comp[1] : Vector.Comp[1]),  
                   ((Comp[2] > Vector.Comp[2]) ? Comp[2] : Vector.Comp[2]),  
                   ((Comp[3] > Vector.Comp[3]) ? Comp[3] : Vector.Comp[3]));
   }

/*-------------------------------------------------------------------------
   Saturate the values by a constants.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::Saturate(const float Min, const float Max)
   {
   return vector4f((Comp[0] > Max) ? Max : ((Comp[0] < Min) ? Min : Comp[0]),
                   (Comp[1] > Max) ? Max : ((Comp[1] < Min) ? Min : Comp[1]),
                   (Comp[2] > Max) ? Max : ((Comp[2] < Min) ? Min : Comp[2]),
                   (Comp[3] > Max) ? Max : ((Comp[3] < Min) ? Min : Comp[3]));
   }

/*-------------------------------------------------------------------------
   Saturate the values.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::Saturate(const vector4f &Min, const vector4f &Max)
   {
   return vector4f((Comp[0] > Max.Comp[0]) ? Max.Comp[0] : ((Comp[0] < Min.Comp[0]) ? Min.Comp[0] : Comp[0]),
                   (Comp[1] > Max.Comp[1]) ? Max.Comp[1] : ((Comp[1] < Min.Comp[1]) ? Min.Comp[1] : Comp[1]),
                   (Comp[2] > Max.Comp[2]) ? Max.Comp[2] : ((Comp[2] < Min.Comp[2]) ? Min.Comp[2] : Comp[2]),
                   (Comp[3] > Max.Comp[3]) ? Max.Comp[3] : ((Comp[3] < Min.Comp[3]) ? Min.Comp[3] : Comp[3]));
   }

/*-------------------------------------------------------------------------
   Find the 3D magnitude squared.
  -------------------------------------------------------------------------*/
inline float vector4f::MagSqr(void) const
   {
   return (Comp[0]*Comp[0] + Comp[1]*Comp[1] + Comp[2]*Comp[2]);
   }

/*-------------------------------------------------------------------------
   Find the 3D magnitude.
  -------------------------------------------------------------------------*/
inline float vector4f::Mag(void) const
   {
   return (float)sqrt(Comp[0]*Comp[0] + Comp[1]*Comp[1] + Comp[2]*Comp[2]);
   }

/*-------------------------------------------------------------------------
   Find the 3D unit vector.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::Unit(void)
   {
   CACHE_ALIGN_16 register float Magnitude = this->Mag();
   return (Magnitude != 0.0) ? (*this * (1.0f / Magnitude)) : *this;
   }

/*-------------------------------------------------------------------------
   Returns the 3D dot product of *this and Vector.
  -------------------------------------------------------------------------*/
inline float vector4f::Dot(const vector4f &Vector)
   {
   return (Comp[0]*Vector.Comp[0] + Comp[1]*Vector.Comp[1] + Comp[2]*Vector.Comp[2]);
   }

/*-------------------------------------------------------------------------
   Returns the 3D cross product of *this and Vector.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::Cross(const vector4f &Vector)
   {
   return vector4f((Comp[1]*Vector.Comp[2] - Comp[2]*Vector.Comp[1]), 
                   (Comp[2]*Vector.Comp[0] - Comp[0]*Vector.Comp[2]), 
                   (Comp[0]*Vector.Comp[1] - Comp[1]*Vector.Comp[0]), Comp[3]);
   }

/*-------------------------------------------------------------------------
   Returns the cosine value between the 3D vectors *this and Vector. To 
   find the angle, the inverse of COS must be applied on this function's 
   result.
  -------------------------------------------------------------------------*/
inline float vector4f::COS(const vector4f &Vector)
   {
   return (this->Dot(Vector) / (this->Mag() * Vector.Mag()));
   }

/*-------------------------------------------------------------------------
   Returns the angle (in radians) between the 3D vectors *this and Vector.
  -------------------------------------------------------------------------*/
inline float vector4f::AngleCOS(const vector4f &Vector)
   {
   return (float)acos(this->COS(Vector));
   }

/*-------------------------------------------------------------------------
   Returns the angle (in radians) between the 3D vectors *this and Point. 
   It uses the dot product to calculate the angle, and therefore operator
   will work only on unit vectors.
  -------------------------------------------------------------------------*/
inline float vector4f::AngleDot(const vector4f &Vector)
   {
   return (float)acos(this->Dot(Vector));
   }

/*-------------------------------------------------------------------------
   Rotates *this 3D point by Rad (in radians) around the point [0, 0, 0]. 

   Algorithm:

   //Rotated around X-axis 
   T.Y     = Y   * CosR.X - Z   * SinR.X; 
   T.Z     = Z   * CosR.X + Y   * SinR.X; 
   //Rotated around Y-axis 
   Point.Z = T.Z * CosR.Y - X   * SinR.Y; //Final Z 
   T.X     = X   * CosR.Y + T.Z * SinR.Y; 
   //Rotated around Z-axis 
   Point.X = T.X * CosR.Z - T.Y * SinR.Z; //Final X 
   Point.Y = T.Y * CosR.Z + T.X * SinR.Z; //Final Y
	Point.t = 0.0f;
  -------------------------------------------------------------------------*/
inline vector4f vector4f::Rotate(const vector4f &Rad)
   {
   //Pre-calculate the sine and cosine values of Rad
   #if defined (INTEL_x86)
   CACHE_ALIGN_16 vector4f CosR;
   CACHE_ALIGN_16 vector4f SinR;
   __asm {
         mov esi,[Rad]
         fld DWORD PTR [esi]
         fsincos
         fstp DWORD PTR [CosR+0]
         fstp DWORD PTR [SinR+0]

         fld DWORD PTR [esi+4]
         fsincos
         fstp DWORD PTR [CosR+4]
         fstp DWORD PTR [SinR+4]

         fld DWORD PTR [esi+8]
         fsincos
         fstp DWORD PTR [CosR+8]
         fstp DWORD PTR [SinR+8]
         }
   #else
   CACHE_ALIGN_16 vector4f CosR((float)cos(Rad.Comp[0]), (float)cos(Rad.Comp[1]), (float)cos(Rad.Comp[2]), 0.0f);
   CACHE_ALIGN_16 vector4f SinR((float)sin(Rad.Comp[0]), (float)sin(Rad.Comp[1]), (float)sin(Rad.Comp[2]), 0.0f);
   #endif

   CACHE_ALIGN_16 vector4f T;
   T.Comp[1] = Comp[1] * CosR.Comp[0] - Comp[2]   * SinR.Comp[0]; 
   T.Comp[2] = Comp[2] * CosR.Comp[0] + Comp[1]   * SinR.Comp[0]; 
   T.Comp[0] = Comp[0] * CosR.Comp[1] + T.Comp[2] * SinR.Comp[1]; 

   return vector4f((T.Comp[0] * CosR.Comp[2] - T.Comp[1] * SinR.Comp[2]),
                   (T.Comp[1] * CosR.Comp[2] + T.Comp[0] * SinR.Comp[2]),
                   (T.Comp[2] * CosR.Comp[1] - Comp[0]   * SinR.Comp[1]), Comp[3]);
   /**/
   /*
   CACHE_ALIGN_16 vector4f T;

   //Around Comp[0]
   T.Comp[0] =    Comp[0];
   T.Comp[1] =    Comp[1]*CosR.Comp[0] +   Comp[2]*SinR.Comp[0];
   T.Comp[2] =   -Comp[1]*SinR.Comp[0] +   Comp[2]*CosR.Comp[0];

   //Around Comp[1]
   T.Comp[0] =  T.Comp[0]*CosR.Comp[1] - T.Comp[2]*SinR.Comp[1];
   T.Comp[2] =  T.Comp[0]*SinR.Comp[1] + T.Comp[2]*CosR.Comp[1];

   //Around Comp[2]
   T.Comp[0] =  T.Comp[0]*CosR.Comp[2] + T.Comp[1]*SinR.Comp[2];
   T.Comp[1] = -T.Comp[0]*SinR.Comp[2] + T.Comp[1]*CosR.Comp[2];  

   return T
   /**/
   }

/*-------------------------------------------------------------------------
   Rotates *this 3D point by Rad (in radians) around the point C.
  -------------------------------------------------------------------------*/
inline vector4f vector4f::Rotate(const vector4f &Rad, const vector4f &Center)
   {
   *this -= Center;
   return this->Rotate(Rad) + Center;
   }


/*==== End of file ===========================================================*/
#endif
