#include "Hrac.h"
//---------------------------------------------------------------------------------------------

Hrac::Hrac(){
                cPost = ' ';
                cJmeno = ' ';
                cPrijmeni = ' ';
                iVek = 0;
                iFS = 0;
                iFSpom = 0;
                iTS = 0;
                iTSpom = 0;
                iZS = 0;
                iZSpom = 0;
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

Hrac::Hrac(char Post, int Cislo, String Jmeno, String Prijmeni, int Vek, int FS, int TS, int ZS, int Smlouva){
                cPost = Post;
                iCislo = Cislo;
                cJmeno = Jmeno;
                cPrijmeni = Prijmeni;
                iVek = Vek;
                iFS = FS;
                iFSpom = 0;
                iTS = TS;
                iTSpom = 0;
                iZS = ZS;
                iZSpom = 0;
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

void Hrac::setFS(int FS, int FSpom){
                iFS = FS;
                iFSpom = FSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setFSpom(int FSpom){
                iFSpom = FSpom;
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
                int iPomFSpom = atoi(FSpom);
                iFS = iPomFSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setFSpom(char *FSpom){
                int iPomFSpom = atoi(FSpom);
                iFSpom = iPomFSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTS(int TS){
                iTS = TS;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTS(int TS, int TSpom){
                iTS = TS;
                iTSpom = TSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTSpom(int TSpom){
                iTSpom = TSpom;
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
                int iPomTSpom = atoi(TSpom);
                iTSpom = iPomTSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setTSpom(char *TSpom){
                int iPomTSpom = atoi(TSpom);
                iTSpom = iPomTSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZS(int ZS){
                iZS = ZS;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZS(int ZS, int ZSpom){
                iZS = ZS;
                iZSpom = ZSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZSpom(int ZSpom){
                iZSpom = ZSpom;
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
                int iPomZSpom = atoi(ZSpom);
                iZSpom = iPomZSpom;
}
//---------------------------------------------------------------------------------------------

void Hrac::setZSpom(char *ZSpom){
                int iPomZSpom = atoi(ZSpom);
                iZSpom = iPomZSpom;
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
                return iVek;
}
//---------------------------------------------------------------------------------------------

int Hrac::getFS(){
                return iFS;
}
//---------------------------------------------------------------------------------------------

int Hrac::getFSpom(){
                return iFSpom;
}
//---------------------------------------------------------------------------------------------

int Hrac::getTS(){
                return iTS;
}
//---------------------------------------------------------------------------------------------

int Hrac::getTSpom(){
                return iTSpom;
}
//---------------------------------------------------------------------------------------------

int Hrac::getZS(){
                return iZS;
}
//---------------------------------------------------------------------------------------------

int Hrac::getZSpom(){
                return iZSpom;
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
