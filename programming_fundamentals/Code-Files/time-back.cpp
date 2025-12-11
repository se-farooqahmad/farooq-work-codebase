#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
    int days;
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Time() : days(0), hours(0), minutes(0), seconds(0) {}

    // Constructor with total seconds
    Time(int t) {
        if (t > 0)
            setSeconds(t);
        else
            days = hours = minutes = seconds = 0;
    }

    // Constructor with days, hours, minutes, seconds
    Time(int d, int h, int m, int s) {
        if (d >= 0 && h >= 0 && m >= 0 && s >= 0) {
            setSeconds(s);
            setMinutes(m);
            setHours(h);
            setDays(d);
        } else {
            days = hours = minutes = seconds = 0;
        }
    }

    // Setters
    void setDays(int d) { days = (d >= 0) ? d : 0; }

    void setHours(int h) {
        if (h >= 0) {
            days += h / 24;
            hours = h % 24;
        } else {
            hours = 0;
        }
    }

    void setMinutes(int m) {
        if (m >= 0) {
            setHours(hours + m / 60);
            minutes = m % 60;
        } else {
            minutes = 0;
        }
    }

    void setSeconds(int s) {
        if (s >= 0) {
            setMinutes(minutes + s / 60);
            seconds = s % 60;
        } else {
            seconds = 0;
        }
    }

    // Friend functions for input/output
    friend ostream &operator<<(ostream &output, const Time &T) {
        output << T.days << "~" << setfill('0') << setw(2) << T.hours
               << ":" << setfill('0') << setw(2) << T.minutes
               << ":" << setfill('0') << setw(2) << T.seconds;
        return output;
    }

    friend istream &operator>>(istream &input, Time &T) {
        int d, h, m, s;
        input >> d >> h >> m >> s;
        T.setSeconds(s);
        T.setMinutes(m);
        T.setHours(h);
        T.setDays(d);
        return input;
    }

    // Calculate total seconds
    int secondCalculate() const {
        return seconds + minutes * 60 + hours * 3600 + days * 86400;
    }

    // Print time in formatted way
    void printTime() const {
        cout << days << "~" << setfill('0') << setw(2) << hours
             << ":" << setfill('0') << setw(2) << minutes
             << ":" << setfill('0') << setw(2) << seconds << endl;
    }
};

#endif
// End of Time.h