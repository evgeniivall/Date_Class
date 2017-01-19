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
Date Date::Add(unsigned short days, unsigned short months, unsigned int years)
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
    return *this;
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

void Date::SetDate(unsigned short day, unsigned short month, unsigned int year)
{
    if(isDateCorrect(day, month, year))
    {
        day_ = day;
        month_ = month;
        year_ = year;
        DayMaxSet();
    }
    else
    {
        SetDate();
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



unsigned int Date::operator -(const Date& op2)const
{

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
    unsigned int day, month, year;
    is >> day >> c >> month >> c >> year;
    date.SetDate(day, month, year);
    return is;
}


bool Date::operator <(const Date& date)const
{
    if(year_ < date.year_)
        return 1;
    else if(year_ == date.year_)
    {
        if(month_ < date.month_)
            return 1;
        else if(month_ == date.month_)
        {
            if(day_ < date.day_)
                return 1;
        }
    }
    return 0;

}


bool Date::operator >(const Date& date)const
{
    if(year_ > date.year_)
        return 1;
    else if(year_ == date.year_)
    {
        if(month_ > date.month_)
            return 1;
        else if(month_ == date.month_)
        {
            if(day_ > date.day_)
                return 1;
        }
    }
    return 0;
}

bool Date::operator ==(const Date& date)const
{
    return ((year_ == date.year_) && (month_ == date.month_) && (year_ == date.year_));
}

bool Date::operator !=(const Date& date)const
{
    return (!(*this == date));
}

bool Date::operator <=(const Date& date)const
{
    return ((*this < date) || (*this == date));
}

bool Date::operator >=(const Date& date)const
{
    return ((*this < date) || (*this == date));
}
