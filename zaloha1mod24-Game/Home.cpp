//---------------------------------------------------------------------------
#pragma hdrstop
#include "ZapasNEW.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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

        MA_iNavsteva->Caption = Match[iMatchIndex]->getNavsteva();

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

void __fastcall TForm1::HO_B_LineUpClick(TObject *Sender)
{
        if(TE_CB_Teams->ItemIndex != -1) {
                HO->Visible = false;
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

void __fastcall TForm1::QuitClick(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HO_B_NextWeekClick(TObject *Sender)
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
                trainingPlayers();
        }

        HO_L_Label4->Caption = "" + ((String)Calendar->getWeek()) + ". tyden sezony,\nrok: " + ((String)Calendar->getYear());
        Label1->Caption = Teams[Manager->getKlub()]->Economy->getAccount();

        updateEnergie();
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

void __fastcall TForm1::HO_B_SetFormationClick(TObject *Sender)
{
        HO->Visible = false;
        SF->Visible = true;
        setPlayersSF();
}
//---------------------------------------------------------------------------