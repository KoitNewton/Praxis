#include<stdio.h>
#include<stdlib.h>
int main()
{
    // unsigned char *p1;
    // unsigned long *p2;
    // p1 = (unsigned char *)0x801000;
    // p2 = (unsigned long *)0x810000;

    // printf("p1=%p,p2=%p,p1+5=%p,p2+5=%p\n",p1,p2,p1+5,p2+5);
    // int a[5]={1,2,3,4,5};
    // int * ptr=(int*)(&a+1);
    // printf("%d,%d",*(a+1),*(ptr-1));
    unsigned int a=~0;
    int b = ~0;
    printf("%u,%d\n",a,b); //4294967295,-1
    char *ptr;
    if ((ptr = (char *)malloc(0)) == NULL)
        puts("Gota null pointer");
    else
        puts("Gota valid pointer");
	//scanf("%d",&a);
	//printf("%c",(a)&(a-1)?'n':'y'); //   若是打印y，否则n 2 ci mi
    //printf("%c",a%2?'n':'y'); //   若是打印y，否则n 2Bei shu
    return 0;



}