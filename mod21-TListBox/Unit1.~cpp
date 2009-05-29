//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//      Dodelat:
//              -na 'onClick' na sestavove tlacitko, smazat ten dany post
//              -tlacitko na vycisteni lajny
//              -tlacitko 'Uloz sestavu' zpristupnit az kdyz u vsech lajn co
//               maji nastaveni 'Hrajici lajna' budou nastaveni vsichni hraci
//               a bude nastaven alespon jeden golman
//
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Team = new Tym();
        Team->nactiTym("teams/aik_m.txt");
        Team->nactiHrace("teams/aik_l.txt");

        String s1 = "";
        String s2 = "";
        int delka;
        for(int i = 0; i < Team->getPocetHracu(); i ++) {
                s1 = (String)Team->Hraci[i]->getPost() + " ";

                //s1 = "";
                delka = 2;
                s2 = (String)Team->Hraci[i]->getCislo();
                delka -= s2.Length();
                for(int j = delka; j > 0; j --) s1 += " ";
                s1 += s2 + " ";

                delka = 12;
                s2 = (String)Team->Hraci[i]->getJmeno();
                delka -= s2.Length();
                s1 += s2;
                for(int j = delka; j >= 0; j --) s1 += " ";

                delka = 13;
                s2 = (String)Team->Hraci[i]->getPrijmeni();
                delka -= s2.Length();
                s1 += s2;
                for(int j = delka; j >= 0; j --) s1 += " ";

                s2 = (String)Team->Hraci[i]->getVek() + " ";
                s1 += s2;
                s2 = (String)Team->Hraci[i]->getFS() + " ";
                s1 += s2;
                s2 = (String)Team->Hraci[i]->getTS() + " ";
                s1 += s2;
                s2 = (String)Team->Hraci[i]->getZS();
                s1 += s2;
                ListBox1->Items->Add(s1);
        }

        for(int i = 0; i < 4; i ++) {
                for(int j = 0; j < 5; j ++) {
                        Sestava[i][j] = -1;
                }
        }

        Golman[0] = -1;
        Golman[1] = -1;

        GroupBox2->Left = 432;
        GroupBox2->Top = 72;
        GroupBox3->Left = 432;
        GroupBox3->Top = 72;
        GroupBox4->Left = 432;
        GroupBox4->Top = 72;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1DblClick(TObject *Sender)
{
        Label1->Caption = "SELECTED:\t" + (String)ListBox1->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1KeyPress(TObject *Sender, char &Key)
{
        if(Key == 13) Label1->Caption = "SELECTED:\t" + (String)ListBox1->ItemIndex;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Panel1->Left = Mouse->CursorPos.x - Form1->Left;
        Panel1->Top = Mouse->CursorPos.y - Form1->Top;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Button == mbLeft) {
                Timer1->Enabled = true;
                Panel1->Visible = true;
                ListBox1->Enabled = false;
                Label2->Caption = (String)Team->Hraci[ListBox1->ItemIndex]->getCislo();
                Label3->Caption = Team->Hraci[ListBox1->ItemIndex]->getJmeno();
                Label4->Caption = Team->Hraci[ListBox1->ItemIndex]->getPrijmeni();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Panel1->Visible = false;
        ListBox1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        Timer1->Enabled = false;
        Panel1->Visible = false;
        ListBox1->Enabled = true;
        Label5->Caption = (String)X + " - " + (String)Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[0][0] != ListBox1->ItemIndex && Sestava[0][1] != ListBox1->ItemIndex && Sestava[0][2] != ListBox1->ItemIndex && Sestava[0][3] != ListBox1->ItemIndex && Sestava[0][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[0][1] = ListBox1->ItemIndex;
                        Button2->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[0][0] != ListBox1->ItemIndex && Sestava[0][1] != ListBox1->ItemIndex && Sestava[0][2] != ListBox1->ItemIndex && Sestava[0][3] != ListBox1->ItemIndex && Sestava[0][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[0][3] = ListBox1->ItemIndex;
                        Button4->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[0][0] != ListBox1->ItemIndex && Sestava[0][1] != ListBox1->ItemIndex && Sestava[0][2] != ListBox1->ItemIndex && Sestava[0][3] != ListBox1->ItemIndex && Sestava[0][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[0][4] = ListBox1->ItemIndex;
                        Button5->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                } 

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[0][0] != ListBox1->ItemIndex && Sestava[0][1] != ListBox1->ItemIndex && Sestava[0][2] != ListBox1->ItemIndex && Sestava[0][3] != ListBox1->ItemIndex && Sestava[0][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[0][2] = ListBox1->ItemIndex;
                        Button3->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[0][0] != ListBox1->ItemIndex && Sestava[0][1] != ListBox1->ItemIndex && Sestava[0][2] != ListBox1->ItemIndex && Sestava[0][3] != ListBox1->ItemIndex && Sestava[0][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[0][0] = ListBox1->ItemIndex;
                        Button1->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button11MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[1][0] != ListBox1->ItemIndex && Sestava[1][1] != ListBox1->ItemIndex && Sestava[1][2] != ListBox1->ItemIndex && Sestava[1][3] != ListBox1->ItemIndex && Sestava[1][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[1][0] = ListBox1->ItemIndex;
                        Button11->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[1][0] != ListBox1->ItemIndex && Sestava[1][1] != ListBox1->ItemIndex && Sestava[1][2] != ListBox1->ItemIndex && Sestava[1][3] != ListBox1->ItemIndex && Sestava[1][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[1][1] = ListBox1->ItemIndex;
                        Button12->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[1][0] != ListBox1->ItemIndex && Sestava[1][1] != ListBox1->ItemIndex && Sestava[1][2] != ListBox1->ItemIndex && Sestava[1][3] != ListBox1->ItemIndex && Sestava[1][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[1][2] = ListBox1->ItemIndex;
                        Button13->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[1][0] != ListBox1->ItemIndex && Sestava[1][1] != ListBox1->ItemIndex && Sestava[1][2] != ListBox1->ItemIndex && Sestava[1][3] != ListBox1->ItemIndex && Sestava[1][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[1][4] = ListBox1->ItemIndex;
                        Button15->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[1][0] != ListBox1->ItemIndex && Sestava[1][1] != ListBox1->ItemIndex && Sestava[1][2] != ListBox1->ItemIndex && Sestava[1][3] != ListBox1->ItemIndex && Sestava[1][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[1][3] = ListBox1->ItemIndex;
                        Button14->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[2][0] != ListBox1->ItemIndex && Sestava[2][1] != ListBox1->ItemIndex && Sestava[2][2] != ListBox1->ItemIndex && Sestava[2][3] != ListBox1->ItemIndex && Sestava[2][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[2][0] = ListBox1->ItemIndex;
                        Button6->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[2][0] != ListBox1->ItemIndex && Sestava[2][1] != ListBox1->ItemIndex && Sestava[2][2] != ListBox1->ItemIndex && Sestava[2][3] != ListBox1->ItemIndex && Sestava[2][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[2][1] = ListBox1->ItemIndex;
                        Button7->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[2][0] != ListBox1->ItemIndex && Sestava[2][1] != ListBox1->ItemIndex && Sestava[2][2] != ListBox1->ItemIndex && Sestava[2][3] != ListBox1->ItemIndex && Sestava[2][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[2][2] = ListBox1->ItemIndex;
                        Button8->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[2][0] != ListBox1->ItemIndex && Sestava[2][1] != ListBox1->ItemIndex && Sestava[2][2] != ListBox1->ItemIndex && Sestava[2][3] != ListBox1->ItemIndex && Sestava[2][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[2][3] = ListBox1->ItemIndex;
                        Button9->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[2][0] != ListBox1->ItemIndex && Sestava[2][1] != ListBox1->ItemIndex && Sestava[2][2] != ListBox1->ItemIndex && Sestava[2][3] != ListBox1->ItemIndex && Sestava[2][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[2][4] = ListBox1->ItemIndex;
                        Button10->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[3][0] != ListBox1->ItemIndex && Sestava[3][1] != ListBox1->ItemIndex && Sestava[3][2] != ListBox1->ItemIndex && Sestava[3][3] != ListBox1->ItemIndex && Sestava[3][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[3][0] = ListBox1->ItemIndex;
                        Button16->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[3][0] != ListBox1->ItemIndex && Sestava[3][1] != ListBox1->ItemIndex && Sestava[3][2] != ListBox1->ItemIndex && Sestava[3][3] != ListBox1->ItemIndex && Sestava[3][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[3][1] = ListBox1->ItemIndex;
                        Button17->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[3][0] != ListBox1->ItemIndex && Sestava[3][1] != ListBox1->ItemIndex && Sestava[3][2] != ListBox1->ItemIndex && Sestava[3][3] != ListBox1->ItemIndex && Sestava[3][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[3][2] = ListBox1->ItemIndex;
                        Button18->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[3][0] != ListBox1->ItemIndex && Sestava[3][1] != ListBox1->ItemIndex && Sestava[3][2] != ListBox1->ItemIndex && Sestava[3][3] != ListBox1->ItemIndex && Sestava[3][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[3][3] = ListBox1->ItemIndex;
                        Button19->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Panel1->Visible) {
                if(Sestava[3][0] != ListBox1->ItemIndex && Sestava[3][1] != ListBox1->ItemIndex && Sestava[3][2] != ListBox1->ItemIndex && Sestava[3][3] != ListBox1->ItemIndex && Sestava[3][4] != ListBox1->ItemIndex && Golman[0] != ListBox1->ItemIndex && Golman[1] != ListBox1->ItemIndex) {
                        Sestava[3][4] = ListBox1->ItemIndex;
                        Button20->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button21Click(TObject *Sender)
{
        GroupBox1->Visible = true;
        GroupBox2->Visible = false;
        GroupBox3->Visible = false;
        GroupBox4->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
        GroupBox1->Visible = false;
        GroupBox3->Visible = true;
        GroupBox2->Visible = false;
        GroupBox4->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
        GroupBox1->Visible = false;
        GroupBox3->Visible = false;
        GroupBox2->Visible = true;
        GroupBox4->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
        GroupBox1->Visible = false;
        GroupBox2->Visible = false;
        GroupBox3->Visible = false;
        GroupBox4->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        bool bTrue = true;
        if(Panel1->Visible) {
                for(int i = 0; i < 4; i ++) {
                        for(int j = 0; j < 5; j ++) {
                                if(Sestava[i][j] == ListBox1->ItemIndex) {
                                        bTrue = false;
                                }
                        }
                }

                if(Golman[0] == ListBox1->ItemIndex || Golman[1] == ListBox1->ItemIndex) {
                        bTrue = false;
                }

                if(bTrue) {
                        Button25->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;;
                        Golman[0] = ListBox1->ItemIndex;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        bool bTrue = true;
        if(Panel1->Visible) {
                for(int i = 0; i < 4; i ++) {
                        for(int j = 0; j < 5; j ++) {
                                if(Sestava[i][j] == ListBox1->ItemIndex) {
                                        bTrue = false;
                                }
                        }
                }

                if(Golman[0] == ListBox1->ItemIndex || Golman[1] == ListBox1->ItemIndex) {
                        bTrue = false;
                }

                if(bTrue) {
                        Button26->Caption = Label2->Caption + " - " + Label3->Caption + " " + Label4->Caption;;
                        Golman[1] = ListBox1->ItemIndex;
                }

                Panel1->Visible = false;
                ListBox1->Enabled = true;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Sestava[0][0] = -1;
        Button5->Caption = "Centr";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button27Click(TObject *Sender)
{
        for(int i = 0; i < 4; i ++) {
                for(int j = 0; j < 5; j ++) {
                        Sestava[i][j] = -1;
                }
        }

        Golman[0] = -1;
        Golman[1] = -1;

        Button1->Caption = "Levy obrance";
        Button2->Caption = "Pravy obrance";
        Button3->Caption = "Prave kridlo";
        Button4->Caption = "Leve kridlo";
        Button5->Caption = "Centr";

        Button6->Caption = "Centr";
        Button7->Caption = "Leve kridlo";
        Button8->Caption = "Prave kridlo";
        Button9->Caption = "Levy obrance";
        Button10->Caption = "Pravy obrance";

        Button11->Caption = "Centr";
        Button12->Caption = "Leve kridlo";
        Button13->Caption = "Prave kridlo";
        Button14->Caption = "Levy obrance";
        Button15->Caption = "Pravy obrance";

        Button16->Caption = "Centr";
        Button17->Caption = "Leve kridlo";
        Button18->Caption = "Prave kridlo";
        Button19->Caption = "Levy obrance";
        Button20->Caption = "Pravy obrance";

        Button25->Caption = "Golman";
        Button26->Caption = "Nahradni golman";
}
//---------------------------------------------------------------------------

