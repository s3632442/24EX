#include "Time.h"
#include <exception>
#include <iomanip>

Time::Time():
    hour(0), minute(0), second(0)
{}

Time::Time(unsigned int hour, unsigned int minute, unsigned int second):
                            hour(hour), minute(minute), second(second)
{}


Time::Time(unsigned int nSeconds){
    this->setTime(nSeconds);
}

Time::Time(const Time& other):
                hour(other.hour), minute(other.minute), second(other.second)
{}

Time::Time(Time&& other):
                hour(other.hour), minute(other.minute), second(other.second)
{}

Time::~Time()
{}


unsigned int Time::getHour(){
    return hour;
}
unsigned int Time::getMinute(){
    return minute;
}
unsigned int Time::getSecond(){
    return second;
}
unsigned int Time::getnSeconds() const{
    return hour*MINS_PER_HOUR*SECS_PER_MIN + minute*SECS_PER_MIN + second;
}
void Time::setTime(unsigned int nSeconds){

    second  = nSeconds%(SECS_PER_MIN);
    nSeconds = nSeconds/SECS_PER_MIN;
    minute = nSeconds%(MINS_PER_HOUR);
    hour = nSeconds/MINS_PER_HOUR;
}


void Time::setTime(unsigned int hour, unsigned int minute, unsigned int second){
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

/*                                           */
/* YOU MAY ADD YOUR MODIFICATIONS HERE       */
/*                                           */