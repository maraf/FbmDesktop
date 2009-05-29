//---------------------------------------------------------------------------
#pragma hdrstop
#include "ZapasNEW.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

void __fastcall TForm1::setColorsLP()
{
        TColor RGB1;
        TColor RGB2;

        RGB1 = RGB(Teams[t]->getR1(), Teams[t]->getG1(), Teams[t]->getB1());
        RGB2 = RGB(Teams[t]->getR2(), Teams[t]->getG2(), Teams[t]->getB2());

        LP->Color = RGB1;
        LP_B1->Brush->Color = RGB2;
        LP_B2->Brush->Color = RGB1;
        LP_B2->Pen->Color = RGB2;
        LP_B3->Brush->Color = RGB2;
        LP_B4->Brush->Color = RGB1;
        LP_B5->Brush->Color = RGB2;
        LP_Name->Color = RGB2;
        LP_Name->Font->Color = RGB1;
        LP_Hall->Color = RGB2;
        LP_Hall->Font->Color = RGB1;
        LP_Capacity->Color = RGB2;
        LP_Capacity->Font->Color = RGB1;
        LP_lCapacity->Color = RGB2;
        LP_lCapacity->Font->Color = RGB1;

        LP_P_L->Color = RGB1;
        LP_P_L->Font->Color = RGB2;
        LP_C_L->Color = RGB1;
        LP_C_L->Font->Color = RGB2;
        LP_J_L->Color = RGB1;
        LP_J_L->Font->Color = RGB2;
        LP_V_L->Color = RGB1;
        LP_V_L->Font->Color = RGB2;
        LP_T_L->Color = RGB1;
        LP_T_L->Font->Color = RGB2;
        LP_F_L->Color = RGB1;
        LP_F_L->Font->Color = RGB2;
        LP_Z_L->Color = RGB1;
        LP_Z_L->Font->Color = RGB2;
        LP_L_L->Color = RGB1;
        LP_L_L->Font->Color = RGB2;
        LP_Zl_L->Color = RGB1;
        LP_Zl_L->Font->Color = RGB2;
        LP_Gl_L->Color = RGB1;
        LP_Gl_L->Font->Color = RGB2;
        LP_Al_L->Color = RGB1;
        LP_Al_L->Font->Color = RGB2;
        LP_En_L->Color = RGB1;
        LP_En_L->Font->Color = RGB2;

        LP_P_M->Font->Color = RGB1;
        LP_P_M->Color = RGB2;
        LP_C_M->Font->Color = RGB1;
        LP_C_M->Color = RGB2;
        LP_J_M->Font->Color = RGB1;
        LP_J_M->Color = RGB2;
        LP_V_M->Font->Color = RGB1;
        LP_V_M->Color = RGB2;
        LP_T_M->Font->Color = RGB1;
        LP_T_M->Color = RGB2;
        LP_F_M->Font->Color = RGB1;
        LP_F_M->Color = RGB2;
        LP_Z_M->Font->Color = RGB1;
        LP_Z_M->Color = RGB2;
        LP_L_M->Font->Color = RGB1;
        LP_L_M->Color = RGB2;
        LP_Zl_M->Font->Color = RGB1;
        LP_Zl_M->Color = RGB2;
        LP_Gl_M->Font->Color = RGB1;
        LP_Gl_M->Color = RGB2;
        LP_Al_M->Font->Color = RGB1;
        LP_Al_M->Color = RGB2;
        LP_En_M->Font->Color = RGB1;
        LP_En_M->Color = RGB2;

        LP_B7->Brush->Color = RGB2;
        LP_GB_Training->Color = RGB2;
        LP_GB_Training->Font->Color = RGB1;
        LP_GB_Players->Color = RGB2;
        LP_GB_Players->Font->Color = RGB1;
        LP_GB_Team->Color = RGB2;
        LP_GB_Team->Font->Color = RGB1;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::setPlayersLP()
{
        String Post, Cislo, Jmeno, Vek, FS, TS, ZS, Line, ZapL, GolL, AsiL, En;

        Post = Teams[t]->Hraci[0]->getPost();
        Cislo = Teams[t]->Hraci[0]->getCislo();
        Jmeno += Teams[t]->Hraci[0]->getJmeno() + " " + Teams[t]->Hraci[0]->getPrijmeni();
        Vek = Teams[t]->Hraci[0]->getVek();
        FS = Teams[t]->Hraci[0]->getFS();
        TS = Teams[t]->Hraci[0]->getTS();
        ZS = Teams[t]->Hraci[0]->getZS();
        ZapL = Teams[t]->Hraci[0]->getZapasyL();
        GolL = Teams[t]->Hraci[0]->getGolyL();
        AsiL = Teams[t]->Hraci[0]->getAsistenceL();
        En = Teams[t]->Hraci[0]->getEnergie();

        if(Teams[t]->Hraci[0]->getSestava() == 5)
                Line = "N";
        else
                Line = Teams[t]->Hraci[0]->getSestava();

        for(int i = 1; i < Teams[t]->getPocetHracu(); i ++){
                Post += "\n";
                Post += Teams[t]->Hraci[i]->getPost();

                Cislo += "\n";
                Cislo += Teams[t]->Hraci[i]->getCislo();

                Jmeno += "\n";
                Jmeno += Teams[t]->Hraci[i]->getJmeno() + " " + Teams[t]->Hraci[i]->getPrijmeni();

                Vek += "\n";
                Vek += Teams[t]->Hraci[i]->getVek();

                FS += "\n";
                FS += Teams[t]->Hraci[i]->getFS();

                TS += "\n";
                TS += Teams[t]->Hraci[i]->getTS();

                ZS += "\n";
                ZS += Teams[t]->Hraci[i]->getZS();

                ZapL += "\n";
                ZapL += Teams[t]->Hraci[i]->getZapasyL();

                GolL += "\n";
                GolL += Teams[t]->Hraci[i]->getGolyL();

                AsiL += "\n";
                AsiL += Teams[t]->Hraci[i]->getAsistenceL();

                En += "\n";
                En += Teams[t]->Hraci[i]->getEnergie();

                Line += "\n";
                if(Teams[t]->Hraci[i]->getSestava() == 5)
                        Line += "N";
                else
                        Line += Teams[t]->Hraci[i]->getSestava();
        }
        
        LP_P_M->Caption = Post;
        LP_C_M->Caption = Cislo;
        LP_J_M->Caption = Jmeno;
        LP_V_M->Caption = Vek;
        LP_F_M->Caption = FS;
        LP_T_M->Caption = TS;
        LP_Z_M->Caption = ZS;
        LP_Zl_M->Caption = ZapL;
        LP_Gl_M->Caption = GolL;
        LP_Al_M->Caption = AsiL;
        LP_En_M->Caption = En;
        LP_L_M->Caption = Line;

        LP_Name->Caption = Teams[t]->getNazevTymu();
        LP_Hall->Caption = Teams[t]->getNazevHaly();
        LP_Capacity->Caption = Teams[t]->getKapacitaHaly();
        LP_Logo->Picture->LoadFromFile("teams/" + Teams[t]->getLogo());
        LP_iHall->Picture->LoadFromFile("teams/" + Teams[t]->getHala());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_P_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('P', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_C_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('C', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_J_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('J', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_V_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('V', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_F_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('F', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_T_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('T', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Z_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('Z', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_L_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('L', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Gl_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('G', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Gl_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('G', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Al_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('H', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Al_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('H', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_En_LClick(TObject *Sender)
{
        Teams[t]->setridHrace('E', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_En_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('E', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_B_BuyClick(TObject *Sender)
{
        if(Teams[Manager->getKlub()]->getPocetHracu() <= 30 && LP_Buy->ItemIndex != -1) {
                Teams[t]->setridHrace('P', true);
                Teams[Manager->getKlub()]->setridHrace('P', true);

                Teams[t]->Hraci[LP_Buy->ItemIndex]->setSestava(5);
                if(!Teams[Manager->getKlub()]->isFreeNumber(Teams[t]->Hraci[LP_Buy->ItemIndex]->getCislo())) {
                        for(int i = 101; i > 1; i --) {
                                if(Teams[Manager->getKlub()]->isFreeNumber(i)) {
                                        Teams[t]->Hraci[LP_Buy->ItemIndex]->setCislo(i);
                                }
                        }
                }
                Teams[Manager->getKlub()]->addPlayer(Teams[t]->Hraci[LP_Buy->ItemIndex]);
                Teams[t]->deletePlayerAt(LP_Buy->ItemIndex);

                Teams[t]->setridHrace('P', true);

                setPlayersLP();

                LP_Buy->Clear();
                String sLP;
                for(int i = 0; i < Teams[t]->getPocetHracu(); i ++){
                        sLP = Teams[t]->Hraci[i]->getCislo();
                        sLP +=  " ";
                        sLP += Teams[t]->Hraci[i]->getPrijmeni();
                        LP_Buy->Items->Add(sLP);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_B_TrainingClick(TObject *Sender)
{
        Teams[Manager->getKlub()]->setTraining(LP_CB_Training->ItemIndex);
        switch(LP_CB_TrainingIntensity->ItemIndex) {
                case 0: Teams[Manager->getKlub()]->setTrainingIntensity(0); break;
                case 1: Teams[Manager->getKlub()]->setTrainingIntensity(0.1); break;
                case 2: Teams[Manager->getKlub()]->setTrainingIntensity(0.2); break;
                case 3: Teams[Manager->getKlub()]->setTrainingIntensity(0.3); break;
                case 4: Teams[Manager->getKlub()]->setTrainingIntensity(0.4); break;
                case 5: Teams[Manager->getKlub()]->setTrainingIntensity(0.5); break;
                case 6: Teams[Manager->getKlub()]->setTrainingIntensity(0.6); break;
                case 7: Teams[Manager->getKlub()]->setTrainingIntensity(0.7); break;
                case 8: Teams[Manager->getKlub()]->setTrainingIntensity(0.8); break;
                case 9: Teams[Manager->getKlub()]->setTrainingIntensity(0.9); break;
                case 10: Teams[Manager->getKlub()]->setTrainingIntensity(1); break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_B_KickClick(TObject *Sender)
{
        if(LP_CB_Players->ItemIndex != -1) {
                if(!(Teams[Manager->getKlub()]->getCountOfGoalkeepers() == 1 && Teams[Manager->getKlub()]->Hraci[LP_CB_Players->ItemIndex]->getPost() == 'G') && Teams[Manager->getKlub()]->getPocetHracu() > 12) {
                        Teams[Manager->getKlub()]->setridHrace('P', true);
                        Teams[Manager->getKlub()]->deletePlayerAt(LP_CB_Players->ItemIndex);
                        LP_CB_Players->DeleteSelected();
                        setPlayersLP();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZpetClick(TObject *Sender)
{
        LP_Buy->Clear();
        LP->Visible = false;
        HO->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_P_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('P', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_C_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('C', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_J_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('J', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_V_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('V', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_F_LDblClck(TObject *Sender)
{
        Teams[t]->setridHrace('F', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_T_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('T', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Z_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('Z', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_L_LDblClick(TObject *Sender)
{
        Teams[t]->setridHrace('L', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------