#include "Zapas.h"
//---------------------------------------------------------------------------------------------

Zapas::Zapas(Tym &team1, Tym &team2){
                Tymy[0] = &team1;
                Tymy[1] = &team2;

                setNavsteva();

                iGoal = 3;

                iCount = 0;
                iCelkoveD = 0;
                iCelkoveH = 0;
                iGolmanD = 0;
                iGolmanH = 0;
                iGolyD = 0;
                iGolyH = 0;
                iStrelyD = 0;
                iStrelyH = 0;
                iUtok = 0;
                fPomer = 1;
                iPodil = 5;
                iStrelec = 0;
                iAsistent = 0;

                iLine[0] = 1;
                iLine[1] = 1;

                iDobaNaHrD = 0;
                iDobaNaHrH = 0;

                bUtoci = false;

}
//---------------------------------------------------------------------------------------------

Zapas::~Zapas(){
}
//---------------------------------------------------------------------------------------------

void Zapas::Inicializace(){
                iGOL[0] = 9;
                iGOL[1] = 7;

                iSTRELA[0] = 25;
                iSTRELA[1] = 23;

                iGolmanD = Tymy[0]->Hraci[0]->getFS() + Tymy[0]->Hraci[0]->getTS() + Tymy[0]->Hraci[0]->getZS();

                int prvni = (iLine[0] - 1) * 5 + 1;
                int posledni = iLine[0] * 5 + 1;
                iCelkoveD = Tymy[0]->getCelkoveFS(prvni, posledni);
                iCelkoveD += Tymy[0]->getCelkoveTS(prvni, posledni);
                iCelkoveD += Tymy[0]->getCelkoveZS(prvni, posledni);


                iGolmanH = Tymy[1]->Hraci[0]->getFS() + Tymy[1]->Hraci[0]->getTS() + Tymy[1]->Hraci[0]->getZS();

                prvni = (iLine[1] - 1) * 5 + 1;
                posledni = iLine[1] * 5 + 1;
                iCelkoveH = Tymy[1]->getCelkoveFS(prvni, posledni);
                iCelkoveH += Tymy[1]->getCelkoveTS(prvni, posledni);
                iCelkoveH += Tymy[1]->getCelkoveZS(prvni, posledni);

}
//---------------------------------------------------------------------------------------------

String Zapas::Akce(){

                iDobaNaHrD ++;
                iDobaNaHrH ++;

                setLajny();

                iCount += 1;

                srand(GetTickCount());

                iUtok = rand() % 99;

                Inicializace();

                if(iCelkoveD >= iCelkoveH){
                        bUtoci = false;
                        fPomer = (iCelkoveD * 100) / iCelkoveH;
                }
                else{
                        bUtoci = true;
                        fPomer = (iCelkoveH * 100) / iCelkoveD;
                }

                if(fPomer >= 100 && fPomer < 120)
                        iPodil = 5;
                if(fPomer >= 120 && fPomer < 140)
                        iPodil = 6;
                if(fPomer >= 140 && fPomer < 160)
                        iPodil = 7;
                if(fPomer >= 160 && fPomer < 180)
                        iPodil = 8;
                if(fPomer >= 180 && fPomer <= 200)
                        iPodil = 9;
                if(fPomer > 200)
                        iPodil = 10;

                iUtoci = rand() % 9;

                if(!bUtoci){
                        if(iUtoci <= iPodil){
                                if(iUtok < iGOL[0]){
                                        iGolyD ++;
                                        setStrelec('D');
                                        setAsistent('D');
                                        iGoal = 0;
                                }
                                if(iUtok < iSTRELA[0])
                                        iStrelyD ++;
                        }
                        else{
                                if(iUtok < iGOL[1]){
                                        iGolyH ++;
                                        setStrelec('H');
                                        setAsistent('H');
                                        iGoal = 1;
                                }
                                if(iUtok < iSTRELA[1])
                                        iStrelyH ++;
                        }
                }
                if(bUtoci){
                        if(iUtoci < iPodil){
                                if(iUtok < iGOL[1]){
                                        iGolyH ++;
                                        setStrelec('H');
                                        setAsistent('H');
                                        iGoal = 1;
                                }
                                if(iUtok < iSTRELA[1])
                                        iStrelyH ++;;
                        }
                        else{
                                if(iUtok < iGOL[0]){
                                        iGolyD ++;
                                        setStrelec('D');
                                        setAsistent('D');
                                        iGoal = 0;
                                }
                                if(iUtok < iSTRELA[1])
                                        iStrelyD ++;
                        }
                }


                return "kuk";
}
//---------------------------------------------------------------------------------------------

