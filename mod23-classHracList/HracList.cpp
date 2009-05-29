/*------------------------------------------------------------------------------------------*/
/*                                class HracList                                            */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/
#include "HracList.h"
//--------------------------------------------------------------------------------------------

HracList::HracList() {
     NumberOfPlayers = 0;
}
//--------------------------------------------------------------------------------------------

HracList::~HracList() {

}
//--------------------------------------------------------------------------------------------

void HracList::add(Hrac &player) {
     Players[NumberOfPlayers] = &player;
     NumberOfPlayers ++;
     sortPlayersBy("post", true);
}
//--------------------------------------------------------------------------------------------

void HracList::remove(int id) {
     free(Players[id]);
     sortPlayersBy("post", true);
}
//--------------------------------------------------------------------------------------------

void HracList::sortPlayersBy(String sHow, bool bRise) {
     if(sHow == "post") {
          sortPlayersByPost(bRise);
     } else if(sHow == "name") {
          sortPlayersByName(bRise);
     } else if(sHow == "age") {
          sortPlayersByAge(bRise);
     } else if(sHow == "fs") {
          sortPlayersByFS(bRise);
     } else if(sHow == "ts") {
          sortPlayersByTS(bRise);
     } else if(sHow == "zs") {
          sortPlayersByZS(bRise);
     }
}
//--------------------------------------------------------------------------------------------

void HracList::sortPlayersByPost(bool bRise) {
        //Players[599] = Players[11];
        //Players[11] = Players[10];
        //Players[10] = Players[599];
}
//--------------------------------------------------------------------------------------------

void HracList::sortPlayersByName(bool bRise) {

}
//--------------------------------------------------------------------------------------------

void HracList::sortPlayersByAge(bool bRise) {

}
//--------------------------------------------------------------------------------------------

void HracList::sortPlayersByFS(bool bRise) {

}
//--------------------------------------------------------------------------------------------

void HracList::sortPlayersByTS(bool bRise) {

}
//--------------------------------------------------------------------------------------------

void HracList::sortPlayersByZS(bool bRise) {

}
//--------------------------------------------------------------------------------------------

int HracList::getNumberOfPlayers() {
     return NumberOfPlayers;
}
//--------------------------------------------------------------------------------------------