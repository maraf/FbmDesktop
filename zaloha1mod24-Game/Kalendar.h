/*------------------------------------------------------------------------------------------*/
/*                                class Kalendar                                            */
/*                                verze 1.0                                                 */
/*------------------------------------------------------------------------------------------*/

#ifndef KalendarH
#define KalendarH

#include <StdCtrls.hpp>
#include <stdio.h>

class Kalendar {

      private:
              int Calendar[102];
              int Schedules[22][6][3];
              int ThisWeek;
              int ThisRound;
              int Year;
              
              bool League;
              bool Transfer;
              bool Holiday;

              void inicializace(String fileName, int iYear, int iThisWeek, int iThisRound);
              void loadSchedules(String fileName);
      public:
              Kalendar(String fileCalendar, String fileSchedules);
              Kalendar(String fileCalendar, String fileSchedules, int iYear, int iThisWeek, int iThisRound);
              ~Kalendar();
        
              void nextSeason();
              void nextDay();
              
              int getSchedule(int match, bool home);
              int getSchedule(int round, int match, bool home);
              int getMatchId(int match);
              int getMatchId(int round, int match);
              int getWeek();
              int getRound();
              int getYear();
              
              bool isTransferPeriod();
              bool isLeague();
              bool isHoliday();
};

#endif
