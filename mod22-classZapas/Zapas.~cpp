/*------------------------------------------------------------------------------------------*/
/*                                class Zapas                                               */
/*                                verze 2.2                                                 */
/*------------------------------------------------------------------------------------------*/
#include "Zapas.h"
//---------------------------------------------------------------------------------------------

Zapas::Zapas(Tym &team1, Tym &team2, int id){
                Tymy[0] = &team1;
                Tymy[1] = &team2;
                iID = id;
                
                srand(GetTickCount());

                setNavsteva();

                iGoal = 3;

                iCount = 0;
                fCelkoveD = 0;
                fCelkoveH = 0;
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

                iLine[0] = 0;
                iLine[1] = 0;

                iDobaNaHrD = 0;
                iDobaNaHrH = 0;

                bUtoci = false;

                ft[0] = 0;
                ft[1] = 0;

                for(int i = 0; i < 30; i ++) {
                        ScorersH[i] = 0;
                        ScorersA[i] = 0;
                        AssistentsH[i] = 0;
                        AssistentsA[i] = 0;
                        StringScorersH[i] = "";
                        StringScorersA[i] = "";
                        StringAssistentsH[i] = "";
                        StringAssistentsA[i] = "";
                }
}
//---------------------------------------------------------------------------------------------

Zapas::~Zapas(){
}
//---------------------------------------------------------------------------------------------

void Zapas::setID(int id){
                iID = id;
}
//---------------------------------------------------------------------------------------------

void Zapas::Inicializace(){
                iGOL[0] = 7;
                iGOL[1] = 6;

                iSTRELA[0] = 27;
                iSTRELA[1] = 26;


                iGolmanD = Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getGoalman()]->getFS();
                iGolmanD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getGoalman()]->getTS();
                iGolmanD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getGoalman()]->getFS();

                fCelkoveD = Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getLeftDefender()]->getFS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getLeftDefender()]->getTS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getLeftDefender()]->getZS();

                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getRightDefender()]->getFS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getRightDefender()]->getTS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getRightDefender()]->getZS();

                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getLeftWing()]->getFS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getLeftWing()]->getTS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getLeftWing()]->getZS();

                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getRightWing()]->getFS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getRightWing()]->getTS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getRightWing()]->getZS();

                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getCenter()]->getFS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getCenter()]->getTS();
                fCelkoveD += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getCenter()]->getZS();

                ft[0] = Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getLeftDefender()]->getEnergie();
                ft[0] += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getRightDefender()]->getEnergie();
                ft[0] += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getLeftWing()]->getEnergie();
                ft[0] += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getRightWing()]->getEnergie();
                ft[0] += Tymy[0]->Hraci[Tymy[0]->Lines[iLine[0]]->getCenter()]->getEnergie();

                ft[0] *= 0.01;
                fCelkoveD *= ft[0];


                iGolmanH = Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getGoalman()]->getFS();
                iGolmanH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getGoalman()]->getTS();
                iGolmanH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getGoalman()]->getFS();

                fCelkoveH = Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getLeftDefender()]->getFS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getLeftDefender()]->getTS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getLeftDefender()]->getZS();

                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getRightDefender()]->getFS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getRightDefender()]->getTS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getRightDefender()]->getZS();

                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getLeftWing()]->getFS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getLeftWing()]->getTS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getLeftWing()]->getZS();

                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getRightWing()]->getFS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getRightWing()]->getTS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getRightWing()]->getZS();

                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getCenter()]->getFS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getCenter()]->getTS();
                fCelkoveH += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getCenter()]->getZS();

                ft[1] = Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getLeftDefender()]->getEnergie();
                ft[1] += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getRightDefender()]->getEnergie();
                ft[1] += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getLeftWing()]->getEnergie();
                ft[1] += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getRightWing()]->getEnergie();
                ft[1] += Tymy[1]->Hraci[Tymy[1]->Lines[iLine[1]]->getCenter()]->getEnergie();

                ft[1] *= 0.01;
                fCelkoveH *= ft[1];
}
//---------------------------------------------------------------------------------------------

