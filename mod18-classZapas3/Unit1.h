//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include "Hrac.h"
#include "Tym.h"
#include "Zapas.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TTimer *Timer1;
        TLabel *Label4;
        TLabel *Label3;
private:	// User declarations
        Zapas *Match;
        Tym *Teams[2];
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall setLineup(int iTeam);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 