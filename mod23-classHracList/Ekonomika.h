/*------------------------------------------------------------------------------------------*/
/*                                class Ekonomika                                           */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/

#ifndef EkonomikaH
#define EkonomikaH

#define ECO_PL_SALARY             1
#define ECO_PL_TRANSFER           2
#define ECO_TE_START              3
#define ECO_HA_PAY                4

#include <StdCtrls.hpp>

class Ekonomika{

      private:
              float Account;

              String LastOutComes[10];
              String LastInComes[10];

      public:
              Ekonomika();
              Ekonomika(float iAccount);
              ~Ekonomika();
              
              bool isAccountOverZero();
              bool isAccountOver20k();

              void outCome(float cost, int which);
              void inCome(float cost, int which);
              
              void setAccount(float iAccount);
              float getAccount();
              
              String getLastOutCome(int index);
              String getLastInCome(int index);
};

#endif
