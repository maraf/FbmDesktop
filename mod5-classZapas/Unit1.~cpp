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
        Panel1->Left = 112;
        Panel1->Top = 84;

        zapas = new Zapas();

//        zapas->iCount = 0;
        zapas->Tymy[0]->nactiHrace("TymA.txt");
        zapas->Tymy[0]->setridHrace('L', true);
        zapas->Tymy[1]->nactiHrace("TymB.txt");
        zapas->Tymy[1]->setridHrace('L', true);

        zapas->Tymy[0]->setNazevTymu("EVVK 'A'");
        zapas->Tymy[1]->setNazevTymu("EVVK 'B'");

        zapas->Inicializace();

        TeamName1->Caption = zapas->Tymy[0]->getNazevTymu();;
        TeamName2->Caption = zapas->Tymy[1]->getNazevTymu();;

//        Label4->Caption = zapas->iCelkoveA[0];
//        Label5->Caption = zapas->iCelkoveB[0];
//        Label6->Caption = zapas->iCelkoveA[1];
//        Label7->Caption = zapas->iCelkoveB[1];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//        zapas->iCount ++;
        cResult = zapas->Akce();
//        Label1->Caption = zapas->iUtok;
        char cPom[7];
        char cCislo;
        sprintf(cPom, "%s", cResult);

        if(cPom[0] == 'D'){
                if(zapas->iStrelec != 0){
                        String s = IntToStr(zapas->iCount);
                        s += ". ";
                        s += zapas->Tymy[0]->Hraci[zapas->iStrelec]->getPrijmeni();
                        s += ", ";
                        s += zapas->Tymy[0]->Hraci[zapas->iAsistent]->getPrijmeni();
                        GolyA->Lines->Add(s);
                }
        }
        if(cPom[0] == 'H'){
                if(zapas->iStrelec != 0){
                        String s = IntToStr(zapas->iCount);
                        s += ". ";
                        s += zapas->Tymy[1]->Hraci[zapas->iStrelec]->getPrijmeni();
                        s += ", ";
                        s += zapas->Tymy[1]->Hraci[zapas->iAsistent]->getPrijmeni();
                        GolyB->Lines->Add(s);
                }
        }

        Timer->Caption = zapas->iCount;
        Shoots1->Caption = zapas->getStrelyD();
        Shoots2->Caption = zapas->getStrelyH();
        Skore1->Caption = zapas->getGolyD();
        Skore2->Caption = zapas->getGolyH();

        if(zapas->iCount == 60){
                Timer1->Enabled = false;
                Button1->Enabled = false;
                Button2->Enabled = false;
                Button3->Enabled = true;
                Button3->Visible = true;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Timer1->Enabled = true;
        Button1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(Timer1->Enabled)
                Timer1->Enabled = false;
        else
                Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Application->Terminate();
        delete(zapas);
}
//---------------------------------------------------------------------------

