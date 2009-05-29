/*------------------------------------------------------------------------------------------*/
/*                                class Lajna                                               */
/*                                verze 1.1                                                 */
/*------------------------------------------------------------------------------------------*/
#include "Lajna.h"
//--------------------------------------------------------------------------------------------

Lajna::Lajna(){
     Goalman = -1;
     ReserveGoalman = -1;
     LeftDefender = -1;
     RightDefender = -1;
     LeftWing = -1;
     RightWing = -1;
     Center = -1;
     
     //Utocne = 0;

     Enabled = false;
     Valid = false;

}
//--------------------------------------------------------------------------------------------

Lajna::Lajna(int iGm, int iRG, int iLd, int iRd, int iLw, int iRw, int iCe, bool bEn, bool bVa) {
     Goalman = iGm;
     ReserveGoalman = iRG;
     LeftDefender = iLd;
     RightDefender = iRd;
     LeftWing = iLw;
     RightWing = iRw;
     Center = iCe;
     
     //Utocne = iUt;
     
     Enabled = bEn;
     Valid = bVa;

}
//--------------------------------------------------------------------------------------------

Lajna::~Lajna() {

}
//--------------------------------------------------------------------------------------------

void Lajna::setAllPosts(int iGm, int iRG, int iLd, int iRd, int iLw, int iRw, int iCe) {
     Goalman = iGm;
     ReserveGoalman = iRG;
     LeftDefender = iLd;
     RightDefender = iRd;
     LeftWing = iLw;
     RightWing = iRw;
     Center = iCe;
}
//--------------------------------------------------------------------------------------------

void Lajna::setGoalman(int iGm) {
     Goalman = iGm;
}
//--------------------------------------------------------------------------------------------

void Lajna::setGoalman(char *cGm) {
     Goalman = atoi(cGm);
}
//--------------------------------------------------------------------------------------------

void Lajna::setReserveGoalman(int iGm) {
     ReserveGoalman = iGm;
}
//--------------------------------------------------------------------------------------------

void Lajna::setReserveGoalman(char *cGm) {
     ReserveGoalman = atoi(cGm);
}
//--------------------------------------------------------------------------------------------

void Lajna::setLeftDefender(int iLd) {
     LeftDefender = iLd;
}
//--------------------------------------------------------------------------------------------

void Lajna::setLeftDefender(char *cLd) {
     LeftDefender = atoi(cLd);
}
//--------------------------------------------------------------------------------------------

void Lajna::setRightDefender(int iRd) {
     RightDefender == iRd;
}
//--------------------------------------------------------------------------------------------

void Lajna::setRightDefender(char *cRd) {
     RightDefender = atoi(cRd);
}
//--------------------------------------------------------------------------------------------

void Lajna::setLeftWing(int iLw) {
     LeftWing = iLw;
}
//--------------------------------------------------------------------------------------------

void Lajna::setLeftWing(char *cLw) {
     LeftWing = atoi(cLw);
}
//--------------------------------------------------------------------------------------------

void Lajna::setRightWing(int iRw) {
     RightWing = iRw;
}
//--------------------------------------------------------------------------------------------

void Lajna::setRightWing(char *cRw) {
     RightWing = atoi(cRw);
}
//--------------------------------------------------------------------------------------------

void Lajna::setCenter(int iCe) {
     Center = iCe;
}
//--------------------------------------------------------------------------------------------

void Lajna::setCenter(char *cCe) {
     Center = atoi(cCe);
}
//--------------------------------------------------------------------------------------------

void Lajna::setEnabled(bool bEn) {
     Enabled = bEn;
}
//--------------------------------------------------------------------------------------------

int Lajna::getGoalman() {
     return Goalman;
}
//--------------------------------------------------------------------------------------------

int Lajna::getReserveGoalman() {
     return ReserveGoalman;
}
//--------------------------------------------------------------------------------------------

int Lajna::getLeftDefender() {
     return LeftDefender;
}
//--------------------------------------------------------------------------------------------

int Lajna::getRightDefender() {
     return RightDefender;
}
//--------------------------------------------------------------------------------------------

int Lajna::getLeftWing() {
     return LeftWing;
}
//--------------------------------------------------------------------------------------------

int Lajna::getRightWing() {
     return RightWing;
}
//--------------------------------------------------------------------------------------------

int Lajna::getCenter() {
     return Center;
}
//--------------------------------------------------------------------------------------------

bool Lajna::isEnabled() {
     return Enabled;
}
//--------------------------------------------------------------------------------------------

bool Lajna::isValid() {
     if(Goalman > -1 && LeftDefender > -1 && RightDefender > -1 && LeftWing > -1 && RightWing > -1 && Center > -1)
          return true;
     else
          return false;
}
//--------------------------------------------------------------------------------------------
