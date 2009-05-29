/*------------------------------------------------------------------------------------------*/
/*                                class Lajna                                               */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/

#ifndef LajnaH
#define LajnaH

#include <StdCtrls.hpp>

class Lajna{

      private:
              int Goalman;
              int LeftDefender;
              int RightDefender;
              int LeftWing;
              int RightWing;
              int Center;
              
              //int Utocne;

              bool Enabled;
              bool Valid;
      public:
              Lajna();
              Lajna(int iGm, int iLd, int iRd, int iLw, int iRw, int iCe, bool bEn, bool bVa);
              ~Lajna();
              
              void setAllPosts(int iGm, int iLd, int iRd, int iLw, int iRw, int iCe);
              void setGoalman(int iGm);
              void setGoalman(char *cGm);
              void setLeftDefender(int iLd);
              void setLeftDefender(char *cLd);
              void setRightDefender(int iRd);
              void setRightDefender(char *cRd);
              void setLeftWing(int iLw);
              void setLeftWing(char *cLw);
              void setRightWing(int iRw);
              void setRightWing(char *cRw);
              void setCenter(int iCe);
              void setCenter(char *cCe);
              
              void setEnabled(bool bEn);
              
              int getGoalman();
              int getLeftDefender();
              int getRightDefender();
              int getLeftWing();
              int getRightWing();
              int getCenter();
              
              bool isEnabled();
              bool isValid();
};

#endif
