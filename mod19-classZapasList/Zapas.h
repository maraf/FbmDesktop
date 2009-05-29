
#ifndef ZapasH
#define ZapasH

#include <StdCtrls.hpp>
#include <stdio.h>
#include "Tym.h"

class Zapas{

      private:
              int iID;
              float fCelkoveD;     // celkove honoty FS, TS a ZS
              float fCelkoveH;     // pro dve lajny obou tymy

              float fCelkemD;      // prumer souctu FS, TS a ZS
              float fCelkemH;      // podelen poctem lajn

              int iCount;          // citac minut
              int iStrelec;        // Strelec aktualniho golu
              int iAsistent;       // Asistent u aktualniho golu
              int ScorersH[30];
              String StringScorersH[30];
              int ScorersA[30];
              String StringScorersA[30];
              int AssistentsH[30];
              String StringAssistentsH[30];
              int AssistentsA[30];
              String StringAssistentsA[30];

              int iUtok;           // vygenerovane cislo fci rand(), od o do 100
              float fPomer;        // pomer je pocet cisel pro skorovani
              int iLine[2];        // ktera lajna hraje, 1 - 1.lajna, 2 - 2.lajna, ... | dom. a hos.
              bool bUtoci;         // ktery tym v dane minute utoci
              int iUtoci;          // navazuje na iPodil, rand cislo, kdo utoci podle iPodilu
              int iPodil;          // podil sily -> kdo ma vetsi sanci utocit 5 az 10
              int iPrumHrD;        // prumerne hodnoty FS, TS a ZS
              int iPrumHrH;        // obou lajn v obou tymu
              int iGolmanD;        // hodnoty FS, TS a ZS
              int iGolmanH;        // obou golmanu obou tymu
              int iGolyD;          // goly vstrelene
              int iGolyH;          // tymy A a B
              int iStrelyD;        // pocet strel za zapas
              int iStrelyH;        // obou tymu
              int iNavsteva;       // navsteva na zapase

              int iDobaNaHrD;      // kolikrat 30sec. jiz byla aktualni lajna
              int iDobaNaHrH;      // na hristi

              int iGoal;           // indikace za padl gol

              int iGOL[2];         // od 0 do iGOL je z utocne akce gol | domaci a hoste
              int iSTRELA[2];      // od 0 do iSTRELA je z utocne akce strela | domaci a hoste 

              float ft[2];         // Koef prumerne energie na hrace v aktu. lajne | domaci a hoste


              void Inicializace(); // nastavuje silu tymu atd.
              void setLajny();     // nastavuje ktere je lajny zrovna hraji
              void updateEnergie(); // rozhoduje o reg.() nebo una.() podle lajne ktere sedi a hraji
              void regenerace(int iLajn, int j, int Kolik); // zvysuje energie, int Kolik je o kolik
              void unava(int iLajn, int j, int Kolik); // snizuje energii, int j je Tym
              void updatePlayersAbility();
              void setStrelec(char cTym);
              void setAsistent(char cTym);

      public:
              Tym *Tymy[2];        // instance dvou tymu ucastnicich se zapasu

              Zapas(Tym &team1, Tym &team2, int id);
              ~Zapas();

              void setID(int id);
              String Akce();       // fce bude vyhodnocovat co se stane v dane akci
              void setNavsteva();  // z hodnot obou tymu vypocte navstevu na utkani
              void setGoal(int Goal); // pokud nekdo dal gol, ktery tym to byl

              int getID();

              int getNavsteva();

              int getGolyD();
              int getGolyH();

              int getStrelyD();
              int getStrelyH();

              int getStrelec();
              int getAsistent();
              int getGoal();
              int getCount();
              String getMinuta();

              int getScorers(bool bHome, int iGoal);
              String getStringScorers(bool bHome, int iGoal);
              int getAssistents(bool bHome, int iGoal);
              String getStringAssistents(bool bHome, int iGoal);
};

#endif
