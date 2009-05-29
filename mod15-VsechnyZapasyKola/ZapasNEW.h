//---------------------------------------------------------------------------

#ifndef ZapasNEWH
#define ZapasNEWH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>

#include "Tym.h"
#include "Zapas.h"
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *MA;
        TButton *button1;
        TShape *MA_B1;
        TLabel *MA_TD_L;
        TLabel *MA_TH_L;
        TImage *MA_LogoD;
        TImage *MA_LogoH;
        TShape *MA_B2D;
        TShape *MA_B2H;
        TShape *MA_B2S;
        TImage *MA_iHall;
        TShape *MA_B2D2;
        TShape *MA_B2D3;
        TShape *MA_B2H3;
        TShape *MA_B2H2;
        TLabel *MA_Hall;
        TLabel *MA_SkoreD;
        TShape *MA_B2S2;
        TShape *MA_B2D4;
        TShape *MA_B2H4;
        TShape *MA_B2D5;
        TShape *MA_B2H5;
        TLabel *MA_SkoreH;
        TLabel *MA_Skore;
        TShape *MA_B2S3;
        TShape *MA_B2S4;
        TShape *MA_B2S5;
        TLabel *MA_Strely;
        TLabel *MA_StrelyD;
        TLabel *MA_StrelyH;
        TLabel *MA_Cas;
        TTimer *Timer1;
        TLabel *MA_Navsteva;
        TLabel *MA_iNavsteva;
        TMemo *MA_SkoreListD;
        TMemo *MA_SkoreListH;
        TShape *MA_B2S6;
        TShape *MA_B2D6;
        TShape *MA_B2H6;
        TShape *MA_B2D7;
        TShape *MA_B2H7;
        TLabel *MA_SD_L;
        TLabel *MA_SH_L;
        TLabel *MA_O1;
        TLabel *MA_O2;
        TLabel *MA_O3;
        TLabel *MA_O4;
        TLabel *MA_O5;
        TLabel *MA_O0;
        TShape *MA_Button1;
        TLabel *MA_LButton1;
        TPanel *MA_LP_D;
        TLabel *MA_LP_DL1;
        TLabel *MA_LP_DL2;
        TLabel *MA_LP_DL3;
        TLabel *MA_LP_DL4;
        TLabel *MA_LP_DL5;
        TLabel *MA_LP_DL6;
        TPanel *MA_LP_H;
        TLabel *MA_LP_HL1;
        TLabel *MA_LP_HL2;
        TLabel *MA_LP_HL3;
        TLabel *MA_LP_HL4;
        TLabel *MA_LP_HL5;
        TLabel *MA_LP_HL6;
        TLabel *MA_LP_DL7;
        TLabel *MA_LP_HL7;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall MA_LButton1Click(TObject *Sender);
        void __fastcall button1Click(TObject *Sender);
        void __fastcall MA_SD_LClick(TObject *Sender);
        void __fastcall MA_SH_LClick(TObject *Sender);
private:	// User declarations
        Tym *tymy[12];
        Zapas *Match[6];
        Tym *tym[3];
        int d;
        int h;
        BYTE D_R1;
        BYTE D_G1;
        BYTE D_B1;
        BYTE D_R2;
        BYTE D_G2;
        BYTE D_B2;
        BYTE H_R1;
        BYTE H_G1;
        BYTE H_B1;
        BYTE H_R2;
        BYTE H_G2;
        BYTE H_B2;
        int iTime;
        bool bGool;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall setColors();
        void __fastcall Draw();
        void __fastcall setLineup(int iTeam);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 