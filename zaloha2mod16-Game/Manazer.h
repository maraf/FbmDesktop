
#ifndef ManazerH
#define ManazerH

#include <StdCtrls.hpp>

class Manazer{

      private:
              String cJmeno;
              String cPrijmeni;
              int iKlub;

      public:
              Manazer();
              Manazer(String Jmeno, String Prijmeni, int Klub);
              ~Manazer();

              void setJmeno(String Jmeno);
              void setPrijmeni(String Prijmeni);
              void setKlub(int Klub);
              void setKlub(char *Klub);


              String getJmeno();
              String getPrijmeni();
              int getKlub();
              
};

#endif
