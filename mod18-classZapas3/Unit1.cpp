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
        Teams[0]->nactiHrace("teams/aik_l.txt");
        Teams[0]->nactiTym("teams/aik_m.txt");
        setLineup(0);

        Teams[1] = new Tym();
        Teams[1]->nactiHrace("teams/pix_l.txt");
        Teams[1]->nactiTym("teams/pix_m.txt");
        setLineup(1);

        Match = new Zapas(*Teams[0], *Teams[1], 1);

        Teams[0]->setridHrace('L', true);
        Teams[1]->setridHrace('L', true);

        for(int i = 0; i < 120; i ++) {
                Match->Akce();
        }

        String s1 = "";
        String s2 = "";

        for(int i = 0; i < Match->getGolyD(); i ++) {
                s1 += Match->getStringScorers(true, i);
                s1 += " ( ";
                s1 += Match->getStringAssistents(true, i);
                s1 += " )\n";
        }

        for(int i = 0; i < Match->getGolyH(); i ++) {
                s2 += Match->getStringScorers(false, i);
                s2 += " ( ";
                s2 += Match->getStringAssistents(false, i);
                s2 += " )\n";
        }

        Label1->Caption = s1;
        Label2->Caption = s2;
        Label3->Caption = Match->getGolyD();
        Label4->Caption = Match->getGolyH();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setLineup(int iTeam)
{
        int iGolman1 = 1;
        int iObrana1 = 2;
        int iObrana2 = 2;
        int iUtok1 = 3;
        int iUtok2 = 3;

        for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++) {
                Teams[iTeam]->Hraci[i]->setSestava(5);
        }

        Teams[iTeam]->setridHrace('A', false);

        for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++){
                if(Teams[iTeam]->Hraci[i]->getPost() == 'G' && iGolman1 != 0){
                        Teams[iTeam]->Hraci[i]->setSestava(1);
                        iGolman1 --;
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'O' && iObrana1 != 0){
                        if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                Teams[iTeam]->Hraci[i]->setSestava(1);
                                iObrana1 --;
                        }
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'U' && iUtok1 != 0){
                        if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                Teams[iTeam]->Hraci[i]->setSestava(1);
                                iUtok1 --;
                        }
                }
        }

        for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++){
                if(Teams[iTeam]->Hraci[i]->getPost() == 'O' && Teams[iTeam]->Hraci[i]->getSestava() == 5 && iObrana2 != 0){
                        if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                Teams[iTeam]->Hraci[i]->setSestava(2);
                                iObrana2 --;
                        }
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'U' && Teams[iTeam]->Hraci[i]->getSestava() == 5 && iUtok1 == 0 && iUtok2 != 0){
                        if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                Teams[iTeam]->Hraci[i]->setSestava(2);
                                iUtok2 --;
                        }
                }
        }
}
//---------------------------------------------------------------------------
