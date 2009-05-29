//---------------------------------------------------------------------------
#pragma hdrstop                                                              
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "ZapasNEW.h"
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_BackClick(TObject *Sender)
{
        SF->Visible = false;
        HO->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setColorsSF()
{
        //TColor RGB1;
        //TColor RGB2;

        //RGB1 = Teams[Manager->getKlub()]->getRGB1();
        //RGB2 = Teams[Manager->getKlub()]->getRGB2();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::setPlayersSF()
{
        SF_LB_Players->Clear();

        String s1 = "";
        String s2 = "";
        int delka;
        for(int i = 0; i < Teams[Manager->getKlub()]->getPocetHracu(); i ++) {
                s1 = (String)Teams[Manager->getKlub()]->Hraci[i]->getPost() + " ";

                //s1 = "";
                delka = 2;
                s2 = (String)Teams[Manager->getKlub()]->Hraci[i]->getCislo();
                delka -= s2.Length();
                for(int j = delka; j > 0; j --) s1 += " ";
                s1 += s2 + " ";

                delka = 12;
                s2 = (String)Teams[Manager->getKlub()]->Hraci[i]->getJmeno();
                delka -= s2.Length();
                s1 += s2;
                for(int j = delka; j >= 0; j --) s1 += " ";

                delka = 13;
                s2 = (String)Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni();
                delka -= s2.Length();
                s1 += s2;
                for(int j = delka; j >= 0; j --) s1 += " ";

                s2 = (String)Teams[Manager->getKlub()]->Hraci[i]->getVek() + " ";
                s1 += s2;
                s2 = (String)Teams[Manager->getKlub()]->Hraci[i]->getFS() + " ";
                s1 += s2;
                s2 = (String)Teams[Manager->getKlub()]->Hraci[i]->getTS() + " ";
                s1 += s2;
                s2 = (String)Teams[Manager->getKlub()]->Hraci[i]->getZS() + " ";
                s1 += s2;
                s2 = (String)Teams[Manager->getKlub()]->Hraci[i]->getEnergie();
                s1 += s2;

                SF_LB_Players->Items->Add(s1);
        }

        String s = "";
        if(Teams[Manager->getKlub()]->Lines[0]->getGoalman() != -1) {
                s = (String)Teams[Manager->getKlub()]->Hraci[Teams[Manager->getKlub()]->Lines[0]->getGoalman()]->getCislo() + " - ";
                s += Teams[Manager->getKlub()]->Hraci[Teams[Manager->getKlub()]->Lines[0]->getGoalman()]->getJmeno() + " ";
                s += Teams[Manager->getKlub()]->Hraci[Teams[Manager->getKlub()]->Lines[0]->getGoalman()]->getPrijmeni() + " ";
                SF_B_Golman->Caption = s;
        }
        s = "";
        if(Teams[Manager->getKlub()]->Lines[0]->getReserveGoalman() != -1) {
                s = (String)Teams[Manager->getKlub()]->Hraci[Teams[Manager->getKlub()]->Lines[0]->getReserveGoalman()]->getCislo() + " - ";
                s += Teams[Manager->getKlub()]->Hraci[Teams[Manager->getKlub()]->Lines[0]->getReserveGoalman()]->getJmeno() + " ";
                s += Teams[Manager->getKlub()]->Hraci[Teams[Manager->getKlub()]->Lines[0]->getReserveGoalman()]->getPrijmeni() + " ";
                SF_B_ReserveGolman->Caption = s;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_PostClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('P', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NumberClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('C', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NameClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('J', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_AgeClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('V', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_FSClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('F', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_TSClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('T', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_ZSClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('Z', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_EnClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('E', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_PostDblClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('P', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NumberDblClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('C', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NameDblClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('J', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_AgeDblClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('V', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_FSDblClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('F', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_TSDblClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('T', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_ZSDblClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('Z', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_EnDblClick(TObject *Sender)
{
        SF_LB_Players->Clear();

        Teams[Manager->getKlub()]->setridHrace('E', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_LB_PlayersMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Button == mbLeft) {
                SF_P_FlowPanel->Visible = true;
                SF_P_FlowPanel->Left = Mouse->CursorPos.x - SF->Left + 10;
                SF_P_FlowPanel->Top = Mouse->CursorPos.y - SF->Top + 5;
                //SF_P_FlowPanel->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                SF_L_FP_Number->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo();
                SF_L_FP_Name->Caption = Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno();
                SF_L_FP_LastName->Caption = Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                SF_LB_Players->Enabled = false;
                Timer2->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_LB_PlayersMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
        if(SF_P_FlowPanel->Visible) {
                SF_P_FlowPanel->Left = Mouse->CursorPos.x - SF->Left + 10;
                SF_P_FlowPanel->Top = Mouse->CursorPos.y - SF->Top + 5;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1st_CenterMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[0][0] != SF_LB_Players->ItemIndex && Sestava[0][1] != SF_LB_Players->ItemIndex && Sestava[0][2] != SF_LB_Players->ItemIndex && Sestava[0][3] != SF_LB_Players->ItemIndex && Sestava[0][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[0][4] = SF_LB_Players->ItemIndex;
                        SF_B_1st_Center->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1st_LeftWingMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[0][0] != SF_LB_Players->ItemIndex && Sestava[0][1] != SF_LB_Players->ItemIndex && Sestava[0][2] != SF_LB_Players->ItemIndex && Sestava[0][3] != SF_LB_Players->ItemIndex && Sestava[0][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[0][2] = SF_LB_Players->ItemIndex;
                        SF_B_1st_LeftWing->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1st_RightWingMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[0][0] != SF_LB_Players->ItemIndex && Sestava[0][1] != SF_LB_Players->ItemIndex && Sestava[0][2] != SF_LB_Players->ItemIndex && Sestava[0][3] != SF_LB_Players->ItemIndex && Sestava[0][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[0][3] = SF_LB_Players->ItemIndex;
                        SF_B_1st_RightWing->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1st_LeftBackMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[0][0] != SF_LB_Players->ItemIndex && Sestava[0][1] != SF_LB_Players->ItemIndex && Sestava[0][2] != SF_LB_Players->ItemIndex && Sestava[0][3] != SF_LB_Players->ItemIndex && Sestava[0][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[0][0] = SF_LB_Players->ItemIndex;
                        SF_B_1st_LeftBack->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1st_RightBackMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[0][0] != SF_LB_Players->ItemIndex && Sestava[0][1] != SF_LB_Players->ItemIndex && Sestava[0][2] != SF_LB_Players->ItemIndex && Sestava[0][3] != SF_LB_Players->ItemIndex && Sestava[0][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[0][1] = SF_LB_Players->ItemIndex;
                        SF_B_1st_RightBack->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_CenterMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[1][0] != SF_LB_Players->ItemIndex && Sestava[1][1] != SF_LB_Players->ItemIndex && Sestava[1][2] != SF_LB_Players->ItemIndex && Sestava[1][3] != SF_LB_Players->ItemIndex && Sestava[1][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[1][4] = SF_LB_Players->ItemIndex;
                        SF_B_2nd_Center->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_LeftWingMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[1][0] != SF_LB_Players->ItemIndex && Sestava[1][1] != SF_LB_Players->ItemIndex && Sestava[1][2] != SF_LB_Players->ItemIndex && Sestava[1][3] != SF_LB_Players->ItemIndex && Sestava[1][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[1][2] = SF_LB_Players->ItemIndex;
                        SF_B_2nd_LeftWing->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_RightWingMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[1][0] != SF_LB_Players->ItemIndex && Sestava[1][1] != SF_LB_Players->ItemIndex && Sestava[1][2] != SF_LB_Players->ItemIndex && Sestava[1][3] != SF_LB_Players->ItemIndex && Sestava[1][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[1][3] = SF_LB_Players->ItemIndex;
                        SF_B_2nd_RightWing->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_LeftBackMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[1][0] != SF_LB_Players->ItemIndex && Sestava[1][1] != SF_LB_Players->ItemIndex && Sestava[1][2] != SF_LB_Players->ItemIndex && Sestava[1][3] != SF_LB_Players->ItemIndex && Sestava[1][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[1][0] = SF_LB_Players->ItemIndex;
                        SF_B_2nd_LeftBack->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_RightBackMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[1][0] != SF_LB_Players->ItemIndex && Sestava[1][1] != SF_LB_Players->ItemIndex && Sestava[1][2] != SF_LB_Players->ItemIndex && Sestava[1][3] != SF_LB_Players->ItemIndex && Sestava[1][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[1][1] = SF_LB_Players->ItemIndex;
                        SF_B_2nd_RightBack->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_CenterMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[2][0] != SF_LB_Players->ItemIndex && Sestava[2][1] != SF_LB_Players->ItemIndex && Sestava[2][2] != SF_LB_Players->ItemIndex && Sestava[2][3] != SF_LB_Players->ItemIndex && Sestava[2][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[2][4] = SF_LB_Players->ItemIndex;
                        SF_B_3rd_Center->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_LeftWingMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[2][0] != SF_LB_Players->ItemIndex && Sestava[2][1] != SF_LB_Players->ItemIndex && Sestava[2][2] != SF_LB_Players->ItemIndex && Sestava[2][3] != SF_LB_Players->ItemIndex && Sestava[2][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[2][2] = SF_LB_Players->ItemIndex;
                        SF_B_3rd_LeftWing->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_RightWingMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[2][0] != SF_LB_Players->ItemIndex && Sestava[2][1] != SF_LB_Players->ItemIndex && Sestava[2][2] != SF_LB_Players->ItemIndex && Sestava[2][3] != SF_LB_Players->ItemIndex && Sestava[2][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[2][3] = SF_LB_Players->ItemIndex;
                        SF_B_3rd_RightWing->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_LeftBackMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[2][0] != SF_LB_Players->ItemIndex && Sestava[2][1] != SF_LB_Players->ItemIndex && Sestava[2][2] != SF_LB_Players->ItemIndex && Sestava[2][3] != SF_LB_Players->ItemIndex && Sestava[2][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[2][0] = SF_LB_Players->ItemIndex;
                        SF_B_3rd_LeftBack->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_RightBackMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[2][0] != SF_LB_Players->ItemIndex && Sestava[2][1] != SF_LB_Players->ItemIndex && Sestava[2][2] != SF_LB_Players->ItemIndex && Sestava[2][3] != SF_LB_Players->ItemIndex && Sestava[2][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[2][1] = SF_LB_Players->ItemIndex;
                        SF_B_3rd_RightBack->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_CenterMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[3][0] != SF_LB_Players->ItemIndex && Sestava[3][1] != SF_LB_Players->ItemIndex && Sestava[3][2] != SF_LB_Players->ItemIndex && Sestava[3][3] != SF_LB_Players->ItemIndex && Sestava[3][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[3][4] = SF_LB_Players->ItemIndex;
                        SF_B_4th_Center->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_LeftBackMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[3][0] != SF_LB_Players->ItemIndex && Sestava[3][1] != SF_LB_Players->ItemIndex && Sestava[3][2] != SF_LB_Players->ItemIndex && Sestava[3][3] != SF_LB_Players->ItemIndex && Sestava[3][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[3][0] = SF_LB_Players->ItemIndex;
                        SF_B_4th_LeftBack->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_LeftWingMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[3][0] != SF_LB_Players->ItemIndex && Sestava[3][1] != SF_LB_Players->ItemIndex && Sestava[3][2] != SF_LB_Players->ItemIndex && Sestava[3][3] != SF_LB_Players->ItemIndex && Sestava[3][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[3][2] = SF_LB_Players->ItemIndex;
                        SF_B_4th_LeftWing->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_RightBackMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[3][0] != SF_LB_Players->ItemIndex && Sestava[3][1] != SF_LB_Players->ItemIndex && Sestava[3][2] != SF_LB_Players->ItemIndex && Sestava[3][3] != SF_LB_Players->ItemIndex && Sestava[3][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[3][1] = SF_LB_Players->ItemIndex;
                        SF_B_4th_RightBack->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_RightWingMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(SF_P_FlowPanel->Visible) {
                if(Sestava[3][0] != SF_LB_Players->ItemIndex && Sestava[3][1] != SF_LB_Players->ItemIndex && Sestava[3][2] != SF_LB_Players->ItemIndex && Sestava[3][3] != SF_LB_Players->ItemIndex && Sestava[3][4] != SF_LB_Players->ItemIndex && Golman[0] != SF_LB_Players->ItemIndex && Golman[1] != SF_LB_Players->ItemIndex) {
                        Sestava[3][3] = SF_LB_Players->ItemIndex;
                        SF_B_4th_RightWing->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_GolmanMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        bool bTrue = true;
        if(SF_P_FlowPanel->Visible) {
                for(int i = 0; i < 4; i ++) {
                        for(int j = 0; j < 5; j ++) {
                                if(Sestava[i][j] == SF_LB_Players->ItemIndex) {
                                        bTrue = false;
                                }
                        }
                }

                if(Golman[0] == SF_LB_Players->ItemIndex || Golman[1] == SF_LB_Players->ItemIndex) {
                        bTrue = false;
                }

                if(bTrue) {
                        Golman[0] = SF_LB_Players->ItemIndex;
                        SF_B_Golman->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_ReserveGolmanMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        bool bTrue = true;
        if(SF_P_FlowPanel->Visible) {
                for(int i = 0; i < 4; i ++) {
                        for(int j = 0; j < 5; j ++) {
                                if(Sestava[i][j] == SF_LB_Players->ItemIndex) {
                                        bTrue = false;
                                }
                        }
                }

                if(Golman[0] == SF_LB_Players->ItemIndex || Golman[1] == SF_LB_Players->ItemIndex) {
                        bTrue = false;
                }

                if(bTrue) {
                        Golman[1] = SF_LB_Players->ItemIndex;
                        SF_B_ReserveGolman->Caption = (String)Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getCislo() + " - " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[SF_LB_Players->ItemIndex]->getPrijmeni();
                }

                Timer2->Enabled = false;
                SF_P_FlowPanel->Visible = false;
                SF_LB_Players->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1stLClick(TObject *Sender)
{
        SF_GB_1stLine->Visible = true;
        SF_GB_2ndLine->Visible = false;
        SF_GB_3rdLine->Visible = false;
        SF_GB_4thLine->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2ndLClick(TObject *Sender)
{
        SF_GB_1stLine->Visible = false;
        SF_GB_2ndLine->Visible = true;
        SF_GB_3rdLine->Visible = false;
        SF_GB_4thLine->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SF_B_3rdLClick(TObject *Sender)
{
        SF_GB_1stLine->Visible = false;
        SF_GB_2ndLine->Visible = false;
        SF_GB_3rdLine->Visible = true;
        SF_GB_4thLine->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4thLClick(TObject *Sender)
{
        SF_GB_1stLine->Visible = false;
        SF_GB_2ndLine->Visible = false;
        SF_GB_3rdLine->Visible = false;
        SF_GB_4thLine->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_SaveClick(TObject *Sender)
{
        bool bTrue = true;
        if(SF_B_Golman->Caption == "Golman") ShowMessage("Musite nastavit golmana!");
        if(SF_CB_1st_Type->ItemIndex == 0) {
                for(int i = 0; i < 5; i ++) {
                        if(Sestava[0][i] == -1) {
                                ShowMessage("Pokud je lajna(1.) nastavena jako \"Hrajici lajna\", musi mit nastaveny vsechny vse cleny!");
                                bTrue = false;
                                break;
                        }
                }
        }
        if(SF_CB_2nd_Type->ItemIndex == 0) {
                for(int i = 0; i < 5; i ++) {
                        if(Sestava[1][i] == -1) ShowMessage("Pokud je lajna(2.) nastavena jako \"Hrajici lajna\", musi mit nastaveny vsechny vse cleny!");
                        bTrue = false;
                        break;
                }
        }
        if(SF_CB_3rd_Type->ItemIndex == 0) {
                for(int i = 0; i < 5; i ++) {
                        if(Sestava[2][i] == -1) ShowMessage("Pokud je lajna(3.) nastavena jako \"Hrajici lajna\", musi mit nastaveny vsechny vse cleny!");
                        bTrue = false;
                        break;
                }
        }
        if(SF_CB_4th_Type->ItemIndex == 0) {
                for(int i = 0; i < 5; i ++) {
                        if(Sestava[3][i] == -1) ShowMessage("Pokud je lajna(4.) nastavena jako \"Hrajici lajna\", musi mit nastaveny vsechny vse cleny!");
                        bTrue = false;
                        break;
                }
        }
        if(SF_CB_1st_Type->ItemIndex == 1 && SF_CB_2nd_Type->ItemIndex == 1 && SF_CB_3rd_Type->ItemIndex == 1 && SF_CB_4th_Type->ItemIndex == 1) {
                ShowMessage("Alespon jedna lajna musi byt nastavena jako \"Hrajici lajna\"!");
                bTrue = false;
        }

        if(bTrue) {
                if(SF_CB_1st_Type->ItemIndex == 0) Teams[Manager->getKlub()]->Lines[0]->setEnabled(true);
                else Teams[Manager->getKlub()]->Lines[0]->setEnabled(false);
                Teams[Manager->getKlub()]->Lines[0]->setAllPosts(Golman[0], Golman[1], Sestava[0][0], Sestava[0][1], Sestava[0][2], Sestava[0][3], Sestava[0][4]);

                if(SF_CB_2nd_Type->ItemIndex == 0) Teams[Manager->getKlub()]->Lines[1]->setEnabled(true);
                else Teams[Manager->getKlub()]->Lines[1]->setEnabled(false);
                Teams[Manager->getKlub()]->Lines[1]->setAllPosts(Golman[0], Golman[1], Sestava[1][0], Sestava[1][1], Sestava[1][2], Sestava[1][3], Sestava[1][4]);

                if(SF_CB_3rd_Type->ItemIndex == 0) Teams[Manager->getKlub()]->Lines[2]->setEnabled(true);
                else Teams[Manager->getKlub()]->Lines[2]->setEnabled(false);
                Teams[Manager->getKlub()]->Lines[2]->setAllPosts(Golman[0], Golman[1], Sestava[2][0], Sestava[2][1], Sestava[2][2], Sestava[2][3], Sestava[2][4]);

                if(SF_CB_4th_Type->ItemIndex == 0) Teams[Manager->getKlub()]->Lines[3]->setEnabled(true);
                else Teams[Manager->getKlub()]->Lines[3]->setEnabled(false);
                Teams[Manager->getKlub()]->Lines[3]->setAllPosts(Golman[0], Golman[1], Sestava[3][0], Sestava[3][1], Sestava[3][2], Sestava[3][3], Sestava[3][4]);
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SF_B_1st_CenterClick(TObject *Sender)
{
        SF_B_1st_Center->Caption = "Centr";
        Sestava[0][4] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1st_LeftWingClick(TObject *Sender)
{
        SF_B_1st_LeftWing->Caption = "Leve kridlo";
        Sestava[0][2] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1st_RightWingClick(TObject *Sender)
{
        SF_B_1st_RightWing->Caption = "Prave kridlo";
        Sestava[0][3] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1st_LeftBackClick(TObject *Sender)
{
        SF_B_1st_LeftBack->Caption = "Levy obrance";
        Sestava[0][0] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1st_RightBackClick(TObject *Sender)
{
        SF_B_1st_RightBack->Caption = "Pravy obrance";
        Sestava[0][1] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_CenterClick(TObject *Sender)
{
        SF_B_2nd_Center->Caption = "Centr";
        Sestava[1][4] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_LeftWingClick(TObject *Sender)
{
        SF_B_2nd_LeftWing->Caption = "Leve kridlo";
        Sestava[1][2] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_RightWingClick(TObject *Sender)
{
        SF_B_2nd_RightWing->Caption = "Prave kridlo";
        Sestava[1][3] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_LeftBackClick(TObject *Sender)
{
        SF_B_2nd_LeftBack->Caption = "Levy obrance";
        Sestava[1][0] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2nd_RightBackClick(TObject *Sender)
{
        SF_B_2nd_RightBack->Caption = "Pravy obrance";
        Sestava[1][1] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_CenterClick(TObject *Sender)
{
        SF_B_3rd_Center->Caption = "Centr";
        Sestava[2][4] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_LeftWingClick(TObject *Sender)
{
        SF_B_3rd_LeftWing->Caption = "Leve kridlo";
        Sestava[2][2] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_RightWingClick(TObject *Sender)
{
        SF_B_3rd_RightWing->Caption = "Prave kridlo";
        Sestava[2][3] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_LeftBackClick(TObject *Sender)
{
        SF_B_3rd_LeftBack->Caption = "Levy obrance";
        Sestava[2][0] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rd_RightBackClick(TObject *Sender)
{
        SF_B_3rd_RightBack->Caption = "Pravy obrance";
        Sestava[2][1] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_CenterClick(TObject *Sender)
{
        SF_B_4th_Center->Caption = "Centr";
        Sestava[3][4] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_LeftWingClick(TObject *Sender)
{
        SF_B_4th_LeftWing->Caption = "Leve kridlo";
        Sestava[3][2] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_RightWingClick(TObject *Sender)
{
        SF_B_4th_RightWing->Caption = "Prave kridlo";
        Sestava[3][3] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_LeftBackClick(TObject *Sender)
{
        SF_B_4th_LeftBack->Caption = "Levy obrance";
        Sestava[3][0] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4th_RightBackClick(TObject *Sender)
{
        SF_B_4th_RightBack->Caption = "Pravy obrance";
        Sestava[3][1] = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_GolmanClick(TObject *Sender)
{
        SF_B_Golman->Caption = "Golman";
        Golman[0] = -1;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_ReserveGolmanClick(TObject *Sender)
{
        SF_B_ReserveGolman->Caption = "Nahradni golman";
        Golman[1] = -1;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_GB_1stLineMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_GB_2ndLineMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_GB_3rdLineMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_GB_4thLineMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_GB_GoalkeeperMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_1stLMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_2ndLMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_3rdLMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_4thLMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_BackMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_SaveMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Timer2->Enabled = false;
        SF_P_FlowPanel->Visible = false;
        SF_LB_Players->Enabled = true;
}
//---------------------------------------------------------------------------
