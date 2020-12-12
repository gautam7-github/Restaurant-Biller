// standard libraries
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <fstream>
// ----------------
// custom made libraries
#include "items.h"
#include "mainDo.h"
// ---------------
using namespace std;
class admin
{
private:
    mainDo RestaurantBiller;

public:
    void adminUserDo()
    {
        bool cont = RestaurantBiller.resetVals();
        int retVal;
        bool retVal_bool;
        if (cont)
        {
            while (true)
            {

                RestaurantBiller.displayMenu();
                retVal = RestaurantBiller.askforOrder();

                if (retVal)
                {
                    exit(EXIT_SUCCESS);
                }
                else
                {
                    retVal_bool = RestaurantBiller.resetVals();
                    if (retVal_bool)
                        continue;
                    else
                        cout << "FATAL ERROR" << endl;
                }
            }
        }
    }
};
int main()
{
    srand(time(NULL));
    class admin adminUser;
    adminUser.adminUserDo();
    return 0;
}