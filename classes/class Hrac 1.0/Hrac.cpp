/*------------------------------------------------------------------------------------------*/
/*                                class Hrac                                                */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/
#include "Hrac.h"
//---------------------------------------------------------------------------------------------

Hrac::Hrac(){
                cPost = ' ';
                cJmeno = ' ';
                cPrijmeni = ' ';
                iVek = 0;
                iFS = 0;
                fFSpom = 0;
                iTS = 0;
                fTSpom = 0;
                iZS = 0;
                fZSpom = 0;
                fEnergie = 100;
                iSestava = 0;
                iZapasyCelkem = 0;
                iZapasyPohar = 0;
                iZapasyLiga = 0;
                iGolyCelkem = 0;
                iGolyPohar = 0;
                iGolyLiga = 0;
                iAsistenceCelkem = 0;
                iAsistencePohar = 0;
                iAsistenceLiga = 0;
                iTrestyCelkem = 0;
                iTrestyPohar = 0;
                iTrestyLiga = 0;
                iSmlouva = 0;

}
//---------------------------------------------------------------------------------------------

Hrac::Hrac(int id, char Post, int Cislo, String Jmeno, String Prijmeni, int Vek, int FS, int TS, int ZS, int Smlouva){
                cPost = Post;
                iCislo = Cislo;
                cJmeno = Jmeno;
                cPrijmeni = Prijmeni;
                iVek = Vek;
                iFS = FS;
                fFSpom = 0;
                iTS = TS;
                fTSpom = 0;
                iZS = ZS;
                fZSpom = 0;
                fEnergie = 100;
                iSestava = 0;
                iZapasyCelkem = 0;
                iZapasyPohar = 0;
                iZapasyLiga = 0;
                iGolyCelkem = 0;
                iGolyPohar = 0;
                iGolyLiga = 0;
                iAsistenceCelkem = 0;
                iAsistencePohar = 0;
                iAsistenceLiga = 0;
                iTrestyCelkem = 0;
                iTrestyPohar = 0;
                iTrestyLiga = 0;
                iSmlouva = Smlouva;
}
//---------------------------------------------------------------------------------------------

Hrac::~Hrac(){
              
}
//---------------------------------------------------------------------------------------------

void Hrac::setID(int id){
                iID = id;
}
//---------------------------------------------------------------------------------------------

void Hrac::setID(char *id){
                int iPomID = atoi(id);
                iID = iPomID;
}
//---------------------------------------------------------------------------------------------

void Hrac::setPost(char Post){
                cPost = Post;
}
//---------------------------------------------------------------------------------------------

void Hrac::setCislo(int Cislo){
                iCislo = Cislo;
}
//---------------------------------------------------------------------------------------------

void Hrac::setCislo(char *Cislo){
                int iPomCislo = atoi(Cislo);
                iCislo = iPomCislo;
}
//---------------------------------------------------------------------------------------------

void Hrac::setJmeno(String Jmeno){
                cJmeno = Jmeno;
}
//---------------------------------------------------------------------------------------------

void Hrac::setJmeno2(String Jmeno2){
                cJmeno2 = Jmeno2;
}
//---------------------------------------------------------------------------------------------

void Hrac::setPrijmeni(String Prijmeni){
                cPrijmeni = Prijmeni;
}
//---------------------------------------------------------------------------------------------

void Hrac::setVek(int Vek){
                iVek = Vek;
}
//---------------------------------------------------------------------------------------------

void Hrac::setVek(char *Vek){
                int iPomVek = atoi(Vek);
                iVek = iPomVek;
}
//---------------------------------------------------------------------------------------------

void Hrac::setFS(int FS){
                iFS = FS;
}
//---------------------------------------------------------------------------------------------

