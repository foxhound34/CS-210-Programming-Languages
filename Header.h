#pragma once // preprocessor directive designed to cause the current source file to be included only once in a single compilation.
#ifndef SOURCE_H //header guards Zybooks 4.16.1
#define SOURCE_H //header guards Zybooks 4.16.1

class Time {
//private variable initialiation
private:
    int hour;
    int minute;
    int second;
 
public:
    Time();//default contructor

    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }
    //Getter and Setters. I can't remember where I found this single line style from.
    void setHour(int h) { hour = h; } //mutator allows for write only access. void has no return

    int getHour() { return hour; } //accessor allows for read only accesses

    void setMinute(int m) { minute = m; }

    int getMinute() { return minute; }

    void setSecond(int s) { second = s; }

    int getSecond() { return second; }
};
#endif //instructs the processor to process code between the guards and the endif. Zybooks 4.16.1 