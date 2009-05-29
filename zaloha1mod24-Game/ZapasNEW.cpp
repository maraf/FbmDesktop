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

        Manager = new Manazer("Marek", "SMM", 9);
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

        TA->Left = 112;
        TA->Top = 84;

        SF->Left = 112;
        SF->Top = 84;

        LP->Visible = false;
        MA->Visible = false;
        SF->Visible = false;
        HO->Visible = true;

        LP_Name->Caption = Teams[t]->getNazevTymu();
        LP_Hall->Caption = Teams[t]->getNazevHaly();
        LP_Capacity->Caption = Teams[t]->getKapacitaHaly();
        LP_Logo->Picture->LoadFromFile("teams/"+Teams[t]->getLogo());
        LP_iHall->Picture->LoadFromFile("teams/"+Teams[t]->getHala());

        setColors();
        
        TE_CB_Teams->Clear();
        for(int i = 0; i < 12; i ++) {
                TE_CB_Teams->AddItem(Teams[i]->getNazevTymu(), this);
        }

        for(int i = 0; i < 4; i ++) {
                for(int j = 0; j < 5; j ++) {
                        Sestava[i][j] = -1;
                }
        }

        Golman[0] = -1;
        Golman[1] = -1;
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
        B_RGB2 = clWhite;
        B_RGB3 = clBlack;

        D_RGB1 = Teams[d]->getRGB1();
        D_RGB2 = Teams[d]->getRGB2();

        H_RGB1 = Teams[h]->getRGB1();
        H_RGB2 = Teams[h]->getRGB2();

        HO->Color = B_RGB1;
        HO_B1->Pen->Color = B_RGB2;
        HO_B1->Brush->Color = B_RGB1;

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

        //Teams[iTeam]->setridHrace('A', false);
        Teams[iTeam]->Lines[0]->setEnabled(true);
        Teams[iTeam]->Lines[1]->setEnabled(true);
        Teams[iTeam]->Lines[2]->setEnabled(false);
        Teams[iTeam]->Lines[3]->setEnabled(false);

        for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++){
                if(Teams[iTeam]->Hraci[i]->getPost() == 'G' && iGolman1 != 0){
                        //Teams[iTeam]->Hraci[i]->setSestava(1);
                        Teams[iTeam]->Lines[0]->setGoalman(i);
                        Teams[iTeam]->Lines[1]->setGoalman(i);
                        iGolman1 --;
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'O' && iObrana1 != 0){
                        //if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                //Teams[iTeam]->Hraci[i]->setSestava(1);
                                if(iObrana1 == 2) Teams[iTeam]->Lines[0]->setLeftDefender(i);
                                else Teams[iTeam]->Lines[0]->setRightDefender(i);
                                iObrana1 --;
                        //}
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'U' && iUtok1 != 0){
                        //if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                //Teams[iTeam]->Hraci[i]->setSestava(1);
                                switch(iUtok1) {
                                        case 3: Teams[iTeam]->Lines[0]->setLeftWing(i); break;
                                        case 2: Teams[iTeam]->Lines[0]->setRightWing(i); break;
                                        case 1: Teams[iTeam]->Lines[0]->setCenter(i); break;
                                }
                                iUtok1 --;
                        //}
                }
        }

        for(int i = 0; i < Teams[iTeam]->getPocetHracu(); i ++){
                if(Teams[iTeam]->Hraci[i]->getPost() == 'O' && Teams[iTeam]->Hraci[i]->getSestava() == 5 && iObrana2 != 0){
                        //if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                //Teams[iTeam]->Hraci[i]->setSestava(2);
                                if(iObrana2 == 2) Teams[iTeam]->Lines[1]->setLeftDefender(i);
                                else Teams[iTeam]->Lines[1]->setRightDefender(i);
                                iObrana2 --;
                        //}
                }
                if(Teams[iTeam]->Hraci[i]->getPost() == 'U' && Teams[iTeam]->Hraci[i]->getSestava() == 5 && iUtok1 == 0 && iUtok2 != 0){
                        //if(Teams[iTeam]->Hraci[i]->getEnergie() > 70) {
                                //Teams[iTeam]->Hraci[i]->setSestava(2);
                                switch(iUtok2) {
                                        case 3: Teams[iTeam]->Lines[1]->setLeftWing(i); break;
                                        case 2: Teams[iTeam]->Lines[1]->setRightWing(i); break;
                                        case 1: Teams[iTeam]->Lines[1]->setCenter(i); break;
                                }
                                iUtok2 --;
                        //}
                }
        }
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

void __fastcall TForm1::trainingPlayers()
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        String s1 = "";
        String s2 = "";
        for(int i = 0; i < 4; i ++) {
                for(int j = 0; j < 5; j ++) {
                        s1 += (String)Sestava[i][j] + " : ";
                }
                s2 += (String)Teams[Manager->getKlub()]->Lines[i]->getLeftDefender();
                s2 += (String)Teams[Manager->getKlub()]->Lines[i]->getRightDefender();
                s2 += (String)Teams[Manager->getKlub()]->Lines[i]->getLeftWing();
                s2 += (String)Teams[Manager->getKlub()]->Lines[i]->getRightWing();
                s2 += (String)Teams[Manager->getKlub()]->Lines[i]->getCenter();
                s1 += "\n";
                s2 += "\n";
        }
        Label2->Caption = (String)Golman[0] + " :: " + (String)Golman[1];
        Label3->Caption = (String)Teams[Manager->getKlub()]->Lines[0]->getGoalman() + " :: " + (String)Teams[Manager->getKlub()]->Lines[0]->getReserveGoalman();
}
//---------------------------------------------------------------------------

