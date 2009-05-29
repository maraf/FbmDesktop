//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include "Zapas.h"
#include "ZapasList.h"
#include "Tym.h"
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
private:	// User declarations
        ZapasList *MatchList;
        Tym *Teams[2];
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall setLineup(int iTeam);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 