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
        Tymy[0] = new Tym();
        Tymy[1] = new Tym();

        iCount = 0;
        iCelkoveA[0] = 0;
        iCelkoveB[0] = 0;
        iCelkoveA[1] = 0;
        iCelkoveB[1] = 0;
        iGolmanA = 0;
        iGolmanB = 0;
        iGolyA = 0;
        iGolyB = 0;
        iStrelyA = 0;
        iStrelyB = 0;
        iUtok = 0;
        iPomer = 1;
        iStrelec = 0;
        iAsistent = 0;

        for(int i = 0; i > 4; i ++)
                iUtoky[i] = 0;

        iLine = 1;

        bUtoci[0] = false;
        bUtoci[0] = false;

        iNavsteva = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormDestroy(TObject *Sender)
{
        delete Tymy[0], Tymy[1];        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Tymy[0]->nactiHrace("tymA.txt");
        Tymy[0]->setridHrace('L', true);
//        Tymy[0]->ulozHrace("tymAzal.txt");

        iGolmanA = Tymy[0]->Hraci[0]->getFS() + Tymy[0]->Hraci[0]->getTS() + Tymy[0]->Hraci[0]->getZS();

        iCelkoveA[0] = Tymy[0]->getCelkoveFS(1, 6);
        iCelkoveA[0] += Tymy[0]->getCelkoveTS(1, 6);
        iCelkoveA[0] += Tymy[0]->getCelkoveZS(1, 6);

        iPrumHrA[0] = iCelkoveA[0] / 5;

        iCelkoveA[1] = Tymy[0]->getCelkoveFS(6, 12);
        iCelkoveA[1] += Tymy[0]->getCelkoveTS(6, 12);
        iCelkoveA[1] += Tymy[0]->getCelkoveZS(6, 12);

        iPrumHrA[1] = iCelkoveA[1] / 5;

        for(int i = 0; i < Tymy[0]->getPocetHracu(); i ++)
                Memo3->Lines->Add(Tymy[0]->Hraci[i]->getPrijmeni() + " " + Tymy[0]->Hraci[i]->getJmeno() + " - " + Tymy[0]->Hraci[i]->getPost() + " - " + Tymy[0]->Hraci[i]->getFS() + " - " + Tymy[0]->Hraci[i]->getTS() + " - " + Tymy[0]->Hraci[i]->getZS());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Tymy[1]->nactiHrace("tymB.txt");
        Tymy[1]->setridHrace('L', true);
//        Tymy[1]->ulozHrace("tymBzal.txt");

        iGolmanB = Tymy[1]->Hraci[0]->getFS() + Tymy[1]->Hraci[0]->getTS() + Tymy[1]->Hraci[0]->getZS();

        iCelkoveB[0] = Tymy[1]->getCelkoveFS(1, 6);
        iCelkoveB[0] += Tymy[1]->getCelkoveTS(1, 6);
        iCelkoveB[0] += Tymy[1]->getCelkoveZS(1, 6);

        iPrumHrB[0] = iCelkoveB[0] / 5;

        iCelkoveB[1] = Tymy[1]->getCelkoveFS(6, 12);
        iCelkoveB[1] += Tymy[1]->getCelkoveTS(6, 12);
        iCelkoveB[1] += Tymy[1]->getCelkoveZS(6, 12);

        iPrumHrB[1] = iCelkoveB[1] / 5;

        for(int i = 0; i < Tymy[1]->getPocetHracu(); i ++)
                Memo4->Lines->Add(Tymy[1]->Hraci[i]->getPrijmeni() + " " + Tymy[1]->Hraci[i]->getJmeno() + " - " + Tymy[1]->Hraci[i]->getPost() + " - " + Tymy[1]->Hraci[i]->getFS() + " - " + Tymy[1]->Hraci[i]->getTS() + " - " + Tymy[1]->Hraci[i]->getZS());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        iGolyA = 0;
        iGolyB = 0;
        iCount = 0;
        Timer1->Enabled = true;
}
//--------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{ 
        iCount += 1;

        srand(GetTickCount());

        if(iCount < 60){
                iUtok = rand() % 99;

                if((iCount % 2) != 0){
                        iLine = 0;

                        if(iCelkoveA[0] > iCelkoveB[0]){
                                if(iUtoky[0] < 5){
                                        bUtoci[0] = true;
                                        iUtoky[0] ++;
                                }
                                else{
                                        bUtoci[0] = false;
                                        iUtoky[0] = 0;
                                }
                        }
                        if(iCelkoveB[0] > iCelkoveA[0]){
                                if(iUtoky[0] < 5){
                                        bUtoci[0] = false;
                                        iUtoky[0] ++;
                                }
                                else{
                                        bUtoci[0] = true;
                                        iUtoky[0] = 0;
                                }
                        }
                }
                else{
                        iLine = 1;

                        if(iCelkoveA[1] > iCelkoveB[1]){
                                if(iUtoky[0] < 5){
                                        bUtoci[1] = true;
                                        iUtoky[1] ++;
                                }
                                else{
                                        bUtoci[1] = false;
                                        iUtoky[1] = 0;
                                }
                        }
                        if(iCelkoveB[1] > iCelkoveA[1]){
                                if(iUtoky[0] < 5){
                                        bUtoci[1] = false;
                                        iUtoky[1] ++;
                                }
                                else{
                                        bUtoci[1] = true;
                                        iUtoky[1] = 0;
                                }
                        }
                }

                if(bUtoci[iLine] == true){
                        if((iCelkoveA[iLine] / iCelkoveB[iLine]) > 2){
                                iPomer = 17;
                        }
                        else{
                                iPomer = 9;
                        }
                        if(iPrumHrA[iLine] < iGolmanB){
                                iPomer = 16;
                        }
                        if(iUtok < iPomer){
                                iGolyA ++;
                                iStrelec = rand() % 5;
                                iAsistent = rand() % 5;
                                while(iStrelec == 0)
                                        iStrelec = rand() % 5;
                                while(iAsistent == iStrelec)
                                        iAsistent = rand() % 5;
                                if(iLine == 1){
                                        iStrelec += 5;
                                        iAsistent += 5;
                                }
                                Memo1->Lines->Add("G - " + Tymy[0]->Hraci[iStrelec]->getPrijmeni() + " " + Tymy[0]->Hraci[iStrelec]->getJmeno());
                                Memo1->Lines->Add("A - " + Tymy[0]->Hraci[iAsistent]->getPrijmeni() + " " + Tymy[0]->Hraci[iAsistent]->getJmeno());
                                Memo1->Lines->Add("-----------------------");
                        }
                        if(iUtok < 50){
                                iStrelyA ++;
                        }
                        Label9->Caption = "AAAA";
                }
                if(bUtoci[iLine] == false){
                        if((iCelkoveB[iLine] / iCelkoveA[iLine]) > 2){
                                iPomer = 17;
                        }
                        else{
                                iPomer = 9;
                        }
                        if(iPrumHrB[iLine] < iGolmanA){
                                iPomer = 16;
                        }
                        if(iUtok < iPomer){
                                iGolyB ++;
                                iStrelec = rand() % 5;
                                iAsistent = rand() % 5;
                                while(iStrelec == 0)
                                        iStrelec = rand() % 5;
                                while(iAsistent == iStrelec)
                                        iAsistent = rand() % 5;
                                if(iLine == 1){
                                        iStrelec += 5;
                                        iAsistent += 5;
                                }
                                Memo2->Lines->Add("G - " + Tymy[1]->Hraci[iStrelec]->getPrijmeni() + " " + Tymy[1]->Hraci[iStrelec]->getJmeno());
                                Memo2->Lines->Add("A - " + Tymy[1]->Hraci[iAsistent]->getPrijmeni() + " " + Tymy[1]->Hraci[iAsistent]->getJmeno());
                                Memo2->Lines->Add("-----------------------");
                        }
                        if(iUtok < 50){
                                iStrelyB ++;
                        }
                        Label9->Caption = "BBBB";
                }
        }
        else{
                Timer1->Enabled = false;
        }

        Label1->Caption = iCelkoveA[iLine];
        Label2->Caption = iCelkoveB[iLine];

        Label7->Caption = iPomer;
        Label8->Caption = iUtok;

        Label3->Caption = iGolyA;
        Label4->Caption = iGolyB;

        Label6->Caption = iCount;

        Label10->Caption = iStrelyA;
        Label11->Caption = iStrelyB;

        Label12->Caption = iGolmanA;
        Label13->Caption = iGolmanB;

        Label14->Caption = iPrumHrB[iLine];
        Label15->Caption = iPrumHrA[iLine];

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Timer1->Enabled = false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Timer1->Enabled = true;        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
        int iCelkemA = 0;
        int iCelkemB = 0;
        float iKoef = 0.90;

        iCelkemA = Tymy[0]->getCelkoveFS() + Tymy[0]->getCelkoveTS() + Tymy[0]->getCelkoveZS();
        iCelkemB = Tymy[1]->getCelkoveFS() + Tymy[1]->getCelkoveTS() + Tymy[1]->getCelkoveZS();

        if(iCelkemA == iCelkemB){
                iKoef = 0.5;
        }
        if(iCelkemA > iCelkemB){
                int i = iCelkemA / iCelkemB;
                if(i > 3){
                        iKoef = 1;
                }
                if(i <= 3){
                        iKoef = 0.7;
                }
        }
        if(iCelkemB > iCelkemA){
                iKoef = 0.2;
        }


        Tymy[0]->setKapacitaHaly(1000);

        iNavsteva = iKoef * Tymy[0]->getKapacitaHaly();

        Label16->Caption = iNavsteva;
}
//---------------------------------------------------------------------------

