//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>

#include "Tym.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TPanel *Panel2;
        TImage *Image2;
        TButton *Button1;
        TMemo *TT_M;
        TMemo *TPoradi_M;
        TMemo *TV_M;
        TMemo *TZ_M;
        TMemo *TR_M;
        TMemo *TP_M;
        TMemo *TGS_M;
        TMemo *TGA_M;
        TMemo *TB_M;
        TMemo *TDot_M;
        TLabel *Tab_L;
        TMemo *NKTD_M;
        TMemo *NKTH_M;
        TMemo *NKGD_M;
        TMemo *NKGH_M;
        TMemo *NKDot_M;
        TLabel *NKolo_L;
        TMemo *PKTD_M;
        TMemo *PKGD_M;
        TMemo *PKDot_M;
        TMemo *PKGH_M;
        TMemo *PKTH_M;
        TLabel *PKolo_L;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
        Tym *Tymy[14];
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 