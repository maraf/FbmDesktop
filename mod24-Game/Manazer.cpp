/*------------------------------------------------------------------------------------------*/
/*                                class Manazer                                             */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/
#include "Manazer.h"
//---------------------------------------------------------------------------------------------

Manazer::Manazer(){
                cJmeno = "";
                cPrijmeni = "";
                iKlub = 0;

}
//---------------------------------------------------------------------------------------------

Manazer::Manazer(String Jmeno, String Prijmeni, int Klub){
                cJmeno = Jmeno;
                cPrijmeni = Prijmeni;
                iKlub = Klub;
}
//---------------------------------------------------------------------------------------------

Manazer::~Manazer(){
              
}
//---------------------------------------------------------------------------------------------

void Manazer::setJmeno(String Jmeno){
                cJmeno = Jmeno;
}
//---------------------------------------------------------------------------------------------

void Manazer::setPrijmeni(String Prijmeni){
                cPrijmeni = Prijmeni;
}
//---------------------------------------------------------------------------------------------

void Manazer::setKlub(int Klub){
                iKlub = Klub;
}
//---------------------------------------------------------------------------------------------

void Manazer::setKlub(char *Klub){
                int iPomKlub = atoi(Klub);
                iKlub = iPomKlub;
}
//---------------------------------------------------------------------------------------------

String Manazer::getJmeno(){
                return cJmeno;
}
//---------------------------------------------------------------------------------------------

String Manazer::getPrijmeni(){
                return cPrijmeni;
}
//---------------------------------------------------------------------------------------------

int Manazer::getKlub(){
                return iKlub;
}
//---------------------------------------------------------------------------------------------
