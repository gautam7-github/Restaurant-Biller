#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <fstream>
#include <vector>
#include "items.h"
using namespace std;

items::items()
{
    finalSale = 0;
    order = 0;
    // change this if dishes increased/decreased
    total = 11;
    // write total items + 1
    total = total + 1;
    // ---------------------

    dishes = new (nothrow) string[total];
    dishes[0] = "NULL ITEM";
    price[0] = 0;

    dishes[1] = "VEG. SANDWICH - COLD";
    price[1] = 30;

    dishes[2] = "VEG. SANDWICH - GRILLED";
    price[2] = 40;

    dishes[3] = "VEG. BURGER - NORMAL";
    price[3] = 30;

    dishes[4] = "VEG. BURGER - SUPREME";
    price[4] = 40;

    dishes[5] = "VEG. BURGER - ULTIMATE";
    price[5] = 55;

    dishes[6] = "COCA COLA - 200mL";
    price[6] = 20;

    dishes[7] = "COCA COLA - 500mL";
    price[7] = 50;

    dishes[8] = "SPRITE - 200mL";
    price[8] = 20;

    dishes[9] = "SPRITE - 500mL";
    price[9] = 50;

    dishes[10] = "FRUIT JUICE - 300mL";
    price[10] = 30;

    dishes[11] = "FRUIT JUICE - 600mL";
    price[11] = 60;

    quantity = new (nothrow) unsigned int[total];

    if (!quantity)
    {
        cout << "FATAL ERROR\n";
        cout << endl;
        exit(1);
    }
    for (int i = 1; i < total; i++)
    {
        sprice[i] = 0;
    }
    takeaway = false;
};
