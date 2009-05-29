//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Teams[0] = new Tym();
        Teams[0]->nactiTym("teams/pix_m.txt");
        Teams[0]->nactiHrace("teams/pix_l.txt");
        Teams[0]->setDobaStridani(2);
        setLineup(0);
        /*Teams[0]->Lines[0]->setEnabled(true);
        Teams[0]->Lines[0]->setGoalman(0);
        Teams[0]->Lines[0]->setLeftDefender(2);
        Teams[0]->Lines[0]->setRightDefender(3);
        Teams[0]->Lines[0]->setLeftWing(10);
        Teams[0]->Lines[0]->setRightWing(11);
        Teams[0]->Lines[0]->setCenter(12);
        Teams[0]->Lines[1]->setEnabled(true);
        Teams[0]->Lines[1]->setGoalman(0);
        Teams[0]->Lines[1]->setLeftDefender(4);
        Teams[0]->Lines[1]->setRightDefender(5);
        Teams[0]->Lines[1]->setLeftWing(13);
        Teams[0]->Lines[1]->setRightWing(14);
        Teams[0]->Lines[1]->setCenter(15);
        Teams[0]->Lines[2]->setEnabled(false);
        Teams[0]->Lines[2]->setGoalman(0);
        Teams[0]->Lines[2]->setLeftDefender(2);
        Teams[0]->Lines[2]->setRightDefender(3);
        Teams[0]->Lines[2]->setLeftWing(10);
        Teams[0]->Lines[2]->setRightWing(11);
        Teams[0]->Lines[2]->setCenter(12);
        Teams[0]->Lines[3]->setEnabled(false);
        Teams[0]->Lines[3]->setGoalman(0);
        Teams[0]->Lines[3]->setLeftDefender(4);
        Teams[0]->Lines[3]->setRightDefender(5);
        Teams[0]->Lines[3]->setLeftWing(13);
        Teams[0]->Lines[3]->setRightWing(14);
        Teams[0]->Lines[3]->setCenter(15);*/


        Teams[1] = new Tym();
        Teams[1]->nactiTym("teams/aik_m.txt");
        Teams[1]->nactiHrace("teams/aik_l.txt");
        Teams[1]->setDobaStridani(3);
        setLineup(1);
        /*Teams[1]->Lines[0]->setEnabled(true);
        Teams[1]->Lines[0]->setGoalman(0);
        Teams[1]->Lines[0]->setLeftDefender(2);
        Teams[1]->Lines[0]->setRightDefender(3);
        Teams[1]->Lines[0]->setLeftWing(13);
        Teams[1]->Lines[0]->setRightWing(14);
        Teams[1]->Lines[0]->setCenter(15);
        Teams[1]->Lines[1]->setEnabled(true);
        Teams[1]->Lines[1]->setGoalman(0);
        Teams[1]->Lines[1]->setLeftDefender(4);
        Teams[1]->Lines[1]->setRightDefender(5);
        Teams[1]->Lines[1]->setLeftWing(16);
        Teams[1]->Lines[1]->setRightWing(17);
        Teams[1]->Lines[1]->setCenter(18);
        Teams[1]->Lines[2]->setEnabled(false);
        Teams[1]->Lines[2]->setGoalman(0);
        Teams[1]->Lines[2]->setLeftDefender(2);
        Teams[1]->Lines[2]->setRightDefender(3);
        Teams[1]->Lines[2]->setLeftWing(13);
        Teams[1]->Lines[2]->setRightWing(14);
        Teams[1]->Lines[2]->setCenter(15);
        Teams[1]->Lines[3]->setEnabled(false);
        Teams[1]->Lines[3]->setGoalman(0);
        Teams[1]->Lines[3]->setLeftDefender(4);
        Teams[1]->Lines[3]->setRightDefender(5);
        Teams[1]->Lines[3]->setLeftWing(16);
        Teams[1]->Lines[3]->setRightWing(17);
        Teams[1]->Lines[3]->setCenter(18);*/

        Match = new Zapas(*Teams[0], *Teams[1], 1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        String s = "";
        for(int i = 0; i < 4; i ++) {
                if(Teams[0]->Lines[i]->isEnabled()) {
                        s = (String)Teams[0]->Hraci[Teams[0]->Lines[i]->getGoalman()]->getCislo() + " - " + Teams[0]->Hraci[Teams[0]->Lines[i]->getGoalman()]->getPrijmeni();
                        Memo1->Lines->Add(s);
                        s = (String)Teams[0]->Hraci[Teams[0]->Lines[i]->getLeftDefender()]->getCislo() + " - " + Teams[0]->Hraci[Teams[0]->Lines[i]->getLeftDefender()]->getPrijmeni();
                        Memo1->Lines->Add(s);
                        s = (String)Teams[0]->Hraci[Teams[0]->Lines[i]->getRightDefender()]->getCislo() + " - " + Teams[0]->Hraci[Teams[0]->Lines[i]->getRightDefender()]->getPrijmeni();
                        Memo1->Lines->Add(s);
                        s = (String)Teams[0]->Hraci[Teams[0]->Lines[i]->getLeftWing()]->getCislo() + " - " + Teams[0]->Hraci[Teams[0]->Lines[i]->getLeftWing()]->getPrijmeni();
                        Memo1->Lines->Add(s);
                        s = (String)Teams[0]->Hraci[Teams[0]->Lines[i]->getRightWing()]->getCislo() + " - " + Teams[0]->Hraci[Teams[0]->Lines[i]->getRightWing()]->getPrijmeni();
                        Memo1->Lines->Add(s);
                        s = (String)Teams[0]->Hraci[Teams[0]->Lines[i]->getCenter()]->getCislo() + " - " + Teams[0]->Hraci[Teams[0]->Lines[i]->getCenter()]->getPrijmeni();
                        Memo1->Lines->Add(s);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        String s = "";
        for(int i = 0; i < 4; i ++) {
                if(Teams[0]->Lines[i]->isEnabled()) {
                        s = (String)Teams[1]->Hraci[Teams[1]->Lines[i]->getGoalman()]->getCislo() + " - " + Teams[1]->Hraci[Teams[1]->Lines[i]->getGoalman()]->getPrijmeni();
                        Memo2->Lines->Add(s);
                        s = (String)Teams[1]->Hraci[Teams[1]->Lines[i]->getLeftDefender()]->getCislo() + " - " + Teams[1]->Hraci[Teams[1]->Lines[i]->getLeftDefender()]->getPrijmeni();
                        Memo2->Lines->Add(s);
                        s = (String)Teams[1]->Hraci[Teams[1]->Lines[i]->getRightDefender()]->getCislo() + " - " + Teams[1]->Hraci[Teams[1]->Lines[i]->getRightDefender()]->getPrijmeni();
                        Memo2->Lines->Add(s);
                        s = (String)Teams[1]->Hraci[Teams[1]->Lines[i]->getLeftWing()]->getCislo() + " - " + Teams[1]->Hraci[Teams[1]->Lines[i]->getLeftWing()]->getPrijmeni();
                        Memo2->Lines->Add(s);
                        s = (String)Teams[1]->Hraci[Teams[1]->Lines[i]->getRightWing()]->getCislo() + " - " + Teams[1]->Hraci[Teams[1]->Lines[i]->getRightWing()]->getPrijmeni();
                        Memo2->Lines->Add(s);
                        s = (String)Teams[1]->Hraci[Teams[1]->Lines[i]->getCenter()]->getCislo() + " - " + Teams[1]->Hraci[Teams[1]->Lines[i]->getCenter()]->getPrijmeni();
                        Memo2->Lines->Add(s);
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Match->Akce();
        Label1->Caption = (String)Match->iLine[0] + " - " + (String)Match->iLine[1] + " :: " + (String)Match->getMinuta() + ".min. ::: " + (String)Match->getGolyD() + " : " + (String)Match->getGolyH();
        if(Match->isGoal()) {
                if(Match->isHomeGoal())
                        Memo3->Lines->Add(Match->getLastGoalString());
                else
                        Memo4->Lines->Add(Match->getLastGoalString());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setLineup(int iTeam)
{
        int iGolman1 = 1;
        int iObrana1 = 2;
        int iObrana2 = 2;
        int iUtok1 = 3;
        int iUtok2 = 3;

        String s = Label3->Caption + " : ";

        //for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++) {
        //        Teams[iTeam]->Hraci[i]->setSestava(5);
        //}

        Teams[iTeam]->setridHrace('A', false);
        Teams[iTeam]->Lines[0]->setEnabled(true);
        Teams[iTeam]->Lines[1]->setEnabled(true);
        Teams[iTeam]->Lines[2]->setEnabled(false);
        Teams[iTeam]->Lines[3]->setEnabled(false);

        for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++){
                if(Teams[iTeam]->Hraci[i]->getPost() == 'G' && iGolman1 != 0){
                        //Teams[iTeam]->Hraci[i]->setSestava(1);
                        Teams[iTeam]->Lines[0]->setGoalman(i);
                        Teams[iTeam]->Lines[1]->setGoalman(i);
                        iGolman1 --; 
                        s += (String)i + " - ";
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'O' && (iObrana1 != 0 || iObrana2 != 0)){
                        //if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                //Teams[iTeam]->Hraci[i]->setSestava(1);
                                if(iObrana1 != 0) {
                                        if(iObrana1 == 2) Teams[iTeam]->Lines[0]->setLeftDefender(i);
                                        else Teams[iTeam]->Lines[0]->setRightDefender(i);
                                        iObrana1 --;
                                        s += (String)i + " - ";
                                } else {
                                        if(iObrana2 == 2) Teams[iTeam]->Lines[1]->setLeftDefender(i);
                                        else Teams[iTeam]->Lines[1]->setRightDefender(i);
                                        iObrana2 --;
                                        s += (String)i + " - ";
                                }
                        //}
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'U' && (iUtok1 != 0 || iUtok2 != 0)){
                        //if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                //Teams[iTeam]->Hraci[i]->setSestava(1);
                                if(iUtok1 != 0) {
                                        switch(iUtok1) {
                                                case 3: Teams[iTeam]->Lines[0]->setLeftWing(i); break;
                                                case 2: Teams[iTeam]->Lines[0]->setRightWing(i); break;
                                                case 1: Teams[iTeam]->Lines[0]->setCenter(i); break;
                                        }
                                        iUtok1 --;
                                        s += (String)i + " - ";
                                } else {
                                        switch(iUtok2) {
                                                case 3: Teams[iTeam]->Lines[1]->setLeftWing(i); break;
                                                case 2: Teams[iTeam]->Lines[1]->setRightWing(i); break;
                                                case 1: Teams[iTeam]->Lines[1]->setCenter(i); break;
                                        }
                                        iUtok2 --;  
                                        s += (String)i + " - ";
                                }
                        //}
                }
        }

        Label3->Caption = s;
}
//---------------------------------------------------------------------------

