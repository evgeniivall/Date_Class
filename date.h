#ifndef DATE_H
#define DATE_H
#include <iostream>

//01 - 31
//02 - 28/29
//03 - 31
//04 - 30 *
//05 - 31
//06 - 30 *
//07 - 31
//08 - 31
//09 - 30 *
//10 - 31
//11 - 30 *
//12 - 31

enum Months { JAN = 1, FEB, MAR, APR, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC};


class Date
{
private:
    unsigned day_;
    unsigned month_;
    unsigned year_;
    unsigned day_max_;
    const unsigned month_max_ = 12;
    void DayMaxSet()
    {
        switch (month_)
        {
            case 4  : day_max_ = 30; break;
            case 6  : day_max_ = 30; break;
            case 9  : day_max_ = 30; break;
            case 11 : day_max_ = 30; break;
            case 2  :
            {
                if(year_%4 || (year_%100 == 0 && year_ % 400))
                    day_max_ = 28;
                else
                    day_max_ = 29;
            }
            default: day_max_ = 31;
        }

    }

public:
    Date(); //Set the current date
    Date(unsigned day,unsigned month, unsigned year) : day_(day), month_(month), year_(year)
    {
       DayMaxSet();
    }
    Date& operator++(int);
    Date& operator--(int);
    Date& operator-(Date& rvalue);
    Date& operator-(unsigned days);
    Date& operator+(unsigned days);
    Date& operator =(Date& op2);
    void Show();

};

#endif // DATE_H
