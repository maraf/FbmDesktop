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

        //AktKolo = 0;
        //rozpisLigy();

        Manager = new Manazer("Marek", "SMM", 3);
        MatchList = new ZapasList();
        Calendar = new Kalendar("calendar/calendar.cal", "schedules.schl");


        for(int i = 0; i < 12; i ++)
                Teams[i] = new Tym();

        Teams[0]->nactiHrace("teams/aik_l.txt");
        Teams[0]->nactiTym("teams/aik_m.txt");
        Teams[0]->setID(1);
        Teams[1]->nactiHrace("teams/alv_l.txt");
        Teams[1]->nactiTym("teams/alv_m.txt"); 
        Teams[1]->setID(1);
        Teams[2]->nactiHrace("teams/bal_l.txt");
        Teams[2]->nactiTym("teams/bal_m.txt");
        Teams[2]->setID(1);
        Teams[3]->nactiHrace("teams/cap_l.txt");
        Teams[3]->nactiTym("teams/cap_m.txt");
        Teams[3]->setID(3);
        Teams[4]->nactiHrace("teams/dal_l.txt");
        Teams[4]->nactiTym("teams/dal_m.txt");
        Teams[4]->setID(4);
        Teams[5]->nactiHrace("teams/fal_l.txt");
        Teams[5]->nactiTym("teams/fal_m.txt");
        Teams[5]->setID(5);
        Teams[6]->nactiHrace("teams/hel_l.txt");
        Teams[6]->nactiTym("teams/hel_m.txt");
        Teams[6]->setID(6);
        Teams[7]->nactiHrace("teams/jar_l.txt");
        Teams[7]->nactiTym("teams/jar_m.txt");
        Teams[7]->setID(7);
        Teams[8]->nactiHrace("teams/jon_l.txt");
        Teams[8]->nactiTym("teams/jon_m.txt");
        Teams[8]->setID(8);
        Teams[9]->nactiHrace("teams/pix_l.txt");
        Teams[9]->nactiTym("teams/pix_m.txt");
        Teams[9]->setID(9);
        Teams[10]->nactiHrace("teams/sto_l.txt");
        Teams[10]->nactiTym("teams/sto_m.txt");
        Teams[10]->setID(10);
        Teams[11]->nactiHrace("teams/war_l.txt");
        Teams[11]->nactiTym("teams/war_m.txt");
        Teams[11]->setID(11);
                
        for(int i = 0; i < 12; i ++){
                setLineup(i);
                Teams[i]->setridHrace('P', true);
        }
        
        R1 = Teams[t]->getR1();
        G1 = Teams[t]->getG1();
        B1 = Teams[t]->getB1();

        R2 = Teams[t]->getR2();
        G2 = Teams[t]->getG2();
        B2 = Teams[t]->getB2();

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

        LP_Name->Caption = Teams[t]->getNazevTymu();
        LP_Hall->Caption = Teams[t]->getNazevHaly();
        LP_Capacity->Caption = Teams[t]->getKapacitaHaly();
        LP_Logo->Picture->LoadFromFile("teams/"+Teams[t]->getLogo());
        LP_iHall->Picture->LoadFromFile("teams/"+Teams[t]->getHala());

        setColors();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::setColors()
{
        D_R1 = Teams[d]->getR1();
        D_G1 = Teams[d]->getG1();
        D_B1 = Teams[d]->getB1();

        D_R2 = Teams[d]->getR2();
        D_G2 = Teams[d]->getG2();
        D_B2 = Teams[d]->getB2();

        H_R1 = Teams[h]->getR1();
        H_G1 = Teams[h]->getG1();
        H_B1 = Teams[h]->getB1();

        H_R2 = Teams[h]->getR2();
        H_G2 = Teams[h]->getG2();
        H_B2 = Teams[h]->getB2();
                      
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
        MA_TD_L->Caption = Teams[d]->getNazevTymu();
        MA_TH_L->Caption = Teams[h]->getNazevTymu();
        MA_LogoD->Picture->LoadFromFile("teams/"+Teams[d]->getLogo());
        MA_LogoH->Picture->LoadFromFile("teams/"+Teams[h]->getLogo());
        MA_iHall->Picture->LoadFromFile("teams/"+Teams[d]->getHala());
        MA_Hall->Caption = Teams[d]->getNazevHaly();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setLineup(int iTeam)
{
        int iGolman1 = 1;
        int iObrana1 = 2;
        int iObrana2 = 2;
        int iUtok1 = 3;
        int iUtok2 = 3;

        for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++) {
                Teams[iTeam]->Hraci[i]->setSestava(5);
        }

        Teams[iTeam]->setridHrace('A', false);

        for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++){
                if(Teams[iTeam]->Hraci[i]->getPost() == 'G' && iGolman1 != 0){
                        Teams[iTeam]->Hraci[i]->setSestava(1);
                        iGolman1 --;
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'O' && iObrana1 != 0){
                        if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                Teams[iTeam]->Hraci[i]->setSestava(1);
                                iObrana1 --;
                        }
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'U' && iUtok1 != 0){
                        if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                Teams[iTeam]->Hraci[i]->setSestava(1);
                                iUtok1 --;
                        }
                }
        }

        for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++){
                if(Teams[iTeam]->Hraci[i]->getPost() == 'O' && Teams[iTeam]->Hraci[i]->getSestava() == 5 && iObrana2 != 0){
                        if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                Teams[iTeam]->Hraci[i]->setSestava(2);
                                iObrana2 --;
                        }
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'U' && Teams[iTeam]->Hraci[i]->getSestava() == 5 && iUtok1 == 0 && iUtok2 != 0){
                        if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                Teams[iTeam]->Hraci[i]->setSestava(2);
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
                //if(AktKolo > 4) HO_B_NextWeek->Enabled = false;
                HO_B_Table->Enabled = true;

                int limit = 0;
                for(int i = 0; i < 12; i ++) {
                        for(int j = 0; j < Teams[i]->getPocetHracu(); j ++) {
                                limit = Teams[i]->Hraci[j]->getVek() * 5 * Teams[i]->Hraci[j]->getFS() * Teams[i]->Hraci[j]->getFS() / 1000;
                                if(Teams[i]->Hraci[j]->getFSpom() >= limit) {
                                        if(Teams[i]->Hraci[j]->getFS() > 100)
                                                Teams[i]->Hraci[j]->setFS(Teams[i]->Hraci[j]->getFS() + 1);
                                        Teams[i]->Hraci[j]->setFSpom(Teams[i]->Hraci[j]->getFSpom() - limit);
                                }
                                limit = Teams[i]->Hraci[j]->getVek() * 30 * Teams[i]->Hraci[j]->getTS() / 100;
                                if(Teams[i]->Hraci[j]->getTSpom() >= limit) {
                                        if(Teams[i]->Hraci[j]->getTS() > 100)
                                                Teams[i]->Hraci[j]->setTS(Teams[i]->Hraci[j]->getTS() + 1);
                                        Teams[i]->Hraci[j]->setTSpom(Teams[i]->Hraci[j]->getTSpom() - limit);
                                }
                                limit = Teams[i]->Hraci[j]->getVek() * 10;
                                if(Teams[i]->Hraci[j]->getZSpom() >= limit) {
                                        if(Teams[i]->Hraci[j]->getZS() > 100)
                                                Teams[i]->Hraci[j]->setZS(Teams[i]->Hraci[j]->getZS() + 1);
                                        Teams[i]->Hraci[j]->setZSpom(Teams[i]->Hraci[j]->getZSpom() - limit);
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
                for(int i = 0; i < Teams[d]->getPocetLajn() * 5 + 1; i ++){
                        s1 += "\n";
                        s1 += Teams[d]->Hraci[i]->getCislo();
                        s2 += "\n";
                        s2 += Teams[d]->Hraci[i]->getPrijmeni();
                        s3 += "\n";
                        s3 += Teams[d]->Hraci[i]->getFS();
                        s4 += "\n";
                        s4 += Teams[d]->Hraci[i]->getTS();
                        s5 += "\n";
                        s5 += Teams[d]->Hraci[i]->getZS();
                        s6 += "\n";
                        s6 += Teams[d]->Hraci[i]->getEnergie();
                        s7 += "\n";
                        s7 += Teams[d]->Hraci[i]->getSestava();
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
                for(int i = 0; i < Teams[h]->getPocetLajn() * 5 + 1; i ++){
                        s1 += "\n";
                        s1 += Teams[h]->Hraci[i]->getCislo();
                        s2 += "\n";
                        s2 += Teams[h]->Hraci[i]->getPrijmeni();
                        s3 += "\n";
                        s3 += Teams[h]->Hraci[i]->getFS();
                        s4 += "\n";
                        s4 += Teams[h]->Hraci[i]->getTS();
                        s5 += "\n";
                        s5 += Teams[h]->Hraci[i]->getZS();
                        s6 += "\n";
                        s6 += Teams[h]->Hraci[i]->getEnergie();
                        s7 += "\n";
                        s7 += Teams[h]->Hraci[i]->getSestava();
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
                TE_CB_Teams->AddItem(Teams[i]->getNazevTymu(), this);
        }
}
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

void __fastcall TForm1::TE_B_SelectClick(TObject *Sender)
{
        if(TE_CB_Teams->ItemIndex != -1) {
                TE->Visible = false;
                t = TE_CB_Teams->ItemIndex;
                LP->Visible = true;
                Teams[t]->setridHrace('P', true);
                setColorsLP();
                setPlayersLP();

                String sLP;
                for(int i = 0; i < Teams[t]->getPocetHracu(); i ++){
                        sLP = Teams[t]->Hraci[i]->getCislo();
                        sLP +=  " ";
                        sLP += Teams[t]->Hraci[i]->getPrijmeni();
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
                        LP_CB_TrainingIntensity->ItemIndex = 10 * Teams[Manager->getKlub()]->getTrainingIntensity();
                        LP_CB_Training->ItemIndex = Teams[Manager->getKlub()]->getTraining();
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

void __fastcall TForm1::inicializujDalsiKolo()
{
        for(int i = 0; i < 6; i ++) {
                if(Calendar->getRound() != 0) MatchList->add(Match[i]);
                Match[i] = new Zapas(*Teams[Calendar->getSchedule(i, true)], *Teams[Calendar->getSchedule(i, false)], Calendar->getMatchId(i));
        }

        for(int i = 0; i < 6; i ++) {
                if(Calendar->getSchedule(i, true) == Manager->getKlub() || Calendar->getSchedule(i, false) == Manager->getKlub()) {
                        d = Calendar->getSchedule(i, true);
                        h = Calendar->getSchedule(i, false);
                        iMatchIndex = i;
                }
        }
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
                        if(Teams[j]->getUmisteni() == i) {
                                if(Teams[j]->getUmisteni() != 1) {
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
                                position += Teams[j]->getUmisteni();
                                name += Teams[j]->getNazevTymu();
                                matches += Teams[j]->getZapasyL();
                                wins += Teams[j]->getVyhryL();
                                draws += Teams[j]->getRemizyL();
                                loses += Teams[j]->getProhryL();
                                scoreH += Teams[j]->getDaneGL();
                                scoreA += Teams[j]->getObdrzeneGL();
                                shootsH += Teams[j]->getDaneSL();
                                shootsA += Teams[j]->getObdrzeneSL();
                                points += Teams[j]->getBodyL();
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
                //if(AktKolo != 0) {
                        lrd += Match[i]->Tymy[0]->getNazevTymu();
                        lrds += Match[i]->getGolyD();
                        lrhs += Match[i]->getGolyH();
                        lrh += Match[i]->Tymy[1]->getNazevTymu();
                //}
                //nrd += Teams[RozpisLigy[AktKolo + 1][0][i]]->getNazevTymu();
                //nrh += Teams[RozpisLigy[AktKolo + 1][1][i]]->getNazevTymu();
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
                iPole[i][0] = Teams[i]->getBodyL();
                iPole[i][1] = i;
                Teams[i]->setUmisteni(12);
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
                                if((Teams[iPole[j][1]]->getDaneGL() - Teams[iPole[j][1]]->getObdrzeneGL()) > (Teams[iPole[i][1]]->getDaneGL() - Teams[iPole[i][1]]->getObdrzeneGL())) {
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
                Teams[iPole[i][1]]->setUmisteni(i + 1);
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

        RGB1 = RGB(Teams[Manager->getKlub()]->getR1(), Teams[Manager->getKlub()]->getG1(), Teams[Manager->getKlub()]->getB1());
        RGB2 = RGB(Teams[Manager->getKlub()]->getR2(), Teams[Manager->getKlub()]->getG2(), Teams[Manager->getKlub()]->getB2());

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

void __fastcall TForm1::LP_F_LDblClick(TObject *Sender)
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


void __fastcall TForm1::HO_B_GameClick(TObject *Sender)
{
        for(int i = 0; i < 12; i ++){
                if(i != Manager->getKlub())
                        setLineup(i);
                Teams[i]->setridHrace('P', true);
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

        D_R1 = Teams[d]->getR1();
        D_G1 = Teams[d]->getG1();
        D_B1 = Teams[d]->getB1();

        D_R2 = Teams[d]->getR2();
        D_G2 = Teams[d]->getG2();
        D_B2 = Teams[d]->getB2();

        H_R1 = Teams[h]->getR1();
        H_G1 = Teams[h]->getG1();
        H_B1 = Teams[h]->getB1();

        H_R2 = Teams[h]->getR2();
        H_G2 = Teams[h]->getG2();
        H_B2 = Teams[h]->getB2();

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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Teams[Manager->getKlub()]->setridHrace('P', true);
        ComboBox1->Clear();
        for(int i = 0; i < Teams[Manager->getKlub()]->getPocetHracu(); i ++)
                ComboBox1->Items->Add((String)Teams[Manager->getKlub()]->Hraci[i]->getCislo() + " " + Teams[Manager->getKlub()]->Hraci[i]->getPrijmeni());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(ComboBox1->ItemIndex != -1) {
                if(!(Teams[Manager->getKlub()]->getCountOfGoalkeepers() == 1 && Teams[Manager->getKlub()]->Hraci[ComboBox1->ItemIndex]->getPost() == 'G') && Teams[Manager->getKlub()]->getPocetHracu() > 12) {
                        Teams[Manager->getKlub()]->setridHrace('P', true);
                        Teams[Manager->getKlub()]->deletePlayerAt(ComboBox1->ItemIndex);
                        Button2Click(Sender);
                }
        }
        //if(Teams[Manager->getKlub()]->getCountOfGoalkeepers() == 1)
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        HO->Visible = false;
        t = Manager->getKlub();
        LP->Visible = true;
        Teams[t]->setridHrace('P', true);
        setColorsLP();
        setPlayersLP();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        for(int i = 0; i < 12; i ++) {
                ComboBox2->Items->Add(Teams[i]->getNazevTymu());
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

void __fastcall TForm1::nextDay()
{
        Calendar->nextDay();
        if(Calendar->isLeague()) {
                HO_L_Label1->Caption = "Je liga";
                HO_B_Game->Enabled = true;
                HO_B_NextWeek->Enabled = false;
                HO_B_Table->Enabled = false;
        } else {
                HO_L_Label1->Caption = "Neni liga";
        }

        if(Calendar->isTransferPeriod()) {
                HO_L_Label2->Caption = "Je prestupni okno";
        } else {
                HO_L_Label2->Caption = "Neni prestupni okno";
        }

        if(Calendar->isHoliday()) {
                HO_L_Label3->Caption = "Jsou dovolene";
        } else {
                HO_L_Label3->Caption = "Nejsou dovolene";
                setCPUteamsTraining();
                trainingPalyers();
        }

        HO_L_Label4->Caption = "" + ((String)Calendar->getWeek()) + ". tyden sezony,\nrok: " + ((String)Calendar->getYear());

        updateEnergie();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setCPUteamsTraining()
{
        for(int i = 0; i < 12; i ++) {
                if(i != Manager->getKlub()) {
                        if((Teams[i]->getCelkoveEN() / (Teams[i]->getPocetHracu() - 1)) > Teams[i]->getTrainingIntensity() * 5) {
                                Teams[i]->setTraining(1);
                                Teams[i]->setTrainingIntensity(0.5);
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::trainingPalyers()
{
        for(int i = 0; i < 12; i ++) {
                Teams[i]->trainingTeam();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::updateEnergie()
{
        // int plus = Teams[i]->Hraci[j]->getEnergie() / 100;
        // plus = 1 - plus;
        // Teams[i]->Hraci[j]->setEnergie(40 * plus);


        for(int i = 0; i < 12; i ++) {
                for(int j = 0; j < Teams[i]->getPocetHracu(); j ++) {
                        if(Teams[i]->Hraci[j]->getEnergie() < 31)
                                Teams[i]->Hraci[j]->setEnergie(Teams[i]->Hraci[j]->getEnergie() + 40);
                        else if(Teams[i]->Hraci[j]->getEnergie() < 41)
                                Teams[i]->Hraci[j]->setEnergie(Teams[i]->Hraci[j]->getEnergie() + 42);
                        else if(Teams[i]->Hraci[j]->getEnergie() < 51)
                                Teams[i]->Hraci[j]->setEnergie(Teams[i]->Hraci[j]->getEnergie() + 37);
                        else if(Teams[i]->Hraci[j]->getEnergie() < 61)
                                Teams[i]->Hraci[j]->setEnergie(Teams[i]->Hraci[j]->getEnergie() + 30);
                        else if(Teams[i]->Hraci[j]->getEnergie() < 71)
                                Teams[i]->Hraci[j]->setEnergie(Teams[i]->Hraci[j]->getEnergie() + 25);
                        else if(Teams[i]->Hraci[j]->getEnergie() < 81)
                                Teams[i]->Hraci[j]->setEnergie(100);
                }
        }
}
//---------------------------------------------------------------------------
