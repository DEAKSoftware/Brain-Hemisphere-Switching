/*============================================================================*/
/*                          Program Entry Point                               */
/*                                                                            */
/* Dominik Deak                                                               */
/*============================================================================*/

/*---------------------------------------------------------------------------
   Don't include this file if it's already defined.   
  ---------------------------------------------------------------------------*/
#ifndef __MAIN_CPP__
#define __MAIN_CPP__


/*---------------------------------------------------------------------------
   Include libraries and other source files needed in this file.
  ---------------------------------------------------------------------------*/
#include "./main.h"


/*----------------------------------------------------------------------------
   Keyboard handlers.
  ----------------------------------------------------------------------------*/
void __cdecl KeyboardHandler(uint8 Char, int X, int Y)
   {
   if (Keyb_LastChar >= (Keyb_Buffer + KEYB_BUFLEN)) {return;}
   *Keyb_LastChar = Char;
   Keyb_LastChar++;
   }

uint8 ReadKey(void)
   {
   if (Keyb_LastChar == Keyb_Buffer) {return 0;}
   Keyb_LastChar--;
   return *Keyb_LastChar;
   }

/*---------------------------------------------------------------------------
   The reshape function.
  ---------------------------------------------------------------------------*/
void __cdecl Reshape(int X_Res, int Y_Res)
   {
   //If the new resolution is 0, the window is minimized
   if ((X_Res == 0) || (Y_Res == 0)) {return;}
   
   //-- Setup the 3D projection --
   GLdouble Left     = -((GLdouble)X_Res / (GLdouble)Y_Res);
   GLdouble Right    = -Left;
   GLdouble Bottom   = -(GLdouble)1.0;
   GLdouble Top      = -Bottom;
   GLdouble Near     =  (GLdouble)1.0;
   GLdouble Far      =  (GLdouble)100.0;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(Left, Right, Bottom, Top, Near, Far);
   //glOrtho(Left, Right, Bottom, Top, -Far, Far); 
         
   //-- Setup the 3D model view matrix along with the OpenGL viewport area --
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glScalef(1.0f, 1.0f, -1.0f);
   glViewport((GLint)0, (GLint)0, (GLsizei)X_Res, (GLsizei)Y_Res); //Set the viewport size  

   //Clear the screen
   glClearDepth(1.0f);
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);     //Set the clear color
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Do the clearing 
   }

/*---------------------------------------------------------------------------
   Monitors display is visibilty.
  ---------------------------------------------------------------------------*/
void __cdecl Entry(int State)
   {
   //Enable control IO
   if (State == GLUT_ENTERED) 
      {
      glutKeyboardFunc((void(*)(byte, int, int))KeyboardHandler);
      glutReshapeFunc((void(*)(int, int))Reshape); //The reshape function
      }

   //Disable control IO
   else if (State == GLUT_LEFT) 
      {
      glutKeyboardFunc(NULL);
      glutReshapeFunc(NULL);
      }
   }

   
/*----------------------------------------------------------------------------
   Main loop.
  ----------------------------------------------------------------------------*/
vector4f R = 0.0f;
void __cdecl MainLoop(void)
   {
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();                                   
   glTranslatef(0, 0, 3.0f);
   glRotatef(rad2deg(R.X), -1.0f,  0.0f,  0.0f);
   glRotatef(rad2deg(R.Y),  0.0f, -1.0f,  0.0f);
   glRotatef(rad2deg(R.Z),  0.0f,  0.0f, -1.0f);
   glScalef(2.0f, 2.0f, 2.0f);


   glPushAttrib(GL_ENABLE_BIT); 
   glPointSize(1.0f);

   //Render blue clusters
   glBegin(GL_POINTS); 
   for (int I = 0; I < POINT_LEN; I++)
      {
      glColor3f(0, 0, 1);
      glVertex3fv((GLfloat*)&Points[I]);
      }
   glEnd();

   glPopAttrib();

   glMatrixMode(GL_MODELVIEW); 
   glPopMatrix();


   glPushAttrib(GL_ENABLE_BIT); 

   glPointSize(15.0f);

   //-- Render yellow dots --
   glBegin(GL_POINTS); 


   #define PT_OFF 0.5f

   glColor3f(1, 1, 0);
   glVertex3f(-PT_OFF, PT_OFF, 1.0f);

   glColor3f(1, 1, 0);
   glVertex3f(PT_OFF, PT_OFF, 1.0f);

   glColor3f(1, 1, 0);
   glVertex3f(-PT_OFF, -PT_OFF, 1.0f);

   glColor3f(1, 1, 0);
   glVertex3f(PT_OFF, -PT_OFF, 1.0f);

   glColor3f(1, 1, 0);
   glVertex3f(0.0f, 0.0f, 1.0f);


   glEnd();

   glPopAttrib();
 

   //Rotate the poits
   //R = (R + 0.015f) % 360.0f;
   R.X += 0.015f;
   R.Y += 0.015f;
   //R.Z += 0.005f;
   R %= 360.0f;


   //-- Display Stuff --
   glFlush();                                   //High end machines may need this

   glutPostRedisplay();                         //Render to frame buffer 
   glutSwapBuffers();                           //Swap the frame buffer and video buffer 

   glClearDepth(1.0f);
   glClearColor(0, 0, 0, 0);                 //Set the clear color 
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Do the clearing 


   if (ReadKey() != 0) 
      {
      if (GLUT_GameMode) {glutLeaveGameMode();}
      if (GLUT_WinHandle != 0){glutDestroyWindow(GLUT_WinHandle);}
      exit(0);
      return;
      }
   }

