//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ZapasNEW.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        bGool = false;
        iTime = 0;

        t = 0;

        AktKolo = 0;
        rozpisLigy();

        Manager = new Manazer("Marek", "SMM", 3);

        for(int i = 0; i < 6; i ++) {
                if(RozpisLigy[AktKolo][0][i] == Manager->getKlub() || RozpisLigy[AktKolo][1][i] == Manager->getKlub()) {
                        d = RozpisLigy[AktKolo][0][i];
                        h = RozpisLigy[AktKolo][1][i];
                        iMatchIndex = i;
                }
        }

        for(int i = 0; i < 12; i ++)
                tymy[i] = new Tym();

        tymy[0]->nactiHrace("teams/aik_l.txt");
        tymy[0]->nactiTym("teams/aik_m.txt");
        tymy[0]->setID(1);
        tymy[1]->nactiHrace("teams/alv_l.txt");
        tymy[1]->nactiTym("teams/alv_m.txt"); 
        tymy[1]->setID(1);
        tymy[2]->nactiHrace("teams/bal_l.txt");
        tymy[2]->nactiTym("teams/bal_m.txt");
        tymy[2]->setID(1);
        tymy[3]->nactiHrace("teams/cap_l.txt");
        tymy[3]->nactiTym("teams/cap_m.txt");
        tymy[3]->setID(3);
        tymy[4]->nactiHrace("teams/dal_l.txt");
        tymy[4]->nactiTym("teams/dal_m.txt");
        tymy[4]->setID(4);
        tymy[5]->nactiHrace("teams/fal_l.txt");
        tymy[5]->nactiTym("teams/fal_m.txt");
        tymy[5]->setID(5);
        tymy[6]->nactiHrace("teams/hel_l.txt");
        tymy[6]->nactiTym("teams/hel_m.txt");
        tymy[6]->setID(6);
        tymy[7]->nactiHrace("teams/jar_l.txt");
        tymy[7]->nactiTym("teams/jar_m.txt");
        tymy[7]->setID(7);
        tymy[8]->nactiHrace("teams/jon_l.txt");
        tymy[8]->nactiTym("teams/jon_m.txt");
        tymy[8]->setID(8);
        tymy[9]->nactiHrace("teams/pix_l.txt");
        tymy[9]->nactiTym("teams/pix_m.txt");
        tymy[9]->setID(9);
        tymy[10]->nactiHrace("teams/sto_l.txt");
        tymy[10]->nactiTym("teams/sto_m.txt");
        tymy[10]->setID(10);
        tymy[11]->nactiHrace("teams/war_l.txt");
        tymy[11]->nactiTym("teams/war_m.txt");
        tymy[11]->setID(11);
                
        for(int i = 0; i < 12; i ++){
                setLineup(i);
                tymy[i]->setridHrace('P', true);
        }
        
        R1 = tymy[t]->getR1();
        G1 = tymy[t]->getG1();
        B1 = tymy[t]->getB1();

        R2 = tymy[t]->getR2();
        G2 = tymy[t]->getG2();
        B2 = tymy[t]->getB2();

        LP->Left = 112;
        LP->Top = 84;

        HO->Left = 112;
        HO->Top = 84;

        MA->Left = 112;
        MA->Top = 84;

        TE->Left = 112;
        TE->Top = 84;

        TA->Left = 112;
        TA->Top = 84;

        SF->Left = 112;
        SF->Top = 84;

        TR->Left = 112;
        TR->Top = 84;

        LP->Visible = false;
        MA->Visible = false;
        TE->Visible = false;
        SF->Visible = false;
        TR->Visible = false;
        HO->Visible = true;

        LP_Name->Caption = tymy[t]->getNazevTymu();
        LP_Hall->Caption = tymy[t]->getNazevHaly();
        LP_Capacity->Caption = tymy[t]->getKapacitaHaly();
        LP_Logo->Picture->LoadFromFile("teams/"+tymy[t]->getLogo());
        LP_iHall->Picture->LoadFromFile("teams/"+tymy[t]->getHala());

        setColors();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::setColors()
{
        D_R1 = tymy[d]->getR1();
        D_G1 = tymy[d]->getG1();
        D_B1 = tymy[d]->getB1();

        D_R2 = tymy[d]->getR2();
        D_G2 = tymy[d]->getG2();
        D_B2 = tymy[d]->getB2();

        H_R1 = tymy[h]->getR1();
        H_G1 = tymy[h]->getG1();
        H_B1 = tymy[h]->getB1();

        H_R2 = tymy[h]->getR2();
        H_G2 = tymy[h]->getG2();
        H_B2 = tymy[h]->getB2();
                      
        TColor B_RGB1;
        TColor B_RGB2;
        TColor B_RGB3;
        TColor D_RGB1;
        TColor D_RGB2;
        TColor H_RGB1;
        TColor H_RGB2;

        B_RGB1 = RGB(0, 140, 0);
        B_RGB2 = RGB(255, 255, 255);
        B_RGB3 = RGB(0, 0, 0);

        D_RGB1 = RGB(D_R1, D_G1, D_B1);
        D_RGB2 = RGB(D_R2, D_G2, D_B2);

        H_RGB1 = RGB(H_R1, H_G1, H_B1);
        H_RGB2 = RGB(H_R2, H_G2, H_B2);

        HO->Color = B_RGB1;
        HO_B1->Pen->Color = B_RGB2;
        HO_B1->Brush->Color = B_RGB1;

        TE->Color = B_RGB1;
        TE_B1->Pen->Color = B_RGB2;
        TE_B1->Brush->Color = B_RGB1;

        TA->Color = B_RGB1;
        TA_B1->Pen->Color = B_RGB2;
        TA_B1->Brush->Color = B_RGB1;

        SF->Color = B_RGB1;
        SF_B1->Pen->Color = B_RGB2;
        SF_B1->Brush->Color = B_RGB1;

        MA->Color = B_RGB1;
        MA_B1->Pen->Color = B_RGB2;
        MA_B1->Brush->Color = B_RGB1;
        MA_Cas->Color = B_RGB2;
        MA_Cas->Font->Color = B_RGB3;
        MA_B2S->Brush->Color = B_RGB2;
        MA_Hall->Color = B_RGB2;
        MA_Hall->Font->Color = B_RGB3;
        MA_Skore->Color = B_RGB2;
        MA_Skore->Font->Color = B_RGB3;
        MA_SkoreD->Color = B_RGB2;
        MA_SkoreD->Font->Color = B_RGB3;
        MA_SkoreH->Color = B_RGB2;
        MA_SkoreH->Font->Color = B_RGB3;
        MA_Strely->Color = B_RGB2;
        MA_Strely->Font->Color = B_RGB3;
        MA_StrelyD->Color = B_RGB2;
        MA_StrelyD->Font->Color = B_RGB3;
        MA_StrelyH->Color = B_RGB2;
        MA_StrelyH->Font->Color = B_RGB3;
        MA_Navsteva->Color = B_RGB2;
        MA_Navsteva->Font->Color = B_RGB3;
        MA_iNavsteva->Color = B_RGB2;
        MA_iNavsteva->Font->Color = B_RGB3;

        MA_B2D->Brush->Color = D_RGB2;
        MA_B2D2->Brush->Color = D_RGB2;
        MA_B2D3->Brush->Color = D_RGB2;
        MA_B2D4->Brush->Color = D_RGB2;
        MA_B2D5->Brush->Color = D_RGB2;
        MA_B2D6->Brush->Color = D_RGB2;
        MA_B2D7->Brush->Color = D_RGB2;

        MA_LP_D->Color = D_RGB2;
        MA_LP_DL1->Color = D_RGB2;
        MA_LP_DL1->Font->Color = D_RGB1;
        MA_LP_DL2->Color = D_RGB2;
        MA_LP_DL2->Font->Color = D_RGB1;
        MA_LP_DL3->Color = D_RGB2;
        MA_LP_DL3->Font->Color = D_RGB1;
        MA_LP_DL4->Color = D_RGB2;
        MA_LP_DL4->Font->Color = D_RGB1;
        MA_LP_DL5->Color = D_RGB2;
        MA_LP_DL5->Font->Color = D_RGB1;
        MA_LP_DL6->Color = D_RGB2;
        MA_LP_DL6->Font->Color = D_RGB1;
        MA_LP_DL7->Color = D_RGB2;
        MA_LP_DL7->Font->Color = D_RGB1;
        MA_LP_H->Color = H_RGB2;
        MA_LP_HL1->Color = H_RGB2;
        MA_LP_HL1->Font->Color = H_RGB1;
        MA_LP_HL2->Color = H_RGB2;
        MA_LP_HL2->Font->Color = H_RGB1;
        MA_LP_HL3->Color = H_RGB2;
        MA_LP_HL3->Font->Color = H_RGB1;
        MA_LP_HL4->Color = H_RGB2;
        MA_LP_HL4->Font->Color = H_RGB1;
        MA_LP_HL5->Color = H_RGB2;
        MA_LP_HL5->Font->Color = H_RGB1;
        MA_LP_HL6->Color = H_RGB2;
        MA_LP_HL6->Font->Color = H_RGB1;
        MA_LP_HL7->Color = H_RGB2;
        MA_LP_HL7->Font->Color = H_RGB1;

        MA_B2H->Brush->Color = H_RGB2;
        MA_B2H2->Brush->Color = H_RGB2;
        MA_B2H3->Brush->Color = H_RGB2;
        MA_B2H4->Brush->Color = H_RGB2;
        MA_B2H5->Brush->Color = H_RGB2;
        MA_B2H6->Brush->Color = H_RGB2;
        MA_B2H7->Brush->Color = H_RGB2;

        MA_TD_L->Color = D_RGB2;
        MA_TD_L->Font->Color = D_RGB1;
        MA_SD_L->Color = D_RGB2;
        MA_SD_L->Font->Color = D_RGB1;
        MA_TH_L->Color = H_RGB2;
        MA_TH_L->Font->Color = H_RGB1;
        MA_SH_L->Color = H_RGB2;
        MA_SH_L->Font->Color = H_RGB1;
        MA_SkoreListD->Color = D_RGB2;
        MA_SkoreListD->Font->Color = D_RGB1;
        MA_SkoreListH->Color = H_RGB2;
        MA_SkoreListH->Font->Color = H_RGB1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Draw()
{
        MA_TD_L->Caption = tymy[d]->getNazevTymu();
        MA_TH_L->Caption = tymy[h]->getNazevTymu();
        MA_LogoD->Picture->LoadFromFile("teams/"+tymy[d]->getLogo());
        MA_LogoH->Picture->LoadFromFile("teams/"+tymy[h]->getLogo());
        MA_iHall->Picture->LoadFromFile("teams/"+tymy[d]->getHala());
        MA_Hall->Caption = tymy[d]->getNazevHaly();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setLineup(int iTeam)
{
        int iGolman1 = 1;
        int iObrana1 = 2;
        int iObrana2 = 2;
        int iUtok1 = 3;
        int iUtok2 = 3;

        for(int i = 0; i < tymy[iTeam]->getPocetHracu(); i ++) {
                tymy[iTeam]->Hraci[i]->setSestava(5);
        }

        tymy[iTeam]->setridHrace('A', false);

        for(int i = 0; i < tymy[iTeam]->getPocetHracu(); i ++){
                if(tymy[iTeam]->Hraci[i]->getPost() == 'G' && iGolman1 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(1);
                        iGolman1 --;
                }
                if(tymy[iTeam]->Hraci[i]->getPost() == 'O' && iObrana1 != 0){
                        if(tymy[iTeam]->Hraci[i]->getEnergie() > 70) {
                                tymy[iTeam]->Hraci[i]->setSestava(1);
                                iObrana1 --;
                        }
                }
                if(tymy[iTeam]->Hraci[i]->getPost() == 'U' && iUtok1 != 0){
                        if(tymy[iTeam]->Hraci[i]->getEnergie() > 70) {
                                tymy[iTeam]->Hraci[i]->setSestava(1);
                                iUtok1 --;
                        }
                }
        }

        for(int i = 0; i < tymy[iTeam]->getPocetHracu(); i ++){
                if(tymy[iTeam]->Hraci[i]->getPost() == 'O' && tymy[iTeam]->Hraci[i]->getSestava() == 5 && iObrana2 != 0){
                        if(tymy[iTeam]->Hraci[i]->getEnergie() > 70) {
                                tymy[iTeam]->Hraci[i]->setSestava(2);
                                iObrana2 --;
                        }
                }
                if(tymy[iTeam]->Hraci[i]->getPost() == 'U' && tymy[iTeam]->Hraci[i]->getSestava() == 5 && iUtok1 == 0 && iUtok2 != 0){
                        if(tymy[iTeam]->Hraci[i]->getEnergie() > 70) {
                                tymy[iTeam]->Hraci[i]->setSestava(2);
                                iUtok2 --;
                        }
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

        Match[0]->Akce();
        Match[1]->Akce();
        Match[2]->Akce();
        Match[3]->Akce();
        Match[4]->Akce();
        Match[5]->Akce();

        //------Others------------------
        if(Match[0]->getGoal() == 0 || Match[0]->getGoal() == 1){
                MA_O1->Caption = Match[0]->Tymy[0]->getNazevTymuKr() + " - " + Match[0]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[0]->getGolyD()) + ":" + IntToStr(Match[0]->getGolyH());
        }
        if(Match[1]->getGoal() == 0 || Match[1]->getGoal() == 1){
                MA_O2->Caption = Match[1]->Tymy[0]->getNazevTymuKr() + " - " + Match[1]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[1]->getGolyD()) + ":" + IntToStr(Match[1]->getGolyH());
        }

        if(Match[2]->getGoal() == 0 || Match[2]->getGoal() == 1){
                MA_O3->Caption = Match[2]->Tymy[0]->getNazevTymuKr() + " - " + Match[2]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[2]->getGolyD()) + ":" + IntToStr(Match[2]->getGolyH());
        }

        if(Match[3]->getGoal() == 0 || Match[3]->getGoal() == 1){
                MA_O4->Caption = Match[3]->Tymy[0]->getNazevTymuKr() + " - " + Match[3]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[3]->getGolyD()) + ":" + IntToStr(Match[3]->getGolyH());
        }

        if(Match[4]->getGoal() == 0 || Match[4]->getGoal() == 1){
                MA_O5->Caption = Match[4]->Tymy[0]->getNazevTymuKr() + " - " + Match[4]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[4]->getGolyD()) + ":" + IntToStr(Match[4]->getGolyH());
        }

        if(Match[5]->getGoal() == 0 || Match[5]->getGoal() == 1){
                MA_O6->Caption = Match[5]->Tymy[0]->getNazevTymuKr() + " - " + Match[5]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[5]->getGolyD()) + ":" + IntToStr(Match[5]->getGolyH());
        }
        //------------------------------

        if(Match[iMatchIndex]->getGoal() == 0){
                char j[10];
                String ss = IntToStr(Match[iMatchIndex]->getCount()/2) + ".min.: ";
                ss += IntToStr(Match[iMatchIndex]->Tymy[0]->Hraci[Match[iMatchIndex]->getStrelec()]->getCislo()) + " ";
                ss += Match[iMatchIndex]->Tymy[0]->Hraci[Match[iMatchIndex]->getStrelec()]->getPrijmeni() + " ( ";
                ss += IntToStr(Match[iMatchIndex]->Tymy[0]->Hraci[Match[iMatchIndex]->getAsistent()]->getCislo()) + " ";
                ss += Match[iMatchIndex]->Tymy[0]->Hraci[Match[iMatchIndex]->getAsistent()]->getPrijmeni() + " )";
                MA_SkoreListD->Lines->Add(ss);
                Match[iMatchIndex]->setGoal(3);
        }
        if(Match[iMatchIndex]->getGoal() == 1){
                String ss = IntToStr(Match[iMatchIndex]->getCount()/2) + ".min.: ";
                ss += IntToStr(Match[iMatchIndex]->Tymy[1]->Hraci[Match[iMatchIndex]->getStrelec()]->getCislo()) + " ";
                ss += Match[iMatchIndex]->Tymy[1]->Hraci[Match[iMatchIndex]->getStrelec()]->getPrijmeni() + " ( ";
                ss += IntToStr(Match[iMatchIndex]->Tymy[1]->Hraci[Match[iMatchIndex]->getAsistent()]->getCislo()) + " ";
                ss += Match[iMatchIndex]->Tymy[1]->Hraci[Match[iMatchIndex]->getAsistent()]->getPrijmeni() + " ) ";
                MA_SkoreListH->Lines->Add(ss);
                Match[iMatchIndex]->setGoal(3);
        }

        String ss = Match[iMatchIndex]->getMinuta();
        ss += ". minuta";
        MA_Cas->Caption = ss;
        MA_SkoreD->Caption = Match[iMatchIndex]->getGolyD();
        MA_SkoreH->Caption = Match[iMatchIndex]->getGolyH();
        MA_StrelyD->Caption = Match[iMatchIndex]->getStrelyD();
        MA_StrelyH->Caption = Match[iMatchIndex]->getStrelyH();

        if(Match[iMatchIndex]->getCount() == 120){
                Timer1->Enabled = false;
                MA_LButton1->Caption = "Pokra�uj";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MA_LButton1Click(TObject *Sender)
{
        if(Match[0]->getCount() != 120){
                if(Timer1->Enabled == true)
                        Timer1->Enabled = false;
                else
                        Timer1->Enabled = true;
        }
        else{
                for(int j = 0; j < 6; j ++) {
                        if(Match[j]->getGolyD() == Match[j]->getGolyH()) {
                                Match[j]->Tymy[0]->setBodyL(Match[j]->Tymy[0]->getBodyL() + 1);
                                Match[j]->Tymy[1]->setBodyL(Match[j]->Tymy[1]->getBodyL() + 1);
                                Match[j]->Tymy[0]->setRemizyL(Match[j]->Tymy[0]->getRemizyL() + 1);
                                Match[j]->Tymy[1]->setRemizyL(Match[j]->Tymy[1]->getRemizyL() + 1);
                        } else if(Match[j]->getGolyD() > Match[j]->getGolyH()) {
                                Match[j]->Tymy[0]->setBodyL(Match[j]->Tymy[0]->getBodyL() + 3);
                                Match[j]->Tymy[0]->setVyhryL(Match[j]->Tymy[0]->getVyhryL() + 1);
                                Match[j]->Tymy[1]->setProhryL(Match[j]->Tymy[1]->getProhryL() + 1);
                        } else if(Match[j]->getGolyD() < Match[j]->getGolyH()) {
                                Match[j]->Tymy[1]->setBodyL(Match[j]->Tymy[1]->getBodyL() + 3);
                                Match[j]->Tymy[1]->setVyhryL(Match[j]->Tymy[1]->getVyhryL() + 1);
                                Match[j]->Tymy[0]->setProhryL(Match[j]->Tymy[0]->getProhryL() + 1);
                        }
                        Match[j]->Tymy[0]->setDaneGL(Match[j]->Tymy[0]->getDaneGL() + Match[j]->getGolyD());
                        Match[j]->Tymy[0]->setObdrzeneGL(Match[j]->Tymy[0]->getObdrzeneGL() + Match[j]->getGolyH());
                        Match[j]->Tymy[0]->setDaneSL(Match[j]->Tymy[0]->getDaneSL() + Match[j]->getStrelyD());
                        Match[j]->Tymy[0]->setObdrzeneSL(Match[j]->Tymy[0]->getObdrzeneSL() + Match[j]->getStrelyH());
                        Match[j]->Tymy[1]->setDaneGL(Match[j]->Tymy[1]->getDaneGL() + Match[j]->getGolyH());     
                        Match[j]->Tymy[1]->setObdrzeneGL(Match[j]->Tymy[1]->getObdrzeneGL() + Match[j]->getGolyD());
                        Match[j]->Tymy[1]->setDaneSL(Match[j]->Tymy[1]->getDaneSL() + Match[j]->getStrelyH());
                        Match[j]->Tymy[1]->setObdrzeneSL(Match[j]->Tymy[1]->getObdrzeneSL() + Match[j]->getStrelyD());
                        for(int i = 0; i < Match[j]->Tymy[0]->getPocetLajn() * 5 + 1; i ++){
                                Match[j]->Tymy[0]->Hraci[i]->setZapasyL(Match[j]->Tymy[0]->Hraci[i]->getZapasyL() + 1);
                        }

                        for(int i = 0; i < Match[j]->Tymy[1]->getPocetLajn() * 5 + 1; i ++){
                                Match[j]->Tymy[1]->Hraci[i]->setZapasyL(Match[j]->Tymy[1]->Hraci[i]->getZapasyL() + 1);
                        }
                }
                MA_SkoreListD->Clear();
                MA_SkoreListH->Clear();

                MA->Visible = false;
                HO->Visible = true;

                HO_B_Game->Enabled = false;
                HO_B_NextWeek->Enabled = true;
                if(AktKolo > 4) HO_B_NextWeek->Enabled = false;
                HO_B_Table->Enabled = true;

                int limit = 0;
                for(int i = 0; i < 12; i ++) {
                        for(int j = 0; j < tymy[i]->getPocetHracu(); j ++) {
                                limit = tymy[i]->Hraci[j]->getVek() * 5 * tymy[i]->Hraci[j]->getFS() * tymy[i]->Hraci[j]->getFS() / 1000;
                                if(tymy[i]->Hraci[j]->getFSpom() >= limit) {
                                        if(tymy[i]->Hraci[j]->getFS() > 100)
                                                tymy[i]->Hraci[j]->setFS(tymy[i]->Hraci[j]->getFS() + 1);
                                        tymy[i]->Hraci[j]->setFSpom(tymy[i]->Hraci[j]->getFSpom() - limit);
                                }
                                limit = tymy[i]->Hraci[j]->getVek() * 30 * tymy[i]->Hraci[j]->getTS() / 100;
                                if(tymy[i]->Hraci[j]->getTSpom() >= limit) {
                                        if(tymy[i]->Hraci[j]->getTS() > 100)
                                                tymy[i]->Hraci[j]->setTS(tymy[i]->Hraci[j]->getTS() + 1);
                                        tymy[i]->Hraci[j]->setTSpom(tymy[i]->Hraci[j]->getTSpom() - limit);
                                }
                                limit = tymy[i]->Hraci[j]->getVek() * 10;
                                if(tymy[i]->Hraci[j]->getZSpom() >= limit) {
                                        if(tymy[i]->Hraci[j]->getZS() > 100)
                                                tymy[i]->Hraci[j]->setZS(tymy[i]->Hraci[j]->getZS() + 1);
                                        tymy[i]->Hraci[j]->setZSpom(tymy[i]->Hraci[j]->getZSpom() - limit);
                                }
                        }
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MA_SD_LClick(TObject *Sender)
{
        if(MA_LP_D->Visible == false){
                String s1, s2, s3, s4, s5, s6, s7;
                for(int i = 0; i < tymy[d]->getPocetLajn() * 5 + 1; i ++){
                        s1 += "\n";
                        s1 += tymy[d]->Hraci[i]->getCislo();
                        s2 += "\n";
                        s2 += tymy[d]->Hraci[i]->getPrijmeni();
                        s3 += "\n";
                        s3 += tymy[d]->Hraci[i]->getFS();
                        s4 += "\n";
                        s4 += tymy[d]->Hraci[i]->getTS();
                        s5 += "\n";
                        s5 += tymy[d]->Hraci[i]->getZS();
                        s6 += "\n";
                        s6 += tymy[d]->Hraci[i]->getEnergie();
                        s7 += "\n";
                        s7 += tymy[d]->Hraci[i]->getSestava();
                }
                MA_LP_DL1->Caption = s1;
                MA_LP_DL2->Caption = s2;
                MA_LP_DL3->Caption = s3;
                MA_LP_DL4->Caption = s4;
                MA_LP_DL5->Caption = s5;
                MA_LP_DL6->Caption = s6;
                MA_LP_DL7->Caption = s7;
                MA_LP_D->Visible = true;
        }
        else{
                MA_LP_D->Visible = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MA_SH_LClick(TObject *Sender)
{
        if(MA_LP_H->Visible == false){
                String s1, s2, s3, s4, s5, s6, s7;
                for(int i = 0; i < tymy[h]->getPocetLajn() * 5 + 1; i ++){
                        s1 += "\n";
                        s1 += tymy[h]->Hraci[i]->getCislo();
                        s2 += "\n";
                        s2 += tymy[h]->Hraci[i]->getPrijmeni();
                        s3 += "\n";
                        s3 += tymy[h]->Hraci[i]->getFS();
                        s4 += "\n";
                        s4 += tymy[h]->Hraci[i]->getTS();
                        s5 += "\n";
                        s5 += tymy[h]->Hraci[i]->getZS();
                        s6 += "\n";
                        s6 += tymy[h]->Hraci[i]->getEnergie();
                        s7 += "\n";
                        s7 += tymy[h]->Hraci[i]->getSestava();
                }
                MA_LP_HL1->Caption = s1;
                MA_LP_HL2->Caption = s2;
                MA_LP_HL3->Caption = s3;
                MA_LP_HL4->Caption = s4;
                MA_LP_HL5->Caption = s5;
                MA_LP_HL6->Caption = s6;
                MA_LP_HL7->Caption = s7;
                MA_LP_H->Visible = true;
        }
        else{
                MA_LP_H->Visible = false;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::HO_B_LineUpClick(TObject *Sender)
{
        HO->Visible = false;
        MA->Visible = false;
        TE->Visible = true;
        TE_CB_Teams->Clear();
        for(int i = 0; i < 12; i ++) {
                TE_CB_Teams->AddItem(tymy[i]->getNazevTymu(), this);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setColorsLP()
{
        TColor RGB1;
        TColor RGB2;

        RGB1 = RGB(tymy[t]->getR1(), tymy[t]->getG1(), tymy[t]->getB1());
        RGB2 = RGB(tymy[t]->getR2(), tymy[t]->getG2(), tymy[t]->getB2());

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
        En = tymy[t]->Hraci[0]->getEnergie();

        if(tymy[t]->Hraci[0]->getSestava() == 5)
                Line = "N";
        else
                Line = tymy[t]->Hraci[0]->getSestava();

        for(int i = 1; i < tymy[t]->getPocetHracu(); i ++){
                Post += "\n";
                Post += tymy[t]->Hraci[i]->getPost();

                Cislo += "\n";
                Cislo += tymy[t]->Hraci[i]->getCislo();

                Jmeno += "\n";
                Jmeno += tymy[t]->Hraci[i]->getJmeno() + " " + tymy[t]->Hraci[i]->getPrijmeni();

                Vek += "\n";
                Vek += tymy[t]->Hraci[i]->getVek();

                FS += "\n";
                FS += tymy[t]->Hraci[i]->getFS();

                TS += "\n";
                TS += tymy[t]->Hraci[i]->getTS();

                ZS += "\n";
                ZS += tymy[t]->Hraci[i]->getZS();

                ZapL += "\n";
                ZapL += tymy[t]->Hraci[i]->getZapasyL();

                GolL += "\n";
                GolL += tymy[t]->Hraci[i]->getGolyL();

                AsiL += "\n";
                AsiL += tymy[t]->Hraci[i]->getAsistenceL();

                En += "\n";
                En += tymy[t]->Hraci[i]->getEnergie();

                Line += "\n";
                if(tymy[t]->Hraci[i]->getSestava() == 5)
                        Line += "N";
                else
                        Line += tymy[t]->Hraci[i]->getSestava();
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

        LP_Name->Caption = tymy[t]->getNazevTymu();
        LP_Hall->Caption = tymy[t]->getNazevHaly();
        LP_Capacity->Caption = tymy[t]->getKapacitaHaly();
        LP_Logo->Picture->LoadFromFile("teams/" + tymy[t]->getLogo());
        LP_iHall->Picture->LoadFromFile("teams/" + tymy[t]->getHala());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TE_B_SelectClick(TObject *Sender)
{
        if(TE_CB_Teams->ItemIndex != -1) {
                TE->Visible = false;
                t = TE_CB_Teams->ItemIndex;
                LP->Visible = true;
                tymy[t]->setridHrace('P', true);
                setColorsLP();
                setPlayersLP();

                String sLP;
                for(int i = 0; i < tymy[t]->getPocetHracu(); i ++){
                        sLP = tymy[t]->Hraci[i]->getCislo();
                        sLP +=  " ";
                        sLP += tymy[t]->Hraci[i]->getPrijmeni();
                        if(t == Manager->getKlub()) LP_CB_Players->Items->Add(sLP);
                        else LP_Buy->Items->Add(sLP);
                }
                if(t == Manager->getKlub()) { // Dodelat zobrazeni!!! a prepsat pro "Muj tym"
                        LP_B5->Visible = false;
                        LP_Buy->Visible = false;
                        LP_B_Buy->Visible = false;
                        LP_B_Loan->Visible = false;
                        LP_iHall->Visible = false;
                        LP_Capacity->Visible = false;
                        LP_lCapacity->Visible = false;
                        LP_Hall->Visible = false;
                        LP_B1->Height = 209;
                        LP_B6->Visible = true;
                        LP_CB_TrainingIntensity->ItemIndex = 10 * tymy[Manager->getKlub()]->getTrainingIntensity();
                        LP_CB_Training->ItemIndex = tymy[Manager->getKlub()]->getTraining();
                } else {
                        LP_B5->Visible = true;
                        LP_Buy->Visible = true;
                        LP_B_Buy->Visible = true;
                        LP_B_Loan->Visible = true;
                        LP_iHall->Visible = true;
                        LP_Capacity->Visible = true;
                        LP_lCapacity->Visible = true;
                        LP_Hall->Visible = true;
                        LP_B1->Height = 429;
                        LP_B6->Visible = false;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TE_B_HomeClick(TObject *Sender)
{
        TE->Visible = false;
        HO->Visible = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::QuitClick(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_P_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('P', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_C_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('C', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_J_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('J', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_V_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('V', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_F_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('F', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_T_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('T', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Z_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('Z', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_L_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('L', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::inicializujDalsiKolo()
{
        for(int i = 0; i < 6; i ++) {
                Match[i] = new Zapas(*tymy[RozpisLigy[AktKolo][0][i]], *tymy[RozpisLigy[AktKolo][1][i]], 1);
        }
        
       for(int i = 0; i < 6; i ++) {
                if(RozpisLigy[AktKolo][0][i] == Manager->getKlub() || RozpisLigy[AktKolo][1][i] == Manager->getKlub()) {
                        d = RozpisLigy[AktKolo][0][i];
                        h = RozpisLigy[AktKolo][1][i];
                        iMatchIndex = i;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rozpisLigy()
{
        RozpisLigy[0][0][0] = 0;
        RozpisLigy[0][0][1] = 1;
        RozpisLigy[0][0][2] = 2;
        RozpisLigy[0][0][3] = 3;
        RozpisLigy[0][0][4] = 4;
        RozpisLigy[0][0][5] = 5;

        RozpisLigy[0][1][0] = 6;
        RozpisLigy[0][1][1] = 7;
        RozpisLigy[0][1][2] = 8;
        RozpisLigy[0][1][3] = 9;
        RozpisLigy[0][1][4] = 10;
        RozpisLigy[0][1][5] = 11;


        RozpisLigy[1][0][0] = 0;
        RozpisLigy[1][0][1] = 1;
        RozpisLigy[1][0][2] = 2;
        RozpisLigy[1][0][3] = 3;
        RozpisLigy[1][0][4] = 4;
        RozpisLigy[1][0][5] = 5;

        RozpisLigy[1][1][0] = 7;
        RozpisLigy[1][1][1] = 8;
        RozpisLigy[1][1][2] = 9;
        RozpisLigy[1][1][3] = 10;
        RozpisLigy[1][1][4] = 11;
        RozpisLigy[1][1][5] = 6;


        RozpisLigy[2][0][0] = 0;
        RozpisLigy[2][0][1] = 1;
        RozpisLigy[2][0][2] = 2;
        RozpisLigy[2][0][3] = 3;
        RozpisLigy[2][0][4] = 4;
        RozpisLigy[2][0][5] = 5;

        RozpisLigy[2][1][0] = 8;
        RozpisLigy[2][1][1] = 9;
        RozpisLigy[2][1][2] = 10;
        RozpisLigy[2][1][3] = 11;
        RozpisLigy[2][1][4] = 6;
        RozpisLigy[2][1][5] = 7;


        RozpisLigy[3][0][0] = 0;
        RozpisLigy[3][0][1] = 1;
        RozpisLigy[3][0][2] = 2;
        RozpisLigy[3][0][3] = 3;
        RozpisLigy[3][0][4] = 4;
        RozpisLigy[3][0][5] = 5;

        RozpisLigy[3][1][0] = 9;
        RozpisLigy[3][1][1] = 10;
        RozpisLigy[3][1][2] = 11;
        RozpisLigy[3][1][3] = 6;
        RozpisLigy[3][1][4] = 7;
        RozpisLigy[3][1][5] = 8;


        RozpisLigy[4][0][0] = 0;
        RozpisLigy[4][0][1] = 1;
        RozpisLigy[4][0][2] = 2;
        RozpisLigy[4][0][3] = 3;
        RozpisLigy[4][0][4] = 4;
        RozpisLigy[4][0][5] = 5;

        RozpisLigy[4][1][0] = 10;
        RozpisLigy[4][1][1] = 11;
        RozpisLigy[4][1][2] = 6;
        RozpisLigy[4][1][3] = 7;
        RozpisLigy[4][1][4] = 8;
        RozpisLigy[4][1][5] = 9;


        RozpisLigy[5][0][0] = 0;
        RozpisLigy[5][0][1] = 1;
        RozpisLigy[5][0][2] = 2;
        RozpisLigy[5][0][3] = 3;
        RozpisLigy[5][0][4] = 4;
        RozpisLigy[5][0][5] = 5;

        RozpisLigy[5][1][0] = 11;
        RozpisLigy[5][1][1] = 6;
        RozpisLigy[5][1][2] = 7;
        RozpisLigy[5][1][3] = 8;
        RozpisLigy[5][1][4] = 9;
        RozpisLigy[5][1][5] = 10;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::HO_B_NextWeekClick(TObject *Sender)
{
        nextDay();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HO_B_TableClick(TObject *Sender)
{
        HO->Visible = false;
        TA->Visible = true;

        String position, name, matches, wins, draws, loses, scoreH, scoreA, shootsH, shootsA, points;

        position = name = matches = wins = draws = loses = scoreH = scoreA = shootsH = shootsA = points = "";

        setUmisteni();

        for(int i = 1; i <= 12; i ++) {
                for(int j = 0; j < 12; j ++) {
                        if(tymy[j]->getUmisteni() == i) {
                                if(tymy[j]->getUmisteni() != 1) {
                                        position += "\n";
                                        name += "\n";
                                        matches += "\n";
                                        wins += "\n";
                                        draws += "\n";
                                        loses += "\n";
                                        scoreH += "\n";
                                        scoreA += "\n";
                                        shootsH += "\n";
                                        shootsA += "\n";
                                        points += "\n";
                                }
                                position += tymy[j]->getUmisteni();
                                name += tymy[j]->getNazevTymu();
                                matches += tymy[j]->getZapasyL();
                                wins += tymy[j]->getVyhryL();
                                draws += tymy[j]->getRemizyL();
                                loses += tymy[j]->getProhryL();
                                scoreH += tymy[j]->getDaneGL();
                                scoreA += tymy[j]->getObdrzeneGL();
                                shootsH += tymy[j]->getDaneSL();
                                shootsA += tymy[j]->getObdrzeneSL();
                                points += tymy[j]->getBodyL();
                        }
                }
        }

        TA_L_Position->Caption = position;
        TA_L_Name->Caption = name;
        TA_L_Matches->Caption = matches;
        TA_L_Wins->Caption = wins;
        TA_L_Draws->Caption = draws;
        TA_L_Loses->Caption = loses;
        TA_L_ScoreA->Caption = scoreA;
        TA_L_ScoreH->Caption = scoreH;
        TA_L_ShootsH->Caption = shootsH;
        TA_L_ShootsA->Caption = shootsA;
        TA_L_Points->Caption = points;

        String lrd, lrds, lrhs, lrh, nrd, nrds, nrhs, nrh;
        lrd = lrds = lrhs = lrh = nrd = nrh = "";

        for(int i = 0; i < 6; i ++) {
                if(i != 0) {
                        lrd += "\n";
                        lrds += "\n";
                        lrhs += "\n";
                        lrh += "\n";
                        nrd += "\n";
                        nrh += "\n";
                }
                if(AktKolo != 0) {
                        lrd += Match[i]->Tymy[0]->getNazevTymu();
                        lrds += Match[i]->getGolyD();
                        lrhs += Match[i]->getGolyH();
                        lrh += Match[i]->Tymy[1]->getNazevTymu();
                }
                nrd += tymy[RozpisLigy[AktKolo + 1][0][i]]->getNazevTymu();
                nrh += tymy[RozpisLigy[AktKolo + 1][1][i]]->getNazevTymu();
        }
        TA_L_LR_D->Caption = lrd;
        TA_L_LR_DS->Caption = lrds;
        TA_L_LR_HS->Caption = lrhs;
        TA_L_LR_H->Caption = lrh;
        TA_L_NR_D->Caption = nrd;
        TA_L_NR_H->Caption = nrh;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TA_B_BackClick(TObject *Sender)
{
        TA->Visible = false;
        HO->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::setUmisteni()
{
        int iPole[12][2];
        for(int i = 0; i < 12; i ++) {
                iPole[i][0] = tymy[i]->getBodyL();
                iPole[i][1] = i;
                tymy[i]->setUmisteni(12);
        }

        for(int i = 11; i >= 0; i --) {
                for(int j = 11; j >= 0; j --) {
                        if(iPole[j][0] > iPole[i][0]) {
                                int policko[2];
                                policko[0] = iPole[i][0];
                                policko[1] = iPole[i][1];
                                iPole[i][0] = iPole[j][0];
                                iPole[i][1] = iPole[j][1];
                                iPole[j][0] = policko[0];
                                iPole[j][1] = policko[1];
                        } else if(iPole[j][0] == iPole[i][0]) {
                                if((tymy[iPole[j][1]]->getDaneGL() - tymy[iPole[j][1]]->getObdrzeneGL()) > (tymy[iPole[i][1]]->getDaneGL() - tymy[iPole[i][1]]->getObdrzeneGL())) {
                                        int policko[2];
                                        policko[0] = iPole[i][0];
                                        policko[1] = iPole[i][1];
                                        iPole[i][0] = iPole[j][0];
                                        iPole[i][1] = iPole[j][1];
                                        iPole[j][0] = policko[0];
                                        iPole[j][1] = policko[1];
                                }
                        }
                }
        }

        for(int i = 0; i < 12; i ++) {
                tymy[iPole[i][1]]->setUmisteni(i + 1);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HO_B_SetFormationClick(TObject *Sender)
{
        HO->Visible = false;
        SF->Visible = true;
        setColorsSF();
        setPlayersSF();
        setComboBoxesSF();
}
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

        RGB1 = RGB(tymy[Manager->getKlub()]->getR1(), tymy[Manager->getKlub()]->getG1(), tymy[Manager->getKlub()]->getB1());
        RGB2 = RGB(tymy[Manager->getKlub()]->getR2(), tymy[Manager->getKlub()]->getG2(), tymy[Manager->getKlub()]->getB2());

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

        for(int i = 0; i < tymy[Manager->getKlub()]->getPocetHracu(); i ++) {
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
                post += tymy[Manager->getKlub()]->Hraci[i]->getPost();
                number += tymy[Manager->getKlub()]->Hraci[i]->getCislo();
                name += tymy[Manager->getKlub()]->Hraci[i]->getJmeno() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni();
                age += tymy[Manager->getKlub()]->Hraci[i]->getVek();
                fs += tymy[Manager->getKlub()]->Hraci[i]->getFS();
                ts += tymy[Manager->getKlub()]->Hraci[i]->getTS();
                zs += tymy[Manager->getKlub()]->Hraci[i]->getZS();
                if(tymy[Manager->getKlub()]->Hraci[i]->getSestava() == 5)
                        line += "N";
                else
                        line += tymy[Manager->getKlub()]->Hraci[i]->getSestava();
                energy += tymy[Manager->getKlub()]->Hraci[i]->getEnergie();
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
        SF_CB_Lines->ItemIndex = tymy[Manager->getKlub()]->getPocetLajn() - 2;

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

        if(tymy[Manager->getKlub()]->getPocetLajn() == 2) {
                SF_CB_3Att1->Visible = false;
                SF_CB_3Att2->Visible = false;
                SF_CB_3Att3->Visible = false;
                SF_CB_3Def1->Visible = false;
                SF_CB_3Def2->Visible = false;
        } else if(tymy[Manager->getKlub()]->getPocetLajn() == 3) {
                SF_CB_3Att1->Visible = true;
                SF_CB_3Att2->Visible = true;
                SF_CB_3Att3->Visible = true;
                SF_CB_3Def1->Visible = true;
                SF_CB_3Def2->Visible = true;
        }

        int utocniku = 0;
        int obrancu = 0;
        int golmanu = 0;

        for(int i = 0; i < tymy[Manager->getKlub()]->getPocetHracu(); i ++) {
                if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'G') golmanu ++;
                else if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'O') obrancu ++;
                else if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'U') utocniku ++;
        }

        tymy[Manager->getKlub()]->setridHrace('P', true);

        for(int i = 0; i < tymy[Manager->getKlub()]->getPocetHracu(); i ++) {
                if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'G')
                        SF_CB_1Goa1->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                else {
                        SF_CB_1Def1->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_1Def2->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Def1->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Def2->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Def1->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Def2->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_1Att1->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_1Att2->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_1Att3->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Att1->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Att2->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_2Att3->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Att1->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Att2->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                        SF_CB_3Att3->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
                }
        }

        tymy[Manager->getKlub()]->setridHrace('P', true);

        int iPom = 0;
        for(int i = 0; i < tymy[Manager->getKlub()]->getPocetHracu(); i ++) {
                if(tymy[Manager->getKlub()]->Hraci[i]->getSestava() == 1) {
                        if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'G') {
                                SF_CB_1Goa1->ItemIndex = i;
                        } else if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'O') {
                                if(iPom == 0) {
                                        SF_CB_1Def1->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else {
                                        SF_CB_1Def2->ItemIndex = i - golmanu;
                                        iPom = 0;
                                }
                        } else if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'U') {
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
                } else if(tymy[Manager->getKlub()]->Hraci[i]->getSestava() == 2) {
                        if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'O') {
                                if(iPom == 0) {
                                        SF_CB_2Def1->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else {
                                        SF_CB_2Def2->ItemIndex = i - golmanu;
                                        iPom = 0;
                                }
                        } else if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'U') {
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
        } for(int i = 0; i < tymy[Manager->getKlub()]->getPocetHracu(); i ++) {
                if(tymy[Manager->getKlub()]->Hraci[i]->getSestava() == 3) {
                        if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'O') {
                                if(iPom == 0) {
                                        SF_CB_3Def1->ItemIndex = i - golmanu;
                                        iPom ++;
                                } else {
                                        SF_CB_3Def2->ItemIndex = i - golmanu;
                                        iPom = 0;
                                }
                        } else if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'U') {
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
                tymy[Manager->getKlub()]->setridHrace('P', true);

                for(int i = 0; i < tymy[Manager->getKlub()]->getPocetHracu(); i ++) {
                        tymy[Manager->getKlub()]->Hraci[i]->setSestava(5);
                }

                int utocniku = 0;
                int obrancu = 0;
                int golmanu = 0;

                for(int i = 0; i < tymy[Manager->getKlub()]->getPocetHracu(); i ++) {
                        if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'G') golmanu ++;
                        else if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'O') obrancu ++;
                        else if(tymy[Manager->getKlub()]->Hraci[i]->getPost() == 'U') utocniku ++;
                }

                tymy[Manager->getKlub()]->setPocetLajn(SF_CB_Lines->ItemIndex + 2);

                tymy[Manager->getKlub()]->Hraci[SF_CB_1Goa1->ItemIndex]->setSestava(1);
                tymy[Manager->getKlub()]->Hraci[SF_CB_1Def1->ItemIndex + golmanu]->setSestava(1);
                tymy[Manager->getKlub()]->Hraci[SF_CB_1Def2->ItemIndex + golmanu]->setSestava(1);
                tymy[Manager->getKlub()]->Hraci[SF_CB_2Def1->ItemIndex + golmanu]->setSestava(2);
                tymy[Manager->getKlub()]->Hraci[SF_CB_2Def2->ItemIndex + golmanu]->setSestava(2);
                tymy[Manager->getKlub()]->Hraci[SF_CB_1Att1->ItemIndex + golmanu]->setSestava(1);
                tymy[Manager->getKlub()]->Hraci[SF_CB_1Att2->ItemIndex + golmanu]->setSestava(1);
                tymy[Manager->getKlub()]->Hraci[SF_CB_1Att3->ItemIndex + golmanu]->setSestava(1);
                tymy[Manager->getKlub()]->Hraci[SF_CB_2Att1->ItemIndex + golmanu]->setSestava(2);
                tymy[Manager->getKlub()]->Hraci[SF_CB_2Att2->ItemIndex + golmanu]->setSestava(2);
                tymy[Manager->getKlub()]->Hraci[SF_CB_2Att3->ItemIndex + golmanu]->setSestava(2);

                if(SF_CB_Lines->ItemIndex == 1) {
                        tymy[Manager->getKlub()]->Hraci[SF_CB_3Def1->ItemIndex + golmanu]->setSestava(3);
                        tymy[Manager->getKlub()]->Hraci[SF_CB_3Def2->ItemIndex + golmanu]->setSestava(3);
                        tymy[Manager->getKlub()]->Hraci[SF_CB_3Att1->ItemIndex + golmanu]->setSestava(3);
                        tymy[Manager->getKlub()]->Hraci[SF_CB_3Att2->ItemIndex + golmanu]->setSestava(3);
                        tymy[Manager->getKlub()]->Hraci[SF_CB_3Att3->ItemIndex + golmanu]->setSestava(3);
                }

                tymy[Manager->getKlub()]->setridHrace('L', true);

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
        tymy[Manager->getKlub()]->setridHrace('P', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NameHeadClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('J', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_AgeHeadClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('V', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_FSHeadClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('F', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_TSHeadClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('T', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_ZSHeadClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('Z', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_LineHeadClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('L', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_PostHeadDblClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('P', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NameHeadDblClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('J', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_AgeHeadDblClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('V', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_FSHeadDblClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('F', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_TSHeadDblClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('T', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_ZSHeadDblClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('Z', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_LineHeadDblClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('L', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LP_P_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('P', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_C_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('C', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_J_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('J', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_V_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('V', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_F_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('F', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_T_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('T', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Z_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('Z', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_L_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('L', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NumberHeadClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('C', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_NumberHeadDblClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('C', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_EnHeadClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('E', true);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SF_L_EnHeadDblClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('E', false);

        setPlayersSF();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Gl_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('G', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Gl_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('G', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Al_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('H', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_Al_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('H', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_En_LClick(TObject *Sender)
{
        tymy[t]->setridHrace('E', true);

        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_En_LDblClick(TObject *Sender)
{
        tymy[t]->setridHrace('E', false);

        setPlayersLP();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::HO_B_GameClick(TObject *Sender)
{
        for(int i = 0; i < 12; i ++){
                if(i != Manager->getKlub())
                        setLineup(i);
                tymy[i]->setridHrace('P', true);
        }

        MA_LButton1->Caption = "PAUZA";
        inicializujDalsiKolo();

        Match[0]->Tymy[0]->setridHrace('L', true);
        Match[0]->Tymy[1]->setridHrace('L', true);

        Match[1]->Tymy[0]->setridHrace('L', true);
        Match[1]->Tymy[1]->setridHrace('L', true);

        Match[2]->Tymy[0]->setridHrace('L', true);
        Match[2]->Tymy[1]->setridHrace('L', true);

        Match[3]->Tymy[0]->setridHrace('L', true);
        Match[3]->Tymy[1]->setridHrace('L', true);

        Match[4]->Tymy[0]->setridHrace('L', true);
        Match[4]->Tymy[1]->setridHrace('L', true);

        Match[5]->Tymy[0]->setridHrace('L', true);
        Match[5]->Tymy[1]->setridHrace('L', true);

        MA_iNavsteva->Caption = Match[0]->getNavsteva();

        MA_O1->Caption = Match[1]->Tymy[0]->getNazevTymuKr() + " - " + Match[1]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[1]->getGolyD()) + ":" + IntToStr(Match[1]->getGolyH());
        MA_O2->Caption = Match[2]->Tymy[0]->getNazevTymuKr() + " - " + Match[2]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[2]->getGolyD()) + ":" + IntToStr(Match[2]->getGolyH());
        MA_O3->Caption = Match[3]->Tymy[0]->getNazevTymuKr() + " - " + Match[3]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[3]->getGolyD()) + ":" + IntToStr(Match[3]->getGolyH());
        MA_O4->Caption = Match[4]->Tymy[0]->getNazevTymuKr() + " - " + Match[4]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[4]->getGolyD()) + ":" + IntToStr(Match[4]->getGolyH());
        MA_O5->Caption = Match[5]->Tymy[0]->getNazevTymuKr() + " - " + Match[5]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[5]->getGolyD()) + ":" + IntToStr(Match[5]->getGolyH());

        D_R1 = tymy[d]->getR1();
        D_G1 = tymy[d]->getG1();
        D_B1 = tymy[d]->getB1();

        D_R2 = tymy[d]->getR2();
        D_G2 = tymy[d]->getG2();
        D_B2 = tymy[d]->getB2();

        H_R1 = tymy[h]->getR1();
        H_G1 = tymy[h]->getG1();
        H_B1 = tymy[h]->getB1();

        H_R2 = tymy[h]->getR2();
        H_G2 = tymy[h]->getG2();
        H_B2 = tymy[h]->getB2();

        setColors();

        Draw();

        HO->Visible = false;
        LP->Visible = false;
        Timer1->Enabled = true;
        MA->Visible = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZpetClick(TObject *Sender)
{
        LP_Buy->Clear();
        LP->Visible = false;
        if(t != Manager->getKlub()) TE->Visible = true;
        else HO->Visible = true;        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LP_B_BuyClick(TObject *Sender)
{
        if(tymy[Manager->getKlub()]->getPocetHracu() <= 30 && LP_Buy->ItemIndex != -1) {
                tymy[t]->setridHrace('P', true);
                tymy[Manager->getKlub()]->setridHrace('P', true);

                tymy[t]->Hraci[LP_Buy->ItemIndex]->setSestava(5);
                if(!tymy[Manager->getKlub()]->isFreeNumber(tymy[t]->Hraci[LP_Buy->ItemIndex]->getCislo())) {
                        for(int i = 101; i > 1; i --) {
                                if(tymy[Manager->getKlub()]->isFreeNumber(i)) {
                                        tymy[t]->Hraci[LP_Buy->ItemIndex]->setCislo(i);
                                }
                        }
                }
                tymy[Manager->getKlub()]->addPlayer(tymy[t]->Hraci[LP_Buy->ItemIndex]);
                tymy[t]->deletePlayerAt(LP_Buy->ItemIndex);

                tymy[t]->setridHrace('P', true);

                setPlayersLP();

                LP_Buy->Clear();
                String sLP;
                for(int i = 0; i < tymy[t]->getPocetHracu(); i ++){
                        sLP = tymy[t]->Hraci[i]->getCislo();
                        sLP +=  " ";
                        sLP += tymy[t]->Hraci[i]->getPrijmeni();
                        LP_Buy->Items->Add(sLP);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        tymy[Manager->getKlub()]->setridHrace('P', true);
        ComboBox1->Clear();
        for(int i = 0; i < tymy[Manager->getKlub()]->getPocetHracu(); i ++)
                ComboBox1->Items->Add((String)tymy[Manager->getKlub()]->Hraci[i]->getCislo() + " " + tymy[Manager->getKlub()]->Hraci[i]->getPrijmeni());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(ComboBox1->ItemIndex != -1) {
                if(!(tymy[Manager->getKlub()]->getCountOfGoalkeepers() == 1 && tymy[Manager->getKlub()]->Hraci[ComboBox1->ItemIndex]->getPost() == 'G') && tymy[Manager->getKlub()]->getPocetHracu() > 12) {
                        tymy[Manager->getKlub()]->setridHrace('P', true);
                        tymy[Manager->getKlub()]->deletePlayerAt(ComboBox1->ItemIndex);
                        Button2Click(Sender);
                }
        }
        //if(tymy[Manager->getKlub()]->getCountOfGoalkeepers() == 1)
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        HO->Visible = false;
        t = Manager->getKlub();
        LP->Visible = true;
        tymy[t]->setridHrace('P', true);
        setColorsLP();
        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        for(int i = 0; i < 12; i ++) {
                ComboBox2->Items->Add(tymy[i]->getNazevTymu());
        }
        Button4->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
        if(ComboBox2->ItemIndex != -1) {
                Manager->setKlub(ComboBox2->ItemIndex);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HO_B_TrainingClick(TObject *Sender)
{
        HO->Visible = false;
        TR->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TR_B_BackClick(TObject *Sender)
{
        TR->Visible = false;
        HO->Visible = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::LP_B_TrainingClick(TObject *Sender)
{
        tymy[Manager->getKlub()]->setTraining(LP_CB_Training->ItemIndex);
        switch(LP_CB_TrainingIntensity->ItemIndex) {
                case 0: tymy[Manager->getKlub()]->setTrainingIntensity(0); break;
                case 1: tymy[Manager->getKlub()]->setTrainingIntensity(0.1); break;
                case 2: tymy[Manager->getKlub()]->setTrainingIntensity(0.2); break;
                case 3: tymy[Manager->getKlub()]->setTrainingIntensity(0.3); break;
                case 4: tymy[Manager->getKlub()]->setTrainingIntensity(0.4); break;
                case 5: tymy[Manager->getKlub()]->setTrainingIntensity(0.5); break;
                case 6: tymy[Manager->getKlub()]->setTrainingIntensity(0.6); break;
                case 7: tymy[Manager->getKlub()]->setTrainingIntensity(0.7); break;
                case 8: tymy[Manager->getKlub()]->setTrainingIntensity(0.8); break;
                case 9: tymy[Manager->getKlub()]->setTrainingIntensity(0.9); break;
                case 10: tymy[Manager->getKlub()]->setTrainingIntensity(1); break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LP_B_KickClick(TObject *Sender)
{
        if(LP_CB_Players->ItemIndex != -1) {
                if(!(tymy[Manager->getKlub()]->getCountOfGoalkeepers() == 1 && tymy[Manager->getKlub()]->Hraci[LP_CB_Players->ItemIndex]->getPost() == 'G') && tymy[Manager->getKlub()]->getPocetHracu() > 12) {
                        tymy[Manager->getKlub()]->setridHrace('P', true);
                        tymy[Manager->getKlub()]->deletePlayerAt(LP_CB_Players->ItemIndex);
                        LP_CB_Players->DeleteSelected();
                        setPlayersLP();
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nextDay()
{
        AktKolo ++;
        if(AktKolo > 2) HO_B_NextWeek->Enabled = false;
        inicializujDalsiKolo();
        HO_B_Game->Enabled = true;
        HO_B_NextWeek->Enabled = false;
        HO_B_Table->Enabled = false;
        setCPUteamsTraining();
        trainingPalyers();
        updateEnergie();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setCPUteamsTraining()
{
        for(int i = 0; i < 12; i ++) {
                if(i != Manager->getKlub()) {
                        if((tymy[i]->getCelkoveEN() / (tymy[i]->getPocetHracu() - 1)) > tymy[i]->getTrainingIntensity() * 5) {
                                tymy[i]->setTraining(1);
                                tymy[i]->setTrainingIntensity(0.5);
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::trainingPalyers()
{
        for(int i = 0; i < 12; i ++) {
                tymy[i]->trainingTeam();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::updateEnergie()
{
        // int plus = tymy[i]->Hraci[j]->getEnergie() / 100;
        // plus = 1 - plus;
        // tymy[i]->Hraci[j]->setEnergie(40 * plus);


        for(int i = 0; i < 12; i ++) {
                for(int j = 0; j < tymy[i]->getPocetHracu(); j ++) {
                        if(tymy[i]->Hraci[j]->getEnergie() < 31)
                                tymy[i]->Hraci[j]->setEnergie(tymy[i]->Hraci[j]->getEnergie() + 40);
                        else if(tymy[i]->Hraci[j]->getEnergie() < 41)
                                tymy[i]->Hraci[j]->setEnergie(tymy[i]->Hraci[j]->getEnergie() + 42);
                        else if(tymy[i]->Hraci[j]->getEnergie() < 51)
                                tymy[i]->Hraci[j]->setEnergie(tymy[i]->Hraci[j]->getEnergie() + 37);
                        else if(tymy[i]->Hraci[j]->getEnergie() < 61)
                                tymy[i]->Hraci[j]->setEnergie(tymy[i]->Hraci[j]->getEnergie() + 30);
                        else if(tymy[i]->Hraci[j]->getEnergie() < 71)
                                tymy[i]->Hraci[j]->setEnergie(tymy[i]->Hraci[j]->getEnergie() + 25);
                        else if(tymy[i]->Hraci[j]->getEnergie() < 81)
                                tymy[i]->Hraci[j]->setEnergie(100);
                }
        }
}
//---------------------------------------------------------------------------
