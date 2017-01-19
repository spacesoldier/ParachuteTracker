#ifndef TIMER_H
#define TIMER_H

// hardware library
//#include "../lib/RTClib/RTClib.h"
#include <RTCLib.h>

RTC_DS1307 rtc;
//char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
DateTime timeNow;
String timestr = "";

void getDateTime(){
    timeNow = rtc.now();
    timestr = "";
    timestr.concat(timeNow.year());
    timestr.concat('-');
    timestr.concat(timeNow.month());
    timestr.concat('-');
    timestr.concat(timeNow.day());
    timestr.concat(' ');
    if (timeNow.hour()<10){
      timestr.concat('0');
    }
    timestr.concat(timeNow.hour());
    timestr.concat(':');
    if (timeNow.minute()<10){
      timestr.concat('0');
    }
    timestr.concat(timeNow.minute());
    timestr.concat(':');
    if (timeNow.second()<10){
      timestr.concat('0');
    }
    timestr.concat(timeNow.second());
}


void initClock(){
  if (! rtc.begin()) {
//    logData("RTC fail");
  }

//  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (! rtc.isrunning()) {
//    logData("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}



#endif
