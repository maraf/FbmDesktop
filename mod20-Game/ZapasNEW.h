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
#include <jpeg.hpp>
//---------------------------------------------------------------------------
#include "Tym.h"
#include "Zapas.h"  
#include "ZapasList.h"
#include "Manazer.h"
#include "Kalendar.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *MA;
        TButton *Quit;
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
        TPanel *LP;
        TShape *LP_B2;
        TShape *LP_B1;
        TLabel *LP_Name;
        TImage *LP_Logo;
        TLabel *LP_Hall;
        TImage *LP_iHall;
        TLabel *LP_lCapacity;
        TLabel *LP_Capacity;
        TShape *LP_B3;
        TShape *LP_B4;
        TLabel *LP_P_L;
        TLabel *LP_C_L;
        TLabel *LP_J_L;
        TLabel *LP_V_L;
        TLabel *LP_F_L;
        TLabel *LP_T_L;
        TLabel *LP_Z_L;
        TLabel *LP_L_L;
        TLabel *LP_Al_L;
        TLabel *LP_En_L;
        TLabel *LP_Zl_L;
        TLabel *LP_Gl_L;
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
        TLabel *LP_En_M;
        TShape *LP_B5;
        TButton *Zpet;
        TComboBox *LP_Buy;
        TButton *LP_B_Buy;
        TButton *LP_B_Loan;
        TButton *HO_B_Game;
        TButton *HO_B_LineUp;
        TPanel *HO;
        TShape *HO_B1;
        TButton *HO_B_NextWeek;
        TButton *HO_B_Table;
        TPanel *TA;
        TShape *TA_B1;
        TButton *TA_B_Back;
        TLabel *TA_L_Position;
        TShape *TA_B2;
        TLabel *TA_L_NameHead;
        TLabel *TA_L_PositionHead;
        TLabel *TA_L_WinsHead;
        TLabel *TA_L_DrawsHead;
        TLabel *TA_L_LosesHead;
        TLabel *TA_L_ScoreHead;
        TLabel *TA_L_PointsHead;
        TLabel *TA_L_Wins;
        TLabel *TA_L_Draws;
        TLabel *TA_L_ScoreA;
        TLabel *TA_L_Loses;
        TLabel *TA_L_ScoreH;
        TLabel *TA_L_Points;
        TLabel *TA_L_Name;
        TShape *TA_B3;
        TLabel *TA_L_LRound;
        TLabel *TA_L_NRound;
        TLabel *TA_L_LR_D;
        TLabel *TA_L_LR_DS;
        TLabel *TA_L_LR_HS;
        TLabel *TA_L_LR_H;
        TLabel *TA_L_NR_D;
        TLabel *TA_L_NR_H;
        TLabel *TA_L_MatchesHead;
        TLabel *TA_L_Matches;
        TLabel *TA_L_ShootsHead;
        TLabel *TA_L_ShootsH;
        TLabel *TA_L_ShootsA;
        TLabel *MA_O6;
        TPanel *SF;
        TShape *SF_B1;
        TButton *SF_B_Back;
        TComboBox *SF_CB_Lines;
        TLabel *SF_L_PostHead;
        TShape *SF_B2;
        TLabel *SF_L_Post;
        TLabel *SF_L_NameHead;
        TLabel *SF_L_Name;
        TLabel *SF_L_AgeHead;
        TLabel *SF_L_Age;
        TLabel *SF_L_FSHead;
        TLabel *SF_L_FS;
        TLabel *SF_L_TSHead;
        TLabel *SF_L_TS;
        TLabel *SF_L_ZSHead;
        TLabel *SF_L_ZS;
        TLabel *SF_L_LineHead;
        TLabel *SF_L_Line;
        TShape *SF_B3;
        TLabel *SF_L_EnHead;
        TLabel *SF_L_En;
        TButton *HO_B_SetFormation;
        TGroupBox *SF_GB_Attackers;
        TGroupBox *SF_GB_Defenders;
        TComboBox *SF_CB_1Def2;
        TComboBox *SF_CB_1Def1;
        TComboBox *SF_CB_1Att2;
        TComboBox *SF_CB_1Att3;
        TGroupBox *SF_GB_Goalkeeper;
        TComboBox *SF_CB_1Goa1;
        TComboBox *SF_CB_2Att1;
        TComboBox *SF_CB_2Att2;
        TComboBox *SF_CB_2Att3;
        TComboBox *SF_CB_3Att1;
        TComboBox *SF_CB_3Att2;
        TComboBox *SF_CB_3Att3;
        TComboBox *SF_CB_2Def1;
        TComboBox *SF_CB_2Def2;
        TComboBox *SF_CB_3Def1;
        TComboBox *SF_CB_3Def2;
        TComboBox *SF_CB_1Att1;
        TButton *SF_B_Save;
        TGroupBox *SF_GB_Lines;
        TLabel *SF_L_NumberHead;
        TLabel *SF_L_Number;
        TGroupBox *GroupBox1;
        TComboBox *ComboBox1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TGroupBox *GroupBox2;
        TComboBox *ComboBox2;
        TButton *Button4;
        TButton *Button7;
        TComboBox *LP_CB_Training;
        TComboBox *LP_CB_TrainingIntensity;
        TButton *LP_B_Training;
        TButton *LP_B_Finances;
        TButton *LP_B_Hall;
        TPanel *LP_B6;
        TShape *LP_B7;
        TGroupBox *LP_GB_Training;
        TGroupBox *LP_GB_Players;
        TComboBox *LP_CB_Players;
        TButton *LP_B_Kick;
        TGroupBox *LP_GB_Team;
        TGroupBox *GroupBox3;
        TLabel *HO_L_Label1;
        TLabel *HO_L_Label2;
        TLabel *HO_L_Label3;
        TLabel *HO_L_Label4;
        TComboBox *TE_CB_Teams;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall MA_LButton1Click(TObject *Sender);
        void __fastcall MA_SD_LClick(TObject *Sender);
        void __fastcall MA_SH_LClick(TObject *Sender);
        void __fastcall HO_B_LineUpClick(TObject *Sender);
        void __fastcall QuitClick(TObject *Sender);
        void __fastcall LP_P_LClick(TObject *Sender);
        void __fastcall LP_C_LClick(TObject *Sender);
        void __fastcall LP_J_LClick(TObject *Sender);
        void __fastcall LP_V_LClick(TObject *Sender);
        void __fastcall LP_F_LClick(TObject *Sender);
        void __fastcall LP_T_LClick(TObject *Sender);
        void __fastcall LP_Z_LClick(TObject *Sender);
        void __fastcall LP_L_LClick(TObject *Sender);
        void __fastcall HO_B_NextWeekClick(TObject *Sender);
        void __fastcall HO_B_TableClick(TObject *Sender);
        void __fastcall TA_B_BackClick(TObject *Sender);
        void __fastcall HO_B_SetFormationClick(TObject *Sender);
        void __fastcall SF_B_BackClick(TObject *Sender);
        void __fastcall SF_CB_1Att1CloseUp(TObject *Sender);
        void __fastcall SF_CB_1Att2CloseUp(TObject *Sender);
        void __fastcall SF_CB_2Att3CloseUp(TObject *Sender);
        void __fastcall SF_CB_2Att2CloseUp(TObject *Sender);
        void __fastcall SF_CB_2Att1CloseUp(TObject *Sender);
        void __fastcall SF_CB_1Att3CloseUp(TObject *Sender);
        void __fastcall SF_CB_3Att1CloseUp(TObject *Sender);
        void __fastcall SF_CB_3Att2CloseUp(TObject *Sender);
        void __fastcall SF_CB_3Att3CloseUp(TObject *Sender);
        void __fastcall SF_CB_1Def1CloseUp(TObject *Sender);
        void __fastcall SF_CB_1Def2CloseUp(TObject *Sender);
        void __fastcall SF_CB_2Def1CloseUp(TObject *Sender);
        void __fastcall SF_CB_2Def2CloseUp(TObject *Sender);
        void __fastcall SF_CB_3Def1CloseUp(TObject *Sender);
        void __fastcall SF_CB_3Def2CloseUp(TObject *Sender);
        void __fastcall SF_B_SaveClick(TObject *Sender);
        void __fastcall SF_CB_LinesChange(TObject *Sender);
        void __fastcall SF_L_PostHeadClick(TObject *Sender);
        void __fastcall SF_L_NameHeadClick(TObject *Sender);
        void __fastcall SF_L_AgeHeadClick(TObject *Sender);
        void __fastcall SF_L_FSHeadClick(TObject *Sender);
        void __fastcall SF_L_TSHeadClick(TObject *Sender);
        void __fastcall SF_L_ZSHeadClick(TObject *Sender);
        void __fastcall SF_L_LineHeadClick(TObject *Sender);
        void __fastcall SF_L_PostHeadDblClick(TObject *Sender);
        void __fastcall SF_L_NameHeadDblClick(TObject *Sender);
        void __fastcall SF_L_AgeHeadDblClick(TObject *Sender);
        void __fastcall SF_L_FSHeadDblClick(TObject *Sender);
        void __fastcall SF_L_TSHeadDblClick(TObject *Sender);
        void __fastcall SF_L_ZSHeadDblClick(TObject *Sender);
        void __fastcall SF_L_LineHeadDblClick(TObject *Sender);
        void __fastcall LP_P_LDblClick(TObject *Sender);
        void __fastcall LP_C_LDblClick(TObject *Sender);
        void __fastcall LP_J_LDblClick(TObject *Sender);
        void __fastcall LP_V_LDblClick(TObject *Sender);
        void __fastcall LP_F_LDblClick(TObject *Sender);
        void __fastcall LP_T_LDblClick(TObject *Sender);
        void __fastcall LP_Z_LDblClick(TObject *Sender);
        void __fastcall LP_L_LDblClick(TObject *Sender);
        void __fastcall SF_L_NumberHeadClick(TObject *Sender);
        void __fastcall SF_L_NumberHeadDblClick(TObject *Sender);
        void __fastcall SF_L_EnHeadClick(TObject *Sender);
        void __fastcall SF_L_EnHeadDblClick(TObject *Sender);
        void __fastcall LP_Gl_LClick(TObject *Sender);
        void __fastcall LP_Gl_LDblClick(TObject *Sender);
        void __fastcall LP_Al_LClick(TObject *Sender);
        void __fastcall LP_Al_LDblClick(TObject *Sender);
        void __fastcall LP_En_LClick(TObject *Sender);
        void __fastcall LP_En_LDblClick(TObject *Sender);
        void __fastcall HO_B_GameClick(TObject *Sender);
        void __fastcall ZpetClick(TObject *Sender);
        void __fastcall LP_B_BuyClick(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall LP_B_TrainingClick(TObject *Sender);
        void __fastcall LP_B_KickClick(TObject *Sender);
private:	// User declarations
        Tym *Teams[12];
        Zapas *Match[6];
        ZapasList *MatchList;
        Manazer *Manager;
        Kalendar *Calendar;
        int iMatchIndex;
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
        int t;
        int R1;
        int G1;
        int B1;
        int R2;
        int G2;
        int B2;
        String Logo;
        String Hall;
        int Capacity;
        //int RozpisLigy[11][2][6];
        //int AktKolo;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall setColors();
        void __fastcall Draw();
        void __fastcall setLineup(int iTeam); 
        void __fastcall setLayouts1();
        void __fastcall setLayouts2();
        void __fastcall setColorsLP();
        void __fastcall setPlayersLP();
        void __fastcall inicializujDalsiKolo();
        void __fastcall setUmisteni();
        void __fastcall setColorsSF();
        void __fastcall setPlayersSF();
        void __fastcall setComboBoxesSF();
        void __fastcall nextDay();
        void __fastcall setCPUteamsTraining();
        void __fastcall trainingPalyers();
        void __fastcall updateEnergie();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 