void Zapas::setLajny(){
                if(iDobaNaHrD == Tymy[0]->getDobaStridani()){
                        iLine[0] ++;
                        if(iLine[0] > Tymy[0]->getPocetLajn())
                                iLine[0] = 1;
                        iDobaNaHrD = 0;
                }

                if(iDobaNaHrH == Tymy[1]->getDobaStridani()){
                        iLine[1] ++;
                        if(iLine[1] > Tymy[1]->getPocetLajn())
                                iLine[1] = 1;
                        iDobaNaHrH = 0;
                }
}
//---------------------------------------------------------------------------------------------

void Zapas::setStrelec(char cTym){
                int iHraci[5];
                int iTym;
                int iCislo;
                int iHrac;

                if(cTym == 'D')
                        iTym = 0;
                if(cTym == 'H')
                        iTym = 1;

                iCislo = rand() % 7;

                switch(iCislo){
                        case 0: iHrac = 0; break;
                        case 1: iHrac = 1; break;
                        case 2: iHrac = 2; break;
                        case 3: iHrac = 2; break;
                        case 4: iHrac = 3; break;
                        case 5: iHrac = 3; break;
                        case 6: iHrac = 4; break;
                        case 7: iHrac = 4; break;
                }

                iStrelec = (iLine[iTym] - 1) * 5 + 1 + iHrac;

}
//---------------------------------------------------------------------------------------------

void Zapas::setAsistent(char cTym){
                int iHraci[5];
                int iTym;
                int iCislo;
                int iHrac;

                if(cTym == 'D')
                        iTym = 0;
                if(cTym == 'H')
                        iTym = 1;

                do{
                        iCislo = rand() % 7;

                        switch(iCislo){
                                case 0: iHrac = 0; break;
                                case 1: iHrac = 1; break;
                                case 2: iHrac = 2; break;
                                case 3: iHrac = 2; break;
                                case 4: iHrac = 3; break;
                                case 5: iHrac = 3; break;
                                case 6: iHrac = 4; break;
                                case 7: iHrac = 4; break;
                        }

                        iAsistent = (iLine[iTym] - 1) * 5 + 1 + iHrac;
                }while(iStrelec == iAsistent);
}
//---------------------------------------------------------------------------------------------

void Zapas::setNavsteva(){
                float fKoef[2] = {0,0};

                iCelkemD = Tymy[0]->getCelkoveFS(0, Tymy[0]->getPocetLajn() * 5 + 1) + Tymy[0]->getCelkoveTS(0, Tymy[0]->getPocetLajn() * 5 + 1) + Tymy[0]->getCelkoveZS(0, Tymy[0]->getPocetLajn() * 5 + 1);
                iCelkemH = Tymy[1]->getCelkoveFS(0, Tymy[1]->getPocetLajn() * 5 + 1) + Tymy[1]->getCelkoveTS(0, Tymy[1]->getPocetLajn() * 5 + 1) + Tymy[1]->getCelkoveZS(0, Tymy[1]->getPocetLajn() * 5 + 1);

                iCelkemD /= Tymy[0]->getPocetLajn();
                iCelkemH /= Tymy[1]->getPocetLajn();

                // Navsteva v domacim sektoru (85% z kapacity haly)
                fKoef[0] = iCelkemD/iCelkemH;
                if(fKoef[0] > 1) fKoef[0] = 1;
                fKoef[0] *= 0.85;

                // Navsteva v hostujicim sektoru (15% z kapacity haly)
                fKoef[1] = iCelkemH/iCelkemD;
                if(fKoef[1] > 1) fKoef[1] = 1;
                fKoef[1] *= 0.15;

                iNavsteva = (fKoef[0] + fKoef[1]) * Tymy[0]->getKapacitaHaly();
}
//---------------------------------------------------------------------------------------------

void Zapas::setGoal(int Goal){
                iGoal = Goal;
}
//---------------------------------------------------------------------------------------------

int Zapas::getNavsteva(){
                return iNavsteva;
}
//---------------------------------------------------------------------------------------------

int Zapas::getGolyD(){
                return iGolyD;
}
//---------------------------------------------------------------------------------------------

int Zapas::getGolyH(){
                return iGolyH;
}
//---------------------------------------------------------------------------------------------

int Zapas::getStrelyD(){
                return iStrelyD;
}
//---------------------------------------------------------------------------------------------

int Zapas::getStrelyH(){
                return iStrelyH;
}
//---------------------------------------------------------------------------------------------

int Zapas::getStrelec(){
                return iStrelec;
}
//---------------------------------------------------------------------------------------------

int Zapas::getAsistent(){
                return iAsistent;
}
//---------------------------------------------------------------------------------------------

int Zapas::getGoal(){
                return iGoal;
}
//---------------------------------------------------------------------------------------------

int Zapas::getCount(){
                return iCount;
}
//---------------------------------------------------------------------------------------------

String Zapas::getMinuta(){
                int iMinuta = iCount / 2;
                if((iCount % 2) == 1 || iMinuta == 0)
                        iMinuta ++;
                return(IntToStr(iMinuta));
}
//---------------------------------------------------------------------------------------------

