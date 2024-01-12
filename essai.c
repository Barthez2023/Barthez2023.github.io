#include<stdio.h>
#include<stdlib.h>
int main() {
    int a;
    int i=0,sum=0;
    printf("enter the number:");
    scanf("%d",&a);
    printf("the cube of this number is:%d\n",a*a*a);
    while (i<100)
    {
        sum+=i*2;
        i++;
    }
    printf("the summer is:%d\n",sum);
    


 return 0;
}