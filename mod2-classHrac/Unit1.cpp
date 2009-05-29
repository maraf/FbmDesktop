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

//        Muj = new Hrac();

//        Muj->setJmeno("Pavel");
//        Muj->setPrijmeni("Janda");
//        Muj->setVek("23");

//        Label1->Caption = Muj->getJmeno() + " " + Muj->getPrijmeni() + " " + Muj->getVek();

//        delete(Muj);

        fTeam = fopen("tymA.txt","r");

        int i = 0;
        int iIndex = 0;
        int iHrac = 0;
        char cZnak;
        char cPole[30];

        while(iHrac < 20){
            Hraci[iHrac] = new Hrac();
            iHrac ++;
        }

        iHrac = 0;

        while((cZnak = getc(fTeam)) != EOF){

                if(cZnak != '-' && iIndex == 0){
                        Hraci[iHrac]->setPost(cZnak);
                        i ++;
                }
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
                if(cZnak != '-' && iIndex == 6){
                        cPole[i] = cZnak;
                        cPole[i+1] = '\0';
                        i ++;
                }
                if(cZnak != '-' && iIndex == 7){
                        cPole[i] = cZnak;
                        cPole[i+1] = '\0';
                        i ++;
                }
                if(cZnak != '-' && iIndex == 8){
                        cPole[i] = cZnak;
                        cPole[i+1] = '\0';
                        i ++;
                }
                if(cZnak == '-'){
                        i = 0;
                        switch(iIndex){
                               case 1: Hraci[iHrac]->setCislo(cPole); break;
                               case 2: Hraci[iHrac]->setJmeno(cPole); break;
                               case 3: Hraci[iHrac]->setPrijmeni(cPole);break;
                               case 4: Hraci[iHrac]->setVek(cPole); break;
                               case 5: Hraci[iHrac]->setFS(cPole); break;
                               case 6: Hraci[iHrac]->setTS(cPole); break;
                               case 7: Hraci[iHrac]->setZS(cPole); break;
                               case 8: Hraci[iHrac]->setSmlouva(cPole); break;
                        }
                        iIndex ++;
                }
                if(cZnak == '\n'){
                        iHrac ++;
                        i = 0;
                        iIndex = 0;
                }
        }

        fclose(fTeam);

