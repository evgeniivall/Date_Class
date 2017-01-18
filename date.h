#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>


typedef unsigned int ui;

class Date
{
private:
    ui day_;
    ui month_;
    ui year_;
    ui day_max_;
    const ui month_max_ = 12;
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
                if(isYearLeap(year_))
                    day_max_ = 28;
                else
                    day_max_ = 29;
            }
            default: day_max_ = 31;
        }

    }
    bool isYearLeap(ui year)
    {
         if(year_%4 || (year_%100 == 0 && year_ % 400))
             return false;
         else
             return true;
    }
    bool isDateCorrect()
    {
        if((month_ > 0) && (month_ < month_max_))
        {
            if((day_ > 0) && (day_ < day_max_))
                return 1;
        }
        return 0;
    }

public:
    Date() : day_(1), month_(1), year_(1), day_max_(31){}
    Date(const Date& d);
    Date(ui day,ui month, ui year) : day_(day), month_(month), year_(year)
    {
       DayMaxSet();
    }
    void SetCurrentDate();
    Date Add(ui days = 0, ui months = 0, ui years = 0);
    Date& operator ++(int);
    Date& operator --(int);
    Date  operator -(ui days);
    Date  operator +(ui days);

    Date& operator =(const Date& op2);
    Date  operator -(const Date& op2);//Repair
    Date  operator +(const Date& op2);//Implement
    //TODO: implement relational operators
    bool operator<(const Date& op2);
    bool operator>(const Date& op2);
    bool operator==(const Date& op2);
    bool operator<=(const Date& op2);
    bool operator>=(const Date& op2);
    //
    friend std::ostream& operator <<(std::ostream &os, const Date& date);
    friend std::istream& operator >>(std::istream &is, Date& date);

    ui GetYear()
    {
        return year_;
    }
    ui GetMonth()
    {
        return month_;
    }
    ui GetDay()
    {
        return day_;
    }

};

#endif // DATE_H
