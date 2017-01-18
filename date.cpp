#include "date.h"



Date::Date(const Date &d)
{
    this->day_ = d.day_;
    this->month_ = d.month_;
    DayMaxSet();
    this->year_ = d.year_;
    this->day_max_ = d.day_max_;
}

void Date::SetCurrentDate()
{
    time_t t;
    tm *tk;
    time(&t);
    tk=localtime(&t);
    year_ = tk->tm_year + 1900;
    month_ = tk->tm_mon + 1;
    day_ = tk->tm_mday;
    DayMaxSet();


}
Date Date::Add(ui days, ui months, ui years)
{
    year_ += years;
    month_ += months;
    if(month_ > 12)
    {
        months %= 12;
        year_++;
    }
    DayMaxSet();
    day_ += days;
    if(day_ > day_max_)
    {
        day_ %= day_max_;
        month_++;
        if(month_ > 12)
        {
            months %= 12;
            year_++;
        }
        DayMaxSet();
    }


}

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

Date& Date::operator =(const Date& date)
{

    day_ = date.day_;
    month_ = date.month_;
    year_ = date.year_;
    day_max_ = date.day_max_;
    return *this;
}

Date Date::operator+(unsigned days)
{
    Date temp(*this);
    for(int i = 0; i < days; i++)
        temp++;
    return temp;
}
//18.01.2017 - 29.01.1996
Date Date::operator -(const Date& op2)
{
    Date temp;
    temp.year_ = year_ - op2.year_;
    if(month_ >= op2.month_)
        temp.month_ = month_ - op2.month_;
    else
    {
        temp.month_ = 12 - op2.month_ + month_;
        temp.year_--;
    }
    temp.DayMaxSet();
    if(day_ >= op2.day_)
        temp.day_ = day_ - op2.day_;
    else
    {
        if(temp.month_ > 1)
        {
            temp.month_--;
            temp.DayMaxSet();
        }
        else
        {
            temp.year_--;
            temp.month_ = 12;
            DayMaxSet();
        }
        temp.day_ = day_max_ - op2.day_ + day_;
    }
    return temp;

}


std::ostream& operator <<(std::ostream &os, const Date& date)
{
    if(date.day_ < 10)
        os << 0 << date.day_;
    else
        os << date.day_;
    os << '.';

    if(date.month_ < 10)
        os << 0 << date.month_;
    else
        os << date.month_;
    os  << '.';
    os << date.year_;
    return os;
}

std::istream& operator >>(std::istream &is, Date& date)
{
    char c;
    is >> date.day_ >> c >> date.month_ >> c >> date.year_;
    date.DayMaxSet();
    //if(date.isDateCorrect())
    //    return is;
    //else

    return is;
}


bool Date::operator <(const Date& date)
{
    if(year_ > date.year_)
        return 0;
    else if(month_ > date.month_)
        return 0;
    else if(day_ > date.day_)
        return 0;
    else if(*this != date)
        return 1;
    else
        return 0;
}


bool Date::operator >(const Date& date)
{
    if(year_ > date.year_)
        return 1;
    else if(month_ > date.month_)
        return 1;
    else if(day_ > date.day_)
        return 1;
    else
        return 0;
}


bool Date::operator ==(const Date& date)
{
    if(year_ != date.year_)
        return 1;
    else if(month_ != date.month_)
        return 1;
    else if(day_ != date.day_)
        return 1;
    else
        return 0;
}

bool Date::operator ==(const Date& date)
{
    if(year_ == date.year_)
        return 1;
    else if(month_ != date.month_)
        return 1;
    else if(day_ != date.day_)
        return 1;
    else
        return 0;
}

bool Date::operator <=(const Date& date)
{
    if((*this < date) || (*this == date))
        return 1;
    else
        return 0;
}



bool Date::operator >=(const Date& date)
{
    if((*this > date) || (*this == date))
        return 1;
    else
        return 0;
}
