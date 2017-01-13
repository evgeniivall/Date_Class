#include <iostream>
#include "date.h"
int main(int argc, char *argv[])
{
    Date d(25,01,2017);
    Date d1(25,1,1);
    d1 = d;
    d1 = d1+10;
    d1.Show();

    return 0;
}
