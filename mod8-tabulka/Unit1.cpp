//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init,weak)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Panel2->Left = 112;
        Panel2->Top = 84;

        for(int i = 0; i < 14; i ++)
                Tymy[i] = new Tym();

        for(int i = 0; i < 14; i ++){
                TT_M->Lines->Add(Tymy[i]->getNazevTymu());
                TZ_M->Lines->Add(Tymy[i]->getZapasyL());
                TV_M->Lines->Add(Tymy[i]->getVyhryL());
                TR_M->Lines->Add(Tymy[i]->getRemizyL());
                TP_M->Lines->Add(Tymy[i]->getProhryL());
                TGS_M->Lines->Add(Tymy[i]->getDaneGL());
                TGA_M->Lines->Add(Tymy[i]->getObdrzeneGL());
                TB_M->Lines->Add(Tymy[i]->getBodyL());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        for(int i = 0; i < 14; i ++)
                delete(Tymy[i]);
        Application->Terminate();
}
//---------------------------------------------------------------------------


