#ifndef ITEM_HEADER
#define ITEM_HEADER

#include <string>
class items
{
public:
    unsigned int total;
    unsigned int *quantity;
    unsigned int order;
    std::string *dishes;
    unsigned int price[12];
    unsigned int sprice[20];
    bool takeaway;
    std::string customerName;
    unsigned int finalSale;

    items();
};
#endif // ITEM_HEADER