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
        tym = new Tym();
        tym->nactiHrace("alv_l.txt");

        String s;
        
        s += tym->Hraci[0]->getPrijmeni();

        for(int i = 1; i < tym->getPocetHracu(); i ++)
                s += "\n"+tym->Hraci[i]->getPrijmeni();

        Label1->Caption = s;

        delete tym;
}
//---------------------------------------------------------------------------
 