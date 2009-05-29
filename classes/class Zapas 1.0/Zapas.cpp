/*------------------------------------------------------------------------------------------*/
/*                                class Zapas                                               */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/
#include "Zapas.h"
//---------------------------------------------------------------------------------------------

Zapas::Zapas(){
                Tymy[0] = new Tym();
                Tymy[1] = new Tym();

                iCount = 0;
                iCelkoveA[0] = 0;
                iCelkoveB[0] = 0;
                iCelkoveA[1] = 0;
                iCelkoveB[1] = 0;
                iGolmanA = 0;
                iGolmanB = 0;
                iGolyA = 0;
                iGolyB = 0;
                iStrelyA = 0;
                iStrelyB = 0;
                iUtok = 0;
                iPomer = 1;
                iStrelec = 0;
                iAsistent = 0;

                for(int i = 0; i > 4; i ++)
                        iUtoky[i] = 0;

                iLine = 1;

                bUtoci[0] = false;
                bUtoci[0] = false;

                iNavsteva = 0;
}
//---------------------------------------------------------------------------------------------

Zapas::~Zapas(){
                delete Tymy[0], Tymy[1];
}
//---------------------------------------------------------------------------------------------

void Zapas::Inicializace(){

                iGolmanA = Tymy[0]->Hraci[0]->getFS() + Tymy[0]->Hraci[0]->getTS() + Tymy[0]->Hraci[0]->getZS();

                iCelkoveA[0] = Tymy[0]->getCelkoveFS(1, 6);
                iCelkoveA[0] += Tymy[0]->getCelkoveTS(1, 6);
                iCelkoveA[0] += Tymy[0]->getCelkoveZS(1, 6);
                iCelkoveA[1] = Tymy[0]->getCelkoveFS(6, 12);
                iCelkoveA[1] += Tymy[0]->getCelkoveTS(6, 12);
                iCelkoveA[1] += Tymy[0]->getCelkoveZS(6, 12);
                
                iPrumHrA[0] = iCelkoveA[0] / 5;
                iPrumHrA[1] = iCelkoveA[1] / 5;


                iGolmanB = Tymy[1]->Hraci[0]->getFS() + Tymy[1]->Hraci[0]->getTS() + Tymy[1]->Hraci[0]->getZS();

                iCelkoveB[0] = Tymy[1]->getCelkoveFS(1, 6);
                iCelkoveB[0] += Tymy[1]->getCelkoveTS(1, 6);
                iCelkoveB[0] += Tymy[1]->getCelkoveZS(1, 6);
                iCelkoveB[1] = Tymy[1]->getCelkoveFS(6, 12);
                iCelkoveB[1] += Tymy[1]->getCelkoveTS(6, 12);
                iCelkoveB[1] += Tymy[1]->getCelkoveZS(6, 12);

                iPrumHrB[0] = iCelkoveB[0] / 5;
                iPrumHrB[1] = iCelkoveB[1] / 5;
}
//---------------------------------------------------------------------------------------------

