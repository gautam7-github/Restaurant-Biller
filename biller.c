#include <stdio.h>
#include <time.h>

void display_menu();
int main()
{
    display_menu();
    int menu_start;
    while (1)
    {
        scanf("%d", &menu_start);
        if (menu_start == 5)
        {
            break;
        }
    }

    return 0;
}
void display_menu()
{
    printf("\t\tABC EATERIA\n");
}
