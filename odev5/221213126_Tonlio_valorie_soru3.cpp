//soru3
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
void asal_sayi(int n){
    int i,cmp=0;
    if (n==1)
    {
        printf("asal sayi\n");
    }
    else
    {
        for (i=2;i<n;i++)
    {
        if (n%i==0)
        {
           cmp=0;
           break;
        }
        else
        cmp=1;
        
    }
    }
    if (cmp==0)
    {
        printf("asal sayi degil\n");
    }
    else
    printf("asal sayi\n");
}
    
    int main (){
    	
    int n;
	printf("n girsiniz:");
	scanf("%d",&n);
	asal_sayi(n);
		
    return 0;  
	}
   
   
 

