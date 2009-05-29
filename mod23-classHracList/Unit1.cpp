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
                Teams[i] = new Tym();

        Teams[0]->nactiHrace("teams/aik_l.txt");
        Teams[0]->nactiTym("teams/aik_m.txt");
        Teams[0]->setID(1);
        Teams[1]->nactiHrace("teams/alv_l.txt");
        Teams[1]->nactiTym("teams/alv_m.txt"); 
        Teams[1]->setID(1);
        Teams[2]->nactiHrace("teams/bal_l.txt");
        Teams[2]->nactiTym("teams/bal_m.txt");
        Teams[2]->setID(1);
        Teams[3]->nactiHrace("teams/cap_l.txt");
        Teams[3]->nactiTym("teams/cap_m.txt");
        Teams[3]->setID(3);
        Teams[4]->nactiHrace("teams/dal_l.txt");
        Teams[4]->nactiTym("teams/dal_m.txt");
        Teams[4]->setID(4);
        Teams[5]->nactiHrace("teams/fal_l.txt");
        Teams[5]->nactiTym("teams/fal_m.txt");
        Teams[5]->setID(5);
        Teams[6]->nactiHrace("teams/hel_l.txt");
        Teams[6]->nactiTym("teams/hel_m.txt");
        Teams[6]->setID(6);
        Teams[7]->nactiHrace("teams/jar_l.txt");
        Teams[7]->nactiTym("teams/jar_m.txt");
        Teams[7]->setID(7);
        Teams[8]->nactiHrace("teams/jon_l.txt");
        Teams[8]->nactiTym("teams/jon_m.txt");
        Teams[8]->setID(8);
        Teams[9]->nactiHrace("teams/pix_l.txt");
        Teams[9]->nactiTym("teams/pix_m.txt");
        Teams[9]->setID(9);
        Teams[10]->nactiHrace("teams/sto_l.txt");
        Teams[10]->nactiTym("teams/sto_m.txt");
        Teams[10]->setID(10);
        Teams[11]->nactiHrace("teams/war_l.txt");
        Teams[11]->nactiTym("teams/war_m.txt");
        Teams[11]->setID(11);
                
        for(int i = 0; i < 12; i ++){
                Teams[i]->setridHrace('P', true);
        }

        PlayerList = new HracList();

        for(int i = 0; i < 12; i ++) {
                for(int j = 0; j < Teams[i]->getPocetHracu(); j ++) {
                        PlayerList->add(*(Teams[i]->Hraci[j]));
                }
        }

        Label1->Caption = PlayerList->getNumberOfPlayers();

        for(int i = 0; i < PlayerList->getNumberOfPlayers(); i ++) {
                Memo1->Lines->Add(PlayerList->Players[i]->getPrijmeni());
        }
}
//---------------------------------------------------------------------------
