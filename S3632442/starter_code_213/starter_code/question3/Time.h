#ifndef COSC1076_A3_TIME_H
#define COSC1076_A3_TIME_H

#include <iostream>

#define MINS_PER_HOUR   60
#define SECS_PER_MIN    60
#define HOURS_PER_DAY   24
#define SECS_PER_DAY    MINS_PER_HOUR*SECS_PER_MIN*HOURS_PER_DAY

class Time{

//Contract: This class can only be used when the time is within 
//              a particular day. If any operation takes the time 
//              to the previous or next day, then this class 
//              should not be used.

public:    
    
    // Constructors/DeConstructors
    Time();
    
    //Contract: hour, minute, second should be valid
    //          hour should be a positive number in range [0,23], 
    //          minute should be a number in range [0,59], 
    //          second should be a numbers in range [0,59]. 
    Time(unsigned int hour, unsigned int minute, unsigned int second);
    
    //nSeconds is the number of seconds since 00:00:00
    //Contract: nSeconds must be less than the number of 
    //             seconds in a day.
    Time(unsigned int nSeconds);
    
    Time(const Time& other);
    Time(Time&& other);
    ~Time();
    
    //Getters and setters
    unsigned int getHour();
    unsigned int getMinute();
    unsigned int getSecond();

    //nSeconds is the number of seconds since 00:00:00
    unsigned int getnSeconds() const;

    //Contract: nSeconds must be less than the number of 
    //             seconds in a day.
    void setTime(unsigned int nSeconds);

    //Contract: hour, minute, second should be valid
    //          hour should be a positive number in range [0,23], 
    //          minute should be a number in range [0,59], 
    //          second should be a numbers in range [0,59]. 
    void setTime(unsigned int hour, unsigned int minute, unsigned int second);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    
private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
};

#endif //COSC1076_A3_TIME_H