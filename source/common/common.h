/*============================================================================*/
/* Common definitions and includes that are used through-out the project are  */
/* placed here.                                                               */
/*                                                                            */
/* Dominik Deak                                                               */
/*============================================================================*/

/*---------------------------------------------------------------------------
   Don't include this file if it's already defined.
  ---------------------------------------------------------------------------*/
#ifndef __COMMON_H__
#define __COMMON_H__


/*----------------------------------------------------------------------------
   Define the author dedtails, etc
  ----------------------------------------------------------------------------*/
#define AUTHOR_NAME "Dominik Deak"


/*----------------------------------------------------------------------------
   Define the target processor
  ----------------------------------------------------------------------------*/
//#define INTEL_x86                             //Intel x86 based processor
//#define INTEL_x86_MMX                         //Intel x86 based processor with MMX (also enables INTEL_x86)
//#define INTEL_x86_SSE                         //Intel x86 based processor with SSE (also enables INTEL_x86 and INTEL_x86_MMX)
//#define INTEL_x86_SSE2                        //Intel x86 based processor with SSE2 (also enables INTEL_x86, INTEL_x86_MMX and INTEL_x86_SSE)
//#define DEC_ALPHA                             //DEC Alpha processor
//#define MIPS                                  //MIPS processor
//#define POWER_PC                              //Motrolla based processor for the Power PC
//#define SPARC                                 //Ultra SPARC processor


/*----------------------------------------------------------------------------
   Standard library includes
  ----------------------------------------------------------------------------*/
//Include all the standard libraries needed
#if defined (WIN32) || defined (WIN64)
#  include <io.h>
#  include <windows.h>
#  include <winbase.h>
#  include <winuser.h>
#  include <float.h>                            //Floating point routines
#  include <crtdbg.h>                           //Debugging utils
#  if defined (INTEL_x86_MMX)
#     define INTEL_x86
#     include <mmintrin.h>                      //MMX intrinsics
#  endif
#  if defined (INTEL_x86_SSE)
#     define INTEL_x86
#     define INTEL_x86_MMX
#     include <mmintrin.h>                      //MMX intrinsics
#     include <xmmintrin.h>                     //SSE intrinsics
#  endif
#  if defined (INTEL_x86_SSE2)
#     define INTEL_x86
#     define INTEL_x86_MMX
#     define INTEL_x86_SSE
#     include <mmintrin.h>                      //MMX intrinsics
#     include <xmmintrin.h>                     //SSE intrinsics
#     include <emmintrin.h>                     //SSE2 intrinsics
#  endif
#  if defined (_DEBUG)                          //Enable debugger macros (must be declared after <crtdbg.h>)
#     define _CRTDBG_MAP_ALLOC
#     define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#     define malloc(Size) _malloc_dbg(Size, _NORMAL_BLOCK, __FILE__, __LINE__)
#     define realloc(Ptr, Size) _realloc_dbg(Ptr, Size, _NORMAL_BLOCK, __FILE__, __LINE__)
#  endif 
 
#elif defined (MAC_OS)
#  undef INTEL_x86
#  undef INTEL_x86_MMX
#  undef INTEL_x86_SSE
#  undef INTEL_x86_SSE2

#elif defined (LINUX)
#  include <sys/time.h>
#  include <stdint.h>
#  include <GL/glx.h>                           //OpenGL X windows
#  include <X11/Xlib.h>                         //X Windows routines
#  include <X11/keysym.h>                       //X Windows keyboard routines
#  include <X11/extensions/xf86dga.h>           //XFree86 
#  include <X11/extensions/xf86vmode.h>         //XFree86 video mode extensions
#  undef INTEL_x86
#  undef INTEL_x86_MMX
#  undef INTEL_x86_SSE
#  undef INTEL_x86_SSE2
#  define stricmp  strcasecmp                   //This function name must be given an alias in Unix
#  define strnicmp strncasecmp                  //This function name must be given an alias in Unix

#elif defined (UNIX)
#  include <varargs.h>                          ///Needed for variable argument lists
#  include <strings.h>
#  include <GL/glx.h>
#  include <X11/Xlib.h>                         //X Windows routines
#  include <X11/keysym.h>                       //X Windows keyboard routines
//#  include <X11/extensions/xf86dga.h>          //XFree86 
#  include <X11/extensions/xf86vmode.h>         //XFree86 video mode extensions
#  undef INTEL_x86
#  undef INTEL_x86_MMX
#  undef INTEL_x86_SSE
#  undef INTEL_x86_SSE2
#  define stricmp  strcasecmp                   //This function name must be given an alias in Unix
#  define strnicmp strncasecmp                  //This function name must be given an alias in Unix
#endif

#include <GL/gl.h>                              //OpenGL library
#include <GL/glu.h>                             //OpenGL utility library
#include <glut.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <time.h>


/*----------------------------------------------------------------------------
   Type definitions
  ----------------------------------------------------------------------------*/
#if defined (WIN32) || defined (WIN64)
   typedef signed char        int8;
   typedef signed __int16     int16;
   typedef signed __int32     int32;
   typedef signed __int64     int64;
   typedef unsigned char      uint8;
   typedef unsigned __int16   uint16;
   typedef unsigned __int32   uint32;
   typedef unsigned __int64   uint64;
   #define DB _emit                    //Reserve the "define byte" keywords in assembler statements
   #define db _emit
#elif defined (LINUX)
   typedef signed char        int8;
   typedef int16_t            int16;
   typedef int32_t            int32;
   typedef int64_t            int64;
   typedef unsigned char      uint8;
   typedef uint16_t           uint16;
   typedef uint32_t           uint32;
   typedef uint64_t           uint64;
   #define __cdecl
   #define __forceinline inline
#else
   typedef signed char        int8;
   typedef signed short int   int16;
   typedef signed int         int32;
   typedef signed long int    int64;
   typedef unsigned char      uint8;
   typedef unsigned short int uint16;
   typedef unsigned int       uint32;
   typedef unsigned long int  uint64;
   #define __cdecl
   #define __forceinline inline
#endif


/*----------------------------------------------------------------------------
   Processor cache alignment related macros
  ----------------------------------------------------------------------------*/
#if (defined (INTEL_x86_MMX) || defined (INTEL_x86_SSE) || defined (INTEL_x86_SSE2)) && (defined (WIN32) || defined (WIN64))
#  define CACHE_ALIGN_8  __declspec(align( 8))    //Alignment on the 8-byte boundary
#  define CACHE_ALIGN_16 __declspec(align(16))    //Alignment on the 16-byte boundary
#  define CACHE_ALIGN_32 __declspec(align(32))    //Alignment on the 32-byte boundary
#  define CACHE_ALIGN_64 __declspec(align(64))    //Alignment on the 64-byte boundary
#else
#  define CACHE_ALIGN_8
#  define CACHE_ALIGN_16
#  define CACHE_ALIGN_32
#  define CACHE_ALIGN_64
#endif


/*==== End of file ===========================================================*/
#endif
