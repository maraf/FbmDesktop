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
                FILE *fTeam;

                fTeam = fopen("main.txt","r");

                int i = 0;
                int iIndex = 0;
                char cZnak;
                char cPole[30];

                             if(cZnak != '-' && iIndex == 1){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 2){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 3){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 4){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak != '-' && iIndex == 5){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak == '-'){
                                      i = 0;
                                      switch(iIndex){
                                                     case 1: Label1->Caption = cPole;; break;
                                                     case 2: Label2->Caption = cPole; break;
                                                     case 3: break;
                                                     case 4: break;
                                                     case 5: Label1->Caption = cPole; break;
                                      }
                                      iIndex ++;
                             }
                             if(cZnak == '\n'){
                                      i = 0;
                                      iIndex = 0;
                             }                while((cZnak = getc(fTeam)) != EOF){

                }

                fclose(fTeam);
}
//---------------------------------------------------------------------------
 