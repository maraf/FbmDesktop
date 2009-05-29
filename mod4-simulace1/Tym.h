
#ifndef TymH
#define TymH

#include <StdCtrls.hpp>
#include <stdio.h>
#include "Hrac.h"

class Tym{

      private:
              String cNazevTymu;
              String cNazevHaly;
              String cLogo;
              int iKapacitaHaly;
              int iPocetHracu;
              int iSponzor;

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
              
              void Hraci_sort_post(bool bVzestupne);
              void Hraci_sort_jmeno(bool bVzestupne);
              void Hraci_sort_cislo(bool bVzestupne);
              void Hraci_sort_vek(bool bVzestupne);
              void Hraci_sort_fs(bool bVzestupne);
              void Hraci_sort_ts(bool bVzestupne);
              void Hraci_sort_zs(bool bVzestupne);
              void Hraci_sort_lineup(bool bVzestupne);
              void Hraci_sort_smlouva(bool bVzestupne);
      
      public:
              Hrac *Hraci[30];

              Tym();
              Tym(String NazevTymu, String NazevHaly, String cLogo, int KapacitaHaly, int PocetHracu, int Sponzor);
              ~Tym();
              
              void setNazevTymu(String NazevTymu);
              void setNazevHaly(String NazevHaly);
              void setLogo(String Logo);
              void setKapacitaHaly(int KapacitaHaly);
              void setPocetHracu(int PocetHracu);
              void setSponzor(int Sponzor);

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


              String getNazevTymu();
              String getNazevHaly();
              String getLogo();
              int getKapacitaHaly();
              int getPocetHracu();
              int getSponzor();
              
              int getCelkoveFS();
              int getCelkoveFS(int PrvniHrac, int PosledniHrac);
              int getCelkoveTS();
              int getCelkoveTS(int PrvniHrac, int PosledniHrac);
              int getCelkoveZS();
              int getCelkoveZS(int PrvniHrac, int PosledniHrac);

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

      
};

#endif