void Hrac::setFS(int FS, float FSpom){
                iFS = FS;
                fFSpom = FSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setFSpom(float FSpom){
                fFSpom = FSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setFS(char *FS){
                int iPomFS = atoi(FS);
                iFS = iPomFS;
}
//---------------------------------------------------------------------------------------------

void Hrac::setFS(char *FS, char *FSpom){
                int iPomFS = atoi(FS);
                iFS = iPomFS;
                float fPomFSpom = atof(FSpom);
                fFSpom = fPomFSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setFSpom(char *FSpom){
                float fPomFSpom = atof(FSpom);
                fFSpom = fPomFSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTS(int TS){
                iTS = TS;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTS(int TS, float TSpom){
                iTS = TS;
                fTSpom = TSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTSpom(float TSpom){
                fTSpom = TSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTS(char *TS){
                int iPomTS = atoi(TS);
                iTS = iPomTS;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTS(char *TS, char *TSpom){
                int iPomTS = atoi(TS);
                iTS = iPomTS;
                float fPomTSpom = atof(TSpom);
                fTSpom = fPomTSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTSpom(char *TSpom){
                float fPomTSpom = atof(TSpom);
                fTSpom = fPomTSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZS(int ZS){
                iZS = ZS;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZS(int ZS, float ZSpom){
                iZS = ZS;
                fZSpom = ZSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZSpom(float ZSpom){
                fZSpom = ZSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZS(char *ZS){
                int iPomZS = atoi(ZS);
                iZS = iPomZS;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZS(char *ZS, char *ZSpom){
                int iPomZS = atoi(ZS);
                iZS = iPomZS;
                float fPomZSpom = atof(ZSpom);
                fZSpom = fPomZSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZSpom(char *ZSpom){
                float fPomZSpom = atof(ZSpom);
                fZSpom = fPomZSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setEnergie(float Energie){
                fEnergie = Energie;
}
//---------------------------------------------------------------------------------------------

void Hrac::setEnergie(char *Energie){
                float fPomEnergie = atof(Energie);
                fEnergie = fPomEnergie;
}
//---------------------------------------------------------------------------------------------

void Hrac::setSestava(int Sestava){
                iSestava = Sestava;
}
//---------------------------------------------------------------------------------------------

void Hrac::setSestava(char *Sestava){
                int iPomSestava = atoi(Sestava);
                iSestava = iPomSestava;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZapasy(int ZapasyCelkem, int ZapasyPohar, int ZapasyLiga){
                iZapasyCelkem = ZapasyCelkem;
                iZapasyPohar = ZapasyPohar;
                iZapasyLiga = ZapasyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZapasy(char *ZapasyCelkem, char *ZapasyPohar, char *ZapasyLiga){
                int iPomZapasyCelkem = atoi(ZapasyCelkem);
                iZapasyCelkem = iPomZapasyCelkem;

                int iPomZapasyPohar = atoi(ZapasyPohar);
                iZapasyPohar = iPomZapasyPohar;

                int iPomZapasyLiga = atoi(ZapasyLiga);
                iZapasyLiga = iPomZapasyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZapasyC(int ZapasyCelkem){
                iZapasyCelkem = ZapasyCelkem;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZapasyC(char *ZapasyCelkem){
                int iPomZapasyCelkem = atoi(ZapasyCelkem);
                iZapasyCelkem = iPomZapasyCelkem;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZapasyP(int ZapasyPohar){
                iZapasyPohar = ZapasyPohar;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZapasyP(char *ZapasyPohar){
                int iPomZapasyPohar = atoi(ZapasyPohar);
                iZapasyPohar = iPomZapasyPohar;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZapasyL(int ZapasyLiga){
                iZapasyLiga = ZapasyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZapasyL(char *ZapasyLiga){
                int iPomZapasyLiga = atoi(ZapasyLiga);
                iZapasyLiga = iPomZapasyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setGoly(int GolyCelkem, int GolyPohar, int GolyLiga){
                iGolyCelkem = GolyCelkem;
                iGolyPohar = GolyPohar;
                iGolyLiga = GolyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setGoly(char *GolyCelkem, char *GolyPohar, char *GolyLiga){
                int iPomGolyCelkem = atoi(GolyCelkem);
                iGolyCelkem = iPomGolyCelkem;

                int iPomGolyPohar = atoi(GolyPohar);
                iGolyPohar = iPomGolyPohar;

                int iPomGolyLiga = atoi(GolyLiga);
                iGolyLiga = iPomGolyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setGolyC(int GolyCelkem){
                iGolyCelkem = GolyCelkem;
}
//---------------------------------------------------------------------------------------------

void Hrac::setGolyC(char *GolyCelkem){
                int iPomGolyCelkem = atoi(GolyCelkem);
                iGolyCelkem = iPomGolyCelkem;
}
//---------------------------------------------------------------------------------------------

void Hrac::setGolyP(int GolyPohar){
                iGolyPohar = GolyPohar;
}
//---------------------------------------------------------------------------------------------

void Hrac::setGolyP(char *GolyPohar){
                int iPomGolyPohar = atoi(GolyPohar);
                iGolyPohar = iPomGolyPohar;
}
//---------------------------------------------------------------------------------------------

void Hrac::setGolyL(int GolyLiga){
                iGolyLiga = GolyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setGolyL(char *GolyLiga){
                int iPomGolyLiga = atoi(GolyLiga);
                iGolyLiga = iPomGolyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setAsistence(int AsistenceCelkem, int AsistencePohar, int AsistenceLiga){
                iAsistenceCelkem = AsistenceCelkem;
                iAsistencePohar = AsistencePohar;
                iAsistenceLiga = AsistenceLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setAsistence(char *AsistenceCelkem, char *AsistencePohar, char *AsistenceLiga){
                int iPomAsistenceCelkem = atoi(AsistenceCelkem);
                iAsistenceCelkem = iPomAsistenceCelkem;

                int iPomAsistencePohar = atoi(AsistencePohar);
                iAsistencePohar = iPomAsistencePohar;

                int iPomAsistenceLiga = atoi(AsistenceLiga);
                iAsistenceLiga = iPomAsistenceLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setAsistenceC(int AsistenceCelkem){
                iAsistenceCelkem = AsistenceCelkem;
}
//---------------------------------------------------------------------------------------------

void Hrac::setAsistenceC(char *AsistenceCelkem){
                int iPomAsistenceCelkem = atoi(AsistenceCelkem);
                iAsistenceCelkem = iPomAsistenceCelkem;
}
//---------------------------------------------------------------------------------------------

void Hrac::setAsistenceP(int AsistencePohar){
                iAsistencePohar = AsistencePohar;
}
//---------------------------------------------------------------------------------------------

void Hrac::setAsistenceP(char *AsistencePohar){
                int iPomAsistencePohar = atoi(AsistencePohar);
                iAsistencePohar = iPomAsistencePohar;
}
//---------------------------------------------------------------------------------------------

void Hrac::setAsistenceL(int AsistenceLiga){
                iAsistenceLiga = AsistenceLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setAsistenceL(char *AsistenceLiga){
                int iPomAsistenceLiga = atoi(AsistenceLiga);
                iAsistenceLiga = iPomAsistenceLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTresty(int TrestyCelkem, int TrestyPohar, int TrestyLiga){
                iTrestyCelkem = TrestyCelkem;
                iTrestyPohar = TrestyPohar;
                iTrestyLiga = TrestyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTresty(char *TrestyCelkem, char *TrestyPohar, char *TrestyLiga){
                int iPomTrestyCelkem = atoi(TrestyCelkem);
                iTrestyCelkem = iPomTrestyCelkem;

                int iPomTrestyPohar = atoi(TrestyPohar);
                iTrestyPohar = iPomTrestyPohar;

                int iPomTrestyLiga = atoi(TrestyLiga);
                iTrestyLiga = iPomTrestyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTrestyC(int TrestyCelkem){
                iTrestyCelkem = TrestyCelkem;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTrestyC(char *TrestyCelkem){
                int iPomTrestyCelkem = atoi(TrestyCelkem);
                iTrestyCelkem = iPomTrestyCelkem;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTrestyP(int TrestyPohar){
                iTrestyPohar = TrestyPohar;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTrestyP(char *TrestyPohar){
                int iPomTrestyPohar = atoi(TrestyPohar);
                iTrestyPohar = iPomTrestyPohar;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTrestyL(int TrestyLiga){
                iTrestyLiga = TrestyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTrestyL(char *TrestyLiga){
                int iPomTrestyLiga = atoi(TrestyLiga);
                iTrestyLiga = iPomTrestyLiga;
}
//---------------------------------------------------------------------------------------------

void Hrac::setSmlouva(int Smlouva){
                iSmlouva = Smlouva;
}
//---------------------------------------------------------------------------------------------

void Hrac::setSmlouva(char *Smlouva){
                int iPomSmlouva = atoi(Smlouva);
                iSmlouva = iPomSmlouva;
}
//---------------------------------------------------------------------------------------------

int Hrac::getID(){
                return iID;
}
//---------------------------------------------------------------------------------------------

char Hrac::getPost(){
                return cPost;
}
//---------------------------------------------------------------------------------------------

int Hrac::getCislo(){
                return iCislo;
}
//---------------------------------------------------------------------------------------------

String Hrac::getJmeno(){
                return cJmeno;
}
//---------------------------------------------------------------------------------------------

String Hrac::getJmeno2(){
                return cJmeno2;
}
//---------------------------------------------------------------------------------------------

String Hrac::getPrijmeni(){
                return cPrijmeni;
}
//---------------------------------------------------------------------------------------------

int Hrac::getVek(){
                return (2007 - iVek);
}
//---------------------------------------------------------------------------------------------

int Hrac::getFS(){
                return iFS;
}
//---------------------------------------------------------------------------------------------

float Hrac::getFSpom(){
                return fFSpom;
}
//---------------------------------------------------------------------------------------------

int Hrac::getTS(){
                return iTS;
}
//---------------------------------------------------------------------------------------------

float Hrac::getTSpom(){
                return fTSpom;
}
//---------------------------------------------------------------------------------------------

int Hrac::getZS(){
                return iZS;
}
//---------------------------------------------------------------------------------------------

float Hrac::getZSpom(){
                return fZSpom;
}
//---------------------------------------------------------------------------------------------

int Hrac::getEnergie(){
                return fEnergie;
}
//---------------------------------------------------------------------------------------------

int Hrac::getSestava(){
                return iSestava;
}
//---------------------------------------------------------------------------------------------

int Hrac::getZapasyC(){
                return iZapasyCelkem;
}
//---------------------------------------------------------------------------------------------

int Hrac::getZapasyP(){
                return iZapasyPohar;
}
//---------------------------------------------------------------------------------------------

int Hrac::getZapasyL(){
                return iZapasyLiga;
}
//---------------------------------------------------------------------------------------------

int Hrac::getGolyC(){
                return iGolyCelkem;
}
//---------------------------------------------------------------------------------------------

int Hrac::getGolyP(){
                return iGolyPohar;
}
//---------------------------------------------------------------------------------------------

int Hrac::getGolyL(){
                return iGolyLiga;
}
//---------------------------------------------------------------------------------------------

int Hrac::getAsistenceC(){
                return iAsistenceCelkem;
}
//---------------------------------------------------------------------------------------------

int Hrac::getAsistenceP(){
                return iAsistencePohar;
}
//---------------------------------------------------------------------------------------------

int Hrac::getAsistenceL(){
                return iAsistenceLiga;
}
//---------------------------------------------------------------------------------------------

int Hrac::getTrestyC(){
                return iTrestyCelkem;
}
//---------------------------------------------------------------------------------------------

int Hrac::getTrestyP(){
                return iTrestyPohar;
}
//---------------------------------------------------------------------------------------------

int Hrac::getTrestyL(){
                return iTrestyLiga;
}
//---------------------------------------------------------------------------------------------

int Hrac::getSmlouva(){
                return iSmlouva;
}
//---------------------------------------------------------------------------------------------
