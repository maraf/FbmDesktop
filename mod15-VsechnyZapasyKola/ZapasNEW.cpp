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

        d = 2;
        h = 9;

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

        Match[0] = new Zapas(*tymy[d], *tymy[h], 1);
        Match[1] = new Zapas(*tymy[0], *tymy[1], 2);
        Match[2] = new Zapas(*tymy[3], *tymy[4], 3);
        Match[3] = new Zapas(*tymy[5], *tymy[6], 4);
        Match[4] = new Zapas(*tymy[7], *tymy[8], 5);
        Match[5] = new Zapas(*tymy[10], *tymy[11], 6);

//        Match->Tymy[0]->nactiHrace("teams/aik_l.txt");
        Match[0]->Tymy[0]->setridHrace('L', true);
//        Match->Tymy[1]->nactiHrace("teams/alv_l.txt");
        Match[0]->Tymy[1]->setridHrace('L', true);

//        Match->Tymy[0]->nactiHrace("teams/aik_l.txt");
        Match[1]->Tymy[0]->setridHrace('L', true);
//        Match->Tymy[1]->nactiHrace("teams/alv_l.txt");
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


        MA->Left = 112;
        MA->Top = 84;

        setColors();

        Draw();
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

        tymy[iTeam]->setridHrace('A', false);

        for(int i = 0; i < tymy[iTeam]->getPocetHracu(); i ++){
                if(tymy[iTeam]->Hraci[i]->getPost() == 'G' && iGolman1 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(1);
                        iGolman1 --;
                }
                if(tymy[iTeam]->Hraci[i]->getPost() == 'O' && iObrana1 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(1);
                        iObrana1 --;
                }
                if(tymy[iTeam]->Hraci[i]->getPost() == 'U' && iUtok1 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(1);
                        iUtok1 --;
                }
        }

        for(int i = 0; i < tymy[iTeam]->getPocetHracu(); i ++){
                if(tymy[iTeam]->Hraci[i]->getPost() == 'O' && tymy[iTeam]->Hraci[i]->getSestava() == 5 && iObrana2 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(2);
                        iObrana2 --;
                }
                if(tymy[iTeam]->Hraci[i]->getPost() == 'U' && tymy[iTeam]->Hraci[i]->getSestava() == 5 && iUtok1 == 0 && iUtok2 != 0){
                        tymy[iTeam]->Hraci[i]->setSestava(2);
                        iUtok2 --;
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
        if(Match[1]->getGoal() == 0 || Match[1]->getGoal() == 1){
                MA_O1->Caption = Match[1]->Tymy[0]->getNazevTymuKr() + " - " + Match[1]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[1]->getGolyD()) + ":" + IntToStr(Match[1]->getGolyH());
        }

        if(Match[2]->getGoal() == 0 || Match[2]->getGoal() == 1){
                MA_O2->Caption = Match[2]->Tymy[0]->getNazevTymuKr() + " - " + Match[2]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[2]->getGolyD()) + ":" + IntToStr(Match[2]->getGolyH());
        }

        if(Match[3]->getGoal() == 0 || Match[3]->getGoal() == 1){
                MA_O3->Caption = Match[3]->Tymy[0]->getNazevTymuKr() + " - " + Match[3]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[3]->getGolyD()) + ":" + IntToStr(Match[3]->getGolyH());
        }

        if(Match[4]->getGoal() == 0 || Match[4]->getGoal() == 1){
                MA_O4->Caption = Match[4]->Tymy[0]->getNazevTymuKr() + " - " + Match[4]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[4]->getGolyD()) + ":" + IntToStr(Match[4]->getGolyH());
        }

        if(Match[5]->getGoal() == 0 || Match[5]->getGoal() == 1){
                MA_O5->Caption = Match[5]->Tymy[0]->getNazevTymuKr() + " - " + Match[5]->Tymy[1]->getNazevTymuKr() + " " + IntToStr(Match[5]->getGolyD()) + ":" + IntToStr(Match[5]->getGolyH());
        }
//------------------------------

        if(Match[0]->getGoal() == 0){
//                if(Match->getGolyD() != 0 && ((Match->getCount()/2) > 20 || (Match->getCount()/2) > 40) && bGool == false){
//                        MA_SkoreListD->Lines->Add("--------------------");
//                        bGool = true;
//                }
                char j[10];
                String ss = IntToStr(Match[0]->getCount()/2) + ".min.: ";
                ss += IntToStr(Match[0]->Tymy[0]->Hraci[Match[0]->getStrelec()]->getCislo()) + " ";
                ss += Match[0]->Tymy[0]->Hraci[Match[0]->getStrelec()]->getPrijmeni() + " ( ";
                ss += IntToStr(Match[0]->Tymy[0]->Hraci[Match[0]->getAsistent()]->getCislo()) + " ";
                ss += Match[0]->Tymy[0]->Hraci[Match[0]->getAsistent()]->getPrijmeni() + " )";
                MA_SkoreListD->Lines->Add(ss);
                Match[0]->setGoal(3);
        }
        if(Match[0]->getGoal() == 1){
                String ss = IntToStr(Match[0]->getCount()/2) + ".min.: ";
                ss += IntToStr(Match[0]->Tymy[1]->Hraci[Match[0]->getStrelec()]->getCislo()) + " ";
                ss += Match[0]->Tymy[1]->Hraci[Match[0]->getStrelec()]->getPrijmeni() + " ( ";
                ss += IntToStr(Match[0]->Tymy[1]->Hraci[Match[0]->getAsistent()]->getCislo()) + " ";
                ss += Match[0]->Tymy[1]->Hraci[Match[0]->getAsistent()]->getPrijmeni() + " ) ";
                MA_SkoreListH->Lines->Add(ss);
                Match[0]->setGoal(3);
        }

        String ss = Match[0]->getMinuta();
        ss += ". minuta";
        MA_Cas->Caption = ss;
        MA_SkoreD->Caption = Match[0]->getGolyD();
        MA_SkoreH->Caption = Match[0]->getGolyH();
        MA_StrelyD->Caption = Match[0]->getStrelyD();
        MA_StrelyH->Caption = Match[0]->getStrelyH();

        if(Match[0]->getCount() == 120){
                Timer1->Enabled = false;
                MA_LButton1->Caption = "Pokraèuj";
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
                for(int i = 0; i < 12; i ++)
                        delete(tymy[i]);

                for(int i = 0; i < 6; i ++)
                        delete(Match[i]);

                Application->Terminate();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::button1Click(TObject *Sender)
{
                for(int i = 0; i < 12; i ++)
                        delete(tymy[i]);

                for(int i = 0; i < 6; i ++)
                        delete(Match[i]);

                Application->Terminate();        
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


