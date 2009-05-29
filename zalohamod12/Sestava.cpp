//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sestava.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        t = 0;

        for(int i = 0; i < 12; i ++)
                tymy[i] = new Tym();

        tymy[0]->nactiHrace("teams/aik_l.txt");
        tymy[0]->setridHrace('P', true);
        tymy[0]->nactiTym("teams/aik_m.txt");
        tymy[1]->nactiHrace("teams/alv_l.txt");
        tymy[1]->setridHrace('P', true);
        tymy[1]->nactiTym("teams/alv_m.txt");
        tymy[2]->nactiHrace("teams/bal_l.txt");
        tymy[2]->setridHrace('P', true);
        tymy[2]->nactiTym("teams/bal_m.txt");
        tymy[3]->nactiHrace("teams/cap_l.txt");
        tymy[3]->setridHrace('P', true);
        tymy[3]->nactiTym("teams/cap_m.txt");
        tymy[4]->nactiHrace("teams/dal_l.txt");
        tymy[4]->setridHrace('P', true);
        tymy[4]->nactiTym("teams/dal_m.txt");
        tymy[5]->nactiHrace("teams/fal_l.txt");
        tymy[5]->setridHrace('P', true);
        tymy[5]->nactiTym("teams/fal_m.txt");
        tymy[6]->nactiHrace("teams/hel_l.txt");
        tymy[6]->setridHrace('P', true);
        tymy[6]->nactiTym("teams/hel_m.txt");
        tymy[7]->nactiHrace("teams/jar_l.txt");
        tymy[7]->setridHrace('P', true);
        tymy[7]->nactiTym("teams/jar_m.txt");
        tymy[8]->nactiHrace("teams/jon_l.txt");
        tymy[8]->setridHrace('P', true);
        tymy[8]->nactiTym("teams/jon_m.txt");
        tymy[9]->nactiHrace("teams/pix_l.txt");
        tymy[9]->setridHrace('P', true);
        tymy[9]->nactiTym("teams/pix_m.txt");
        tymy[10]->nactiHrace("teams/sto_l.txt");
        tymy[10]->setridHrace('P', true);
        tymy[10]->nactiTym("teams/sto_m.txt");
        tymy[11]->nactiHrace("teams/war_l.txt");
        tymy[11]->setridHrace('P', true);
        tymy[11]->nactiTym("teams/war_m.txt");


        R1 = tymy[t]->getR1();
        G1 = tymy[t]->getG1();
        B1 = tymy[t]->getB1();

        R2 = tymy[t]->getR2();
        G2 = tymy[t]->getG2();
        B2 = tymy[t]->getB2();

        LP->Left = 112;
        LP->Top = 84;

        setColors();

        LP_Name->Caption = tymy[t]->getNazevTymu();
        LP_Hall->Caption = tymy[t]->getNazevHaly();
        LP_Capacity->Caption = tymy[t]->getKapacitaHaly();
        LP_Logo->Picture->LoadFromFile("teams/"+tymy[t]->getLogo());
        LP_iHall->Picture->LoadFromFile("teams/"+tymy[t]->getHala());

        setPlayers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        for(int i = 0; i < 12; i ++)
                delete(tymy[i]);

        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_P_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('P', true);

        setPlayers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_C_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('C', true);

        setPlayers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_J_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('J', true);

        setPlayers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_V_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('V', true);

        setPlayers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_F_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('F', true);

        setPlayers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_T_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('T', true);

        setPlayers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Z_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('Z', true);

        setPlayers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_L_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('L', true);

        setPlayers();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setColors()
{
        LP->Color = RGB(R1,G1,B1);;
        LP_B1->Brush->Color = RGB(R2,G2,B2);
        LP_B2->Brush->Color = RGB(R1,G1,B1);
        LP_B2->Pen->Color = RGB(R2,G2,B2);
        LP_B3->Brush->Color = RGB(R2,G2,B2);
        LP_B4->Brush->Color = RGB(R1,G1,B1);
        LP_Name->Color = RGB(R2,G2,B2);
        LP_Name->Font->Color = RGB(R1,G1,B1);
        LP_Hall->Color = RGB(R2,G2,B2);
        LP_Hall->Font->Color = RGB(R1,G1,B1);
        LP_Capacity->Color = RGB(R2,G2,B2);
        LP_Capacity->Font->Color = RGB(R1,G1,B1);
        LP_lCapacity->Color = RGB(R2,G2,B2);
        LP_lCapacity->Font->Color = RGB(R1,G1,B1);

        LP_P_L->Color = RGB(R1,G1,B1);
        LP_P_L->Font->Color = RGB(R2,G2,B2);
        LP_C_L->Color = RGB(R1,G1,B1);
        LP_C_L->Font->Color = RGB(R2,G2,B2);
        LP_J_L->Color = RGB(R1,G1,B1);
        LP_J_L->Font->Color = RGB(R2,G2,B2);
        LP_V_L->Color = RGB(R1,G1,B1);
        LP_V_L->Font->Color = RGB(R2,G2,B2);
        LP_T_L->Color = RGB(R1,G1,B1);
        LP_T_L->Font->Color = RGB(R2,G2,B2);
        LP_F_L->Color = RGB(R1,G1,B1);
        LP_F_L->Font->Color = RGB(R2,G2,B2);
        LP_Z_L->Color = RGB(R1,G1,B1);
        LP_Z_L->Font->Color = RGB(R2,G2,B2);
        LP_L_L->Color = RGB(R1,G1,B1);
        LP_L_L->Font->Color = RGB(R2,G2,B2);
        LP_Zl_L->Color = RGB(R1,G1,B1);
        LP_Zl_L->Font->Color = RGB(R2,G2,B2);
        LP_Gl_L->Color = RGB(R1,G1,B1);
        LP_Gl_L->Font->Color = RGB(R2,G2,B2);
        LP_Al_L->Color = RGB(R1,G1,B1);
        LP_Al_L->Font->Color = RGB(R2,G2,B2);
        LP_Zp_L->Color = RGB(R1,G1,B1);
        LP_Zp_L->Font->Color = RGB(R2,G2,B2);
        LP_Gp_L->Color = RGB(R1,G1,B1);
        LP_Gp_L->Font->Color = RGB(R2,G2,B2);
        LP_Ap_L->Color = RGB(R1,G1,B1);
        LP_Ap_L->Font->Color = RGB(R2,G2,B2);

        LP_P_M->Font->Color = RGB(R1,G1,B1);
        LP_P_M->Color = RGB(R2,G2,B2);
        LP_C_M->Font->Color = RGB(R1,G1,B1);
        LP_C_M->Color = RGB(R2,G2,B2);
        LP_J_M->Font->Color = RGB(R1,G1,B1);
        LP_J_M->Color = RGB(R2,G2,B2);
        LP_V_M->Font->Color = RGB(R1,G1,B1);
        LP_V_M->Color = RGB(R2,G2,B2);
        LP_T_M->Font->Color = RGB(R1,G1,B1);
        LP_T_M->Color = RGB(R2,G2,B2);
        LP_F_M->Font->Color = RGB(R1,G1,B1);
        LP_F_M->Color = RGB(R2,G2,B2);
        LP_Z_M->Font->Color = RGB(R1,G1,B1);
        LP_Z_M->Color = RGB(R2,G2,B2);
        LP_L_M->Font->Color = RGB(R1,G1,B1);
        LP_L_M->Color = RGB(R2,G2,B2);
        LP_Zl_M->Font->Color = RGB(R1,G1,B1);
        LP_Zl_M->Color = RGB(R2,G2,B2);
        LP_Gl_M->Font->Color = RGB(R1,G1,B1);
        LP_Gl_M->Color = RGB(R2,G2,B2);
        LP_Al_M->Font->Color = RGB(R1,G1,B1);
        LP_Al_M->Color = RGB(R2,G2,B2);
        LP_Zp_M->Font->Color = RGB(R1,G1,B1);
        LP_Zp_M->Color = RGB(R2,G2,B2);
        LP_Gp_M->Font->Color = RGB(R1,G1,B1);
        LP_Gp_M->Color = RGB(R2,G2,B2);
        LP_Ap_M->Font->Color = RGB(R1,G1,B1);
        LP_Ap_M->Color = RGB(R2,G2,B2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setPlayers()
{
        String Post, Cislo, Jmeno, Vek, FS, TS, ZS, Line, ZapL, GolL, AsiL, ZapP, GolP, AsiP;

        Post = tymy[t]->Hraci[0]->getPost();
        Cislo = tymy[t]->Hraci[0]->getCislo();
        Jmeno += tymy[t]->Hraci[0]->getJmeno() + " " + tymy[t]->Hraci[0]->getPrijmeni();
        Vek = tymy[t]->Hraci[0]->getVek();
        FS = tymy[t]->Hraci[0]->getFS();
        TS = tymy[t]->Hraci[0]->getTS();
        ZS = tymy[t]->Hraci[0]->getZS();
        ZapL = tymy[t]->Hraci[0]->getZapasyL();
        GolL = tymy[t]->Hraci[0]->getGolyL();
        AsiL = tymy[t]->Hraci[0]->getAsistenceL();
        ZapP = tymy[t]->Hraci[0]->getZapasyP();
        GolP = tymy[t]->Hraci[0]->getGolyP();
        AsiP = tymy[t]->Hraci[0]->getAsistenceP();

        if(tymy[t]->Hraci[0]->getSestava() == 5)
                Line = "N";
        else
                Line = tymy[t]->Hraci[0]->getSestava();

        for(int i = 1; i < tymy[t]->getPocetHracu(); i ++){
//                LP_P_M->Lines->Add(tymy[t]->Hraci[i]->getPost());
                Post += "\n";
                Post += tymy[t]->Hraci[i]->getPost();
                LP_P_M->Caption = Post;

//                LP_C_M->Lines->Add(tymy[t]->Hraci[i]->getCislo());
                Cislo += "\n";
                Cislo += tymy[t]->Hraci[i]->getCislo();
                LP_C_M->Caption = Cislo;

//                LP_J_M->Lines->Add(tymy[t]->Hraci[i]->getJmeno() + " " + tymy[t]->Hraci[i]->getPrijmeni());
                Jmeno += "\n";
                Jmeno += tymy[t]->Hraci[i]->getJmeno() + " " + tymy[t]->Hraci[i]->getPrijmeni();
                LP_J_M->Caption = Jmeno;

//                LP_V_M->Lines->Add(tymy[t]->Hraci[i]->getVek());
                Vek += "\n";
                Vek += tymy[t]->Hraci[i]->getVek();
                LP_V_M->Caption = Vek;

//                LP_F_M->Lines->Add(tymy[t]->Hraci[i]->getFS());
                FS += "\n";
                FS += tymy[t]->Hraci[i]->getFS();
                LP_F_M->Caption = FS;

//                LP_T_M->Lines->Add(tymy[t]->Hraci[i]->getTS());
                TS += "\n";
                TS += tymy[t]->Hraci[i]->getTS();
                LP_T_M->Caption = TS;

//                LP_Z_M->Lines->Add(tymy[t]->Hraci[i]->getZS());
                ZS += "\n";
                ZS += tymy[t]->Hraci[i]->getZS();
                LP_Z_M->Caption = ZS;

//                LP_Zl_M->Lines->Add(tymy[t]->Hraci[i]->getZapasyL());
                ZapL += "\n";
                ZapL += tymy[t]->Hraci[i]->getZapasyL();
                LP_Zl_M->Caption = ZapL;

//                LP_Gl_M->Lines->Add(tymy[t]->Hraci[i]->getGolyL());
                GolL += "\n";
                GolL += tymy[t]->Hraci[i]->getGolyL();
                LP_Gl_M->Caption = GolL;

//                LP_Al_M->Lines->Add(tymy[t]->Hraci[i]->getAsistenceL());
                AsiL += "\n";
                AsiL += tymy[t]->Hraci[i]->getAsistenceL();
                LP_Al_M->Caption = AsiL;

//                LP_Zp_M->Lines->Add(tymy[t]->Hraci[i]->getZapasyP());
                ZapP += "\n";
                ZapP += tymy[t]->Hraci[i]->getZapasyP();
                LP_Zp_M->Caption = ZapP;

//                LP_Gp_M->Lines->Add(tymy[t]->Hraci[i]->getGolyP());
                GolP += "\n";
                GolP += tymy[t]->Hraci[i]->getGolyP();
                LP_Gp_M->Caption = GolP;

//                LP_Ap_M->Lines->Add(tymy[t]->Hraci[i]->getAsistenceP());
                AsiP += "\n";
                AsiP += tymy[t]->Hraci[i]->getAsistenceP();
                LP_Ap_M->Caption = AsiP;

                Line += "\n";
                if(tymy[t]->Hraci[i]->getSestava() == 5)
                        Line += "N";
                else
                        Line += tymy[t]->Hraci[i]->getSestava();
                LP_L_M->Caption = Line;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        t --;

        tymy[t]->setridHrace('L', true);

        R1 = tymy[t]->getR1();
        G1 = tymy[t]->getG1();
        B1 = tymy[t]->getB1();

        R2 = tymy[t]->getR2();
        G2 = tymy[t]->getG2();
        B2 = tymy[t]->getB2();

        setColors();

        setPlayers();

        LP_Name->Caption = tymy[t]->getNazevTymu();
        LP_Hall->Caption = tymy[t]->getNazevHaly();
        LP_Capacity->Caption = tymy[t]->getKapacitaHaly();
        LP_Logo->Picture->LoadFromFile("teams/"+tymy[t]->getLogo());
        LP_iHall->Picture->LoadFromFile("teams/"+tymy[t]->getHala());

        Button3->Enabled = true;
        if(t == 0)
                Button2->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        t ++;

        tymy[t]->setridHrace('L', true);

        R1 = tymy[t]->getR1();
        G1 = tymy[t]->getG1();
        B1 = tymy[t]->getB1();

        R2 = tymy[t]->getR2();
        G2 = tymy[t]->getG2();
        B2 = tymy[t]->getB2();

        setColors();

        setPlayers();

        LP_Name->Caption = tymy[t]->getNazevTymu();
        LP_Hall->Caption = tymy[t]->getNazevHaly();
        LP_Capacity->Caption = tymy[t]->getKapacitaHaly();
        LP_Logo->Picture->LoadFromFile("teams/"+tymy[t]->getLogo());
        LP_iHall->Picture->LoadFromFile("teams/"+tymy[t]->getHala());

        Button2->Enabled = true;
        if(t == 11)
                Button3->Enabled = false;
}
//---------------------------------------------------------------------------