/*----------------------------------------------------------------------------
  Main.
  ----------------------------------------------------------------------------*/
void __cdecl main(int ArgCount, char* *Argv)
   {
   srand(time(NULL));
   
   memset(Keyb_Buffer, 0, sizeof(Keyb_Buffer));
   
   
   //Randomise points
   for (int I = 0; I < POINT_LEN; I++)
      {
      Points[I] = (vector4f(256.0f, 256.0f, 256.0f, 0.0f) - (vector4f(rand(), rand(), rand(), 0.0f) % 512.0f)).Unit();
      //Points[I] *= ((float)(rand() % 100) / 100.0f);
      }
   
   
   
   glutInit(&ArgCount, Argv);
   
   GLint GLUT_Flags = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE;
   glutInitDisplayMode(GLUT_Flags);             //Set the display mode to true color, with a double buffer  
   glutInitWindowPosition(0, 0);                //Set the window postion


   int X_Res = 800;
   int Y_Res = 600;
   bool FullScreen = false;

   if (FullScreen)                          //Run in full screen mode if necessary
      {
      char ModeString[0x100]; *ModeString = 0;
      sprintf(ModeString, "%dx%d:%d@%d", X_Res, Y_Res, 16, 60);
      glutGameModeString(ModeString);
      
      //Determine if game mode is possible
      if (glutGameModeGet((GLenum)GLUT_GAME_MODE_POSSIBLE) != 0) 
         {
         glutEnterGameMode();
         GLUT_GameMode = true;
         }
      else
         {
         printf("WARNING: main( ): Unable to set game mode.\n");
         GLUT_GameMode = false;
         }
      }
   
   //Use the standard GLUT setup if game mode failed or setup rendering in
   // windowed mode.
   if (!GLUT_GameMode)
      {
      glutInitWindowSize(X_Res, Y_Res); //Set the window size as specified
      GLUT_WinHandle = glutCreateWindow("Dots - " AUTHOR_NAME); //Create the actual GLUT window  
      if (FullScreen) {glutFullScreen();}
      }
   
   //-- GLUT handers --
   glutDisplayFunc((void(*)(void))MainLoop);    //Define the main looping function 
   glutReshapeFunc((void(*)(int, int))Reshape); //The reshape function
   glutEntryFunc((void(*)(int))Entry);
   glutKeyboardFunc((void(*)(uint8, int, int))KeyboardHandler);

   
   //-- Setup the 3D projection --
   GLdouble Left     = -((GLdouble)X_Res / (GLdouble)Y_Res) * (GLdouble)0.5;
   GLdouble Right    = -Left;
   GLdouble Bottom   = -(GLdouble)0.5;
   GLdouble Top      = -Bottom;
   GLdouble Near     =  (GLdouble)1.0;
   GLdouble Far      =  (GLdouble)100.0;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(Left, Right, Bottom, Top, Near, Far);
   //glOrtho(Left, Right, Bottom, Top, -Far, Far); 
      
   //-- Setup the 3D model view matrix along with the OpenGL viewport area --
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glScalef(1.0f, 1.0f, -1.0f);
   glViewport((GLint)0, (GLint)0, (GLsizei)X_Res, (GLsizei)Y_Res); //Set the viewport size  

   //-- Set up other OpenGL stuff --
   glDepthRange((GLfloat)0.0f, (GLfloat)1.0f);
   glDepthFunc(GL_LESS);
   glDisable(GL_DEPTH_TEST);

   //glEnable(GL_CULL_FACE);
   //glFrontFace(GL_CW);
   glCullFace(GL_BACK);

   glEnable(GL_POINT_SMOOTH); 
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
   //glBlendFunc(GL_SRC_ALPHA, GL_ONE); 

   glutMainLoop();
   }
   


/*==== End of file ===========================================================*/
#endif    