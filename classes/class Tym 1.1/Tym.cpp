/*------------------------------------------------------------------------------------------*/
/*                                class Tym                                                 */
/*                                verze 1.1                                                 */
/*------------------------------------------------------------------------------------------*/
#include "Tym.h"
//---------------------------------------------------------------------------------------------

Tym::Tym(){
                cNazevTymu = " ";
                cNazevTymuKr = " ";
                cNazevHaly = " ";
                cLogo = "default.bmp";
                iKapacitaHaly = 0;
                iPocetHracu = 0;
                iSponzor = 0;
                iPocetLajn = 2;
                iDobaStridani = 2;
                iTraining = 0;
                fTrainingIntensity = 0;

                iR1 = 0;
                iG1 = 0;
                iB1 = 0;
                iR2 = 255;
                iG2 = 255;
                iB2 = 255;
                
                for(int iHrac = 0; iHrac < 30; iHrac ++)
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
                iDaneSL = 0;
                iObdrzeneSL = 0;
                iBodyL = 0;
                iUmisteni = 12;
}
//---------------------------------------------------------------------------------------------

Tym::Tym(int id, String NazevTymu, String NazevTymuKr, String NazevHaly, String Logo, int KapacitaHaly, int PocetHracu, int PocetLajn, int DobaStridani, int Sponzor){
                cNazevTymu = NazevTymu;
                cNazevTymuKr = NazevTymuKr;
                cNazevHaly = NazevHaly;
                cLogo = Logo;
                iKapacitaHaly = KapacitaHaly;
                iPocetHracu = PocetHracu;
                iSponzor = Sponzor;
                iPocetLajn = PocetLajn;
                iDobaStridani = DobaStridani;
                iTraining = 0;
                fTrainingIntensity = 0;

                iR1 = 0;
                iG1 = 0;
                iB1 = 0;
                iR2 = 255;
                iG2 = 255;
                iB2 = 255;
                
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
                iDaneSL = 0;
                iObdrzeneSL = 0;
                iBodyL = 0;
                iUmisteni = 12;
}
//---------------------------------------------------------------------------------------------

Tym::~Tym(){
                for(int iHrac = 0; iHrac < 30; iHrac ++)
                        delete(Hraci[iHrac]);
}
//---------------------------------------------------------------------------------------------

void Tym::setID(int id){
                iID = id;
}
//---------------------------------------------------------------------------------------------

void Tym::setNazevTymu(String NazevTymu){
                cNazevTymu = NazevTymu;
}
//---------------------------------------------------------------------------------------------

