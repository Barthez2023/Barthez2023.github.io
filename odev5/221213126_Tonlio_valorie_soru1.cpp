//soru1
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
double faktoriyel(int l){
    int i;
    double f=1;
    for ( i=1;i<=l;i++)
    {
        f=f*i;
    }
 return f;
}
int kombinasyon(int n,int r){
    return faktoriyel(n)/(faktoriyel(r) * faktoriyel(n-r));
}
int main(){
   int n,r;
    printf("kombinasyon parametreleri girsiniz\n");
    printf("n girsiniz:");
    scanf("%d",&n);
    printf("r girsiniz:");
    scanf("%d",&r);
    printf("C(%d,%d)=%d\n",n,r,kombinasyon (n,r));



return 0;
}



