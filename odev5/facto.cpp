#include<stdio.h>
#include <string.h>
#include <stdlib.h>
double factoriel(int n){
	if(n<0)
	    exit(1);
    else
    {
    	if(n==1|| n==0)
	        return 1;
	    return n * factoriel(n-1);
    	
	}
	    
	    
	    
	    
	    

	
	
}
int main(){
	printf("%f",factoriel(5));
	
	
	
	
	return 0;
}
