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
    Date d1, d2;
    d1.SetDate(29,01,1996);
    d2.SetDate(2, 12, 1996);
    std::cout << d1 << std::endl << d2 << std::endl;
    if(d1 < d2)
    {
        std::cout << "YES";
    }
    else{
        std::cout << "NO";
    }


    return 0;
}

