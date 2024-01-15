#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
bool polindrome_number(int n){
    /*
    int T[10],i,a,j=0,k,l=0,b;
    b=n;
    while(n!=0){
        a=n;
        n=n/10;
        i=a-(n*10);
        T[j]=i;
        j++;
    }
    k=T[l];
    l++;
    while(l<=j){
        k=k*10+T[l];
        l++;
    }
    if(b==k)
        return true;
    else 
        return false;*/
    int i,a,,k,b;
    b=n;
    while(n!=0){
        a=n;
        n=n/10;
        i=a-(n*10);
        k=k*10+i;
    }
    return k==b;


}
int main(){
    int n;
    printf("enter the numbre: ");
    scanf("%d",&n);
    if(polindrome_number(n))
        printf("%d is a polindrome number\n",n);
    else
        printf("%d is not a polindrome number\n",n);

    return 0;
}