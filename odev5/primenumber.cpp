#include<stdio.h>
#include<stdlib.h>
bool primenumber(int n){
	int i;
	if(n<=1){
		return false;
	}
	for(i=2;i<n;i++){
		if(n%i==0){
			return false;
				}
					}
	 return true;
	 
	}
int basama(int n){
	int i,toplam=0,a;
	while(n!=0){
		a=n;
		n=n/10;
		toplam+=a-(n*10);
	}
	return toplam;
}
double facto(int n){
	int i,f=1;
	if(n==0||n==1)
	    return 1;
	for(i=2;i<=n;i++)  {
		f*=i;
	}  
	return f;
}
int combi(int n,int r){
	if(n>=r)
	    return facto(n)/(facto(r)*facto(n-r));
	printf("le premier parametre de la combinaison doit etre superieur au deuxieme"); 
	
}


int main(){
	
	int a;
	printf("entrer un nombre:");
	scanf("%d",&a);
	if(primenumber(a))
	    printf("c'est un nombre premier\n");
	else
	    printf("c'est n' est pas un nombre premier\n");
	
	printf("%d\n",basama(a));
	printf("%f\n",facto(5));
	printf("%d\n",combi(10,5));
	
	
	
	
	
	return 0;
}
