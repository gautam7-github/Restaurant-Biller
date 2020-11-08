#ifndef MAINDO_HEADER
#define MAINDO_HEADER
#include "items.h"
class mainDo : public items
{
private:
    items I;

public:
    mainDo();
    void displayBrand();
    void displayFinalBill();
    void displayMenu();
    int askforOrder();
    void finalBill();
    void writeBilltoFile();
    bool resetVals();
    ~mainDo();
};
#endif // MAINDO_HEADER