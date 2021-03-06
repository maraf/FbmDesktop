
#ifndef TymH
#define TymH

#include <StdCtrls.hpp>
#include <stdio.h>
#include "Hrac.h"

class Tym{

      private:
              int iID;
              String cNazevTymu;
              String cNazevTymuKr;
              String cNazevHaly;
              String cLogo;
              String cHala;
              int iKapacitaHaly;
              int iPocetHracu;
              int iSponzor;
              int iPocetLajn;
              int iDobaStridani;

              int iR1;
              int iG1;
              int iB1;
              int iR2;
              int iG2;
              int iB2;

              int iVyhryP;
              int iVyhryL;
              int iRemizyL;
              int iProhryP;
              int iProhryL;
              int iDaneGP;
              int iDaneGL;
              int iObdrzeneGP;
              int iObdrzeneGL;
              int iBodyL;
              int iUmisteni;

              void Hraci_sort_post(bool bVzestupne);
              void Hraci_sort_jmeno(bool bVzestupne);
              void Hraci_sort_cislo(bool bVzestupne);
              void Hraci_sort_vek(bool bVzestupne);
              void Hraci_sort_fs(bool bVzestupne);
              void Hraci_sort_ts(bool bVzestupne);
              void Hraci_sort_zs(bool bVzestupne);
              void Hraci_sort_lineup(bool bVzestupne);
              void Hraci_sort_smlouva(bool bVzestupne);
              void Hraci_sort_celkove(bool bVzestupne);

      public:
              Hrac *Hraci[30];

              Tym();
              Tym(int id, String NazevTymu, String NazevTymuKr, String NazevHaly, String cLogo, int KapacitaHaly, int PocetHracu, int PocetLajn, int DobaStridani, int Sponzor);
              ~Tym();

              void setID(int id);
              void setNazevTymu(String NazevTymu);
              void setNazevTymuKr(String NazevTymuKr);
              void setNazevHaly(String NazevHaly);
              void setLogo(String Logo);
              void setKapacitaHaly(int KapacitaHaly);
              void setPocetHracu(int PocetHracu);
              void setSponzor(int Sponzor);
              void setPocetLajn(int PocetLajn);
              void setDobaStridani(int DobaStridani);

              void nactiTym(String cNazevSouboru);
              void ulozTym(String cNazevSouboru);

              void nactiHrace(String cNazevSouboru);
              void ulozHrace(String cNazevSouboru);
              void setridHrace(char cPodle, bool bVzestupne);

              void setVyhryP(int VyhryP);
              void setVyhryL(int VyhryL);
              void setRemizyL(int RemizyL);
              void setProhryP(int ProhryP);
              void setProhryL(int ProhryL);
              void setDaneGP(int DaneGP);
              void setDaneGL(int DaneGL);
              void setObdrzeneGP(int ObdrzeneGP);
              void setObdrzeneGL(int ObdrzeneGL);
              void setBodyL(int BodyL);
              void setUmisteni(int Umisteni);


              int getID();
              String getNazevTymu();
              String getNazevTymuKr();
              String getNazevHaly();
              String getLogo();
              String getHala();
              int getKapacitaHaly();
              int getPocetHracu();
              int getSponzor();
              int getPocetLajn();
              int getDobaStridani();

              int getR1();
              int getG1();
              int getB1();
              int getR2();
              int getG2();
              int getB2();
              
              int getCelkoveFS();
              int getCelkoveFS(int PrvniHrac, int PosledniHrac);
              int getCelkoveTS();
              int getCelkoveTS(int PrvniHrac, int PosledniHrac);
              int getCelkoveZS();
              int getCelkoveZS(int PrvniHrac, int PosledniHrac);
              int getCelkoveEN();
              int getCelkoveEN(int PrvniHrac, int PosledniHrac);

              int getZapasyC();
              int getZapasyP();
              int getZapasyL();
              int getVyhryC();
              int getVyhryP();
              int getVyhryL();
              int getRemizyL();
              int getProhryC();
              int getProhryP();
              int getProhryL();
              int getDaneGC();
              int getDaneGP();
              int getDaneGL();
              int getObdrzeneGC();
              int getObdrzeneGP();
              int getObdrzeneGL();
              int getBodyL();
              int getUmisteni();

      
};

#endif
