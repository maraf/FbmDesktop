#include "ZapasList.h"
//--------------------------------------------------------------------------------------------

ZapasList::ZapasList() {
     NumberOfMatches = 0;
}
//--------------------------------------------------------------------------------------------

ZapasList::~ZapasList() {

}
//--------------------------------------------------------------------------------------------

void ZapasList::add(Zapas *Match) {
     Tym *Team1 = new Tym();
     Tym *Team2 = new Tym();
     Matches[NumberOfMatches] = new Zapas(*Team1, *Team2, 0);
     *Matches[NumberOfMatches] = *Match;
     NumberOfMatches ++;          
}
//--------------------------------------------------------------------------------------------

void ZapasList::remove(int id) {
     if(id < NumberOfMatches) {
          delete Matches[id];
          
          for(int i = id; i < NumberOfMatches - 1; i ++) {
               *Matches[i] = *Matches[i + 1];
          }
     }
}
//--------------------------------------------------------------------------------------------

Zapas ZapasList::getMatch(int id) {
     if(id < NumberOfMatches) {
          return *Matches[id];
     } else {
          Tym *Team1 = new Tym();
          Tym *Team2 = new Tym();
          Zapas *Match = new Zapas(*Team1, *Team2, 0);
          return *Match;
     }
}
//--------------------------------------------------------------------------------------------

Zapas ZapasList::getMatch(String sHome, String sAway) {
     for(int i = 0; i < NumberOfMatches; i ++) {
          if(Matches[i]->Tymy[0]->getNazevTymu() == sHome && Matches[i]->Tymy[1]->getNazevTymu() == sAway) {
               return *Matches[i];
          }
     }

     Tym *Team1 = new Tym();
     Tym *Team2 = new Tym();
     Zapas *Match = new Zapas(*Team1, *Team2, 0);
     return *Match;
}
//--------------------------------------------------------------------------------------------

int ZapasList::getNumberOfMatches() {
     return NumberOfMatches;
}
//--------------------------------------------------------------------------------------------