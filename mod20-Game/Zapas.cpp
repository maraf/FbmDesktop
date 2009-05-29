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

                iLine[0] = 1;
                iLine[1] = 1;

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

                iGolmanD = Tymy[0]->Hraci[0]->getFS() + Tymy[0]->Hraci[0]->getTS() + Tymy[0]->Hraci[0]->getZS();

                int prvni = (iLine[0] - 1) * 5 + 1;
                int posledni = iLine[0] * 5 + 1;
                fCelkoveD = Tymy[0]->getCelkoveFS(prvni, posledni);
                fCelkoveD += Tymy[0]->getCelkoveTS(prvni, posledni);
                fCelkoveD += Tymy[0]->getCelkoveZS(prvni, posledni);

                ft[0] = Tymy[0]->getCelkoveEN(prvni, posledni)/5;
                ft[0] *= 0.01;

                fCelkoveD *= ft[0];


                iGolmanH = Tymy[1]->Hraci[0]->getFS() + Tymy[1]->Hraci[0]->getTS() + Tymy[1]->Hraci[0]->getZS();

                prvni = (iLine[1] - 1) * 5 + 1;
                posledni = iLine[1] * 5 + 1;
                fCelkoveH = Tymy[1]->getCelkoveFS(prvni, posledni);
                fCelkoveH += Tymy[1]->getCelkoveTS(prvni, posledni);
                fCelkoveH += Tymy[1]->getCelkoveZS(prvni, posledni);
                
                ft[1] = Tymy[1]->getCelkoveEN(prvni, posledni)/5;
                ft[1] *= 0.01;

                fCelkoveH *= ft[1];
}
//---------------------------------------------------------------------------------------------

String Zapas::Akce(){

                iDobaNaHrD ++;
                iDobaNaHrH ++;

                setLajny();
                updateEnergie();
                updatePlayersAbility();

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

void Zapas::updateEnergie(){
                for(int j = 0; j < 2; j ++){
                        for(int i = 1; i <= Tymy[j]->getPocetLajn(); i ++){
                                if(i == iLine[j])
                                        unava(i, j, 2);
                                else
                                        regenerace(i, j, 1);
                        }
                }

                if(iCount == 40 || iCount == 80){
                        for(int j = 0; j < 2; j ++)
                                for(int i = 1; i <= Tymy[j]->getPocetLajn(); i ++)
                                        regenerace(i, j, 8);
                }
}
//---------------------------------------------------------------------------------------------

void Zapas::regenerace(int iLajn, int j, int Kolik){
                for(int i = (iLajn - 1) * 5 + 1; i < (iLajn - 1) * 5 + 1 + 5; i ++){
                        if(Tymy[j]->Hraci[i]->getEnergie() < 90)
                                Tymy[j]->Hraci[i]->setEnergie(Tymy[j]->Hraci[i]->getEnergie() + Kolik);
                }
}
//---------------------------------------------------------------------------------------------

void Zapas::unava(int iLajn, int j, int Kolik){
                for(int i = (iLajn - 1) * 5 + 1; i < (iLajn - 1) * 5 + 1 + 5; i ++){
                        if(Tymy[j]->Hraci[i]->getEnergie() > 5)
                                Tymy[j]->Hraci[i]->setEnergie(Tymy[j]->Hraci[i]->getEnergie() - Kolik);
                }
}
//---------------------------------------------------------------------------------------------

void Zapas::updatePlayersAbility() {
                for(int j = 0; j < 2; j ++){
                        for(int i = 1; i <= Tymy[j]->getPocetLajn(); i ++){
                                if(i == iLine[j]) {
                                        for(int k = (i - 1) * 5 + 1; k < (i - 1) * 5 + 1 + 5; k ++) {
                                                Tymy[j]->Hraci[k]->setFSpom(Tymy[j]->Hraci[k]->getFSpom() + 1);
                                                Tymy[j]->Hraci[k]->setTSpom(Tymy[j]->Hraci[k]->getFSpom() + 1);
                                                Tymy[j]->Hraci[k]->setZSpom(Tymy[j]->Hraci[k]->getFSpom() + 1);
                                        }
                                }
                        }
                        Tymy[j]->Hraci[0]->setFSpom(Tymy[j]->Hraci[0]->getFSpom() + 1);
                        Tymy[j]->Hraci[0]->setTSpom(Tymy[j]->Hraci[0]->getTSpom() + 1);
                        Tymy[j]->Hraci[0]->setZSpom(Tymy[j]->Hraci[0]->getZSpom() + 1);
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
