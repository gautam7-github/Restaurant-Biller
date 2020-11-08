#ifndef ITEM_HEADER
#define ITEM_HEADER

#include <string>
class items
{
public:
    unsigned int *quantity;
    unsigned int order;
    std::string *dishes;
    unsigned int price[10];
    unsigned int sprice[10];
    bool takeaway;
    std::string customerName;
    unsigned int finalSale;

    items();
};
#endif // ITEM_HEADER