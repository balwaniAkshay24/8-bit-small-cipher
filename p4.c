#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
unsigned int blockshift (unsigned int n)
{
         unsigned int data=n,b=0xff,c,ans=0x00,d,e,f;
         int i,j,k,l;
         for(i=0; i<4;i++)
    {
         c=data&b;
         c=c>>(8*i);
         e = c>>4;
         d= (c&0x0f)<<4;
         f= e|d;
         f= f<<(8*i);
         ans= ans|f;
         b=b<<8;
         }
         printf("\nAfter blockshift:%x ", ans);
         return ans;
         }
    unsigned int player(unsigned int n)
{
    int player[8]={3,5,0,6,1,7,2,4},i,s,j;
    unsigned int temp,ans=0x00,b=0x01,c,d,a=n,e,f=0xff,ans1=0x00;
    for(j=0;j<4;j++)
    {
     c=a&f;
     c=c>>(8*j);
    for(i=0;i<8;i++)
    {
    e=c&b;
    e=e>>i;
     if(player[i]>0)
     e=e<<player[i] | e>>7;
    ans= ans|e;   
    b= b<<1 | b>>7 & 0xffff;
   
}
ans = ans<<(8*j);
ans1= ans1|ans;
ans=0x00;
f=f<<8;
}
    printf("\nAfter permutation:%x",ans1);
    return ans1;
}
  
  unsigned int sub (unsigned int n)
{
    unsigned int sbox[16]={0x1,0x2,0x4,0xd,0x6,0xf,0xb,0x8,0xa,0x5,0xe,0x3,0x9,0xc,0x7,0x0}, data=n,b=0x000f,c,ans=0,u,v;
    int i,l,m;
    for(i=0;i<8;i++)
    {
      c=data&b;
       m=4*i;
       v= c>>m;
       u= sbox[v];
       l=4*i;
       u= u<<l; 
       ans=ans | u;
      b= b<<4 | b>>12;
      }
      printf("\nAfter substitution %x ", ans);
      return ans;
           }       
unsigned int splayer (unsigned int n)
{
         n=blockshift(n);
         n=player(n);
         n=sub(n);
         return n;
         }
int cshift(unsigned int p,int p1)
{
    //unsigned long int  d= 0x1248932A;
    unsigned int u;
    unsigned int i,n;
    // printf("\n%x ", p);
     u=p;
	 if(p1==13)
	 {	u=(((u<<13) | (u>>19))&0xffffffff);
	 	printf("\nCircular Shift layer output for a:%x" ,u );			
	 	u=(((u<<16) | (u>>16))&0xffffffff);
	 	printf("\nLast Step a:%x" ,u);
         }
	 else if(p1==27)
	 {	u=(((u<<5) | (u>>27))&0xffffffff);
	 	printf("\nCircular Shift layer output for b:%x" ,u);
         u=(((u<<16) | (u>>16))&0xffffffff);
        printf("\nLast Step b:%x" ,u); 			
         }
	 return u;
}
int main()
{
    unsigned int a=0x01234567, b=0x89abcdef,u,v,c1,c2,c3,c4;
    printf("\nPlaintext for a:%x" , a);
    a= splayer(a);
    printf("\nSP layer output for a:%x" , a);
    printf("\n--------------------------------");
    printf("\nPlaintext for b:%x" , b);
    b= splayer(b);
    printf("\nSP layer output for b:%x" , b);
    c1=cshift(a,13);
	c2=cshift(b,27);
	getch();
}
