/*------------------------------------------------------------------------------------------*/
/*                                class Ekonomika                                           */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/
#include "Ekonomika.h"
//--------------------------------------------------------------------------------------------

Ekonomika::Ekonomika(){
     Account = 0;

     for(int i = 0; i < 10; i ++) {
          LastOutComes[i] = "";
          LastInComes[i] = "";
     }
}
//--------------------------------------------------------------------------------------------

Ekonomika::Ekonomika(float iAccount){
     Account = iAccount;

     for(int i = 0; i < 10; i ++) {
          LastOutComes[i] = "";
          LastInComes[i] = "";
     }
}
//--------------------------------------------------------------------------------------------

Ekonomika::~Ekonomika(){
}
//--------------------------------------------------------------------------------------------

bool Ekonomika::isAccountOverZero() {
     if(Account > 0) return true;
     else return false;
}
//--------------------------------------------------------------------------------------------

bool Ekonomika::isAccountOver20k() {
     if(Account > 20000) return true;
     else return false;
}
//--------------------------------------------------------------------------------------------

void Ekonomika::outCome(float cost, int which) {
     Account -= cost;
     
     int i = 0;
     while(LastOutComes[i] != "") i ++;
     
     switch(which) {
          case 1: LastOutComes[i] = "Platy hráèù: " + (String)cost; break;
          case 2: LastOutComes[i] = "Pøestup hráèe: " + (String)cost; break;
          case 3: LastOutComes[i] = "Startovné do ligy: " + (String)cost; break;
          case 4: LastOutComes[i] = "Provoz haly: " + (String)cost; break;
     }
}
//--------------------------------------------------------------------------------------------

void Ekonomika::inCome(float cost, int which) {
     Account += cost;
     
     int i = 0;
     while(LastInComes[i] != "") i ++;
     
     switch(which) {
          case 1: LastInComes[i] = "Peníze od sponzorù " + (String)cost; break;
     }
}
//--------------------------------------------------------------------------------------------

void Ekonomika::setAccount(float iAccount) {
     Account = iAccount;
}
//--------------------------------------------------------------------------------------------

float Ekonomika::getAccount() {
     return Account;
}
//--------------------------------------------------------------------------------------------

String Ekonomika::getLastOutCome(int index) {
     return LastOutComes[index];
}
//--------------------------------------------------------------------------------------------

String Ekonomika::getLastInCome(int index) {
     return LastInComes[index];
}
//--------------------------------------------------------------------------------------------
