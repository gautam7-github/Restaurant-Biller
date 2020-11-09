#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <fstream>
#include "items.h"
#include "mainDo.h"
using namespace std;
class admin
{
private:
    mainDo RB;

public:
    admin()
    {
        cout << "YUPP" << endl;
        system("pause");
    }
    void adminUserDo()
    {
        bool cont = RB.resetVals();
        int retVal;
        bool retVal_bool;
        if (cont)
        {
            while (true)
            {

                RB.displayMenu();
                retVal = RB.askforOrder();

                if (retVal)
                {
                    exit(EXIT_SUCCESS);
                }
                else
                {
                    retVal_bool = RB.resetVals();
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

// ------------------- END OF FILE -------------------
// DONT GO DOWN
// HELL THIS WAY

/*class items
{
public:
    unsigned int *quantity;
    unsigned int order;
    string *dishes;
    unsigned int price[10];
    unsigned int sprice[10];
    bool takeaway;
    string customerName;
    unsigned int finalSale;

    items()
    {
        finalSale = 0;
        order = 0;

        dishes = new (nothrow) string[10];

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
        quantity = new (nothrow) unsigned int[10];

        if (!quantity)
        {
            cout << "FATAL ERROR\n";
            cout << endl;
            exit(1);
        }
        for (int i = 1; i < 10; i++)
        {
            quantity[i] = 0;
            cout << "OK" << endl;
        }
        for (int i = 1; i < 10; i++)
        {
            sprice[i] = 0;
        }
        takeaway = false;
    }
};
class mainDo : public items
{
public:
    void displayBrand()
    {
        system("cls");
        cout << setw(50);
        cout << "EATERIA LA GRANDE" << endl;
        cout << "\n\n";
        cout << setw(35);
        time_t now = time(0);
        char *dt = ctime(&now);
        cout << "DATE & TIME : " << dt << endl;
        cout << "\n\n";
    }
    void displayFinalBill()
    {
        system("cls");
        cout << setw(50);
        cout << "EATERIA LA GRANDE" << endl;
        cout << "\n\n";
        cout << setw(35);
        time_t now = time(0);
        char *dt = ctime(&now);

        cout << "DATE & TIME : " << dt << endl;
        cout << "\n\n";
        cout << setw(40);
        cout << "FINAL INVOICE" << endl;
        cout << "ORDER NUMBER : " << 1 + (rand() % 30);
        cout << setw(30);
        takeaway ? cout << "TAKEAWAY" : cout << "DINE-IN";
        cout << endl;
        cout << "NAME : " << customerName << endl;
    }
    void displayMenu()
    {
        displayBrand();
        cout << "ITEM[N]\t\t      ITEM NAME           \t\tPRICE\tQUANTITY\n";
        cout << endl;
        cout << "\nSANDWICHES\n";
        cout << endl;
        cout << "ITEM[1]\t\tVEG. SANDWICH - COLD      \t\t" << price[1] << ".00";
        cout << "\t" << quantity[1] << endl;
        cout << "ITEM[2]\t\tVEG. SANDWICH - GRILLED   \t\t" << price[2] << ".00 ";
        cout << "\t" << quantity[2] << endl;
        cout << "\nBURGERS\n";
        cout << endl;
        cout << "ITEM[3]\t\tVEG. BURGER   - NORMAL    \t\t" << price[3] << ".00";
        cout << "\t" << quantity[3] << endl;
        cout << "ITEM[4]\t\tVEG. BURGER   - SUPER     \t\t" << price[4] << ".00";
        cout << "\t" << quantity[4] << endl;
        cout << "ITEM[5]\t\tVEG. BURGER   - ULTIMATE  \t\t" << price[5] << ".00";
        cout << "\t" << quantity[5] << endl;
        cout << "\nBEVERAGES\n";
        cout << endl;
        cout << "ITEM[6]\t\tCOCA COLA     - 200mL     \t\t" << price[6] << ".00";
        cout << "\t" << quantity[6] << endl;
        cout << "ITEM[7]\t\tCOCA COLA     - 500mL     \t\t" << price[7] << ".00";
        cout << "\t" << quantity[7] << endl;
        cout << "ITEM[8]\t\tSPRITE        - 200mL     \t\t" << price[8] << ".00";
        cout << "\t" << quantity[8] << endl;
        cout << "ITEM[9]\t\tSPRITE        - 500mL     \t\t" << price[9] << ".00";
        cout << "\t" << quantity[9] << endl;
    }
    int askforOrder()
    {
        try
        {
            cout << "CUSTOMER NAME : ";
            cin >> customerName;
            cout << "\n\n";
            cout << "ORDER PLEASE : " << endl;

            while (true)
            {
                displayMenu();
                cout << "$$$$ -> ";
                cin >> order;
                switch (order)
                {
                case 0:
                    cout << "1. FINALIZE BILL" << endl;
                    cout << "2. EXIT WIZARD" << endl;
                    cout << "3. NEXT ORDER" << endl;
                    cin >> quantity[0];
                    switch (quantity[0])
                    {
                    case 0:
                        throw 0;
                        break;
                    case 1:
                        assert(finalSale == 0);
                        unsigned int TAKEAWAY;
                        cout << "TAKEAWAY OR DINE-IN ? " << endl;
                        cout << "##-> ";
                        cin >> TAKEAWAY;
                        if (TAKEAWAY == 1)
                        {
                            cout << "TAKEAWAY" << endl;
                            takeaway = true;
                        }
                        else
                        {
                            cout << "DINE IN" << endl;
                        }
                        system("cls");
                        finalBill();
                        break;
                    case 2:
                        return 1;
                        break;
                    case 3:
                        return 0;
                        break;
                    default:
                        cout << "NOPE NOT VALID NUMBER....NOOB" << endl;
                        break;
                    }
                    break;
                case 1:
                    cout << " QUANTITY : ";
                    cin >> quantity[0];
                    for (int counter = 1; counter <= quantity[0]; counter++)
                    {
                        quantity[1]++;
                    }
                    cout << "ITEM 1 : " << dishes[1] << " -> " << quantity[1] << endl;
                    break;
                case 2:
                    cout << " QUANTITY : ";
                    cin >> quantity[0];
                    for (int counter = 1; counter <= quantity[0]; counter++)
                    {
                        quantity[2]++;
                    }
                    cout << "ITEM 2 : " << dishes[2] << " -> " << quantity[2] << endl;
                    break;
                case 3:
                    cout << " QUANTITY : ";
                    cin >> quantity[0];
                    for (int counter = 1; counter <= quantity[0]; counter++)
                    {
                        quantity[3]++;
                    }
                    cout << "ITEM 3 : " << dishes[3] << " -> " << quantity[3] << endl;
                    break;
                case 4:
                    cout << " QUANTITY : ";
                    cin >> quantity[0];
                    for (int counter = 1; counter <= quantity[0]; counter++)
                    {
                        quantity[4]++;
                    }
                    cout << "ITEM 4 : " << dishes[4] << " -> " << quantity[4] << endl;
                    break;
                case 5:
                    cout << " QUANTITY : ";
                    cin >> quantity[0];
                    for (int counter = 1; counter <= quantity[0]; counter++)
                    {
                        quantity[5]++;
                    }
                    cout << "ITEM 5 : " << dishes[5] << " -> " << quantity[5] << endl;
                    break;
                case 6:
                    cout << " QUANTITY : ";
                    cin >> quantity[0];
                    for (int counter = 1; counter <= quantity[0]; counter++)
                    {
                        quantity[6]++;
                    }
                    cout << "ITEM 6 : " << dishes[6] << " -> " << quantity[6] << endl;
                    break;
                case 7:
                    cout << " QUANTITY : ";
                    cin >> quantity[0];
                    for (int counter = 1; counter <= quantity[0]; counter++)
                    {
                        quantity[7]++;
                    }
                    cout << "ITEM 7 : " << dishes[7] << " -> " << quantity[7] << endl;
                    break;
                case 8:
                    cout << " QUANTITY : ";
                    cin >> quantity[0];
                    for (int counter = 1; counter <= quantity[0]; counter++)
                    {
                        quantity[8]++;
                    }
                    cout << "ITEM 8 : " << dishes[8] << " -> " << quantity[8] << endl;
                    break;
                case 9:
                    cout << " QUANTITY : ";
                    cin >> quantity[0];
                    for (int counter = 1; counter <= quantity[0]; counter++)
                    {
                        quantity[9]++;
                    }
                    cout << "ITEM 9 : " << dishes[9] << " -> " << quantity[9] << endl;
                    break;
                default:
                    cout << "NOPE THAT's NOT A VALID ITEM....NOOB" << endl;
                }
            }
        }
        catch (int x)
        {
            cout << "EMERGENCY ALERT" << endl;
            exit(1);
        }
    }
    void finalBill()
    {
        int i;
        displayFinalBill();
        cout << setw(15) << "ITEM NUMBER" << setw(20) << "ITEM NAME" << setw(20) << "QUANTITY" << setw(10) << "PRICE[1]" << setw(20) << "PRICE[TOTAL]" << endl;
        for (i = 1; i <= 9; i++)
        {
            if (quantity[i] > 0)
            {
                sprice[i] = price[i] * quantity[i];
                cout << setw(15) << i << setw(25) << dishes[i] << setw(10) << quantity[i] << setw(10) << price[i];
                cout << setw(20) << sprice[i] << endl;
            }
        }
        for (i = 1; i <= 9; i++)
        {
            finalSale = sprice[i] + finalSale;
        }

        cout << "\n\n\n";
        cout << setw(40);
        cout << "----------------------" << endl;
        cout << setw(40);
        cout << "| FINAL SALE PRICE  : " << setw(5) << finalSale << " |" << endl;
        cout << setw(40);
        cout << "| TAX VALUE IMPOSED : " << setw(5) << floor(finalSale * 0.05) << " | " << endl;
        cout << setw(40);
        cout << "| TOTAL SALE PRICE  : " << setw(5) << finalSale + floor(finalSale * 0.05) << " | " << endl;
        cout << setw(40);
        cout << "----------------------" << endl;

        writeBilltoFile();
    }
    void writeBilltoFile()
    {
        try
        {
            fstream billfile;
            billfile.open("mybill.txt", ios::out);

            //writing bill details to file
            if (billfile.is_open())
            {
                billfile << setw(50);
                billfile << "-----------------------------------------------" << endl;
                billfile << "\t\tEATERIA LA GRANDE" << endl;
                billfile << "\n\n";
                billfile << setw(35);
                time_t now = time(0);
                char *dt = ctime(&now);

                billfile << "DATE & TIME : " << dt << endl;
                billfile << "\n\n";
                billfile << setw(40);
                billfile << "FINAL INVOICE" << endl;
                billfile << "ORDER NUMBER : " << 1 + (rand() % 30);
                billfile << setw(40);
                takeaway ? billfile << "ORDER TYPE : TAKEAWAY" : billfile << "ORDER TYPE : DINE-IN";
                billfile << endl;
                billfile << "NAME : " << customerName << endl;
                billfile << "\n\n";
                billfile << setw(15) << "ITEM NUMBER" << setw(20) << "ITEM NAME" << setw(20) << "QUANTITY" << setw(10) << "PRICE[1]" << setw(20) << "PRICE[TOTAL]" << endl;
                for (int i = 1; i <= 9; i++)
                {
                    if (quantity[i] > 0)
                    {
                        sprice[i] = price[i] * quantity[i];
                        billfile << setw(15) << i << setw(25) << dishes[i] << setw(10) << quantity[i] << setw(10) << price[i];
                        billfile << setw(20) << sprice[i] << endl;
                    }
                }
                billfile << "\n\n\n";
                billfile << setw(40);
                billfile << "----------------------" << endl;
                billfile << setw(40);
                billfile << "| FINAL SALE PRICE  : " << setw(5) << finalSale << " |" << endl;
                billfile << setw(40);
                billfile << "| TAX VALUE IMPOSED : " << setw(5) << floor(finalSale * 0.05) << " | " << endl;
                billfile << setw(40);
                billfile << "| TOTAL SALE PRICE  : " << setw(5) << finalSale + floor(finalSale * 0.05) << " | " << endl;
                billfile << setw(40);
                billfile << "----------------------" << endl;
                billfile << "\n\n\n";
                billfile << setw(30);
                billfile << "THANK YOU FOR VISITING US!" << endl;
                billfile << setw(30);
                billfile << "EATERIA LA GRANDE" << endl;
                billfile << setw(30);
                billfile << "FRENCH CUISINE AT IT'S BEST. 👌" << endl;
                billfile << "-----------------------------------------------";
            }
            else
            {
                throw "FILE ACCESS ERROR";
            }
            billfile.close();
            cout << "PRESS 0 THEN 3 TO PROCEED..." << endl;
            system("pause");
            resetVals();
        }
        catch (const char *e)
        {
            cout << "FATAL ERROR" << endl;
            exit(EXIT_SUCCESS);
        }
    }
    bool resetVals()
    {
        int i;
        for (i = 1; i < 10; i++)
        {
            quantity[i] = 0;
        }
        finalSale = 0;
        order = 0;
        for (i = 1; i < 10; i++)
        {
            sprice[i] = 0;
        }
        takeaway = false;
        if ((finalSale == 0) && (order == 0))
            return true;
        else
            return false;
    }
    ~mainDo()
    {
        for (int i = 0; i <= 9; i++)
        {
            sprice[i] = 0;
        }
        delete quantity;
    }
};*/