/*------------------------------------------------------------------------------------------*/
/*                                class HracList                                            */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/

#ifndef HracListH
#define HracListH

#include <StdCtrls.hpp>

#include "Hrac.h";

class HracList{

      private:
              int NumberOfPlayers;
              
              void sortPlayersByPost(bool bRise);
              void sortPlayersByName(bool bRise);
              void sortPlayersByAge(bool bRise);
              void sortPlayersByFS(bool bRise);
              void sortPlayersByTS(bool bRise);
              void sortPlayersByZS(bool bRise);
  
      public:
              Hrac *Players[600];

              HracList();
              ~HracList();
              
              void add(Hrac &player);
              void remove(int id);
              
              void sortPlayersBy(String sHow, bool bRise);
              
              int getNumberOfPlayers();
};

#endif
