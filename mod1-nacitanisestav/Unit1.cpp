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


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        fTeam = fopen("sestavy/tymA.txt","r");

        int i = 0;
        int iIndex = 0;
        int iHrac = 0;
        char cZnak;

        char cPost[2];
        char cJmeno[20];
        char cVek[3];
        char cRychlost[3];
        char cTechnika[3];
        char cSmlouva[5];

        while((cZnak = getc(fTeam)) != EOF){

                if(cZnak != '-' && iIndex == 0){
                        cPost[i] = cZnak;
                        cPost[i+1] = '\0';
                        i ++;
                }
                if(cZnak != '-' && iIndex == 1){
                        cJmeno[i] = cZnak;
                        cJmeno[i+1] = '\0';
                        i ++;
                }
                if(cZnak != '-' && iIndex == 2){
                        cVek[i] = cZnak;
                        cVek[i+1] = '\0';
                        i ++;
                }
                if(cZnak != '-' && iIndex == 3){
                        cRychlost[i] = cZnak;
                        cRychlost[i+1] = '\0';
                        i ++;
                }
                if(cZnak != '-' && iIndex == 4){
                        cTechnika[i] = cZnak;
                        cTechnika[i+1] = '\0';
                        i ++;
                }
                if(cZnak != '-' && iIndex == 5){
                        cSmlouva[i] = cZnak;
                        cSmlouva[i+1] = '\0';
                        i ++;
                }
                if(cZnak == '-'){
                        i = 0;
                        iIndex ++;
                }
        }

        Label1->Caption = cJmeno;
        Label2->Caption = cPost;
        Label3->Caption = cVek;
        Label4->Caption = cRychlost;
        Label5->Caption = cTechnika;
        Label6->Caption = cSmlouva;

        fclose(fTeam);
}
//---------------------------------------------------------------------------


