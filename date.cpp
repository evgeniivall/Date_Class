#include "date.h"


Date::Date()
{

}

//01 - 31
//02 - 28/29
//03 - 31
//04 - 30
//05 - 31
//06 - 30
//07 - 31
//08 - 31
//09 - 30
//10 - 31
//11 - 30
//12 - 31
Date& Date::operator ++(int)
{
    if(day_ < day_max_)
    {
        day_++;
        return *this;
    }
    else if(month_ < month_max_)
    {
        day_ = 1;
        month_++;
        DayMaxSet();
        return *this;
    }
    else
    {
        day_ = 1;
        month_ = 1;
        year_++;
        DayMaxSet();
        return *this;
    }
}

Date& Date::operator --(int)
{
    if(day_ > 1)
    {
        day_--;
        return *this;
    }
    else if(month_ > 1)
    {
        month_--;
        DayMaxSet();
        day_ = day_max_;
        return *this;
    }
    else
    {
        year_--;
        month_ = month_max_;
        DayMaxSet();
        day_ = day_max_;
        return *this;
    }
}
Date& Date::operator-(Date& rvalue)
{

}

Date& Date::operator =(Date& op2)
{

    this->day_ = op2.day_;
    this->month_ = op2.month_;
    this->year_ = op2.year_;
    this->day_max_ = op2.day_max_;
    return *this;
}

Date& Date::operator+(unsigned days)
{
    Date temp(22,2,2);
    temp = *this;
    for(int i = 0; i < days; i++)
        temp++;
    return temp;
}

void Date::Show()
{
    if(day_ < 10)
        std::cout << 0 << day_;
    else
        std::cout << day_;
    std::cout << '.';

    if(month_ < 10)
        std::cout << 0 << month_;
    else
        std::cout << month_;
    std::cout << '.';
    std::cout << year_;
}
