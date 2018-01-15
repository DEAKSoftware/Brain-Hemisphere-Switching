/*============================================================================*/
/*                          Program Entry Point                               */
/*                                                                            */
/* Dominik Deak                                                               */
/*============================================================================*/


/*---------------------------------------------------------------------------
   Don't include this file if it's already defined.   
  ---------------------------------------------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__


/*---------------------------------------------------------------------------
   Include libraries and other source files needed in this file.
  ---------------------------------------------------------------------------*/
#include "./common/common.h"
#include "./common/math.h"
#include "./vector/vector.h"


/*----------------------------------------------------------------------------
   Global data
  ----------------------------------------------------------------------------*/
#define KEYB_BUFLEN 256
uint8  Keyb_Buffer[KEYB_BUFLEN];
uint8* Keyb_LastChar = Keyb_Buffer;

#define POINT_LEN 2048
vector4f Points[POINT_LEN];

bool GLUT_GameMode = false;
int  GLUT_WinHandle = 0;


/*----------------------------------------------------------------------------
   Global functions
  ----------------------------------------------------------------------------*/
void __cdecl Entry(int State);
void __cdecl Reshape(int X_Res, int Y_Res);
void __cdecl KeyboardHandler(uint8 Char, int X, int Y);
uint8 ReadKey(void);
void __cdecl MainLoop(void);
void __cdecl main(int ArgCount, char* *Argv);
       

/*==== End of file ===========================================================*/
#endif 