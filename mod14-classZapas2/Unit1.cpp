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
        for(int i = 0; i < 12; i ++)
                tymy[i] = new Tym();

        tymy[0]->nactiHrace("teams/aik_l.txt");
        tymy[0]->nactiTym("teams/aik_m.txt");
        tymy[1]->nactiHrace("teams/alv_l.txt");
        tymy[1]->nactiTym("teams/alv_m.txt");
        tymy[2]->nactiHrace("teams/bal_l.txt");
        tymy[2]->nactiTym("teams/bal_m.txt");
        tymy[3]->nactiHrace("teams/cap_l.txt");
        tymy[3]->nactiTym("teams/cap_m.txt");
        tymy[4]->nactiHrace("teams/dal_l.txt");
        tymy[4]->nactiTym("teams/dal_m.txt");
        tymy[5]->nactiHrace("teams/fal_l.txt");
        tymy[5]->nactiTym("teams/fal_m.txt");
        tymy[6]->nactiHrace("teams/hel_l.txt");
        tymy[6]->nactiTym("teams/hel_m.txt");
        tymy[7]->nactiHrace("teams/jar_l.txt");
        tymy[7]->nactiTym("teams/jar_m.txt");
        tymy[8]->nactiHrace("teams/jon_l.txt");
        tymy[8]->nactiTym("teams/jon_m.txt");
        tymy[9]->nactiHrace("teams/pix_l.txt");
        tymy[9]->nactiTym("teams/pix_m.txt");
        tymy[10]->nactiHrace("teams/sto_l.txt");
        tymy[10]->nactiTym("teams/sto_m.txt");
        tymy[11]->nactiHrace("teams/war_l.txt");
        tymy[11]->nactiTym("teams/war_m.txt");

        for(int i = 0; i < 12; i ++){
                setLineup(i);
                tymy[i]->setridHrace('P', true);
        }

        Match = new Zapas(*tymy[0], *tymy[11]);

        Match->Tymy[0]->setridHrace('L', true);
//        Match->Tymy[0]->ulozHrace("aik.lineup");
        Match->Tymy[1]->setridHrace('L', true);
//        Match->Tymy[1]->ulozHrace("pix.lineup");

        Label18->Caption = Match->getNavsteva();

        Match->Akce();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::setLineup(int iTeam)
{
        int iGolman1 = 1;
        int iObrana1 = 2;
        int iObrana2 = 2;
        int iUtok1 = 3;
        int iUtok2 = 3;

        tymy[iTeam]->setridHrace('A', false);

        for(int i = 0; i < tymy[iTeam]->getPocetHracu(); i ++){
                if(tymy[iTeam]->Hraci[i]->getPost() == 'G' && iGolman1 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(1);
                        iGolman1 --;
                }
                if(tymy[iTeam]->Hraci[i]->getPost() == 'O' && iObrana1 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(1);
                        iObrana1 --;
                }
                if(tymy[iTeam]->Hraci[i]->getPost() == 'U' && iUtok1 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(1);
                        iUtok1 --;
                }
        }

        for(int i = 0; i < tymy[iTeam]->getPocetHracu(); i ++){
                if(tymy[iTeam]->Hraci[i]->getPost() == 'O' && tymy[iTeam]->Hraci[i]->getSestava() == 5 && iObrana2 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(2);
                        iObrana2 --;
                }
                if(tymy[iTeam]->Hraci[i]->getPost() == 'U' && tymy[iTeam]->Hraci[i]->getSestava() == 5 && iUtok1 == 0 && iUtok2 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(2);
                        iUtok2 --;
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        for(int i = 0; i < 12; i ++)
                delete(tymy[i]);

        delete Match;

        Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Match->Akce();
        Label1->Caption = Match->getCount()/2;
        Label2->Caption = Match->getCount();

        if(Match->getGoal() == 0){
                String ss = Match->Tymy[0]->Hraci[Match->getStrelec()]->getPrijmeni() + ", " + Match->Tymy[0]->Hraci[Match->getAsistent()]->getPrijmeni();
                Memo1->Lines->Add(ss);
                Match->setGoal(3);
        }
        if(Match->getGoal() == 1){
                String ss = Match->Tymy[1]->Hraci[Match->getStrelec()]->getPrijmeni() + ", " + Match->Tymy[1]->Hraci[Match->getAsistent()]->getPrijmeni();
                Memo2->Lines->Add(ss);
                Match->setGoal(3);
        }
        Label10->Caption = Match->getStrelyD();
        Label11->Caption = Match->getStrelyH();
//        Label12->Caption = Match->iLine[0];
//        Label13->Caption = Match->iLine[1];
        Label14->Caption = Match->getGolyD();
        Label15->Caption = Match->getGolyH();

        if(Match->getCount() == 120)
                Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

