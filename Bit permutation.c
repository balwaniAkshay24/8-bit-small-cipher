#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int main()
{
    int player[8]={5,4,0,6,1,2,7,3},i,s;
    unsigned int temp,ans=0x00,b=0x01,c=0x00,d,a=0xbf,e;
    //printf("Enter data:");
    //scanf("%ud", &a);
    //printf("\n");
    for(i=0;i<8;i++)
    {
    e=a&b;
    printf("%x ",e);
     if(i>0)
    e=e>>i;
     printf("%x ",e);
     if(player[i]>0)
     e=e<<player[i] | e>>7;
    ans= ans|e;   
     printf("%x ",ans);
    b= b<<1 | b>>7;
     printf("%x ",b);
    printf("\n");
}
    printf("\nThe final answer: %x",ans);
    //getch();
}
