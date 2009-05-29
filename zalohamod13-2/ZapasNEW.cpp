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
        iTime = 0;

        d = 0;
        h = 1;

        for(int i = 0; i < 12; i ++)
                tymy[i] = new Tym();

        tymy[0]->nactiHrace("teams/aik_l.txt");
        tymy[0]->nactiTym("teams/aik_m.txt");
        tymy[1]->nactiHrace("teams/alv_l.txt");
        tymy[1]->nactiTym("teams/alv_m.txt");
        tymy[2]->nactiHrace("teams/bal_l.txt");
        tymy[2]->nactiTym("teams/bal_m.txt");
        tymy[3]->nactiHrace("teams/cap_l.txt");
        tymy[3]->nactiTym("teams/cap_m.txt");
        tymy[4]->nactiHrace("teams/dal_l.txt");
        tymy[4]->nactiTym("teams/dal_m.txt");
        tymy[5]->nactiHrace("teams/fal_l.txt");
        tymy[5]->nactiTym("teams/fal_m.txt");
        tymy[6]->nactiHrace("teams/hel_l.txt");
        tymy[6]->nactiTym("teams/hel_m.txt");
        tymy[7]->nactiHrace("teams/jar_l.txt");
        tymy[7]->nactiTym("teams/jar_m.txt");
        tymy[8]->nactiHrace("teams/jon_l.txt");
        tymy[8]->nactiTym("teams/jon_m.txt");
        tymy[9]->nactiHrace("teams/pix_l.txt");
        tymy[9]->nactiTym("teams/pix_m.txt");
        tymy[10]->nactiHrace("teams/sto_l.txt");
        tymy[10]->nactiTym("teams/sto_m.txt");
        tymy[11]->nactiHrace("teams/war_l.txt");
        tymy[11]->nactiTym("teams/war_m.txt");

        for(int i = 0; i < 12; i ++){
                setLineup(i);
                tymy[i]->setridHrace('P', true);
        }

        Match = new Zapas();

        Match->Tymy[0]->nactiHrace("teams/aik_l.txt");
        Match->Tymy[0]->setridHrace('L', true);
        Match->Tymy[1]->nactiHrace("teams/alv_l.txt");
        Match->Tymy[1]->setridHrace('L', true);

        Match->Inicializace();

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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        for(int i = 0; i < 12; i ++)
                delete(tymy[i]);

        delete Match;

        Application->Terminate();
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

        MA->Color = RGB(0, 140, 0);
        MA_B1->Pen->Color = RGB(255, 255, 255);
        MA_B1->Brush->Color = RGB(0, 140, 0);
        MA_Cas->Color = RGB(255, 255, 255);
        MA_Cas->Font->Color = RGB(0, 0, 0);
        MA_B2S->Brush->Color = RGB(255, 255, 255);
        MA_Hall->Color = RGB(255, 255, 255);
        MA_Hall->Font->Color = RGB(0, 0, 0);
        MA_Skore->Color = RGB(255, 255, 255);
        MA_Skore->Font->Color = RGB(0, 0, 0);
        MA_SkoreD->Color = RGB(255, 255, 255);
        MA_SkoreD->Font->Color = RGB(0, 0, 0);
        MA_SkoreH->Color = RGB(255, 255, 255);
        MA_SkoreH->Font->Color = RGB(0, 0, 0);
        MA_Strely->Color = RGB(255, 255, 255);
        MA_Strely->Font->Color = RGB(0, 0, 0);
        MA_StrelyD->Color = RGB(255, 255, 255);
        MA_StrelyD->Font->Color = RGB(0, 0, 0);
        MA_StrelyH->Color = RGB(255, 255, 255);
        MA_StrelyH->Font->Color = RGB(0, 0, 0);
        MA_Navsteva->Color = RGB(255, 255, 255);
        MA_Navsteva->Font->Color = RGB(0, 0, 0);
        MA_iNavsteva->Color = RGB(255, 255, 255);
        MA_iNavsteva->Font->Color = RGB(0, 0, 0);


        MA_B2D->Brush->Color = RGB(D_R2, D_G2, D_B2);
        MA_B2D2->Brush->Color = RGB(D_R2, D_G2, D_B2);
        MA_B2D3->Brush->Color = RGB(D_R2, D_G2, D_B2);
        MA_B2D4->Brush->Color = RGB(D_R2, D_G2, D_B2);
        MA_B2D5->Brush->Color = RGB(D_R2, D_G2, D_B2);
        MA_B2H->Brush->Color = RGB(H_R2, H_G2, H_B2);
        MA_B2H2->Brush->Color = RGB(H_R2, H_G2, H_B2);
        MA_B2H3->Brush->Color = RGB(H_R2, H_G2, H_B2);
        MA_B2H4->Brush->Color = RGB(H_R2, H_G2, H_B2);
        MA_B2H5->Brush->Color = RGB(H_R2, H_G2, H_B2);

        MA_TD_L->Color = RGB(D_R2, D_G2, D_B2);
        MA_TD_L->Font->Color = RGB(D_R1, D_G1, D_B1);
        MA_TH_L->Color = RGB(H_R2, H_G2, H_B2);
        MA_TH_L->Font->Color = RGB(H_R1, H_G1, H_B1);
        MA_SkoreListD->Color = RGB(D_R2, D_G2, D_B2);
        MA_SkoreListD->Font->Color = RGB(D_R1, D_G1, D_B1);
        MA_SkoreListH->Color = RGB(H_R2, H_G2, H_B2);
        MA_SkoreListH->Font->Color = RGB(H_R1, H_G1, H_B1);
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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        d += 2;
        h += 2;
        setColors();
        Draw();

        if(h == 11)
                Button2->Enabled = false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        cResult = Match->Akce();
        char cPom[7];
        char cCislo;
        sprintf(cPom, "%s", cResult);

        if(cPom[0] == 'D'){
                if(Match->iStrelec != 0){
                        String s = IntToStr(Match->iCount);
                        s += ".: ";
                        s += Match->Tymy[0]->Hraci[Match->iStrelec]->getPrijmeni();
                        s += ", ";
                        s += Match->Tymy[0]->Hraci[Match->iAsistent]->getPrijmeni();
                        MA_SkoreListD->Caption = MA_SkoreListD->Caption + "\n" + s;
                }
        }
        if(cPom[0] == 'H'){
                if(Match->iStrelec != 0){
                        String s = IntToStr(Match->iCount);
                        s += ".: ";
                        s += Match->Tymy[1]->Hraci[Match->iStrelec]->getPrijmeni();
                        s += ", ";
                        s += Match->Tymy[1]->Hraci[Match->iAsistent]->getPrijmeni();
                        MA_SkoreListH->Caption = MA_SkoreListH->Caption + "\n" + s;
                }
        }

        String ss = StrToInt(Match->iCount);
        ss += ". minuta";
        MA_Cas->Caption = ss;
        MA_SkoreD->Caption = Match->iGolyA;
        MA_SkoreH->Caption = Match->iGolyB;
        MA_StrelyD->Caption = Match->iStrelyA;
        MA_StrelyH->Caption = Match->iStrelyB;

        if(Match->iCount == 60)
                Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

