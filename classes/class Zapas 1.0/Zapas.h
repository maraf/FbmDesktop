/*------------------------------------------------------------------------------------------*/
/*                                class Zapas                                               */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/

#ifndef ZapasH
#define ZapasH

#include <StdCtrls.hpp>
#include <stdio.h>
#include "Tym.h"

class Zapas{

      private:
              int iCount;          // citac minut
              int iCelkoveA[2];    // celkove honoty FS, TS a ZS
              int iCelkoveB[2];    // pro dve lajny obou tymy
              int iGolyA;          // goly vstrelene
              int iGolyB;          // tymy A a B
              int iStrelyA;        // pocet strel za zapas
              int iStrelyB;        // obou tymu
              int iStrelec;        // Strelec aktualniho golu
              int iAsistent;       // Asistent u aktualniho golu
              int iUtok;           // vygenerovane cislo fci rand(), od o
              int iPomer;          // do 100, pomer je pocet cisel pro skorovani
              int iLine;           // ktera lajna hraje, 0 .. 1.lajna, 1 .. 2.lajna
              int iUtoky[4];       // utoky jednotlivych lajn obou tymy
              bool bUtoci[2];      // ktery tym v dane minute utoci
              int iPrumHrA[2];     // prumerne hodnoty FS, TS a ZS
              int iPrumHrB[2];     // obou lajn v obou tymu
              int iGolmanA;        // hodnoty FS, TS a ZS
              int iGolmanB;        // obou golmanu obou tymu
              int iNavsteva;       // navsteva na zapase
              char cPom;           // kdo dal gol??

      public:
              Tym *Tymy[2];        // instance dvou tymu ucastnicich se zapasu

              Zapas();
              ~Zapas();

              void Inicializace(); // nastaveni tridnich promenych
              String Akce();         // fce bude vyhodnocovat co se stane v dane akci
              void setNavsteva();  // z hodnot obou tymu vypocte navstevu na utkani

              int getNavsteva();

              int getGolyD();
              int getGolyH();

              int getStrelyD();
              int getStrelyH();

};

#endif