String Zapas::Akce(){

                iDobaNaHrD ++;
                iDobaNaHrH ++;
                Goal = false;

                setLajny();
                updateEnergie();
                //updatePlayersAbility();

                iCount += 1;

                iUtok = rand() % 99;

                Inicializace();

                if(fCelkoveD >= fCelkoveH){
                        bUtoci = false;
                        fPomer = (fCelkoveD * 100) / fCelkoveH;
                }
                else{
                        bUtoci = true;
                        fPomer = (fCelkoveH * 100) / fCelkoveD;
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
                                        Goal = true;
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
                                        Goal = true;
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
                                        Goal = true;

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
                                        Goal = true;
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
                        do {
                                iLine[0] ++;
                                if(iLine[0] == 4) iLine[0] = 0;
                        } while (!Tymy[0]->Lines[iLine[0]]->isEnabled());
                        iDobaNaHrD = 0;
                }

                if(iDobaNaHrH == Tymy[1]->getDobaStridani()){
                        do {
                                iLine[1] ++;
                                if(iLine[1] == 4) iLine[1] = 0;
                        } while (!Tymy[1]->Lines[iLine[1]]->isEnabled());
                        iDobaNaHrH = 0;
                }
}
//---------------------------------------------------------------------------------------------

void Zapas::updateEnergie(){
                for(int i = 0; i < 2; i ++) {
                        for(int j = 0; j < 4; j ++) {
                                if(j == iLine[i]) unava(j, i, 2);
                                regenerace(j, i, 1);
                        }
                }

                if(iCount == 40 || iCount == 80){
                        for(int i = 0; i < 2; i ++) {
                                for(int j = 0; j < 4; j ++) {
                                        regenerace(j, i, 8);
                                }
                        }
                }
}
//---------------------------------------------------------------------------------------------

void Zapas::regenerace(int iLajn, int j, float Kolik){
     if(Tymy[j]->Lines[iLajn]->getGoalman() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getGoalman()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getGoalman()]->getEnergie() + (Kolik/2));
     if(Tymy[j]->Lines[iLajn]->getLeftDefender() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getLeftDefender()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getLeftDefender()]->getEnergie() + Kolik);
     if(Tymy[j]->Lines[iLajn]->getRightDefender() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getRightDefender()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getRightDefender()]->getEnergie() + Kolik);
     if(Tymy[j]->Lines[iLajn]->getLeftWing() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getLeftWing()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getLeftWing()]->getEnergie() + Kolik);
     if(Tymy[j]->Lines[iLajn]->getRightWing() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getRightWing()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getRightWing()]->getEnergie() + Kolik);
}
//---------------------------------------------------------------------------------------------

void Zapas::unava(int iLajn, int j, float Kolik){
     if(Tymy[j]->Lines[iLajn]->getGoalman() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getGoalman()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getGoalman()]->getEnergie() - (Kolik/2));
     if(Tymy[j]->Lines[iLajn]->getLeftDefender() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getLeftDefender()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getLeftDefender()]->getEnergie() - Kolik);
     if(Tymy[j]->Lines[iLajn]->getRightDefender() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getRightDefender()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getRightDefender()]->getEnergie() - Kolik);
     if(Tymy[j]->Lines[iLajn]->getLeftWing() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getLeftWing()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getLeftWing()]->getEnergie() - Kolik);
     if(Tymy[j]->Lines[iLajn]->getRightWing() != -1) Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getRightWing()]->setEnergie(Tymy[j]->Hraci[Tymy[j]->Lines[iLajn]->getRightWing()]->getEnergie() - Kolik);
}
//---------------------------------------------------------------------------------------------

