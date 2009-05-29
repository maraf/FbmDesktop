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
        Teams[0] = "AIK";
        Teams[1] = "ÄLVSTRANDEN";
        Teams[2] = "BALROG";
        Teams[3] = "CAPERIO_TÄBY";
        Teams[4] = "DALEN";
        Teams[5] = "FALUN";
        Teams[6] = "HELSINGBORG";
        Teams[7] = "JÄRFÄLLA";
        Teams[8] = "JÖNKÖPINGS";
        Teams[9] = "PIXBO";
        Teams[10] = "STORVRETA";
        Teams[11] = "WARBERG";

        Calendar = new Kalendar("calendar.cal", "schedules.schl");
        //Calendar->loadSchedules("schedules.schl");
        //Label7->Caption = Calendar->Schedules[0][0][1];
        //
        //String s = "";
        //for(int i = 0; i < 102; i ++) {
        //        s += Calendar->Calendar[i];
        //        s += " - ";
        //}
        //Label6->Caption = s;
        //
        if(Calendar->isLeague()) Label1->Caption = "Je liga";
        else Label1->Caption = "Neni liga";
        if(Calendar->isTransferPeriod()) Label2->Caption = "Je prestupni okno";
        else Label2->Caption = "Neni prestupni okno";
        if(Calendar->isHoliday()) Label5->Caption = "Jsou dovolene";
        else Label5->Caption = "Nejsou dovolene";
        Label3->Caption = "Je " + ((String)Calendar->getWeek()) + ". tyden";
        Label4->Caption = "Je rok: " + ((String)Calendar->getYear());
        Label6->Caption = "";

        String s1 = "HOME:\n";
        String s2 = "AWAY:\n";
        String s3 = "ID:\n";
        if(Calendar->isLeague() && Calendar->getSchedule(0, true) != -1) {
                for(int i = 0; i < 6; i ++) {
                        s1 += Teams[Calendar->getSchedule(i, true)];
                        s2 += Teams[Calendar->getSchedule(i, false)];
                        s3 += Calendar->getMatchId(i);
                        s1 += "\n";
                        s2 += "\n";
                        s3 += "\n";
                }
                Label6->Caption = (String)(Calendar->getRound() + 1) + ". kolo";
        } else {
                Label6->Caption = "";
        }
        Label7->Caption = s1;
        Label8->Caption = s2;
        Label9->Caption = s3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Calendar->nextDay();
        if(Calendar->isLeague()) Label1->Caption = "Je liga";
        else Label1->Caption = "Neni liga";
        if(Calendar->isTransferPeriod()) Label2->Caption = "Je prestupni okno";
        else Label2->Caption = "Neni prestupni okno";
        if(Calendar->isHoliday()) Label5->Caption = "Jsou dovolene";
        else Label5->Caption = "Nejsou dovolene";
        Label3->Caption = "Je " + ((String)Calendar->getWeek()) + ". tyden";
        Label4->Caption = "Je rok: " + ((String)Calendar->getYear());

        if(Calendar->getWeek() == 51) Button1->Enabled = false;

        String s1 = "HOME:\n";
        String s2 = "AWAY:\n";
        String s3 = "ID:\n";
        if(Calendar->isLeague() && Calendar->getSchedule(0, true) != -1) {
                for(int i = 0; i < 6; i ++) {
                        s1 += Teams[Calendar->getSchedule(i, true)];
                        s2 += Teams[Calendar->getSchedule(i, false)];
                        s3 += Calendar->getMatchId(i);
                        s1 += "\n";
                        s2 += "\n";
                        s3 += "\n";
                }
                Label6->Caption = (String)(Calendar->getRound() + 1) + ". kolo";
        } else {
                Label6->Caption = "";
        }
        Label7->Caption = s1;
        Label8->Caption = s2;
        Label9->Caption = s3;
}
//---------------------------------------------------------------------------


