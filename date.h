#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>



class Date
{
private:
    unsigned short day_;
    unsigned short month_;
    unsigned int year_;
    unsigned short day_max_;
    const unsigned short month_max_ = 12;
    void DayMaxSet()
    {
        day_max_ = MaxDay(month_, year_);
    }
    unsigned short MaxDay(unsigned short month, unsigned int year)
    {
        switch (month)
        {
            case 4  : return 30;
            case 6  : return 30;
            case 9  : return 30;
            case 11 : return 30;
            case 2  :
            {
                if(isYearLeap(year))
                    return 28;
                else
                    return 29;
            }
            default: return 31;
        }
    }

    bool isYearLeap(unsigned int year)
    {
         if(year%4 || (year%100 == 0 && year % 400))
             return false;
         else
             return true;
    }
    bool isDateCorrect(unsigned short day, unsigned short month, unsigned int year)
    {
        if((month > 0) && (month <= month_max_))
        {
            if((day > 0) && (day <= MaxDay(month, year)))
            {
                if(year > 0)

                return true;
            }
        }

        return false;
    }



public:
    Date() : day_(1), month_(1), year_(1), day_max_(31){}
    Date(const Date& d);
    Date(unsigned short day,unsigned short month, unsigned int year) :
        day_(day), month_(month), year_(year)
    {
       DayMaxSet();
    }


    void SetDate(unsigned short day = 1, unsigned short month = 1, unsigned int year = 1);

    void SetCurrentDate();
    Date Add(unsigned short days = 0, unsigned short months = 0, unsigned int years = 0);
    Date& operator =(const Date& op2);

    Date& operator ++(int);
    Date& operator --(int);
    Date  operator -(unsigned int days)const;
    Date  operator +(unsigned int days)const;
    unsigned int operator -(const Date& op2)const;

    //Relative opertorn
    bool operator < (const Date& op2)const;
    bool operator > (const Date& op2)const;
    bool operator ==(const Date& op2)const;
    bool operator !=(const Date& date)const;
    bool operator <=(const Date& op2)const;
    bool operator >=(const Date& op2)const;

    //I/O Operators
    friend std::ostream& operator <<(std::ostream &os, const Date& date);
    friend std::istream& operator >>(std::istream &is, Date& date);

    unsigned int GetYear()
    {
        return year_;
    }
    unsigned short GetMonth()
    {
        return month_;
    }
    unsigned short GetDay()
    {
        return day_;
    }

};

#endif // DATE_H