void Zapas::updatePlayersAbility() {
     for(int j = 0; j < 2; j ++) {
          for(int i = 0; i < 4; i ++) {
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getGoalman()]->setFSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getGoalman()]->getFSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftDefender()]->setFSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftDefender()]->getFSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightDefender()]->setFSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightDefender()]->getFSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftWing()]->setFSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftWing()]->getFSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightWing()]->setFSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightWing()]->getFSpom() + 1);

                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getGoalman()]->setTSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getGoalman()]->getTSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftDefender()]->setTSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftDefender()]->getTSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightDefender()]->setTSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightDefender()]->getTSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftWing()]->setTSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftWing()]->getTSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightWing()]->setTSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightWing()]->getTSpom() + 1);

                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getGoalman()]->setZSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getGoalman()]->getZSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftDefender()]->setZSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftDefender()]->getZSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightDefender()]->setZSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightDefender()]->getZSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftWing()]->setZSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getLeftWing()]->getZSpom() + 1);
                Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightWing()]->setZSpom(Tymy[j]->Hraci[Tymy[j]->Lines[i]->getRightWing()]->getZSpom() + 1);
          }
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
                        case 0: iStrelec = Tymy[iTym]->Lines[iLine[iTym]]->getLeftDefender(); break;
                        case 1: iStrelec = Tymy[iTym]->Lines[iLine[iTym]]->getRightDefender(); break;
                        case 2: iStrelec = Tymy[iTym]->Lines[iLine[iTym]]->getLeftWing(); break;
                        case 3: iStrelec = Tymy[iTym]->Lines[iLine[iTym]]->getLeftWing(); break;
                        case 4: iStrelec = Tymy[iTym]->Lines[iLine[iTym]]->getRightWing(); break;
                        case 5: iStrelec = Tymy[iTym]->Lines[iLine[iTym]]->getRightWing(); break;
                        case 6: iStrelec = Tymy[iTym]->Lines[iLine[iTym]]->getCenter(); break;
                        case 7: iStrelec = Tymy[iTym]->Lines[iLine[iTym]]->getCenter(); break;
                }
                Tymy[iTym]->Hraci[iStrelec]->setGolyL(Tymy[iTym]->Hraci[iStrelec]->getGolyL() + 1);

                if(cTym == 'D') {
                        ScorersH[getGolyD() - 1] = Tymy[0]->Hraci[iStrelec]->getID();
                        StringScorersH[getGolyD() - 1] += (String)Tymy[0]->Hraci[iStrelec]->getCislo() + " ";
                        StringScorersH[getGolyD() - 1] += Tymy[0]->Hraci[iStrelec]->getPrijmeni();
                } else if(cTym == 'H') {
                        ScorersA[getGolyH() - 1] = Tymy[1]->Hraci[iStrelec]->getID();
                        StringScorersA[getGolyH() - 1] += (String)Tymy[1]->Hraci[iStrelec]->getCislo() + " ";
                        StringScorersA[getGolyH() - 1] += Tymy[1]->Hraci[iStrelec]->getPrijmeni();
                }
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
                                case 0: iAsistent = Tymy[iTym]->Lines[iLine[iTym]]->getLeftDefender(); break;
                                case 1: iAsistent = Tymy[iTym]->Lines[iLine[iTym]]->getRightDefender(); break;
                                case 2: iAsistent = Tymy[iTym]->Lines[iLine[iTym]]->getLeftWing(); break;
                                case 3: iAsistent = Tymy[iTym]->Lines[iLine[iTym]]->getLeftWing(); break;
                                case 4: iAsistent = Tymy[iTym]->Lines[iLine[iTym]]->getRightWing(); break;
                                case 5: iAsistent = Tymy[iTym]->Lines[iLine[iTym]]->getRightWing(); break;
                                case 6: iAsistent = Tymy[iTym]->Lines[iLine[iTym]]->getCenter(); break;
                                case 7: iAsistent = Tymy[iTym]->Lines[iLine[iTym]]->getCenter(); break;
                        }
                } while(iStrelec == iAsistent);
                Tymy[iTym]->Hraci[iAsistent]->setAsistenceL(Tymy[iTym]->Hraci[iAsistent]->getAsistenceL() + 1);

                if(cTym == 'D') {
                        AssistentsH[getGolyD() - 1] = Tymy[0]->Hraci[iAsistent]->getID();
                        StringAssistentsH[getGolyD() - 1] += (String)Tymy[0]->Hraci[iAsistent]->getCislo() + " ";
                        StringAssistentsH[getGolyD() - 1] += Tymy[0]->Hraci[iAsistent]->getPrijmeni();
                } else if(cTym == 'H') {
                        AssistentsA[getGolyH() - 1] = Tymy[1]->Hraci[iAsistent]->getID();
                        StringAssistentsA[getGolyH() - 1] += (String)Tymy[1]->Hraci[iAsistent]->getCislo() + " ";
                        StringAssistentsA[getGolyH() - 1] += Tymy[1]->Hraci[iAsistent]->getPrijmeni();
                }
}
//---------------------------------------------------------------------------------------------

