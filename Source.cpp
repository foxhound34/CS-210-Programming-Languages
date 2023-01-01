/* Project 1: CHADA Tech Clock
   CS210 Professor Eric Gregori
   Code Written by Derek Bamford
   Date: 11/12/22 Uploaded
*/

#include <iostream> // standard input/output stream
#include <string> //Allows for string data
#include <stdlib.h>//standard library

using namespace std;
#include "Header.h" //hearder for .ccp to read .h file containing our class

//Code returns two didgit string or adds 0 to single string to make a two digit string
string twoDigitString(unsigned int n) {

    if (n >= 10 && n <= 59) {
        string str = to_string(n);//converts integer to string
        return str;
    }
    else {
        string str = "0" + to_string(n);
        return str;
    }
}
//code loops to add char c to output, our output char will be *
string nCharString(size_t n, char c) {

    string strVar;
    int i;

    for (i = 0; i < n; ++i) {
        if (i >= 0) {
            strVar += c;
        }
    }
    return strVar;
}
//Passes the attributes h, m, s and formats it as a 24hr clock and prints
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {

    string convert = twoDigitString(h) + ':' + twoDigitString(m) + ':' + twoDigitString(s);
    return convert;
}
//Passes the attributes h, m, s and formats it as a 24hr clock
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {

    string convert;
    // code checks to see how h should be converted from a 24hr clock to a 12hr clock and prints
    if (h >= 13 && h <= 23) {
        h = h - 12;
        convert = twoDigitString(h) + ':' + twoDigitString(m) + ':' + twoDigitString(s) + " " + "P M";
        return convert;
    }
    if (h == 0) {
        h = 12;
        convert = twoDigitString(h) + ':' + twoDigitString(m) + ':' + twoDigitString(s) + " " + "A M";
        return convert;
    }
    if (h == 12) {
        convert = twoDigitString(h) + ':' + twoDigitString(m) + ':' + twoDigitString(s) + " " + "P M";
        return convert;
    }
    else {
        convert = twoDigitString(h) + ':' + twoDigitString(m) + ':' + twoDigitString(s) + " " + "A M";
        return convert;
    }
}
//function that can be called to display user menu to terminal
void printMenu() {
    cout << "                *************************" << endl;
    cout << "                * 1 - Add One Hour      *" << endl;
    cout << endl;
    cout << "                * 2 - Add One Minute    *" << endl;
    cout << endl;
    cout << "                * 3 - Add One Second    *" << endl;
    cout << endl;
    cout << "                * 4 - Exit Program      *" << endl;
    cout << "                *************************" << endl;
    cout << endl;
    cout << "                    Enter menu option" << endl;
}
//function to display the 24hr and 12Hour clocks. The functions formatTime12 and formatTime24 are called to display time
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}
//function to add one hour of time after user input using .get and .set
//Time is our getter/setter class using a passby reference variable to send the addtion of 1 to the class method to be set
void addOneHour(Time& hVar) {

    int h;
    if (hVar.getHour() >= 0 && hVar.getHour() <= 22) {
        h = hVar.getHour() + 1;
        hVar.setHour(h);
        return;
    }
    if (hVar.getHour() == 23) {
        h = 0;
        hVar.setHour(h);
    }
}
//function to add one minute of time after user input using .get and .set
void addOneMinute(Time& minVar) {

    int m;
    if (minVar.getMinute() >= 0 && minVar.getMinute() <= 58) {
        m = minVar.getMinute() + 1;
        minVar.setMinute(m);
        return;
    }
    if (minVar.getMinute() == 59) {
        m = 0;
        addOneHour(minVar);
        minVar.setMinute(m);
    }
}
//function to add one second of time after user input using .get and .set
void addOneSecond(Time& secVar) {

    int s;
    if (secVar.getSecond() >= 0 && secVar.getSecond() <= 58) {
        s = secVar.getSecond() + 1;
        secVar.setSecond(s);
        return;
    }
    if (secVar.getSecond() == 59) {
        s = 0;
        addOneMinute(secVar);
        secVar.setSecond(s);
    }
}

void mainMenu(Time myTime) {
    int n = 0;

    // looping switch case for user input
    while (n != 4) {

        system("CLS");// clears screen found at https://mathbits.com/MathBits/CompSci/Screen/clear.htm
        displayClocks(myTime.getHour(), myTime.getMinute(), myTime.getSecond());//Calls displayClock to get Hour, Minute, Second
        printMenu();//calls print menu function

        cin >> n;

        switch (n) {
        case 1:
            addOneHour(myTime);
            break; //prevents fall through
        case 2:
            addOneMinute(myTime);
            break;
        case 3:
            addOneSecond(myTime);
            break;
        case 4:
            cout << "Goodbye" << endl; //exits loop 
            break;
        default:
            cout << "Invald Entry" << endl; //default print statement
        }
    }
}
int main() {
    Time myObj(21, 30, 0); //initialized the object myObj and passes the attributes into the time class to initialized the start time of the clock
    mainMenu(myObj); //calls the user menu function
    return 0;//closes program
}