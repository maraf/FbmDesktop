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
        o = 0;

        for(int i = 0; i < 12; i ++)
                Tymy[i] = new Tym();

        Tymy[0]->nactiHrace("aik_l.txt");
        Tymy[1]->nactiHrace("alv_l.txt");
        Tymy[2]->nactiHrace("bal_l.txt");
        Tymy[3]->nactiHrace("cap_l.txt");
        Tymy[4]->nactiHrace("dal_l.txt");
        Tymy[5]->nactiHrace("fal_l.txt");
        Tymy[6]->nactiHrace("hel_l.txt");
        Tymy[7]->nactiHrace("jar_l.txt");
        Tymy[8]->nactiHrace("jon_l.txt");
        Tymy[9]->nactiHrace("pix_l.txt");
        Tymy[10]->nactiHrace("sto_l.txt");
        Tymy[11]->nactiHrace("war_l.txt");

        for(int i = 0; i < Tymy[o]->getPocetHracu(); i ++){
                Memo1->Lines->Add(Tymy[o]->Hraci[i]->getPrijmeni()+" "+Tymy[o]->Hraci[i]->getJmeno());
                Memo2->Lines->Add(Tymy[o]->Hraci[i]->getFS());
                Memo3->Lines->Add(Tymy[o]->Hraci[i]->getTS());
                Memo4->Lines->Add(Tymy[o]->Hraci[i]->getZS());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        for(int i = 0; i < 12; i ++)
                delete Tymy[i];

        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        o ++;
        Memo1->Clear();
        Memo2->Clear();
        Memo3->Clear();
        Memo4->Clear();

        for(int i = 0; i < Tymy[o]->getPocetHracu(); i ++){
                Memo1->Lines->Add(Tymy[o]->Hraci[i]->getPrijmeni()+" "+Tymy[o]->Hraci[i]->getJmeno());
                Memo2->Lines->Add(Tymy[o]->Hraci[i]->getFS());
                Memo3->Lines->Add(Tymy[o]->Hraci[i]->getTS());
                Memo4->Lines->Add(Tymy[o]->Hraci[i]->getZS());
        }

        Button3->Enabled = true;
        if(o == 11)
                Button2->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        o --;
        Memo1->Clear();
        Memo2->Clear();
        Memo3->Clear();
        Memo4->Clear();

        for(int i = 0; i < Tymy[o]->getPocetHracu(); i ++){
                Memo1->Lines->Add(Tymy[o]->Hraci[i]->getPrijmeni()+" "+Tymy[o]->Hraci[i]->getJmeno());
                Memo2->Lines->Add(Tymy[o]->Hraci[i]->getFS());
                Memo3->Lines->Add(Tymy[o]->Hraci[i]->getTS());
                Memo4->Lines->Add(Tymy[o]->Hraci[i]->getZS());
        }

        Button2->Enabled = true;
        if(o == 0)
                Button3->Enabled = false;
}
//---------------------------------------------------------------------------

