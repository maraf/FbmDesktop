#include "Tym.h"
//---------------------------------------------------------------------------------------------

Tym::Tym(){
                cNazevTymu = " ";
                cNazevHaly = " ";
                cLogo = "default.bmp";
                iKapacitaHaly = 0;
                iPocetHracu = 0;
                iSponzor = 0;
                
                for(int iHrac = 0; iHrac < 20; iHrac ++)
                        Hraci[iHrac] = new Hrac();
                
                iVyhryP = 0;
                iVyhryL = 0;
                iRemizyL = 0;
                iProhryP = 0;
                iProhryL = 0;
                iDaneGP = 0;
                iDaneGL = 0;
                iObdrzeneGP = 0;
                iObdrzeneGL = 0;
                iBodyL = 0;
}
//---------------------------------------------------------------------------------------------

Tym::Tym(String NazevTymu, String NazevHaly, String Logo, int KapacitaHaly, int PocetHracu, int Sponzor){
                cNazevTymu = NazevTymu;
                cNazevHaly = NazevHaly;
                cLogo = Logo;
                iKapacitaHaly = KapacitaHaly;
                iPocetHracu = PocetHracu;
                iSponzor = Sponzor;
                
                for(int iHrac = 0; iHrac < 20; iHrac ++)
                        Hraci[iHrac] = new Hrac();
                
                iVyhryP = 0;
                iVyhryL = 0;
                iRemizyL = 0;
                iProhryP = 0;
                iProhryL = 0;
                iDaneGP = 0;
                iDaneGL = 0;
                iObdrzeneGP = 0;
                iObdrzeneGL = 0;
                iBodyL = 0;
}
//---------------------------------------------------------------------------------------------

Tym::~Tym(){
                for(int iHrac = 0; iHrac < 20; iHrac ++)
                        delete(Hraci[iHrac]);
}
//---------------------------------------------------------------------------------------------

void Tym::setNazevTymu(String NazevTymu){
                cNazevTymu = NazevTymu;
}
//---------------------------------------------------------------------------------------------

void Tym::setNazevHaly(String NazevHaly){
                cNazevHaly = NazevHaly;
}
//---------------------------------------------------------------------------------------------

void Tym::setLogo(String Logo){
                cLogo = Logo;
}
//---------------------------------------------------------------------------------------------

void Tym::setKapacitaHaly(int KapacitaHaly){
                iKapacitaHaly = KapacitaHaly;
}
//---------------------------------------------------------------------------------------------

void Tym::setPocetHracu(int PocetHracu){
                iPocetHracu = PocetHracu;
}
//---------------------------------------------------------------------------------------------

void Tym::setSponzor(int Sponzor){
                iSponzor = Sponzor;
}
//---------------------------------------------------------------------------------------------

void Tym::nactiHrace(String cNazevSouboru){
                FILE *fTeam;
                
                char cNazev[40];
                sprintf(cNazev, "%s", cNazevSouboru);

                fTeam = fopen(cNazev,"r");

                int i = 0;
                int iIndex = 0;
                int iHrac = 0;
                char cZnak;
                char cPole[30];
                
                iPocetHracu ++;
                
                while((cZnak = getc(fTeam)) != EOF){

                             if(cZnak != '-' && iIndex == 0){
                                      Hraci[iHrac]->setPost(cZnak);
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 1){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 2){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 3){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 4){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 5){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 6){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 7){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 8){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 9){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak == '-'){
                                      i = 0;
                                      switch(iIndex){
                                                     case 1: Hraci[iHrac]->setCislo(cPole); break;
                                                     case 2: Hraci[iHrac]->setSestava(cPole); break;
                                                     case 3: Hraci[iHrac]->setJmeno(cPole); break;
                                                     case 4: Hraci[iHrac]->setPrijmeni(cPole);break;
                                                     case 5: Hraci[iHrac]->setVek(cPole); break;
                                                     case 6: Hraci[iHrac]->setFS(cPole); break;
                                                     case 7: Hraci[iHrac]->setTS(cPole); break;
                                                     case 8: Hraci[iHrac]->setZS(cPole); break;
                                                     case 9: Hraci[iHrac]->setSmlouva(cPole); break;
                                      }
                                      iIndex ++;
                             }
                             if(cZnak == '\n'){
                                      iHrac ++;
                                      i = 0;
                                      iIndex = 0;
                                      iPocetHracu ++;
                             }
                }

                fclose(fTeam);
}
//---------------------------------------------------------------------------------------------

void Tym::ulozHrace(String cNazevSouboru){
                FILE *fTeam;
     
                char cNazev[40];
                sprintf(cNazev, "%s", cNazevSouboru);

                fTeam = fopen(cNazev,"w");

                int iHrac = 0;

                while(iHrac < iPocetHracu){
                            fprintf(fTeam, "%c-%i-%i-%s-%s-%i-%i-%i-%i-%i-", Hraci[iHrac]->getPost(), Hraci[iHrac]->getCislo(), Hraci[iHrac]->getSestava(), Hraci[iHrac]->getJmeno(), Hraci[iHrac]->getPrijmeni(), Hraci[iHrac]->getVek(), Hraci[iHrac]->getFS(), Hraci[iHrac]->getTS(), Hraci[iHrac]->getZS(), Hraci[iHrac]->getSmlouva());
                            if(iHrac < (iPocetHracu - 1))
                                     fprintf(fTeam, "\n");
                            iHrac ++;
                }
                
                fclose(fTeam);
}
//---------------------------------------------------------------------------------------------