void Zapas::setNavsteva(){
                float fKoef[2] = {0,0};

                fCelkemD = Tymy[0]->getCelkoveFS(0, Tymy[0]->getPocetLajn() * 5 + 1) + Tymy[0]->getCelkoveTS(0, Tymy[0]->getPocetLajn() * 5 + 1) + Tymy[0]->getCelkoveZS(0, Tymy[0]->getPocetLajn() * 5 + 1);
                fCelkemH = Tymy[1]->getCelkoveFS(0, Tymy[1]->getPocetLajn() * 5 + 1) + Tymy[1]->getCelkoveTS(0, Tymy[1]->getPocetLajn() * 5 + 1) + Tymy[1]->getCelkoveZS(0, Tymy[1]->getPocetLajn() * 5 + 1);

                fCelkemD /= Tymy[0]->getPocetLajn();
                fCelkemH /= Tymy[1]->getPocetLajn();

                // Navsteva v domacim sektoru (85% z kapacity haly)
                fKoef[0] = fCelkemD/fCelkemH;
                if(fKoef[0] > 1) fKoef[0] = 1;
                fKoef[0] *= 0.85;

                // Navsteva v hostujicim sektoru (15% z kapacity haly)
                fKoef[1] = fCelkemH/fCelkemD;
                if(fKoef[1] > 1) fKoef[1] = 1;
                fKoef[1] *= 0.15;

                iNavsteva = (fKoef[0] + fKoef[1]) * Tymy[0]->getKapacitaHaly();
}
//---------------------------------------------------------------------------------------------

void Zapas::setGoal(int Goal){
                iGoal = Goal;
}
//---------------------------------------------------------------------------------------------

int Zapas::getID(){
                return iID;
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

int Zapas::getScorers(bool bHome, int iGoal) {
        if(bHome) {
                return ScorersH[iGoal];
        } else {
                return ScorersA[iGoal];
        }
}
//---------------------------------------------------------------------------------------------

String Zapas::getStringScorers(bool bHome, int iGoal) {
        if(bHome) {
                return StringScorersH[iGoal];
        } else {
                return StringScorersA[iGoal];
        }
}
//---------------------------------------------------------------------------------------------

int Zapas::getAssistents(bool bHome, int iGoal) {
        if(bHome) {
                return AssistentsH[iGoal];
        } else {
                return AssistentsA[iGoal];
        }
}
//---------------------------------------------------------------------------------------------

String Zapas::getStringAssistents(bool bHome, int iGoal) {
        if(bHome) {
                return StringAssistentsH[iGoal];
        } else {
                return StringAssistentsA[iGoal];
        }
}
//---------------------------------------------------------------------------------------------

bool Zapas::isGoal() {
        return Goal;
}
//---------------------------------------------------------------------------------------------

bool Zapas::isHomeGoal() {
        if(iGoal == 0) return true;
        else return false;
}
//---------------------------------------------------------------------------------------------

bool Zapas::isAwayGoal() {
        if(iGoal == 1) return true;
        else return false;
}
//---------------------------------------------------------------------------------------------

String Zapas::getLastGoalString() {
        if(iGoal == 0) {
                return ((String)getMinuta() + ".min. " + StringScorersH[iGolyD - 1] + " ( " + StringAssistentsH[iGolyD - 1]) + " ) ";
        } else if(iGoal == 1) {
                return ((String)getMinuta() + ".min. " + StringScorersA[iGolyH - 1] + " ( " + StringAssistentsA[iGolyH - 1]) + " ) ";
        }
}
//---------------------------------------------------------------------------------------------
