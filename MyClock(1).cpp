// MyClock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Jewelia England
// CS 210 Project 1
// November 12 2023
// ClockApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <windows.h> 
#include <time.h>
#include <string> 

using namespace std;
class Clock
{

public:

//Getters ands setters 
    int getGmtMinute(void)
    {
        return gmtMinute;
    }
    int getGmtHour(void)
    {
        return gmtHour;
    }
    int getGmtSecond(void)
    {
        return gmtSecond;
    }
    void setGmtMinute(int iMinute)
    {
        gmtMinute = iMinute;
    }
    void setGmtHour(int iHour)
    {
        gmtHour = iHour;
    }
    void setGmtSecond(int iSecond)
    {
        gmtSecond = iSecond;
    }
    void addGmtHour()
    {
        gmtHour += 1;
    }
    void addGmtMinute()
    {
        gmtMinute += 1;
    }
    void addGmtSecond()
    {
        gmtSecond += 1;
    }


    int getMinute(void)
    {
        return minute;
    }
    int getHour(void)
    {
        return hour;
    }
    int getSecond(void)
    {
        return second;
    }
    void setMinute(int iMinute)
    {
        minute = iMinute;
    }
    void setHour(int iHour)
    {
        hour = iHour;
    }
    void setSecond(int iSecond)
    {
        second = iSecond;
    }
    void addHour()
    {
        hour += 1;
    }
    void addMinute()
    {
        minute += 1;
    }
    void addSecond()
    {
        second += 1;
    }
    void setLocalTime(string ltime)
    {
        localTime = ltime;
    }
    void setGmtTime(string gtime)
    {
        gmtTime = gtime;
    }
    string getLocalTime()
    {
        return(localTime);
    }
    string getGmtTime()
    {
        return(gmtTime);
    }
    //Private variables access through mutators
private:
    int hour = 12;
    int minute = 12;
    int second = 12;
    int gmtHour = 12;
    int gmtMinute = 12;
    int gmtSecond = 12;
    string localTime;
    string gmtTime;
};
// Driver Code 
int main()
{
    Clock myClock;
    int menuChoice;

    time_t t_time = time(0);

    tm* gmt_time = gmtime(&t_time);
    tm* local_time = localtime(&t_time);

    myClock.setHour(local_time->tm_hour);
    myClock.setMinute(local_time->tm_min);
    myClock.setSecond(local_time->tm_sec);

    myClock.setGmtHour(gmt_time->tm_hour);
    myClock.setGmtMinute(gmt_time->tm_min);
    myClock.setGmtSecond(gmt_time->tm_sec);

    // Main loop
    while (1)
    {
        system("cls");
        //building time strings
        myClock.setLocalTime(std::to_string(myClock.getHour()) + ":" + (myClock.getMinute() < 10 ? "0" : "") + std::to_string(myClock.getMinute()) + ":" + (myClock.getSecond() < 10 ? "0" : "") + std::to_string(myClock.getSecond()));

        myClock.setGmtTime(std::to_string(myClock.getGmtHour()) + ":" + (myClock.getGmtMinute() < 10 ? "0" : "") + std::to_string(myClock.getGmtMinute()) + ":" + (myClock.getGmtSecond() < 10 ? "0" : "") + std::to_string(myClock.getGmtSecond()));

        //printing out time
        cout << "****************************             **************************" << endl << endl;
        cout << "*         12-Hour Clock    *             *      24-Hour Clock     *" << endl << endl;
        cout << "*          " << myClock.getLocalTime() << "        *             "            "*       " << myClock.getGmtTime() << "         *" << endl << endl;
        cout << "****************************             **************************" << endl << endl << endl;

        // print out menu        cout << "******************************************************" << endl;
        cout << "*    1 - Add One Hour                                *" << endl << endl;
        cout << "*    2 - Add One Minute                              *" << endl << endl;;
        cout << "*    3 - Add One Second                              *" << endl << endl;
        cout << "*    4 - Exit Program                                *" << endl;
        cout << "******************************************************" << endl;

        // get input
        cin >> menuChoice;
        switch (menuChoice)
        {
        case 1:
            myClock.addGmtHour();
            myClock.addHour();
            break;
        case 2:
            myClock.addGmtMinute();
            myClock.addMinute();
            break;
        case 3:
            myClock.addGmtSecond();
            myClock.addSecond();
            break;
        case 4:
            exit(0);
            break;

        default:
            break;

        }
       // system("cls");
    }
}