void Tym::setNazevTymuKr(String NazevTymuKr){
                cNazevTymuKr = NazevTymuKr;
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

void Tym::setPocetLajn(int PocetLajn){
                iPocetLajn = PocetLajn;
}
//---------------------------------------------------------------------------------------------

void Tym::setDobaStridani(int DobaStridani){
                iDobaStridani = DobaStridani;
}
//---------------------------------------------------------------------------------------------

void Tym::setTraining(int Training) {
                iTraining = Training;
}
//---------------------------------------------------------------------------------------------

void Tym::setTrainingIntensity(float TrIn) {
                fTrainingIntensity = TrIn;
}
//---------------------------------------------------------------------------------------------

void Tym::trainingTeam() {
                for(int i = 0; i < getPocetHracu(); i ++) {
                        if(Hraci[i]->getEnergie() > (getTrainingIntensity() * 10)) {
                                if(getTraining() == 0) {
                                        Hraci[i]->setFSpom(Hraci[i]->getFSpom() + (3 * getTrainingIntensity()));
                                } else if(getTraining() == 1) {
                                        Hraci[i]->setTSpom(Hraci[i]->getTSpom() + (3 * getTrainingIntensity()));
                                }
                                Hraci[i]->setEnergie(Hraci[i]->getEnergie() - (getTrainingIntensity() * 10));
                        }
                }
}
//---------------------------------------------------------------------------------------------

void Tym::nactiTym(String cNazevSouboru){
                FILE *fTeam;

                char cNazev[40];
                sprintf(cNazev, "%s", cNazevSouboru);

                fTeam = fopen(cNazev,"r");

                int i = 0;
                int iLine = 1;
                char cZnak;
                char cPole[30];

                while((cZnak = getc(fTeam)) != EOF){
                             if(cZnak != '-' && cZnak != '\n'){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak == '-'){
                                      i = 0;
                                      switch(iLine){
                                                     case 1: cNazevTymu = cPole; break;
                                                     case 2: cNazevTymuKr = cPole; break;
                                                     case 3: cNazevHaly = cPole; break;
                                                     case 4: iKapacitaHaly = atoi(cPole); break;
                                                     case 5: iR1 = atoi(cPole); break;
                                                     case 6: iG1 = atoi(cPole); break;
                                                     case 7: iB1 = atoi(cPole); break;
                                                     case 8: iR2 = atoi(cPole); break;
                                                     case 9: iG2 = atoi(cPole); break;
                                                     case 10: iB2 = atoi(cPole); break;
                                                     case 11: cLogo = cPole; break;
                                                     case 12: cHala = cPole; break;
                                      }
                                      iLine ++;
                             }
                             if(cZnak == '\n'){

                             }
                }

                fclose(fTeam);
}
//---------------------------------------------------------------------------------------------

void Tym::ulozTym(String cNazevSouboru){
                // implementace funkce
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
                             if(cZnak != '-' && iIndex == 10){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak == '-'){
                                      i = 0;
                                      switch(iIndex){                                     
                                                     case 1: Hraci[iHrac]->setID(cPole); break;
                                                     case 2: Hraci[iHrac]->setCislo(cPole); break;
                                                     case 3: Hraci[iHrac]->setSestava(cPole); break;
                                                     case 4: Hraci[iHrac]->setJmeno(cPole); break;
                                                     case 5: Hraci[iHrac]->setPrijmeni(cPole);break;
                                                     case 6: Hraci[iHrac]->setFS(cPole); break;
                                                     case 7: Hraci[iHrac]->setTS(cPole); break;
                                                     case 8: Hraci[iHrac]->setZS(cPole); break;
                                                     case 9: Hraci[iHrac]->setVek(cPole); break;
                                                     case 10: Hraci[iHrac]->setSmlouva(2100); break;
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
           case 'A': Hraci_sort_celkove(bVzestupne); break;
           case 'G': Hraci_sort_golyL(bVzestupne); break;
           case 'H': Hraci_sort_asistenceL(bVzestupne); break;
           case 'B': Hraci_sort_kanBodyL(bVzestupne); break;
           case 'E': Hraci_sort_energie(bVzestupne); break;
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
                    if(Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

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
                    if(Hraci[j]->getPrijmeni() == Hraci[i]->getPrijmeni() && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getPrijmeni() == Hraci[i]->getPrijmeni() && Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

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
                    if(Hraci[j]->getCislo() == Hraci[i]->getCislo() && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getCislo() == Hraci[i]->getCislo() && Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

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
                    if(Hraci[j]->getVek() == Hraci[i]->getVek() && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getVek() == Hraci[i]->getVek() && Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

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
                    if(Hraci[j]->getFS() == Hraci[i]->getFS() && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getFS() == Hraci[i]->getFS() && Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

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
                    if(Hraci[j]->getTS() == Hraci[i]->getTS() && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getTS() == Hraci[i]->getTS() && Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

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
                    if(Hraci[j]->getZS() == Hraci[i]->getZS() && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getZS() == Hraci[i]->getZS() && Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

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
                    if(Hraci[j]->getSestava() == Hraci[i]->getSestava() && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getSestava() == Hraci[i]->getSestava() && Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
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

void Tym::Hraci_sort_celkove(bool bVzestupne){

    int i = 1;
    int j = 0;
    int iCelkem1 = 0;
    int iCelkem2 = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    iCelkem1 = Hraci[j]->getFS() + Hraci[j]->getTS() + Hraci[j]->getZS();
                    iCelkem2 = Hraci[i]->getFS() + Hraci[i]->getTS() + Hraci[i]->getZS();
                    if(iCelkem1 < iCelkem2){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    if(iCelkem1 == iCelkem2 && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(iCelkem1 == iCelkem2 && Hraci[j]->getVek() == Hraci[i]->getVek() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

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

void Tym::Hraci_sort_golyL(bool bVzestupne) {

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getGolyL() < Hraci[i]->getGolyL()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    if(Hraci[j]->getGolyL() == Hraci[i]->getGolyL() && (Hraci[j]->getGolyL() + Hraci[j]->getAsistenceL()) < (Hraci[i]->getGolyL() + Hraci[i]->getAsistenceL())){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getGolyL() == Hraci[i]->getGolyL() && (Hraci[j]->getGolyL() + Hraci[j]->getAsistenceL()) == (Hraci[i]->getGolyL() + Hraci[i]->getAsistenceL()) && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    i ++;
            }
            if(!bVzestupne) i = j + 1;
            else i = 0;

            j ++;
    }

     delete(HrPomocny);
}
//----------------------------------------------------------------------------------------------

void Tym::Hraci_sort_asistenceL(bool bVzestupne) {

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getAsistenceL() < Hraci[i]->getAsistenceL()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    if(Hraci[j]->getAsistenceL() == Hraci[i]->getAsistenceL() && (Hraci[j]->getGolyL() + Hraci[j]->getAsistenceL()) < (Hraci[i]->getGolyL() + Hraci[i]->getAsistenceL())){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getAsistenceL() == Hraci[i]->getAsistenceL() && (Hraci[j]->getGolyL() + Hraci[j]->getAsistenceL()) == (Hraci[i]->getGolyL() + Hraci[i]->getAsistenceL()) && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    i ++;
            }
            if(!bVzestupne) i = j + 1;
            else i = 0;

            j ++;
    }

     delete(HrPomocny);
}
//----------------------------------------------------------------------------------------------

void Tym::Hraci_sort_kanBodyL(bool bVzestupne) {

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if((Hraci[j]->getGolyL() + Hraci[j]->getAsistenceL())  < (Hraci[i]->getGolyL() + Hraci[i]->getAsistenceL())){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    if((Hraci[j]->getGolyL() + Hraci[j]->getAsistenceL()) == (Hraci[i]->getGolyL() + Hraci[i]->getAsistenceL()) && (Hraci[j]->getGolyL() + Hraci[j]->getAsistenceL()) < (Hraci[i]->getGolyL() + Hraci[i]->getAsistenceL())){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if((Hraci[j]->getGolyL() + Hraci[j]->getAsistenceL()) == (Hraci[i]->getGolyL() + Hraci[i]->getAsistenceL()) && (Hraci[j]->getGolyL() + Hraci[j]->getAsistenceL()) == (Hraci[i]->getGolyL() + Hraci[i]->getAsistenceL()) && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    i ++;
            }
            if(!bVzestupne) i = j + 1;
            else i = 0;

            j ++;
    }

     delete(HrPomocny);
}
//----------------------------------------------------------------------------------------------

void Tym::Hraci_sort_energie(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < iPocetHracu){
            while(i < iPocetHracu){
                    if(Hraci[j]->getEnergie() < Hraci[i]->getEnergie()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    if(Hraci[j]->getEnergie() == Hraci[i]->getEnergie() && Hraci[j]->getPost() < Hraci[i]->getPost()){

                                            *HrPomocny = *Hraci[j];
                                            *Hraci[j] = *Hraci[i];
                                            *Hraci[i] = *HrPomocny;
                    }
                    if(Hraci[j]->getEnergie() == Hraci[i]->getEnergie() && Hraci[j]->getPost() == Hraci[i]->getPost() && Hraci[j]->getCislo() < Hraci[i]->getCislo()){

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

void Tym::deletePlayerAt(int i) {
    for(int j = i; j < getPocetHracu(); j ++) {
          *Hraci[j] = *Hraci[j + 1];
    } 
    delete(Hraci[getPocetHracu() - 1]);
    Hraci[getPocetHracu() - 1] = new Hrac();
    iPocetHracu --;
}
//---------------------------------------------------------------------------------------------

void Tym::addPlayer(Hrac *Player) {
    *Hraci[getPocetHracu()] = *Player;
    iPocetHracu ++;
}
//---------------------------------------------------------------------------------------------

bool Tym::isFreeNumber(int number) {
    for(int i = 0; i < getPocetHracu(); i ++) {
        if(Hraci[i]->getCislo() == number) return false;
    }
    return true;
}
//---------------------------------------------------------------------------------------------

int Tym::getCountOfGoalkeepers() {
    int count = 0;
    for(int i = 0; i < getPocetHracu(); i ++) if(Hraci[i]->getPost() == 'G') count ++;
    return count;
}
//---------------------------------------------------------------------------------------------

int Tym::getCountOfDefenders() {
    int count = 0;
    for(int i = 0; i < getPocetHracu(); i ++) if(Hraci[i]->getPost() == 'O') count ++;
    return count;
}
//---------------------------------------------------------------------------------------------

int Tym::getCountOfAttackers() {
    int count = 0;
    for(int i = 0; i < getPocetHracu(); i ++) if(Hraci[i]->getPost() == 'U') count ++;
    return count;
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

void Tym::setDaneSL(int DaneSL){
                iDaneSL = DaneSL;
}
//---------------------------------------------------------------------------------------------

void Tym::setObdrzeneSL(int ObdrzeneSL){
                iObdrzeneSL = ObdrzeneSL;
}
//---------------------------------------------------------------------------------------------

void Tym::setBodyL(int BodyL){
                iBodyL = BodyL;
}
//---------------------------------------------------------------------------------------------

void Tym::setUmisteni(int Umisteni){
                iUmisteni = Umisteni;
}
//---------------------------------------------------------------------------------------------

int Tym::getID(){
                return iID;
}
//---------------------------------------------------------------------------------------------

String Tym::getNazevTymu(){
                return cNazevTymu;
}
//---------------------------------------------------------------------------------------------

String Tym::getNazevTymuKr(){
                return cNazevTymuKr;
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

String Tym::getHala(){
                return cHala;
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

int Tym::getPocetLajn(){
                return iPocetLajn;
}
//---------------------------------------------------------------------------------------------

int Tym::getDobaStridani(){
                return iDobaStridani;
}
//---------------------------------------------------------------------------------------------

int Tym::getTraining() {
                return iTraining;
}
//---------------------------------------------------------------------------------------------

float Tym::getTrainingIntensity() {
                return fTrainingIntensity;
}
//---------------------------------------------------------------------------------------------

int Tym::getR1(){
                return iR1;
}
//---------------------------------------------------------------------------------------------

int Tym::getG1(){
                return iG1;
}
//---------------------------------------------------------------------------------------------

int Tym::getB1(){
                return iB1;
}
//---------------------------------------------------------------------------------------------

int Tym::getR2(){
                return iR2;
}
//---------------------------------------------------------------------------------------------

int Tym::getG2(){
                return iG2;
}
//---------------------------------------------------------------------------------------------

int Tym::getB2(){
                return iB2;
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

int Tym::getCelkoveEN(){
                int i = 0;
                int iCelkove = 0;

                while(i < iPocetHracu){
                        iCelkove += Hraci[i]->getEnergie();
                        i ++;
                }
                return iCelkove;
}
//---------------------------------------------------------------------------------------------

int Tym::getCelkoveEN(int PrvniHrac, int PosledniHrac){
                int iCelkove = 0;
                
                while(PrvniHrac < PosledniHrac){
                        iCelkove += Hraci[PrvniHrac]->getEnergie();
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
                return (iVyhryL + iProhryL + iRemizyL);
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

int Tym::getDaneSL(){
                return iDaneSL;
}
//---------------------------------------------------------------------------------------------

int Tym::getObdrzeneSL(){
                return iObdrzeneSL;
}
//---------------------------------------------------------------------------------------------

int Tym::getBodyL(){
                return iBodyL;
}
//---------------------------------------------------------------------------------------------

int Tym::getUmisteni(){
                return iUmisteni;
}
//---------------------------------------------------------------------------------------------
