#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int main()
{
     int  d= 0x0000f06e,a;
     printf("Before circular shift:%x",d);
    d = d <<5| d >>11;
    printf("\nAfter circular shift left:%x",d);
    //d= 0x1248932A;
    //d = d <<7 | d >>25;
    //printf("\nAfter circular shift right:%lx",d);

    getch();
}
