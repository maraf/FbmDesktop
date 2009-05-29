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
        int *i;
        int *a;

        i = (int *) malloc(sizeof(int));
        *i = 5;

        a = i;

        *a = 6;

        Label1->Caption = *i;
        Label2->Caption = *a;

        free(i);

        Hrac *Player;
        Player = new Hrac();
        Player->setPrijmeni("Kordula");

        Moje(*Player);

        Label1->Caption = Player->getPrijmeni();

        delete Player;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Moje(Hrac &Pla){
        Hrac *Pl;

        Pl = &Pla;
        Pl->setPrijmeni("Sigi");
}