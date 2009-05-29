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
        tym = new Tym();
        tym->nactiHrace("alv_l.txt");
        tym->setridHrace('P', true);
        tym->nactiTym("alv_m.txt");

        R1 = tym->getR1();
        G1 = tym->getG1();
        B1 = tym->getB1();

        R2 = tym->getR2();
        G2 = tym->getG2();
        B2 = tym->getB2();

//        Logo = "pix.jpg";
//        Hall = "pixh.jpg";
//        Capacity = 1850;

        LP->Left = 112;
        LP->Top = 84;
        LP->Color = RGB(R1,G1,B1);;
        LP_B1->Brush->Color = RGB(R2,G2,B2);
        LP_B2->Brush->Color = RGB(R1,G1,B1);
        LP_B2->Pen->Color = RGB(R2,G2,B2);
        LP_B3->Brush->Color = RGB(R2,G2,B2);
        LP_B4->Brush->Color = RGB(R1,G1,B1);
//        LP_Logo->Picture->LoadFromFile(Logo);
        LP_Name->Color = RGB(R2,G2,B2);
        LP_Name->Font->Color = RGB(R1,G1,B1);
        LP_Hall->Color = RGB(R2,G2,B2);
        LP_Hall->Font->Color = RGB(R1,G1,B1);
//        LP_iHall->Picture->LoadFromFile(Hall);
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

