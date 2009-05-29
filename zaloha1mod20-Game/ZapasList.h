
#ifndef ZapasListH
#define ZapasListH

#include <StdCtrls.hpp>

#include "Zapas.h";

class ZapasList{

      private:
              int NumberOfMatches;
  
      public:
              Zapas *Matches[200];

              ZapasList();
              ~ZapasList();
              
              void add(Zapas *Match);
              void remove(int id);
              
              Zapas getMatch(int id);
              Zapas getMatch(String sHome, String sAway);
              
              int getNumberOfMatches();
};

#endif
