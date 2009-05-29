//---------------------------------------------------------------------------
#pragma hdrstop
#include "ZapasNEW.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_BackClick(TObject *Sender)
{
        SF->Visible = false;
        HO->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setColorsSF()
{
        TColor RGB1;
        TColor RGB2;

        RGB1 = Teams[Manager->getKlub()]->getRGB1();
        RGB2 = Teams[Manager->getKlub()]->getRGB2();

        SF_B2->Brush->Color = RGB1;
        SF_B2->Pen->Color = RGB2;
        SF_B3->Brush->Color = RGB2;
        SF_L_PostHead->Color = RGB1;
        SF_L_PostHead->Font->Color = RGB2;
        SF_L_NumberHead->Color = RGB1;
        SF_L_NumberHead->Font->Color = RGB2;
        SF_L_NameHead->Color = RGB1;
        SF_L_NameHead->Font->Color = RGB2;
        SF_L_AgeHead->Color = RGB1;
        SF_L_AgeHead->Font->Color = RGB2;
        SF_L_FSHead->Color = RGB1;
        SF_L_FSHead->Font->Color = RGB2;
        SF_L_TSHead->Color = RGB1;
        SF_L_TSHead->Font->Color = RGB2;
        SF_L_ZSHead->Color = RGB1;
        SF_L_ZSHead->Font->Color = RGB2;
        SF_L_LineHead->Color = RGB1;
        SF_L_LineHead->Font->Color = RGB2;
        SF_L_EnHead->Color = RGB1;
        SF_L_EnHead->Font->Color = RGB2;

        SF_L_Post->Color = RGB2;
        SF_L_Post->Font->Color = RGB1;
        SF_L_Number->Color = RGB2;
        SF_L_Number->Font->Color = RGB1;
        SF_L_Name->Color = RGB2;
        SF_L_Name->Font->Color = RGB1;
        SF_L_Age->Color = RGB2;
        SF_L_Age->Font->Color = RGB1;
        SF_L_FS->Color = RGB2;
        SF_L_FS->Font->Color = RGB1;
        SF_L_TS->Color = RGB2;
        SF_L_TS->Font->Color = RGB1;
        SF_L_ZS->Color = RGB2;
        SF_L_ZS->Font->Color = RGB1;
        SF_L_Line->Color = RGB2;
        SF_L_Line->Font->Color = RGB1;
        SF_L_En->Color = RGB2;
        SF_L_En->Font->Color = RGB1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::setPlayersSF()
{
        String post, number, name, age, fs, ts, zs, line, energy;

        post = number = name = age = fs = ts = zs = line = energy = "";

        for(int i = 0; i < Teams[Manager->getKlub()]->getPocetHracu(); i ++) {
                if(i != 0) {
                        post += "\n";
                        number += "\n";
                        name += "\n";
                        age += "\n";
                        fs += "\n";
                        ts += "\n";
                        zs += "\n";
                        line += "\n";
                        energy += "\n";
                }
                post += Teams[Manager->getKlub()]->Hraci[i]->getPost();
                number += Teams[Manager->getKlub()]->Hraci[i]->getCislo();
                name += Teams[Manager->getKlub()]->Hraci[i]->getJmeno() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni();
                age += Teams[Manager->getKlub()]->Hraci[i]->getVek();
                fs += Teams[Manager->getKlub()]->Hraci[i]->getFS();
                ts += Teams[Manager->getKlub()]->Hraci[i]->getTS();
                zs += Teams[Manager->getKlub()]->Hraci[i]->getZS();
                if(Teams[Manager->getKlub()]->Hraci[i]->getSestava() == 5)
                        line += "N";
                else
                        line += Teams[Manager->getKlub()]->Hraci[i]->getSestava();
                energy += Teams[Manager->getKlub()]->Hraci[i]->getEnergie();
        }

        SF_L_Post->Caption = post;
        SF_L_Number->Caption = number;
        SF_L_Name->Caption = name;
        SF_L_Age->Caption = age;
        SF_L_FS->Caption = fs;
        SF_L_TS->Caption = ts;
        SF_L_ZS->Caption = zs;
        SF_L_Line->Caption = line;
        SF_L_En->Caption = energy;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setComboBoxesSF()
{
        SF_CB_Lines->ItemIndex = Teams[Manager->getKlub()]->getPocetLajn() - 2;

        SF_CB_1Goa1->Clear();
        SF_CB_1Att1->Clear();
        SF_CB_1Att2->Clear();
        SF_CB_1Att3->Clear();
        SF_CB_2Att1->Clear();
        SF_CB_2Att2->Clear();
        SF_CB_2Att3->Clear();
        SF_CB_3Att1->Clear();
        SF_CB_3Att2->Clear();
        SF_CB_3Att3->Clear();
        SF_CB_1Def1->Clear();
        SF_CB_1Def2->Clear();
        SF_CB_2Def1->Clear();
        SF_CB_2Def2->Clear();
        SF_CB_3Def1->Clear();
        SF_CB_3Def2->Clear();

        if(Teams[Manager->getKlub()]->getPocetLajn() == 2) {
                SF_CB_3Att1->Visible = false;
                SF_CB_3Att2->Visible = false;
                SF_CB_3Att3->Visible = false;
                SF_CB_3Def1->Visible = false;
                SF_CB_3Def2->Visible = false;
        } else if(Teams[Manager->getKlub()]->getPocetLajn() == 3) {
                SF_CB_3Att1->Visible = true;
                SF_CB_3Att2->Visible = true;
                SF_CB_3Att3->Visible = true;
                SF_CB_3Def1->Visible = true;
                SF_CB_3Def2->Visible = true;
        }

        int utocniku = 0;
        int obrancu = 0;
        int golmanu = 0;

        for(int i = 0; i < Teams[Manager->getKlub()]->getPocetHracu(); i ++) {
                if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'G') golmanu ++;
                else if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'O') obrancu ++;
                else if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'U') utocniku ++;
        }

        Teams[Manager->getKlub()]->setridHrace('P', true);

        for(int i = 0; i < Teams[Manager->getKlub()]->getPocetHracu(); i ++) {
                if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'G')
                        SF_CB_1Goa1->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                else {
                        SF_CB_1Def1->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_1Def2->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Def1->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Def2->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Def1->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Def2->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_1Att1->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_1Att2->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_1Att3->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Att1->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Att2->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Att3->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Att1->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Att2->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Att3->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                }
        }

        Teams[Manager->getKlub()]->setridHrace('P', true);

        int iPom = 0;
        for(int i = 0; i < Teams[Manager->getKlub()]->getPocetHracu(); i ++) {
                if(Teams[Manager->getKlub()]->Hraci[i]->getSestava() == 1) {
                        if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'G') {
                                SF_CB_1Goa1->ItemIndex = i;
                        } else if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'O') {
                                if(iPom == 0) {
                                        SF_CB_1Def1->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else {
                                        SF_CB_1Def2->ItemIndex = i - golmanu;
                                        iPom = 0;
                                }
                        } else if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'U') {
                                if(iPom == 0) {
                                        SF_CB_1Att1->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else if(iPom == 1) {
                                        SF_CB_1Att2->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else {
                                        SF_CB_1Att3->ItemIndex = i - golmanu;
                                        iPom = 0;
                                }
                        }
                } else if(Teams[Manager->getKlub()]->Hraci[i]->getSestava() == 2) {
                        if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'O') {
                                if(iPom == 0) {
                                        SF_CB_2Def1->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else {
                                        SF_CB_2Def2->ItemIndex = i - golmanu;
                                        iPom = 0;
                                }
                        } else if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'U') {
                                if(iPom == 0) {
                                        SF_CB_2Att1->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else if(iPom == 1) {
                                        SF_CB_2Att2->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else {
                                        SF_CB_2Att3->ItemIndex = i - golmanu;
                                        iPom = 0;
                                }
                        }
                }
        } for(int i = 0; i < Teams[Manager->getKlub()]->getPocetHracu(); i ++) {
                if(Teams[Manager->getKlub()]->Hraci[i]->getSestava() == 3) {
                        if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'O') {
                                if(iPom == 0) {
                                        SF_CB_3Def1->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else {
                                        SF_CB_3Def2->ItemIndex = i - golmanu;
                                        iPom = 0;
                                }
                        } else if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'U') {
                                if(iPom == 0) {
                                        SF_CB_3Att1->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else if(iPom == 1) {
                                        SF_CB_3Att2->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else {
                                        SF_CB_3Att3->ItemIndex = i - golmanu;
                                        iPom = 0;
                                }
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_1Att1CloseUp(TObject *Sender)
{
        if(SF_CB_1Att1->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_1Att1->ItemIndex = -1;
        } else if(SF_CB_1Att1->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_1Att1->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_1Att1->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_1Att2CloseUp(TObject *Sender)
{
        if(SF_CB_1Att2->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_1Att2->ItemIndex = -1;
        } else if(SF_CB_1Att2->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_1Att2->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_1Att2->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_1Att3CloseUp(TObject *Sender)
{
        if(SF_CB_1Att3->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_1Att3->ItemIndex = -1;
        } else if(SF_CB_1Att3->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_1Att3->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_1Att3->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_2Att1CloseUp(TObject *Sender)
{
        if(SF_CB_2Att1->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_2Att1->ItemIndex = -1;
        } else if(SF_CB_2Att1->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_2Att1->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_2Att2CloseUp(TObject *Sender)
{
        if(SF_CB_2Att2->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_2Att2->ItemIndex = -1;
        } else if(SF_CB_2Att2->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_2Att2->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_2Att2->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_2Att3CloseUp(TObject *Sender)
{
        if(SF_CB_2Att3->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_2Att3->ItemIndex = -1;
        } else if(SF_CB_2Att3->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_2Att3->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_2Att3->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SF_CB_3Att1CloseUp(TObject *Sender)
{
        if(SF_CB_3Att1->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_3Att1->ItemIndex = -1;
        } else if(SF_CB_3Att1->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_2Att1->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_3Att1->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_3Att1->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_3Att2CloseUp(TObject *Sender)
{
        if(SF_CB_3Att2->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_3Att2->ItemIndex = -1;
        } else if(SF_CB_3Att2->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_3Att2->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_3Att2->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_3Att3CloseUp(TObject *Sender)
{
        if(SF_CB_3Att3->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_2Att3->ItemIndex) {
                SF_CB_3Att3->ItemIndex = -1;
        } else if(SF_CB_3Att3->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_3Att3->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_3Att3->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_1Def1CloseUp(TObject *Sender)
{
        if(SF_CB_1Def1->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_1Def1->ItemIndex = -1;
        } else if(SF_CB_1Def1->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_1Def1->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_1Def1->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_1Def2CloseUp(TObject *Sender)
{
        if(SF_CB_1Def2->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_1Def2->ItemIndex = -1;
        } else if(SF_CB_1Def2->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_1Def2->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_1Def2->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_2Def1CloseUp(TObject *Sender)
{
        if(SF_CB_2Def1->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_2Def1->ItemIndex = -1;
        } else if(SF_CB_2Def1->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_2Def1->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_2Def1->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_2Def2CloseUp(TObject *Sender)
{
        if(SF_CB_2Def2->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_2Def2->ItemIndex = -1;
        } else if(SF_CB_2Def2->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_2Def2->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_2Def2->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_3Def1CloseUp(TObject *Sender)
{
        if(SF_CB_3Def1->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_3Def1->ItemIndex = -1;
        } else if(SF_CB_3Def1->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_2Def2->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_3Def1->ItemIndex == SF_CB_3Def2->ItemIndex) {
                SF_CB_3Def1->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_3Def2CloseUp(TObject *Sender)
{
        if(SF_CB_3Def2->ItemIndex == SF_CB_1Att1->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_1Att2->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_1Att3->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_2Att1->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_2Att2->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_2Att3->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_3Att1->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_3Att2->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_3Att3->ItemIndex) {
                SF_CB_3Def2->ItemIndex = -1;
        } else if(SF_CB_3Def2->ItemIndex == SF_CB_1Def1->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_2Def1->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_1Def2->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_3Def1->ItemIndex || SF_CB_3Def2->ItemIndex == SF_CB_2Def2->ItemIndex) {
                SF_CB_3Def2->ItemIndex = -1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_B_SaveClick(TObject *Sender)
{
        if(SF_CB_1Goa1->ItemIndex == -1 || SF_CB_1Def1->ItemIndex == -1 || SF_CB_1Def2->ItemIndex == -1 || SF_CB_2Def1->ItemIndex == -1 || SF_CB_2Def2->ItemIndex == -1 || SF_CB_1Att1->ItemIndex == -1 || SF_CB_1Att2->ItemIndex == -1 || SF_CB_1Att3->ItemIndex == -1 || SF_CB_2Att1->ItemIndex == -1 || SF_CB_2Att2->ItemIndex == -1 || SF_CB_2Att3->ItemIndex == -1) {

        } else if(SF_CB_Lines->ItemIndex == 1 && (SF_CB_3Def1->ItemIndex == -1 || SF_CB_3Def2->ItemIndex == -1 || SF_CB_3Att1->ItemIndex == -1 || SF_CB_3Att2->ItemIndex == -1 || SF_CB_3Att3->ItemIndex == -1)) {

        } else {
                Teams[Manager->getKlub()]->setridHrace('P', true);

                for(int i = 0; i < Teams[Manager->getKlub()]->getPocetHracu(); i ++) {
                        Teams[Manager->getKlub()]->Hraci[i]->setSestava(5);
                }

                int utocniku = 0;
                int obrancu = 0;
                int golmanu = 0;

                for(int i = 0; i < Teams[Manager->getKlub()]->getPocetHracu(); i ++) {
                        if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'G') golmanu ++;
                        else if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'O') obrancu ++;
                        else if(Teams[Manager->getKlub()]->Hraci[i]->getPost() == 'U') utocniku ++;
                }

                Teams[Manager->getKlub()]->setPocetLajn(SF_CB_Lines->ItemIndex + 2);

                Teams[Manager->getKlub()]->Hraci[SF_CB_1Goa1->ItemIndex]->setSestava(1);
                Teams[Manager->getKlub()]->Hraci[SF_CB_1Def1->ItemIndex + golmanu]->setSestava(1);
                Teams[Manager->getKlub()]->Hraci[SF_CB_1Def2->ItemIndex + golmanu]->setSestava(1);
                Teams[Manager->getKlub()]->Hraci[SF_CB_2Def1->ItemIndex + golmanu]->setSestava(2);
                Teams[Manager->getKlub()]->Hraci[SF_CB_2Def2->ItemIndex + golmanu]->setSestava(2);
                Teams[Manager->getKlub()]->Hraci[SF_CB_1Att1->ItemIndex + golmanu]->setSestava(1);
                Teams[Manager->getKlub()]->Hraci[SF_CB_1Att2->ItemIndex + golmanu]->setSestava(1);
                Teams[Manager->getKlub()]->Hraci[SF_CB_1Att3->ItemIndex + golmanu]->setSestava(1);
                Teams[Manager->getKlub()]->Hraci[SF_CB_2Att1->ItemIndex + golmanu]->setSestava(2);
                Teams[Manager->getKlub()]->Hraci[SF_CB_2Att2->ItemIndex + golmanu]->setSestava(2);
                Teams[Manager->getKlub()]->Hraci[SF_CB_2Att3->ItemIndex + golmanu]->setSestava(2);

                if(SF_CB_Lines->ItemIndex == 1) {
                        Teams[Manager->getKlub()]->Hraci[SF_CB_3Def1->ItemIndex + golmanu]->setSestava(3);
                        Teams[Manager->getKlub()]->Hraci[SF_CB_3Def2->ItemIndex + golmanu]->setSestava(3);
                        Teams[Manager->getKlub()]->Hraci[SF_CB_3Att1->ItemIndex + golmanu]->setSestava(3);
                        Teams[Manager->getKlub()]->Hraci[SF_CB_3Att2->ItemIndex + golmanu]->setSestava(3);
                        Teams[Manager->getKlub()]->Hraci[SF_CB_3Att3->ItemIndex + golmanu]->setSestava(3);
                }

                Teams[Manager->getKlub()]->setridHrace('L', true);

                setPlayersSF();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_CB_LinesChange(TObject *Sender)
{
        if(SF_CB_Lines->ItemIndex == 0) {
                SF_CB_3Att1->Visible = false;
                SF_CB_3Att2->Visible = false;
                SF_CB_3Att3->Visible = false;
                SF_CB_3Def1->Visible = false;
                SF_CB_3Def2->Visible = false;

                SF_CB_3Att1->ItemIndex = -1;
                SF_CB_3Att2->ItemIndex = -1;
                SF_CB_3Att3->ItemIndex = -1;
                SF_CB_3Def1->ItemIndex = -1;
                SF_CB_3Def2->ItemIndex = -1;
        } else if(SF_CB_Lines->ItemIndex == 1) {
                SF_CB_3Att1->Visible = true;
                SF_CB_3Att2->Visible = true;
                SF_CB_3Att3->Visible = true;
                SF_CB_3Def1->Visible = true;
                SF_CB_3Def2->Visible = true;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_PostHeadClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('P', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NameHeadClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('J', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_AgeHeadClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('V', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_FSHeadClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('F', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_TSHeadClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('T', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_ZSHeadClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('Z', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_LineHeadClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('L', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_PostHeadDblClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('P', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NameHeadDblClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('J', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_AgeHeadDblClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('V', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_FSHeadDblClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('F', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_TSHeadDblClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('T', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_ZSHeadDblClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('Z', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_LineHeadDblClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('L', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NumberHeadClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('C', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NumberHeadDblClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('C', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_EnHeadClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('E', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_EnHeadDblClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('E', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------