//        LP_Name->Caption = "PIXBO WALLENSTAM IBK";
//        LP_Hall->Caption = "Lisebergshallen";
//        LP_Capacity->Caption = Capacity;

        LP_Name->Caption = tym->getNazevTymu();
        LP_Hall->Caption = tym->getNazevHaly();
        LP_Capacity->Caption = tym->getKapacitaHaly();
        LP_Logo->Picture->LoadFromFile(tym->getLogo());
        LP_iHall->Picture->LoadFromFile(tym->getHala());

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                LP_P_M->Lines->Add(tym->Hraci[i]->getPost());
                LP_C_M->Lines->Add(tym->Hraci[i]->getCislo());
                LP_J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                LP_V_M->Lines->Add(tym->Hraci[i]->getVek());
                LP_F_M->Lines->Add(tym->Hraci[i]->getFS());
                LP_T_M->Lines->Add(tym->Hraci[i]->getTS());
                LP_Z_M->Lines->Add(tym->Hraci[i]->getZS());
                LP_Zl_M->Lines->Add(tym->Hraci[i]->getZapasyL());
                LP_Gl_M->Lines->Add(tym->Hraci[i]->getGolyL());
                LP_Al_M->Lines->Add(tym->Hraci[i]->getAsistenceL());
                LP_Zp_M->Lines->Add(tym->Hraci[i]->getZapasyP());
                LP_Gp_M->Lines->Add(tym->Hraci[i]->getGolyP());
                LP_Ap_M->Lines->Add(tym->Hraci[i]->getAsistenceP());
                if(tym->Hraci[i]->getSestava() == 5)
                        LP_L_M->Lines->Add("N");
                else
                        LP_L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
        setLayouts1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        delete(tym);
        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_P_LClick(TObject *Sender)
{
        setLayouts2();

        LP_P_M->Lines->Clear();
        LP_C_M->Lines->Clear();
        LP_J_M->Lines->Clear();
        LP_V_M->Lines->Clear();
        LP_F_M->Lines->Clear();
        LP_T_M->Lines->Clear();
        LP_Z_M->Lines->Clear();
        LP_L_M->Lines->Clear();
        LP_Zl_M->Lines->Clear();
        LP_Gl_M->Lines->Clear();
        LP_Al_M->Lines->Clear();
        LP_Zp_M->Lines->Clear();
        LP_Gp_M->Lines->Clear();
        LP_Ap_M->Lines->Clear();

        tym->setridHrace('P', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                LP_P_M->Lines->Add(tym->Hraci[i]->getPost());
                LP_C_M->Lines->Add(tym->Hraci[i]->getCislo());
                LP_J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                LP_V_M->Lines->Add(tym->Hraci[i]->getVek());
                LP_F_M->Lines->Add(tym->Hraci[i]->getFS());
                LP_T_M->Lines->Add(tym->Hraci[i]->getTS());
                LP_Z_M->Lines->Add(tym->Hraci[i]->getZS());
                LP_Zl_M->Lines->Add(tym->Hraci[i]->getZapasyL());
                LP_Gl_M->Lines->Add(tym->Hraci[i]->getGolyL());
                LP_Al_M->Lines->Add(tym->Hraci[i]->getAsistenceL());
                LP_Zp_M->Lines->Add(tym->Hraci[i]->getZapasyP());
                LP_Gp_M->Lines->Add(tym->Hraci[i]->getGolyP());
                LP_Ap_M->Lines->Add(tym->Hraci[i]->getAsistenceP());
                if(tym->Hraci[i]->getSestava() == 5)
                        LP_L_M->Lines->Add("N");
                else
                        LP_L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }

        setLayouts1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_C_LClick(TObject *Sender)
{
        setLayouts2();

        LP_P_M->Lines->Clear();
        LP_C_M->Lines->Clear();
        LP_J_M->Lines->Clear();
        LP_V_M->Lines->Clear();
        LP_F_M->Lines->Clear();
        LP_T_M->Lines->Clear();
        LP_Z_M->Lines->Clear();
        LP_L_M->Lines->Clear();
        LP_Zl_M->Lines->Clear();
        LP_Gl_M->Lines->Clear();
        LP_Al_M->Lines->Clear();
        LP_Zp_M->Lines->Clear();
        LP_Gp_M->Lines->Clear();
        LP_Ap_M->Lines->Clear();

        tym->setridHrace('C', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                LP_P_M->Lines->Add(tym->Hraci[i]->getPost());
                LP_C_M->Lines->Add(tym->Hraci[i]->getCislo());
                LP_J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                LP_V_M->Lines->Add(tym->Hraci[i]->getVek());
                LP_F_M->Lines->Add(tym->Hraci[i]->getFS());
                LP_T_M->Lines->Add(tym->Hraci[i]->getTS());
                LP_Z_M->Lines->Add(tym->Hraci[i]->getZS());
                LP_Zl_M->Lines->Add(tym->Hraci[i]->getZapasyL());
                LP_Gl_M->Lines->Add(tym->Hraci[i]->getGolyL());
                LP_Al_M->Lines->Add(tym->Hraci[i]->getAsistenceL());
                LP_Zp_M->Lines->Add(tym->Hraci[i]->getZapasyP());
                LP_Gp_M->Lines->Add(tym->Hraci[i]->getGolyP());
                LP_Ap_M->Lines->Add(tym->Hraci[i]->getAsistenceP());
                if(tym->Hraci[i]->getSestava() == 5)
                        LP_L_M->Lines->Add("N");
                else
                        LP_L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }

        setLayouts1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_J_LClick(TObject *Sender)
{
        setLayouts2();

        LP_P_M->Lines->Clear();
        LP_C_M->Lines->Clear();
        LP_J_M->Lines->Clear();
        LP_V_M->Lines->Clear();
        LP_F_M->Lines->Clear();
        LP_T_M->Lines->Clear();
        LP_Z_M->Lines->Clear();
        LP_L_M->Lines->Clear();
        LP_Zl_M->Lines->Clear();
        LP_Gl_M->Lines->Clear();
        LP_Al_M->Lines->Clear();
        LP_Zp_M->Lines->Clear();
        LP_Gp_M->Lines->Clear();
        LP_Ap_M->Lines->Clear();

        tym->setridHrace('J', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                LP_P_M->Lines->Add(tym->Hraci[i]->getPost());
                LP_C_M->Lines->Add(tym->Hraci[i]->getCislo());
                LP_J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                LP_V_M->Lines->Add(tym->Hraci[i]->getVek());
                LP_F_M->Lines->Add(tym->Hraci[i]->getFS());
                LP_T_M->Lines->Add(tym->Hraci[i]->getTS());
                LP_Z_M->Lines->Add(tym->Hraci[i]->getZS());
                LP_Zl_M->Lines->Add(tym->Hraci[i]->getZapasyL());
                LP_Gl_M->Lines->Add(tym->Hraci[i]->getGolyL());
                LP_Al_M->Lines->Add(tym->Hraci[i]->getAsistenceL());
                LP_Zp_M->Lines->Add(tym->Hraci[i]->getZapasyP());
                LP_Gp_M->Lines->Add(tym->Hraci[i]->getGolyP());
                LP_Ap_M->Lines->Add(tym->Hraci[i]->getAsistenceP());
                if(tym->Hraci[i]->getSestava() == 5)
                        LP_L_M->Lines->Add("N");
                else
                        LP_L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }

        setLayouts1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_V_LClick(TObject *Sender)
{
        setLayouts2();

        LP_P_M->Lines->Clear();
        LP_C_M->Lines->Clear();
        LP_J_M->Lines->Clear();
        LP_V_M->Lines->Clear();
        LP_F_M->Lines->Clear();
        LP_T_M->Lines->Clear();
        LP_Z_M->Lines->Clear();
        LP_L_M->Lines->Clear();
        LP_Zl_M->Lines->Clear();
        LP_Gl_M->Lines->Clear();
        LP_Al_M->Lines->Clear();
        LP_Zp_M->Lines->Clear();
        LP_Gp_M->Lines->Clear();
        LP_Ap_M->Lines->Clear();

        tym->setridHrace('V', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                LP_P_M->Lines->Add(tym->Hraci[i]->getPost());
                LP_C_M->Lines->Add(tym->Hraci[i]->getCislo());
                LP_J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                LP_V_M->Lines->Add(tym->Hraci[i]->getVek());
                LP_F_M->Lines->Add(tym->Hraci[i]->getFS());
                LP_T_M->Lines->Add(tym->Hraci[i]->getTS());
                LP_Z_M->Lines->Add(tym->Hraci[i]->getZS());
                LP_Zl_M->Lines->Add(tym->Hraci[i]->getZapasyL());
                LP_Gl_M->Lines->Add(tym->Hraci[i]->getGolyL());
                LP_Al_M->Lines->Add(tym->Hraci[i]->getAsistenceL());
                LP_Zp_M->Lines->Add(tym->Hraci[i]->getZapasyP());
                LP_Gp_M->Lines->Add(tym->Hraci[i]->getGolyP());
                LP_Ap_M->Lines->Add(tym->Hraci[i]->getAsistenceP());
                if(tym->Hraci[i]->getSestava() == 5)
                        LP_L_M->Lines->Add("N");
                else
                        LP_L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }

        setLayouts1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_F_LClick(TObject *Sender)
{
        setLayouts2();

        LP_P_M->Lines->Clear();
        LP_C_M->Lines->Clear();
        LP_J_M->Lines->Clear();
        LP_V_M->Lines->Clear();
        LP_F_M->Lines->Clear();
        LP_T_M->Lines->Clear();
        LP_Z_M->Lines->Clear();
        LP_L_M->Lines->Clear();
        LP_Zl_M->Lines->Clear();
        LP_Gl_M->Lines->Clear();
        LP_Al_M->Lines->Clear();
        LP_Zp_M->Lines->Clear();
        LP_Gp_M->Lines->Clear();
        LP_Ap_M->Lines->Clear();

        tym->setridHrace('F', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                LP_P_M->Lines->Add(tym->Hraci[i]->getPost());
                LP_C_M->Lines->Add(tym->Hraci[i]->getCislo());
                LP_J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                LP_V_M->Lines->Add(tym->Hraci[i]->getVek());
                LP_F_M->Lines->Add(tym->Hraci[i]->getFS());
                LP_T_M->Lines->Add(tym->Hraci[i]->getTS());
                LP_Z_M->Lines->Add(tym->Hraci[i]->getZS());
                LP_Zl_M->Lines->Add(tym->Hraci[i]->getZapasyL());
                LP_Gl_M->Lines->Add(tym->Hraci[i]->getGolyL());
                LP_Al_M->Lines->Add(tym->Hraci[i]->getAsistenceL());
                LP_Zp_M->Lines->Add(tym->Hraci[i]->getZapasyP());
                LP_Gp_M->Lines->Add(tym->Hraci[i]->getGolyP());
                LP_Ap_M->Lines->Add(tym->Hraci[i]->getAsistenceP());
                if(tym->Hraci[i]->getSestava() == 5)
                        LP_L_M->Lines->Add("N");
                else
                        LP_L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }

        setLayouts1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_T_LClick(TObject *Sender)
{
        setLayouts2();

        LP_P_M->Lines->Clear();
        LP_C_M->Lines->Clear();
        LP_J_M->Lines->Clear();
        LP_V_M->Lines->Clear();
        LP_F_M->Lines->Clear();
        LP_T_M->Lines->Clear();
        LP_Z_M->Lines->Clear();
        LP_L_M->Lines->Clear();
        LP_Zl_M->Lines->Clear();
        LP_Gl_M->Lines->Clear();
        LP_Al_M->Lines->Clear();
        LP_Zp_M->Lines->Clear();
        LP_Gp_M->Lines->Clear();
        LP_Ap_M->Lines->Clear();

        tym->setridHrace('T', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                LP_P_M->Lines->Add(tym->Hraci[i]->getPost());
                LP_C_M->Lines->Add(tym->Hraci[i]->getCislo());
                LP_J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                LP_V_M->Lines->Add(tym->Hraci[i]->getVek());
                LP_F_M->Lines->Add(tym->Hraci[i]->getFS());
                LP_T_M->Lines->Add(tym->Hraci[i]->getTS());
                LP_Z_M->Lines->Add(tym->Hraci[i]->getZS());
                LP_Zl_M->Lines->Add(tym->Hraci[i]->getZapasyL());
                LP_Gl_M->Lines->Add(tym->Hraci[i]->getGolyL());
                LP_Al_M->Lines->Add(tym->Hraci[i]->getAsistenceL());
                LP_Zp_M->Lines->Add(tym->Hraci[i]->getZapasyP());
                LP_Gp_M->Lines->Add(tym->Hraci[i]->getGolyP());
                LP_Ap_M->Lines->Add(tym->Hraci[i]->getAsistenceP());
                if(tym->Hraci[i]->getSestava() == 5)
                        LP_L_M->Lines->Add("N");
                else
                        LP_L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }

        setLayouts1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Z_LClick(TObject *Sender)
{
        setLayouts2();

        LP_P_M->Lines->Clear();
        LP_C_M->Lines->Clear();
        LP_J_M->Lines->Clear();
        LP_V_M->Lines->Clear();
        LP_F_M->Lines->Clear();
        LP_T_M->Lines->Clear();
        LP_Z_M->Lines->Clear();
        LP_L_M->Lines->Clear();
        LP_Zl_M->Lines->Clear();
        LP_Gl_M->Lines->Clear();
        LP_Al_M->Lines->Clear();
        LP_Zp_M->Lines->Clear();
        LP_Gp_M->Lines->Clear();
        LP_Ap_M->Lines->Clear();

        tym->setridHrace('Z', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                LP_P_M->Lines->Add(tym->Hraci[i]->getPost());
                LP_C_M->Lines->Add(tym->Hraci[i]->getCislo());
                LP_J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                LP_V_M->Lines->Add(tym->Hraci[i]->getVek());
                LP_F_M->Lines->Add(tym->Hraci[i]->getFS());
                LP_T_M->Lines->Add(tym->Hraci[i]->getTS());
                LP_Z_M->Lines->Add(tym->Hraci[i]->getZS());
                LP_Zl_M->Lines->Add(tym->Hraci[i]->getZapasyL());
                LP_Gl_M->Lines->Add(tym->Hraci[i]->getGolyL());
                LP_Al_M->Lines->Add(tym->Hraci[i]->getAsistenceL());
                LP_Zp_M->Lines->Add(tym->Hraci[i]->getZapasyP());
                LP_Gp_M->Lines->Add(tym->Hraci[i]->getGolyP());
                LP_Ap_M->Lines->Add(tym->Hraci[i]->getAsistenceP());
                if(tym->Hraci[i]->getSestava() == 5)
                        LP_L_M->Lines->Add("N");
                else
                        LP_L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }

        setLayouts1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_L_LClick(TObject *Sender)
{
        setLayouts2();

        LP_P_M->Lines->Clear();
        LP_C_M->Lines->Clear();
        LP_J_M->Lines->Clear();
        LP_V_M->Lines->Clear();
        LP_F_M->Lines->Clear();
        LP_T_M->Lines->Clear();
        LP_Z_M->Lines->Clear();
        LP_L_M->Lines->Clear();
        LP_Zl_M->Lines->Clear();
        LP_Gl_M->Lines->Clear();
        LP_Al_M->Lines->Clear();
        LP_Zp_M->Lines->Clear();
        LP_Gp_M->Lines->Clear();
        LP_Ap_M->Lines->Clear();

        tym->setridHrace('L', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                LP_P_M->Lines->Add(tym->Hraci[i]->getPost());
                LP_C_M->Lines->Add(tym->Hraci[i]->getCislo());
                LP_J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                LP_V_M->Lines->Add(tym->Hraci[i]->getVek());
                LP_F_M->Lines->Add(tym->Hraci[i]->getFS());
                LP_T_M->Lines->Add(tym->Hraci[i]->getTS());
                LP_Z_M->Lines->Add(tym->Hraci[i]->getZS());
                LP_Zl_M->Lines->Add(tym->Hraci[i]->getZapasyL());
                LP_Gl_M->Lines->Add(tym->Hraci[i]->getGolyL());
                LP_Al_M->Lines->Add(tym->Hraci[i]->getAsistenceL());
                LP_Zp_M->Lines->Add(tym->Hraci[i]->getZapasyP());
                LP_Gp_M->Lines->Add(tym->Hraci[i]->getGolyP());
                LP_Ap_M->Lines->Add(tym->Hraci[i]->getAsistenceP());
                if(tym->Hraci[i]->getSestava() == 5)
                        LP_L_M->Lines->Add("N");
                else
                        LP_L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }

        setLayouts1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setLayouts1(){
        LP_P_M->Height = tym->getPocetHracu() * 18;
        LP_C_M->Height = tym->getPocetHracu() * 18;
        LP_J_M->Height = tym->getPocetHracu() * 18;
        LP_V_M->Height = tym->getPocetHracu() * 18;
        LP_F_M->Height = tym->getPocetHracu() * 18;
        LP_T_M->Height = tym->getPocetHracu() * 18;
        LP_Z_M->Height = tym->getPocetHracu() * 18;
        LP_L_M->Height = tym->getPocetHracu() * 18;
        LP_Zl_M->Height = tym->getPocetHracu() * 18;
        LP_Gl_M->Height = tym->getPocetHracu() * 18;
        LP_Al_M->Height = tym->getPocetHracu() * 18;
        LP_Zp_M->Height = tym->getPocetHracu() * 18;
        LP_Gp_M->Height = tym->getPocetHracu() * 18;
        LP_Ap_M->Height = tym->getPocetHracu() * 18;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setLayouts2(){
        LP_P_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_C_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_J_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_V_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_F_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_T_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_Z_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_L_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_Zl_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_Gl_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_Al_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_Zp_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_Gp_M->Height = tym->getPocetHracu() * 18 + 18;
        LP_Ap_M->Height = tym->getPocetHracu() * 18 + 18;
}
//---------------------------------------------------------------------------

