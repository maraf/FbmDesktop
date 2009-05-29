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
        MatchList = new ZapasList();

        Teams[0] = new Tym();
        Teams[0]->nactiHrace("teams/aik_l.txt");
        Teams[0]->nactiTym("teams/aik_m.txt");
        setLineup(0);

        Teams[1] = new Tym();
        Teams[1]->nactiHrace("teams/pix_l.txt");
        Teams[1]->nactiTym("teams/pix_m.txt");
        setLineup(1);

        Zapas *Match = new Zapas(*Teams[0], *Teams[1], 1);

        Teams[0]->setridHrace('L', true);
        Teams[1]->setridHrace('L', true);

        for(int i = 0; i < 120; i ++) {
                Match->Akce();
        }

        MatchList->add(Match);
        delete Match;

        String s = "";
        s += (String)MatchList->Matches[0]->getGolyD() + " : " + (String)MatchList->Matches[0]->getGolyH();

        Label1->Caption = s;

        Match = new Zapas(*Teams[1], *Teams[0], 2);

        Teams[0]->setridHrace('L', true);
        Teams[1]->setridHrace('L', true);

        for(int i = 0; i < 120; i ++) {
                Match->Akce();
        }

        MatchList->add(Match);
        delete Match;

        s += "\n" + (String)MatchList->Matches[1]->getGolyD() + " : " + (String)MatchList->Matches[1]->getGolyH();
        Label1->Caption = s;
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