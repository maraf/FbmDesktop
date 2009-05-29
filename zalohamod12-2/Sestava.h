//---------------------------------------------------------------------------

#ifndef SestavaH
#define SestavaH
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
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *LP;
        TLabel *LP_C_L;
        TLabel *LP_J_L;
        TLabel *LP_V_L;
        TLabel *LP_F_L;
        TLabel *LP_T_L;
        TLabel *LP_Z_L;
        TLabel *LP_P_L;
        TLabel *LP_L_L;
        TImage *LP_Logo;
        TLabel *LP_Name;
        TShape *LP_B1;
        TButton *button1;
        TLabel *LP_Hall;
        TImage *LP_iHall;
        TLabel *LP_lCapacity;
        TLabel *LP_Capacity;
        TShape *LP_B2;
        TShape *LP_B3;
        TShape *LP_B4;
        TLabel *LP_Al_L;
        TLabel *LP_Zp_L;
        TLabel *LP_Gp_L;
        TLabel *LP_Ap_L;
        TLabel *LP_Zl_L;
        TLabel *LP_Gl_L;
        TButton *Button2;
        TButton *Button3;
        TLabel *LP_P_M;
        TLabel *LP_C_M;
        TLabel *LP_J_M;
        TLabel *LP_V_M;
        TLabel *LP_F_M;
        TLabel *LP_T_M;
        TLabel *LP_Z_M;
        TLabel *LP_L_M;
        TLabel *LP_Zl_M;
        TLabel *LP_Gl_M;
        TLabel *LP_Al_M;
        TLabel *LP_Zp_M;
        TLabel *LP_Gp_M;
        TLabel *LP_Ap_M;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall LP_P_LClick(TObject *Sender);
        void __fastcall LP_C_LClick(TObject *Sender);
        void __fastcall LP_J_LClick(TObject *Sender);
        void __fastcall LP_V_LClick(TObject *Sender);
        void __fastcall LP_F_LClick(TObject *Sender);
        void __fastcall LP_T_LClick(TObject *Sender);
        void __fastcall LP_Z_LClick(TObject *Sender);
        void __fastcall LP_L_LClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
        Tym *tymy[12];
        Tym *tym[3];
        int t;
        BYTE R1;
        BYTE G1;
        BYTE B1;
        BYTE R2;
        BYTE G2;
        BYTE B2;
        String Logo;
        String Hall;
        int Capacity;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall setLayouts1();
        void __fastcall setLayouts2();
        void __fastcall setColors();
        void __fastcall setPlayers();
        void __fastcall setLineup(int iTeam);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 