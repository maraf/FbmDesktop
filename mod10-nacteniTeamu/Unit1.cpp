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
                int iLine = 1;
                char cZnak;
                char cPole[30];
                String cNazevT;
                String cNazevH;
                String cKapacitaH;
                String cBarvy;
                String cLogo;
                String cHala;

                int R1, G1, B1, R2, G2, B2;

                while((cZnak = getc(fTeam)) != EOF){
                             if(cZnak != '-' && cZnak != '\n'){
                                      cPole[i] = cZnak;
                                      cPole[i+1] = '\0';
                                      i ++;
                             }
                             if(cZnak == '-'){
                                      i = 0;
                                      switch(iLine){
                                                     case 1: cNazevT = cPole; break;
                                                     case 2: cNazevH = cPole; break;
                                                     case 3: cKapacitaH = cPole; break;
                                                     case 4: R1 = atoi(cPole); break;
                                                     case 5: G1 = atoi(cPole); break;
                                                     case 6: B1 = atoi(cPole); break;
                                                     case 7: R2 = atoi(cPole); break;
                                                     case 8: G2 = atoi(cPole); break;
                                                     case 9: B2 = atoi(cPole); break;
                                                     case 10: cLogo = cPole; break;
                                                     case 11: cHala = cPole; break;
                                      }
                                      iLine ++;
                             }
                             if(cZnak == '\n'){

                             }
                }

                fclose(fTeam);

                Label1->Caption = cNazevT;
                Label2->Caption = cNazevH;
                Label3->Caption = cKapacitaH;
                Label4->Caption = R1;
                Label7->Caption = G1;
                Label8->Caption = B1;
                Label9->Caption = R2;
                Label10->Caption = G2;
                Label11->Caption = B2;
                Label5->Caption = cLogo;
                Label6->Caption = cHala;

                Shape1->Brush->Color = RGB(R1, G1, B1);
                Shape2->Brush->Color = RGB(R2, G2, B2);

}
//---------------------------------------------------------------------------
