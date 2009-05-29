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
        Panel1->Left = 112;
        Panel1->Top = 84;

        tym = new Tym();
        tym->nactiHrace("TymA.txt");
        tym->setridHrace('P', true);
        tym->nactiTym("TymA.txt");

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                P_M->Lines->Add(tym->Hraci[i]->getPost());
                C_M->Lines->Add(tym->Hraci[i]->getCislo());
                J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                V_M->Lines->Add(tym->Hraci[i]->getVek());
                F_M->Lines->Add(tym->Hraci[i]->getFS());
                T_M->Lines->Add(tym->Hraci[i]->getTS());
                Z_M->Lines->Add(tym->Hraci[i]->getZS());
                if(tym->Hraci[i]->getSestava() == 5)
                        L_M->Lines->Add("N");
                else
                        L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        delete(tym);
        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::P_LClick(TObject *Sender)
{
        P_M->Lines->Clear();
        C_M->Lines->Clear();
        J_M->Lines->Clear();
        V_M->Lines->Clear();
        F_M->Lines->Clear();
        T_M->Lines->Clear();
        Z_M->Lines->Clear();
        L_M->Lines->Clear();

        tym->setridHrace('P', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                P_M->Lines->Add(tym->Hraci[i]->getPost());
                C_M->Lines->Add(tym->Hraci[i]->getCislo());
                J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                V_M->Lines->Add(tym->Hraci[i]->getVek());
                F_M->Lines->Add(tym->Hraci[i]->getFS());
                T_M->Lines->Add(tym->Hraci[i]->getTS());
                Z_M->Lines->Add(tym->Hraci[i]->getZS());
                if(tym->Hraci[i]->getSestava() == 5)
                        L_M->Lines->Add("N");
                else
                        L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::C_LClick(TObject *Sender)
{
        P_M->Lines->Clear();
        C_M->Lines->Clear();
        J_M->Lines->Clear();
        V_M->Lines->Clear();
        F_M->Lines->Clear();
        T_M->Lines->Clear();
        Z_M->Lines->Clear();
        L_M->Lines->Clear();

        tym->setridHrace('C', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                P_M->Lines->Add(tym->Hraci[i]->getPost());
                C_M->Lines->Add(tym->Hraci[i]->getCislo());
                J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                V_M->Lines->Add(tym->Hraci[i]->getVek());
                F_M->Lines->Add(tym->Hraci[i]->getFS());
                T_M->Lines->Add(tym->Hraci[i]->getTS());
                Z_M->Lines->Add(tym->Hraci[i]->getZS());
                if(tym->Hraci[i]->getSestava() == 5)
                        L_M->Lines->Add("N");
                else
                        L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::J_LClick(TObject *Sender)
{
        P_M->Lines->Clear();
        C_M->Lines->Clear();
        J_M->Lines->Clear();
        V_M->Lines->Clear();
        F_M->Lines->Clear();
        T_M->Lines->Clear();
        Z_M->Lines->Clear();
        L_M->Lines->Clear();

        tym->setridHrace('J', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                P_M->Lines->Add(tym->Hraci[i]->getPost());
                C_M->Lines->Add(tym->Hraci[i]->getCislo());
                J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                V_M->Lines->Add(tym->Hraci[i]->getVek());
                F_M->Lines->Add(tym->Hraci[i]->getFS());
                T_M->Lines->Add(tym->Hraci[i]->getTS());
                Z_M->Lines->Add(tym->Hraci[i]->getZS());
                if(tym->Hraci[i]->getSestava() == 5)
                        L_M->Lines->Add("N");
                else
                        L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::V_LClick(TObject *Sender)
{
        P_M->Lines->Clear();
        C_M->Lines->Clear();
        J_M->Lines->Clear();
        V_M->Lines->Clear();
        F_M->Lines->Clear();
        T_M->Lines->Clear();
        Z_M->Lines->Clear();
        L_M->Lines->Clear();

        tym->setridHrace('V', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                P_M->Lines->Add(tym->Hraci[i]->getPost());
                C_M->Lines->Add(tym->Hraci[i]->getCislo());
                J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                V_M->Lines->Add(tym->Hraci[i]->getVek());
                F_M->Lines->Add(tym->Hraci[i]->getFS());
                T_M->Lines->Add(tym->Hraci[i]->getTS());
                Z_M->Lines->Add(tym->Hraci[i]->getZS());
                if(tym->Hraci[i]->getSestava() == 5)
                        L_M->Lines->Add("N");
                else
                        L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::F_LClick(TObject *Sender)
{
        P_M->Lines->Clear();
        C_M->Lines->Clear();
        J_M->Lines->Clear();
        V_M->Lines->Clear();
        F_M->Lines->Clear();
        T_M->Lines->Clear();
        Z_M->Lines->Clear();
        L_M->Lines->Clear();

        tym->setridHrace('F', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                P_M->Lines->Add(tym->Hraci[i]->getPost());
                C_M->Lines->Add(tym->Hraci[i]->getCislo());
                J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                V_M->Lines->Add(tym->Hraci[i]->getVek());
                F_M->Lines->Add(tym->Hraci[i]->getFS());
                T_M->Lines->Add(tym->Hraci[i]->getTS());
                Z_M->Lines->Add(tym->Hraci[i]->getZS());
                if(tym->Hraci[i]->getSestava() == 5)
                        L_M->Lines->Add("N");
                else
                        L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_LClick(TObject *Sender)
{
        P_M->Lines->Clear();
        C_M->Lines->Clear();
        J_M->Lines->Clear();
        V_M->Lines->Clear();
        F_M->Lines->Clear();
        T_M->Lines->Clear();
        Z_M->Lines->Clear();
        L_M->Lines->Clear();

        tym->setridHrace('T', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                P_M->Lines->Add(tym->Hraci[i]->getPost());
                C_M->Lines->Add(tym->Hraci[i]->getCislo());
                J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                V_M->Lines->Add(tym->Hraci[i]->getVek());
                F_M->Lines->Add(tym->Hraci[i]->getFS());
                T_M->Lines->Add(tym->Hraci[i]->getTS());
                Z_M->Lines->Add(tym->Hraci[i]->getZS());
                if(tym->Hraci[i]->getSestava() == 5)
                        L_M->Lines->Add("N");
                else
                        L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Z_LClick(TObject *Sender)
{
        P_M->Lines->Clear();
        C_M->Lines->Clear();
        J_M->Lines->Clear();
        V_M->Lines->Clear();
        F_M->Lines->Clear();
        T_M->Lines->Clear();
        Z_M->Lines->Clear();
        L_M->Lines->Clear();

        tym->setridHrace('Z', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                P_M->Lines->Add(tym->Hraci[i]->getPost());
                C_M->Lines->Add(tym->Hraci[i]->getCislo());
                J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                V_M->Lines->Add(tym->Hraci[i]->getVek());
                F_M->Lines->Add(tym->Hraci[i]->getFS());
                T_M->Lines->Add(tym->Hraci[i]->getTS());
                Z_M->Lines->Add(tym->Hraci[i]->getZS());
                if(tym->Hraci[i]->getSestava() == 5)
                        L_M->Lines->Add("N");
                else
                        L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::L_LClick(TObject *Sender)
{
        P_M->Lines->Clear();
        C_M->Lines->Clear();
        J_M->Lines->Clear();
        V_M->Lines->Clear();
        F_M->Lines->Clear();
        T_M->Lines->Clear();
        Z_M->Lines->Clear();
        L_M->Lines->Clear();

        tym->setridHrace('L', true);

        for(int i = 0; i < tym->getPocetHracu(); i ++){
                P_M->Lines->Add(tym->Hraci[i]->getPost());
                C_M->Lines->Add(tym->Hraci[i]->getCislo());
                J_M->Lines->Add(tym->Hraci[i]->getJmeno() + " " + tym->Hraci[i]->getPrijmeni());
                V_M->Lines->Add(tym->Hraci[i]->getVek());
                F_M->Lines->Add(tym->Hraci[i]->getFS());
                T_M->Lines->Add(tym->Hraci[i]->getTS());
                Z_M->Lines->Add(tym->Hraci[i]->getZS());
                if(tym->Hraci[i]->getSestava() == 5)
                        L_M->Lines->Add("N");
                else
                        L_M->Lines->Add(tym->Hraci[i]->getSestava());
        }
}
//---------------------------------------------------------------------------


















