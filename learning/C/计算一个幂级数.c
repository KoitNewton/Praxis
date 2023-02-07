#include <stdio.h>

void main(){
    float income = 16.8;
    int i = 0;
    while(income < 30) {
         income = income * 1.05;
         i++;
         printf("%d年后工资为:%f\n",i,income);
    }  
    printf("i=%d\n",i);
}