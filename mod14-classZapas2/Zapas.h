
#ifndef ZapasH
#define ZapasH

#include <StdCtrls.hpp>
#include <stdio.h>
#include "Tym.h"

class Zapas{

      private:
              int iCelkoveD;       // celkove honoty FS, TS a ZS
              int iCelkoveH;       // pro dve lajny obou tymy

              float iCelkemD;      // prumer souctu FS, TS a ZS
              float iCelkemH;      // podelen poctem lajn

              int iCount;          // citac minut
              int iStrelec;        // Strelec aktualniho golu
              int iAsistent;       // Asistent u aktualniho golu

              int iUtok;           // vygenerovane cislo fci rand(), od o do 100
              float fPomer;        // pomer je pocet cisel pro skorovani
              int iLine[2];        // ktera lajna hraje, 0 .. 1.lajna, 1 .. 2.lajna, ...
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

      public:
              Tym *Tymy[2];        // instance dvou tymu ucastnicich se zapasu

              Zapas(Tym &team1, Tym &team2);
              ~Zapas();

              void Inicializace();
              String Akce();       // fce bude vyhodnocovat co se stane v dane akci
              void setLajny();
              void setStrelec(char cTym);
              void setAsistent(char cTym);
              void setNavsteva();  // z hodnot obou tymu vypocte navstevu na utkani
              void setGoal(int Goal);

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
};

#endif