//      Hodnoty cPodle:
//
//      P ..... post
//      J ..... prijemeni
//      C ..... cislo
//      F ..... FS
//      T ..... TS
//      Z ..... ZS
//      V ..... vek
//      S ..... smlouva

        Hraci_sort('P', false);

        Label1->Caption = Hraci[0]->getJmeno() + " " + Hraci[0]->getPrijmeni() + " " + Hraci[0]->getCislo() + " " + Hraci[0]->getVek() + " " + Hraci[0]->getFS() + " " + Hraci[0]->getTS() + " " + Hraci[0]->getSmlouva();
        Label2->Caption = Hraci[1]->getJmeno() + " " + Hraci[1]->getPrijmeni() + " " + Hraci[1]->getCislo() + " " + Hraci[1]->getVek() + " " + Hraci[1]->getFS() + " " + Hraci[1]->getTS() + " " + Hraci[1]->getSmlouva();
        Label3->Caption = Hraci[2]->getJmeno() + " " + Hraci[2]->getPrijmeni() + " " + Hraci[2]->getCislo() + " " + Hraci[2]->getVek() + " " + Hraci[2]->getFS() + " " + Hraci[2]->getTS() + " " + Hraci[2]->getSmlouva();
        Label4->Caption = Hraci[3]->getJmeno() + " " + Hraci[3]->getPrijmeni() + " " + Hraci[3]->getCislo() + " " + Hraci[3]->getVek() + " " + Hraci[3]->getFS() + " " + Hraci[3]->getTS() + " " + Hraci[3]->getSmlouva();
        Label5->Caption = Hraci[4]->getJmeno() + " " + Hraci[4]->getPrijmeni() + " " + Hraci[4]->getCislo() + " " + Hraci[4]->getVek() + " " + Hraci[4]->getFS() + " " + Hraci[4]->getTS() + " " + Hraci[4]->getSmlouva();
        Label6->Caption = Hraci[5]->getJmeno() + " " + Hraci[5]->getPrijmeni() + " " + Hraci[5]->getCislo() + " " + Hraci[5]->getVek() + " " + Hraci[5]->getFS() + " " + Hraci[5]->getTS() + " " + Hraci[5]->getSmlouva();
        Label7->Caption = Hraci[6]->getJmeno() + " " + Hraci[6]->getPrijmeni() + " " + Hraci[6]->getCislo() + " " + Hraci[6]->getVek() + " " + Hraci[6]->getFS() + " " + Hraci[6]->getTS() + " " + Hraci[6]->getSmlouva();
        Label8->Caption = Hraci[7]->getJmeno() + " " + Hraci[7]->getPrijmeni() + " " + Hraci[7]->getCislo() + " " + Hraci[7]->getVek() + " " + Hraci[7]->getFS() + " " + Hraci[7]->getTS() + " " + Hraci[7]->getSmlouva();
        Label9->Caption = Hraci[8]->getJmeno() + " " + Hraci[8]->getPrijmeni() + " " + Hraci[8]->getCislo() + " " + Hraci[8]->getVek() + " " + Hraci[8]->getFS() + " " + Hraci[8]->getTS() + " " + Hraci[8]->getSmlouva();
        Label10->Caption = Hraci[9]->getJmeno() + " " + Hraci[9]->getPrijmeni() + " " + Hraci[9]->getCislo() + " " + Hraci[9]->getVek() + " " + Hraci[9]->getFS() + " " + Hraci[9]->getTS() + " " + Hraci[9]->getSmlouva();
        Label11->Caption = Hraci[10]->getJmeno() + " " + Hraci[10]->getPrijmeni() + " " + Hraci[10]->getCislo() + " "+ Hraci[10]->getVek() + " " + Hraci[10]->getFS() + " " + Hraci[10]->getTS() + " " + Hraci[10]->getSmlouva();

        fTeam = fopen("tymB.txt", "w");

        iHrac = 0;

        while(iHrac < 11){
                fprintf(fTeam, "%c-%i-%s-%s-%i-%i-%i-%i-%i-", Hraci[iHrac]->getPost(), Hraci[iHrac]->getCislo(), Hraci[iHrac]->getJmeno(), Hraci[iHrac]->getPrijmeni(), Hraci[iHrac]->getVek(), Hraci[iHrac]->getFS(), Hraci[iHrac]->getTS(), Hraci[iHrac]->getZS(), Hraci[iHrac]->getSmlouva());
                if(iHrac < 10) fprintf(fTeam, "\n");
                iHrac ++;
        }

        int iVyslFS = 0;
        iHrac = 0;

        while(iHrac < 11){
                iVyslFS += Hraci[iHrac]->getFS();
                iHrac ++;
        }

        Label12->Caption = iVyslFS/11;

        fclose(fTeam);

        for(iHrac = 0; iHrac < 20; iHrac ++)
             delete(Hraci[iHrac]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Hraci_sort(char cPodle, bool bVzestupne){

    switch(cPodle){
           case 'P': Hraci_sort_post(bVzestupne); break;
//           case 'J': Hraci_sort_jmeno(bVzestupne); break;
//           case 'C': Hraci_sort_cislo(bVzestupne); break;
//           case 'V': Hraci_sort_vek(bVzestupne); break;
//           case 'F': Hraci_sort_fs(bVzestupne); break;
//           case 'T': Hraci_sort_ts(bVzestupne); break;
//           case 'Z': Hraci_sort_zs(bVzestupne); break;
//           case 'S': Hraci_sort_smlouva(bVzestupne); break;
    }
}

void __fastcall TForm1::Hraci_sort_post(bool bVzestupne){

    int i = 1;
    int j = 0;
    Hrac *HrPomocny;
    HrPomocny = new Hrac();

    while(j < 11){
            while(i < 11){
                    if(Hraci[j]->getPost() < Hraci[i]->getPost()){

                                *HrPomocny = *Hraci[j];
                                *Hraci[j] = *Hraci[i];
                                *Hraci[i] = *HrPomocny;

                    }
                    i ++;
            }
            if(bVzestupne) i = 0;
            else i = j + 1;

            j ++;
    }

     delete(HrPomocny);
}