void Tym::setridHrace(char cPodle, bool bVzestupne){

    switch(cPodle){
           case 'P': Hraci_sort_post(bVzestupne); break;
           case 'J': Hraci_sort_jmeno(bVzestupne); break;
           case 'C': Hraci_sort_cislo(bVzestupne); break;
           case 'V': Hraci_sort_vek(bVzestupne); break;
           case 'F': Hraci_sort_fs(bVzestupne); break;
           case 'T': Hraci_sort_ts(bVzestupne); break;
           case 'Z': Hraci_sort_zs(bVzestupne); break;
           case 'L': Hraci_sort_lineup(bVzestupne); break;
           case 'S': Hraci_sort_smlouva(bVzestupne); break;
    }
}
//---------------------------------------------------------------------------------------------

void Tym::Hraci_sort_post(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getPost() < Hraci[i]->getPost()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    i ++;
            }
            if(bVzestupne) i = 0;
            else i = j + 1;

            j ++;
    }

     delete(HrPomocny);
}
//---------------------------------------------------------------------------------------------

void Tym::Hraci_sort_jmeno(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getPrijmeni() < Hraci[i]->getPrijmeni()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    i ++;
            }
            if(bVzestupne) i = 0;
            else i = j + 1;

            j ++;
    }

     delete(HrPomocny);
}
//---------------------------------------------------------------------------------------------

void Tym::Hraci_sort_cislo(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getCislo() < Hraci[i]->getCislo()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    i ++;
            }
            if(bVzestupne) i = 0;
            else i = j + 1;

            j ++;
    }

     delete(HrPomocny);
}
//---------------------------------------------------------------------------------------------

void Tym::Hraci_sort_vek(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getVek() < Hraci[i]->getVek()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    i ++;
            }
            if(bVzestupne) i = 0;
            else i = j + 1;

            j ++;
    }

     delete(HrPomocny);
}
//---------------------------------------------------------------------------------------------

void Tym::Hraci_sort_fs(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getFS() < Hraci[i]->getFS()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    i ++;
            }
            if(bVzestupne) i = 0;
            else i = j + 1;

            j ++;
    }

     delete(HrPomocny);
}
//---------------------------------------------------------------------------------------------

void Tym::Hraci_sort_ts(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getTS() < Hraci[i]->getTS()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    i ++;
            }
            if(bVzestupne) i = 0;
            else i = j + 1;

            j ++;
    }

     delete(HrPomocny);
}
//---------------------------------------------------------------------------------------------

void Tym::Hraci_sort_zs(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getZS() < Hraci[i]->getZS()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    i ++;
            }
            if(bVzestupne) i = 0;
            else i = j + 1;

            j ++;
    }

     delete(HrPomocny);
}
//---------------------------------------------------------------------------------------------

void Tym::Hraci_sort_lineup(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getSestava() < Hraci[i]->getSestava()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    if(Hraci[j]->getSestava() == Hraci[i]->getSestava()){              
                                if(Hraci[j]->getPost() < Hraci[i]->getPost()){
          
                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;

                                }
                    }
                    i ++;
            }
            if(!bVzestupne) i = j + 1;
            else i = 0;

            j ++;
    }

     delete(HrPomocny);
}
//---------------------------------------------------------------------------------------------

void Tym::Hraci_sort_smlouva(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getSmlouva() < Hraci[i]->getSmlouva()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    i ++;
            }
            if(bVzestupne) i = 0;
            else i = j + 1;

            j ++;
    }

     delete(HrPomocny);
}
//---------------------------------------------------------------------------------------------

void Tym::setVyhryP(int VyhryP){
                iVyhryP = VyhryP;
}
//---------------------------------------------------------------------------------------------

void Tym::setVyhryL(int VyhryL){
                iVyhryL = VyhryL;
}
//---------------------------------------------------------------------------------------------

void Tym::setRemizyL(int RemizyL){
                iRemizyL = RemizyL;
}
//---------------------------------------------------------------------------------------------

void Tym::setProhryP(int ProhryP){
                iProhryP = iProhryP;
}
//---------------------------------------------------------------------------------------------

void Tym::setProhryL(int ProhryL){
                iProhryL = ProhryL;
}
//---------------------------------------------------------------------------------------------

void Tym::setDaneGP(int DaneGP){
                iDaneGP = DaneGP;
}
//---------------------------------------------------------------------------------------------

void Tym::setDaneGL(int DaneGL){
                iDaneGL = DaneGL;
}
//---------------------------------------------------------------------------------------------

