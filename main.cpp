#include <iostream>
#include "date.h"

void d(bool a)
{
    if(a)
        std::cout << "Yes" << std::endl;
    else {
        std::cout << "No" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    Date d1(29, 1, 1996);
    Date d2(19, 9, 1996);
    Date d3(28, 5, 2005);
    Date d4(1, 1, 1993);
    Date d5(29, 1, 1996);

    d(d1 > d2);//NO
    d(d2 == d3);//NO
    d(d4 <= d3);//YES
    d(d5 == d1);//YES
    d(d4 > d1);//NO


    return 0;
}