String Zapas::Akce(){
                cPom = "-";
       
                iCount += 1;

                srand(GetTickCount());

                iUtok = rand() % 99;

                if((iCount % 2) != 0){
                        iLine = 0;

                        if(iCelkoveA[0] > iCelkoveB[0]){
                                if(iUtoky[0] < 5){
                                        bUtoci[0] = true;
                                        iUtoky[0] ++;
                                }
                                else{
                                        bUtoci[0] = false;
                                        iUtoky[0] = 0;
                                }
                        }
                        if(iCelkoveB[0] > iCelkoveA[0]){
                                if(iUtoky[0] < 5){
                                        bUtoci[0] = false;
                                        iUtoky[0] ++;
                                }
                                else{
                                        bUtoci[0] = true;
                                        iUtoky[0] = 0;
                                }
                        }
                }
                else{
                        iLine = 1;

                        if(iCelkoveA[1] > iCelkoveB[1]){
                                if(iUtoky[0] < 5){
                                        bUtoci[1] = true;
                                        iUtoky[1] ++;
                                }
                                else{
                                        bUtoci[1] = false;
                                        iUtoky[1] = 0;
                                }
                        }
                        if(iCelkoveB[1] > iCelkoveA[1]){
                                if(iUtoky[0] < 5){
                                        bUtoci[1] = false;
                                        iUtoky[1] ++;
                                }
                                else{
                                        bUtoci[1] = true;
                                        iUtoky[1] = 0;
                                }
                        }
                }

                if(bUtoci[iLine] == true){
                        if((iCelkoveA[iLine] / iCelkoveB[iLine]) > 2){
                                iPomer = 17;
                        }
                        else{
                                iPomer = 9;
                        }
                        if(iPrumHrA[iLine] < iGolmanB){
                                iPomer = 16;
                        }
                        if(iUtok < iPomer){
                                iGolyA ++;
                                cPom = 'D';
                                iStrelec = rand() % 5;
                                iAsistent = rand() % 5;
                                while(iStrelec == 0)
                                        iStrelec = rand() % 5;
                                while(iAsistent == iStrelec)
                                        iAsistent = rand() % 5;
                                if(iLine == 1){
                                        iStrelec += 5;
                                        iAsistent += 5;
                                }
                        }
                        if(iUtok < 50){
                                iStrelyA ++;
                        }
                }
                if(bUtoci[iLine] == false){
                        if((iCelkoveB[iLine] / iCelkoveA[iLine]) > 2){
                                iPomer = 17;
                        }
                        else{
                                iPomer = 9;
                        }
                        if(iPrumHrB[iLine] < iGolmanA){
                                iPomer = 16;
                        }
                        if(iUtok < iPomer){
                                iGolyB ++;
                                cPom = 'H';
                                iStrelec = rand() % 5;
                                iAsistent = rand() % 5;
                                while(iStrelec == 0)
                                        iStrelec = rand() % 5;
                                while(iAsistent == iStrelec)
                                        iAsistent = rand() % 5;
                                if(iLine == 1){
                                        iStrelec += 5;
                                        iAsistent += 5;
                                }
                        }
                        if(iUtok < 50){
                                iStrelyB ++;
                        }
                }
                if(cPom == 'D' || cPom == 'H'){
                        if(cPom == 'D'){
                                String cReturn = cPom;
                                cReturn += "-";
                                cReturn += Tymy[0]->Hraci[iStrelec]->getCislo();
                                cReturn += "-";
                                cReturn += Tymy[0]->Hraci[iAsistent]->getCislo();
                                return cReturn;
                        }
                        if(cPom == 'H'){
                                String cReturn = cPom;
                                cReturn += "-";
                                cReturn += Tymy[1]->Hraci[iStrelec]->getCislo();
                                cReturn += "-";
                                cReturn += Tymy[1]->Hraci[iAsistent]->getCislo();
                                return cReturn;
                        }
                }
                else{
                        return "0";
                }
}
//---------------------------------------------------------------------------------------------

void Zapas::setNavsteva(){
                int iCelkemA = 0;
                int iCelkemB = 0;
                float iKoef = 0.90;

                iCelkemA = Tymy[0]->getCelkoveFS() + Tymy[0]->getCelkoveTS() + Tymy[0]->getCelkoveZS();
                iCelkemB = Tymy[1]->getCelkoveFS() + Tymy[1]->getCelkoveTS() + Tymy[1]->getCelkoveZS();

                if(iCelkemA == iCelkemB){
                            iKoef = 0.5;
                }
                if(iCelkemA > iCelkemB){
                            int i = iCelkemA / iCelkemB;
                            if(i > 3){
                                 iKoef = 1;
                            }
                            if(i <= 3){
                                 iKoef = 0.7;
                            }
                }
                if(iCelkemB > iCelkemA){
                            iKoef = 0.2;
                }
                iNavsteva = iKoef * Tymy[0]->getKapacitaHaly();
}
//---------------------------------------------------------------------------------------------

int Zapas::getNavsteva(){
                return iNavsteva;
}
//---------------------------------------------------------------------------------------------

int Zapas::getGolyD(){
                return iGolyA;
}
//---------------------------------------------------------------------------------------------

int Zapas::getGolyH(){
                return iGolyB;
}
//---------------------------------------------------------------------------------------------

int Zapas::getStrelyD(){
                return iStrelyA;
}
//---------------------------------------------------------------------------------------------

int Zapas::getStrelyH(){
                return iStrelyB;
}
//---------------------------------------------------------------------------------------------
                
