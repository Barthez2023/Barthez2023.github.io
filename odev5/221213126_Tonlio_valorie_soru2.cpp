//soru2
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int basama_sayi(int n){
    int a,som=0;
    while (n>0)
    {   
        a=n;
        n=n/10;
        som+=(a-(n*10));
    }
     return som;
}
int main(){
	int n;
	printf("n girsiniz:");
	scanf("%d",&n);
	printf("Girdiginiz sayi basamak degerleri toplam:%d\n",basama_sayi(n));



return 0;
}
