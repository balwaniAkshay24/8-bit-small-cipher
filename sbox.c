#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int main()
{
    unsigned int sbox[16]={0xd,0x8,0xa,0x6,0xe,0x3,0x4,0x9,0x1,0x7,0xf,0x0,0xb,0xc,0x2,0x5}, data=0x8888,b=0x000f,c,ans=0,u,v;
    int i,l,m;
    for(i=0;i<4;i++)
    {
      c=data&b;
       printf("%x ", c);
       m=4*i;
       v= c>>m;
       printf("%x ", v);
       u= sbox[v];
       printf("%x ", u);
       l=4*i;
       u= u<<l; 
       printf("%x ", u);
       ans=ans | u;
       printf("%x ", ans);
       printf("\n");
      b= b<<4 | b>>12;
      }
      printf("\n%x ", ans);
      getch();
      }
      
      