void Tym::setObdrzeneGP(int ObdrzeneGP){
                iObdrzeneGP = ObdrzeneGP;
}
//---------------------------------------------------------------------------------------------

void Tym::setObdrzeneGL(int ObdrzeneGL){
                iObdrzeneGL = ObdrzeneGL;
}
//---------------------------------------------------------------------------------------------

void Tym::setBodyL(int BodyL){
                iBodyL = BodyL;
}
//---------------------------------------------------------------------------------------------

String Tym::getNazevTymu(){
                return cNazevTymu;
}
//---------------------------------------------------------------------------------------------

String Tym::getNazevHaly(){
                return cNazevHaly;
}
//---------------------------------------------------------------------------------------------

String Tym::getLogo(){
                return cLogo;
}
//---------------------------------------------------------------------------------------------

int Tym::getKapacitaHaly(){
                return iKapacitaHaly;
}
//---------------------------------------------------------------------------------------------

int Tym::getPocetHracu(){
                return iPocetHracu;
}
//---------------------------------------------------------------------------------------------

int Tym::getSponzor(){
                return iSponzor;
}
//---------------------------------------------------------------------------------------------

int Tym::getCelkoveFS(){
                int i = 0;
                int iCelkove = 0;

                while(i < iPocetHracu){
                        iCelkove += Hraci[i]->getFS();
                        i ++;
                }
                return iCelkove;
}
//---------------------------------------------------------------------------------------------

int Tym::getCelkoveFS(int PrvniHrac, int PosledniHrac){
                int iCelkove = 0;
                
                while(PrvniHrac < PosledniHrac){
                        iCelkove += Hraci[PrvniHrac]->getFS();
                        PrvniHrac ++;
                }
                return iCelkove;
}
//---------------------------------------------------------------------------------------------

int Tym::getCelkoveTS(){
                int i = 0;
                int iCelkove = 0;

                while(i < iPocetHracu){
                        iCelkove += Hraci[i]->getTS();
                        i ++;
                }
                return iCelkove;
}
//---------------------------------------------------------------------------------------------

int Tym::getCelkoveTS(int PrvniHrac, int PosledniHrac){
                int iCelkove = 0;
                
                while(PrvniHrac < PosledniHrac){
                        iCelkove += Hraci[PrvniHrac]->getTS();
                        PrvniHrac ++;
                }
                return iCelkove;
}
//---------------------------------------------------------------------------------------------

int Tym::getCelkoveZS(){
                int i = 0;
                int iCelkove = 0;

                while(i < iPocetHracu){
                        iCelkove += Hraci[i]->getZS();
                        i ++;
                }
                return iCelkove;
}
//---------------------------------------------------------------------------------------------

int Tym::getCelkoveZS(int PrvniHrac, int PosledniHrac){
                int iCelkove = 0;
                
                while(PrvniHrac < PosledniHrac){
                        iCelkove += Hraci[PrvniHrac]->getZS();
                        PrvniHrac ++;
                }
                return iCelkove;
}
//---------------------------------------------------------------------------------------------

int Tym::getZapasyC(){
                return (iVyhryL + iVyhryP + iRemizyL + iProhryP + iProhryL);
}
//---------------------------------------------------------------------------------------------

int Tym::getZapasyP(){
                return (iVyhryP + iProhryP);
}
//---------------------------------------------------------------------------------------------

int Tym::getZapasyL(){
                return (iVyhryL + iProhryL);
}
//---------------------------------------------------------------------------------------------

int Tym::getVyhryC(){
                return (iVyhryP + iVyhryP);
}
//---------------------------------------------------------------------------------------------

int Tym::getVyhryP(){
                return iVyhryP;
}
//---------------------------------------------------------------------------------------------

int Tym::getVyhryL(){
                return iVyhryL;
}
//---------------------------------------------------------------------------------------------

int Tym::getRemizyL(){
                return iRemizyL;
}
//---------------------------------------------------------------------------------------------

int Tym::getProhryC(){
                return (iProhryP + iProhryL);
}
//---------------------------------------------------------------------------------------------

int Tym::getProhryP(){
                return iProhryP;
}
//---------------------------------------------------------------------------------------------

int Tym::getProhryL(){
                return iProhryL;
}
//---------------------------------------------------------------------------------------------

int Tym::getDaneGC(){
                return (iDaneGP + iDaneGL);
}
//---------------------------------------------------------------------------------------------

int Tym::getDaneGP(){
                return iDaneGP;
}
//---------------------------------------------------------------------------------------------

int Tym::getDaneGL(){
                return iDaneGL;
}
//---------------------------------------------------------------------------------------------

int Tym::getObdrzeneGC(){
                return (iObdrzeneGP + iObdrzeneGL);
}
//---------------------------------------------------------------------------------------------

int Tym::getObdrzeneGP(){
                return iObdrzeneGP;
}
//---------------------------------------------------------------------------------------------

int Tym::getObdrzeneGL(){
                return iObdrzeneGL;
}
//---------------------------------------------------------------------------------------------

int Tym::getBodyL(){
                return iBodyL;
}
//---------------------------------------------------------------------------------------------
