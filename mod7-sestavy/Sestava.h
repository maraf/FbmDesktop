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
        TPanel *Panel1;
        TImage *Background;
        TMemo *C_M;
        TMemo *J_M;
        TMemo *V_M;
        TMemo *F_M;
        TMemo *T_M;
        TLabel *C_L;
        TLabel *J_L;
        TLabel *V_L;
        TLabel *F_L;
        TLabel *T_L;
        TLabel *Z_L;
        TMemo *Z_M;
        TMemo *P_M;
        TLabel *P_L;
        TButton *Button1;
        TMemo *L_M;
        TLabel *L_L;
        TComboBox *G_CB;
        TComboBox *O2_1_CB;
        TComboBox *U2_1_CB;
        TComboBox *O1_1_CB;
        TComboBox *U3_1_CB;
        TComboBox *U1_1_CB;
        TComboBox *U1_2_CB;
        TComboBox *U2_2_CB;
        TComboBox *U3_2_CB;
        TComboBox *O2_2_CB;
        TComboBox *O1_2_CB;
        TButton *Button2;
        TImage *Image1;
        TImage *Image2;
        TLabel *Label1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall P_LClick(TObject *Sender);
        void __fastcall C_LClick(TObject *Sender);
        void __fastcall J_LClick(TObject *Sender);
        void __fastcall V_LClick(TObject *Sender);
        void __fastcall F_LClick(TObject *Sender);
        void __fastcall T_LClick(TObject *Sender);
        void __fastcall Z_LClick(TObject *Sender);
        void __fastcall L_LClick(TObject *Sender);
private:	// User declarations
        Tym *tym;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 