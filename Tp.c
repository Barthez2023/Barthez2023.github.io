#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define Max 200
//function 1
int somme_entier_pair(int n){
    int som=0,i;
    for (i=0;i<=n;i++)
    {
        if (i%2==0)
        {
            som+=i;
        }
        
    }
    return som;
}
//function 2
void eleve(void){
    char *nom,*prenom;
    int CNE;
    float *T,som=0;
    int i;
    nom=malloc(sizeof(char)*Max);
    prenom=malloc(sizeof(char)*Max);
    T=malloc(sizeof(float)*Max);
    if (nom==NULL || prenom==NULL || T==NULL)
    {
        printf("Allocation refuser!!!");
        exit(1);
    }
    printf("entrer votre nom:");
    gets(nom);
    printf("entrer votre prenom:");
    gets(prenom);
    printf("entrer votre CNE:");
    scanf("%d",&CNE);
    printf("veillez entrer vos notes:\n");
    for (i=0;i<12;i++)
    {
       printf("Note n%d=",i+1);
       scanf("%f",&T[i]);
       som+=T[i];
    }
    printf("\n");
    printf("----------------------------------------presentation de l'eleve--------------------------------------\n");
    printf("Nom:%s\n",nom);
    printf("Prenom:%s\n",prenom);
    printf("CNE:%d\n",CNE);
    printf("La moyenne:%f\n",(float)som/12);
    
free(nom);
free(prenom);
free(T);
}
//function3
//cette fonction prend un tableau et retourne le max et le min a l'aide des pointeurs
void max_min (int T[],int n,int *max,int *min){
    int aide;
    min=T;
    max=T+1;
    for (min=T;min<T+n;min++)
    {
        if (*min>*max)
        {
            aide=*min;
            *min=*max;
            *max=aide;
            max++;
        }
        
    }
min=T;
max=T+n-1;
printf("Le max est:%d\n",*max);
printf("Le min est:%d\n",*min);
}

//function 4
void trie (int T[],int *p,int *p1,int n){
    int aide;
    p=T;
    p1=p+1;
    for (p=T;p<T+n-1;p++)
    {
        for (p1=p+1;p1<T+n;p1++)
    {
        if (*p>=*p1)
        {
            aide=*p;
            *p=*p1;
            *p1=aide;
        }

    }
        
    }
    p=T;
    for (p=T;p<T+n;p++)
    {
        printf("%d ",*p);
    }
}
// function 5
int Nchiffres(long n){
    int cmp=0;
    do
    {
        if (n<0)
        {
            n=-1*n;
        }
        
        n=n/10;
        cmp++;
    } while (n>0);

    return cmp;
}
//function 6
void fct3 (int T[],int *np,int *nimp,int *nbz,int n){
    int *p;
    p=T;
    for (p=T;p<T+n;p++)
    {
        if (*p==0)
        {
            *nbz=*nbz+1;
        }
        else
        {
            if (*p%2==0)
            {
                *np=*np+1;
            }
            else
            *nimp=*nimp+1;
        }
        
    }
   
}
void Prod_Mat(int a[50][50],int b[50][50],int c[50][50],int n,int p){
    int i,j,k;
    for (i=0;i<n;i++)
    {
        for (j=0;j<p;j++)
        {
            c[i][j]=0;
            for (k=0;k<n;k++)
            {
              c[i][j]+=a[i][k]*b[k][j];
            }
            
        }
        
    }
}

typedef struct 
{
   float x;
   float y;
}Point;

typedef struct 
{
    int jour;
    int mois;
    int anne;
}Date;


typedef struct 
{
   int heure;
   int minute;
   int seconde;
}Heure;
int conver_ensconde(Heure h){
    return (h.heure*3600+h.minute*60+h.seconde);
}
Heure conver_truct(int n){
    Heure h;
    h.heure=n/3600;
    n=n%3600;
    h.minute=n/60;
    n=n%60;
    h.seconde=n;
    return h;
}
Heure add(Heure h,Heure h1){
    Heure h2;
    h2.heure=h.heure+h1.heure;
    h2.minute=h.minute+h1.minute;
    h2.seconde=h.seconde+h1.seconde;
    if (h2.minute>60)
    {
        h2.minute-=60;
        h2.heure+=1;
    }
    if (h2.seconde>60)
    {
        h2.seconde-=60;
        h2.minute+=1;
    }
    
    
    return h2;
}

typedef struct
{
   int jour ;
   char mois [10] ;
   int annee ;
}Date1;

typedef struct
{
    int no_rue ;
    char rue [100] ;
    int code_postal ; 
    char ville [30] ; 
    char pays [30] ;
}Adress;

typedef struct 
{
    long CNE;
    char nom [30] ;
    char prenom [30] ;
    Date1 date_naiss;
    Adress ads ;
   char email [30] ;
   char phone [14] ;
   char site_web [30] ;
}Etudiant;
void lecture_etudiant(Etudiant etudiant1[], int n){
    int i;
    for (i=0;i<n;i++)
    {
       printf("Veillez s'il vous plait entrer les coordonnes de l'etudiant No%d\n",i+1);
       printf("Entrer le numero de CNE:");
       scanf("%ld",&etudiant1[i].CNE);
       printf("Entrer le numero le nom:");
       scanf("%s",etudiant1[i].nom);
       printf("Entrer le numero prenom:");
       scanf("%s",etudiant1[i].prenom);
       printf("Entrer la date de naissance:\n");
       printf("Jour de naissance:");
       scanf("%d",&etudiant1[i].date_naiss.jour);
       printf("Mois de naissance:");
       scanf("%s",etudiant1[i].date_naiss.mois);
       printf("Anne de naissance:");
       scanf("%d",&etudiant1[i].date_naiss.annee);
       printf("Veillez entrer les donnes en rapporet avec votre adress:\n");
       printf("N_o de rue:");
       scanf("%d",&etudiant1[i].ads.no_rue);
       printf("Rue:");
       scanf("%s",etudiant1[i].ads.rue);
       printf("Code postal:");
       scanf("%d",&etudiant1[i].ads.code_postal);
       printf("Pays:");
       scanf("%s",etudiant1[i].ads.pays);
       printf("Ville:");
       scanf("%s",etudiant1[i].ads.ville);
       printf("Entrer votre adress mail:");
       scanf("%s",etudiant1[i].email);
       printf("Entrer votre numero de tel:");
       scanf("%s",etudiant1[i].phone);
       printf("Entrer votre site web:");
       scanf("%s",etudiant1[i].site_web);
    }
}
void affichage_etudiant(Etudiant etudiant1[],int n){
    //ici nous allons affichez les etudiants
    int i;
    FILE *f;
    f=fopen("Annuaire.txt", "w");
    if (f==NULL)
    {
        exit(1);
    }
    
    for (i=0;i<n;i++)
    {
        printf("Les coordonnes de l'etudiant No%d\n",i+1);
        fprintf(f,"Les coordonnes de l'etudiant No%d\n",i+1);
        printf("CNE:%ld\n",&etudiant1[i].CNE);
        fprintf(f,"CNE:%ld\n",&etudiant1[i].CNE);
        printf("Nom:%s\n",etudiant1[i].nom);
        fprintf(f,"Nom:%s\n",etudiant1[i].nom);
        printf("Prenom:%s\n",etudiant1[i].prenom);
        fprintf(f,"Prenom:%s\n",etudiant1[i].prenom);
        printf("Date de naissance:%d-%s-%d\n",etudiant1[i].date_naiss.jour,etudiant1[i].date_naiss.mois,etudiant1[i].date_naiss.annee);
        fprintf(f,"Date de naissance:%d-%s-%d\n",etudiant1[i].date_naiss.jour,etudiant1[i].date_naiss.mois,etudiant1[i].date_naiss.annee);
        printf("Adress:Rue No:%d, Nom de la Rue:%s, Code postal:%d, Pays:%s, Ville:%s\n",etudiant1[i].ads.no_rue,etudiant1[i].ads.rue,etudiant1[i].ads.code_postal,etudiant1[i].ads.pays,etudiant1[i].ads.ville);
        fprintf(f,"Adress:Rue No:%d, Nom de la Rue:%s, Code postal:%d, Pays:%s, Ville:%s\n",etudiant1[i].ads.no_rue,etudiant1[i].ads.rue,etudiant1[i].ads.code_postal,etudiant1[i].ads.pays,etudiant1[i].ads.ville);
        printf("Adress mail:%s\n",etudiant1[i].email);
        fprintf(f,"Adress mail:%s\n",etudiant1[i].email);
        printf("Telephone:%s\n",etudiant1[i].phone);
        fprintf(f,"Telephone:%s\n",etudiant1[i].phone);
        printf("Site web:%s\n",etudiant1[i].site_web);
        fprintf(f,"Site web:%s\n",etudiant1[i].site_web);
        printf("\n");
        fprintf(f,"\n");
}
fclose(f);
}
void recuperer_unetudiant(Etudiant etudiant1[],int n){
     FILE *f;
     FILE *fic;
     int i;
     char choix[20];
     char cne[10];
     char texte[255];
    f=fopen("Annuaire.txt", "r");
    fic=fopen("Etudiant_recupere.txt","w");
    if (f==NULL)
    {
        exit(1);
    }
    if (fic==NULL)
    {
        exit(1);
    }
    printf("ici ont vas recuperer un etudiant dans le fichier\n");
    printf("Voulez vous recuperer un etudiant dans le fichier?");
    scanf("%s",choix);
    if (strcmp(choix,"oui")==0)
    {
        printf("Veillez entrer le CNE de l'etudiant recherche:");
        scanf("%s",cne);
         while (fgets(texte,255,f)!=NULL){
            if (strstr(texte,cne)!=NULL)
            {    
                printf("Les coordonnes relatives a l'etudiant dont le CNE est %s sont les suivant:\n",cne);
                fprintf(fic,"Les coordonnes relatives a l'etudiant dont le CNE est %s sont les suivant:\n",cne);
                 printf("%s",texte);
                 fprintf(fic,"%s",texte);
                 while (fgets(texte, 255, f) != NULL && strcmp(texte, "\n") != 0) {
                 printf("%s", texte);
                 fprintf(fic,"%s",texte);
                   }
            }
                 }    
                  }

fclose(f);
fclose(fic);


}
void Modifie_etudiant(Etudiant etudinat1[],int n){
     FILE *f;
     FILE *fic;
     int i,tr;
     char nom[50];
     char choix[20];
     long cne;
     char texte[255];
    f=fopen("Annuaire.txt", "r");
    fic=fopen("etudiant_modif.txt","w");
    if (f==NULL)
    {
        exit(1);
    }
    if (fic==NULL)
    {
        exit(1);
    }

    printf("ici ont vas modifier un etudiant dans le fichier\n");
    printf("Voulez vous modifier un etudiant dans le fichier?");
    scanf("%s",choix);
    if (strcmp(choix,"oui")==0)
    {
        printf("Veillez entrer le CNE de l'etudiant recherche:");
        scanf("%ld",&cne);
        for (i=0;i<n;i++)
        {    
            if (fscanf(f,"%ld\n %s\n %s\n %d\n %s\n %d\n %s\n %s\n %d\n %s\n %s\n %s\n %s\n",&etudinat1[i].CNE,etudinat1[i].nom,etudinat1[i].prenom,&etudinat1[i].date_naiss.jour,etudinat1[i].date_naiss.mois,&etudinat1[i].date_naiss.annee,&etudinat1[i].ads.no_rue,etudinat1[i].ads.rue,&etudinat1[i].ads.code_postal,etudinat1[i].ads.ville,etudinat1[i].ads.pays,etudinat1[i].email,etudinat1[i].phone,etudinat1[i].site_web)!=EOF);
        {
            if (etudinat1[i].CNE==cne)
            {
                tr=1;
                printf("Entrer le nouveau nom:");
                scanf("%s",etudinat1[i].nom);
            }
           fprintf(fic,"%ld\n %s\n %s\n %d\n %s\n %d\n %s\n %s\n %d\n %s\n %s\n %s\n %s\n",etudinat1[i].CNE,etudinat1[i].nom,etudinat1[i].prenom,etudinat1[i].date_naiss.jour,etudinat1[i].date_naiss.mois,etudinat1[i].date_naiss.annee,etudinat1[i].ads.no_rue,etudinat1[i].ads.rue,etudinat1[i].ads.code_postal,etudinat1[i].ads.ville,etudinat1[i].ads.pays,etudinat1[i].email,etudinat1[i].phone,etudinat1[i].site_web );
           printf("%ld %s\n", etudinat1[i].CNE,etudinat1[i].nom);
        } 
        }
        
        
        
       
}

}



  
int main (){
    //Nous allons ecrire un programme qui permet d'enreigister les etudiants :
    Etudiant *etudiant;
    int i,n;
    etudiant=(Etudiant*)malloc(sizeof(Etudiant)*Max);
    if (etudiant==NULL)
    {
        exit(1);
    }
    printf("combien d'etudinat voulez vous enreigistre:");
    scanf("%d",&n);
    //lecture_etudiant(etudiant,n);
    //affichage_etudiant(etudiant,n);
    //recuperer_unetudiant(etudiant,n);
    Modifie_etudiant(etudiant,n);
    
    free(etudiant);

    /*
    //ce programme fait l'appel des fonction declarer ci dessou ces fonction font appel a des structures et certains retourne meme es strutures.
    Heure h3,h4;
    int n;
    printf("les donnes de la premiere horaire\n");
    printf("entrer l'heure:");
    scanf("%d",&h3.heure);
    printf("entrer les minutes:");
    scanf("%d",&h3.minute);
    printf("entrer les secondes:");
    scanf("%d",&h3.seconde);

    printf("les donnes de la deuxieme horaire\n");
    printf("entrer l'heure:");
    scanf("%d",&h4.heure);
    printf("entrer les minutes:");
    scanf("%d",&h4.minute);
    printf("entrer les secondes:");
    scanf("%d",&h4.seconde);
printf("la premiere horaire est equivalente a %d esn seconde\n",conver_ensconde(h3));
printf("la deuxieme horaire est equivalente a %d esn seconde\n",conver_ensconde(h4));
printf("enter un nombre de seconde:");
scanf("%d",&n);
printf("Le nombre entrer est equivaut a:%dh,%dm,%ds\n",conver_truct(n).heure,conver_truct(n).minute,conver_truct(n).seconde);
printf("La somme des deux horaire est de:%dh,%dm,%ds\n",add(h3,h4).heure,add(h3,h4).minute,add(h3,h4).seconde);
*/


    /*Date date={25,8,2003}; ce bout de code montre juste qu'il est possible d'initialiser les valeurs de la structure sdes la depart
    printf("nous sommes le %d ,%d,%d\n",date.jour,date.mois,date.anne);*/
    /*
    Date date;
    Date *date1;
    date1=&date;//ici date1 n'est pas une structure date c'est un pointeur qui pointe sur les elements de date c'est a dire que l'ont parcour les elements de date a partie du pointeurs date1.
    int n,i;
    printf("combien de dates voulez vous enreigistrer:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
    printf("entrer le jour:");
    scanf("%d",&date1->jour);
    printf("entrer le mois:");
    scanf("%d",&date1->mois);
    printf("entrer l'annee:");
    scanf("%d",&date1->anne);  
    }

     for (i=0;i<n;i++)
    {
    printf("nous sommes le %d ,%d,%d",date1->jour,date1->mois,date1->anne);
    }*/


/*
    //ce programme reprend le programme precedent mais en utilisant les tableaux de structures.
    Date *date;
    Date *date1;
    int n,i;
    date=(Date*)malloc(sizeof(Date)*Max);
    date1=date; //ici date1 n'est pas une structure date c'est un pointeur qui pointe sur les elements de date c'est a dire que l'ont parcour les elements de date a partie du pointeurs date1.
    printf("combien de dates voulez vous enreigistrer:");
    scanf("%d",&n);
    
    
    // remplissage du tableau pour ce faire nous n'utilisons pas les pointeurs car nous allons utiliser l'allocation dynamique
    for (i=0;i<n;i++)
    {
    printf("Les coordonnes du jour n%d",i+1);
    printf("entrer le jour:");
    scanf("%d",&date[i].jour);
    printf("entrer le mois:");
    scanf("%d",&date[i].mois);
    printf("entrer l'annee:");
    scanf("%d",&date[i].anne);  
    }
    
    //affichage des donnes ici l'ont peut procede de deux maniere avec ou sans les pointeurs.
    //sans les pointeurs:
    for (i=0;i<n;i++)
    {
    printf("Les coordonnes du jour n%d\n",i+1);
    printf("nous sommes le %d ,%d,%d\n",date[i].jour,date[i].mois,date[i].anne);
    }

    //avec les pointeurs:
    for (i=0;i<n;i++)
    {
    printf("Les coordonnes du jour n%d\n",i+1);
    printf("nous sommes le %d ,%d,%d\n",date1->jour,date1->mois,date1->anne);
    date1++;
    }
    free(date);

*/
    /*
    printf("entrer le jour:");
    scanf("%d",&date.jour);
    printf("entrer le mois:");
    scanf("%d",&date.mois);
    printf("entrer l'annee:");
    scanf("%d",&date.anne);
    printf("\n");
    printf("nous sommes le %d ,%d,%d",date.jour,date.mois,date.anne);*/









    /*
    //ce programme declare une structure point et affiche ces elements
    Point *mypoint;
    int i,n;
    mypoint=malloc(sizeof(Point)*Max);
    if (mypoint==NULL)
    {
        exit(1);
    }
    
    printf("conbien de point voulez vous entrer:");
    scanf("%d",&n);
    printf("Enreigistrement des points:\n");
    for (i=0;i<n;i++)
    {
        printf("Coordonnes du point no%d\n",i+1);
        printf("x=");
        scanf("%f",&mypoint[i].x);
        printf("y=");
        scanf("%f",&mypoint[i].y);
    }
    //affichage des differents point
    for (i=0;i<n;i++)
    {
        printf("Coordonnes du point no%d\n",i+1);
        printf("(%.2f , %.2f)\n",mypoint[i].x,mypoint[i].y);
        //printf("%f\n",mypoint[i].x);
        //printf("%f\n",mypoint[i].y);
    }

    free(mypoint);

*/
















    /*
    //appel de la fonction 7 elle calcul le produit de deux matrice
    srand(time(NULL));
    int i,j,k,n,p;
    int A[50][50],B[50][50],C[50][50];
    printf("entrer les nombre de lignes du tableux:");
    scanf("%d",&n);
    printf("entrer les nombre de colonnes du tableux:");
    scanf("%d",&p);
    //remplissage des tableau
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            A[i][j]=rand()%10;
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            B[i][j]=rand()%10;
        }
    }
    
    //affichage des tableaux
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }

    Prod_Mat(A,B,C,n,p);
    printf("\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    */




    /*
    // appel de la fonction 6 cette fonction prnd un tableau et affiche le nombre  d'lements pair et impaire et ceux qui sont egale a zero
    int *T,*q;
    int np=0,nimp=0,nbz=0,n;
    srand(time(NULL));
    T=malloc(sizeof(int)*Max);
    if (T==NULL)
    {
        exit(1);
    }
    
    printf("entrer les nombre d'element que vous souhaite dans le tableau:");
    scanf("%d",&n);
    q=T;
    for (q=T;q<T+n;q++)
    {
        *q=rand()%10;
    }
    
    for (q=T;q<T+n;q++)
    {
        printf("%d ",*q);
    }
    printf("\n");
    fct3(T,&np,&nimp,&nbz,n);
    printf("Le nombre de nombre pair dans les tableau est:%d\n",np);
   printf("Le nombre de nombre impair dans les tableau est:%d\n",nimp);
   printf("Le nombre de nombre egale a zero dans les tableau est:%d\n",nbz);
    

  free(T);
  */


    /*
    //appel de la fonction 5 ctte fonction recuperre un nombre et calcul le nombre de chiffre contenu dans se nombre
    long n;
    printf("entrer un nombre:");
    scanf("%ld",&n);
    printf("le nombre de chiffre contenu dans le nombre %ld est :%d",n,Nchiffres(n));
*/

    /*
    //appel de la fonction 4 cette fonction recupere un tableau aleatoire et classe ces valeurs par ordre croissant avec les pointeurs
    srand(time(NULL));
    int *T,p,n,*q,p1;
    T=malloc(sizeof(int)*Max);
    if (T==NULL)
    {
       exit(1);
    }
    printf("entrer la taille du tableau:");
    scanf("%d",&n);
    q=T;
    for (q=T;q<T+n;q++)
    {
        *q=rand()%100;
    }
    for (q=T;q<T+n;q++)
    {
       printf("%d ",*q);
    }

    printf("\n");
    trie(T,&p,&p1,n);
    free(T);


    */
    











    /* appel de la fonction 1
    //un programme qui implémente une fonction qui retourne la somme des entiers pairs 
    //inférieurs ou égaux à un entier n donné (passé en argument).
    int a;
    printf("Entre un nombre de votre choix:");
    scanf("%d",&a);
    printf("La somme des nombre pair compris entre 0 et %d est :%d",a,somme_entier_pair(a));
*/

/*
// appel de la fonction 2
eleve();*/

/*
//appel de la fonction 3
int n,i;
int *T;
int v_min,v_max;
T=malloc(sizeof(int)*Max);
if (T==NULL)
{
   printf("Not allocation!!!");
   exit(1);
}
printf("Entrer le nombre d'elements de votre tableaux:");
scanf("%d",&n);
printf("Remplissage du tableau\n");
for (i=0;i<n;i++)
{
    printf("T[%d]=",i+1);
    scanf("%d",&T[i]);
}

max_min(T,n,&v_max,&v_min);


free(T);

*/












/*
    //ce code demanade a l'utilisateur d'entrer un caractere trouve son equivalence en ascii et le converti en binaire
    int caractere,mo=0,A_cara,*T,i=0,a=0,b=0;  //mo modulo A_cara caractere en ascii
    printf("Entrer un caractre:");
    scanf("%c",&caractere);
    T=malloc(sizeof(int)*16);
    if (T==NULL)
    {
        printf("Allocation echouer");
        exit(1);
    }
    
    b=(int)caractere;
    A_cara=b;
    do
    {
        mo=A_cara%2;
        A_cara=(A_cara-mo)/2;
        T[i]=mo;
        i++;
        a++;
        
    } while (A_cara!=1);
    T[a]=1;
    puts("Le code binaire du caractere entree est:");
    for (i =a; i>=0; i--)
    {
        
        printf("%d",T[i]);
    }
    
    printf("\n");
    printf("Le caractere entrer est:%c et son code ASCII est:%d",caractere,b);

    free(T);
/*


/*
// ce code demande  a l'utilisateur d'entrer tois nombre et les classe par odre decroissant
int a,b,c;
printf("Entrer les valeur de a,b et c :");
scanf("%d %d %d",&a,&b,&c);
if (a>b && a>c)
{
   if (b>c)
   {
    printf("Les nombre dans l'odre decroissant:%d %d %d",a,b,c);
   }
   else if (c>b)
   {
    printf("Les nombre dans l'odre decroissant:%d %d %d",a,c,b);
   }
}
else
{
    if (b>a && b>c)
{
   if (a>c)
   {
    printf("Les nombre dans l'odre decroissant:%d %d %d",b,a,c);
   }
   else if (c>a)
   {
    printf("Les nombre dans l'odre decroissant:%d %d %d",b,c,a);
   }
}
else
{
    if (c>a && c>b)
{
   if (b>a)
   {
    printf("Les nombre dans l'odre decroissant:%d %d %d",c,b,a);
   }
   else if (a>b)
   {
    printf("Les nombre dans l'odre decroissant:%d %d %d",c,a,b);
   }
}
}


}
*/


/*
// Calcul des solutions réelles d'une équation du second degré 
float a,b,c,Det,S1,S2;
char d;
printf("entrer les coefficient de l'equation a resoudre:");
scanf("%f %f %f",&a,&b,&c);
printf("l'equation que vous voulez resoudre est belle et bien : %.1fx^2+%.1fx+%.1f=0\n",a,b,c);
Det=(b*b-(4*a*c));

if(Det>0) {
    S1=(-1*b+(pow(Det,0.5)))/2*a;
    S2=(-1*b-(pow(Det,0.5)))/2*a;
    printf("cette equation a deux solutions S1=%f et S2=%f",S1,S2);
}
else
{
    if (Det==0)
    {
        S1=(-1*b)/2*a;
    printf("cette equation a une solution double S=%f ",S1);
    }
    else
    {
        printf("Cette equation n'a pas de solutions reel mais elle a des solutions complexes");
    }
    
    
}

*/

/*
// ce programme utilise la boucle for avec un float
float i;
for ( i=0; i <2; i+=0.1)
{
   printf("%f\n",i);
}
*/

/*
// ce programme recherche tout les nombre de 3 chiffres telle que abc=a^3+b^3+c^3
int j,k,i,cmp=0;
for (i=1;i<10;i++)
{
    for (j=0;j<10;j++)
    {
        for (k=0;k<10;k++)
        {
            if ((i*i*i+j*j*j+k*k*k)==((i*100)+(j*10)+k))
            {
                printf("Le nombre %d est un nombre recherche\n",((i*100)+(j*10)+k));
                cmp++;
            }
            
        }
        
    }
    
}
printf("Il existe %d nombre de 3 chiffres verifiants notre regle",cmp);
*/


/*

#define T_max 50
int *T,*TP,*TN;
int i,som=0,j,taille,cmp=0,cmp1=0,cmp2=0;
T=malloc(sizeof(int)*T_max);
TN=malloc(sizeof(int)*T_max);
TP=malloc(sizeof(int)*T_max);
if (T==NULL)
{
    printf("Espace non dispo");
    exit(1);
}
if (TN==NULL)
{
    printf("Espace non dispo");
    exit(1);
}
if (TP==NULL)
{
    printf("Espace non dispo");
    exit(1);
}

printf("Entrer la taille du tableau:");
scanf("%d",&taille);
for (i=0;i<taille;i++)
{
   printf("Entrer les elements du tableau:T[%d]=",i+1);
   scanf("%d",&T[i]);
   som+=T[i];
}
//affichage du tableau dans le sens d'entree des donnes
printf("Le tableau :\n");
for (i=0;i<taille;i++)
{
    printf("%d\t",T[i]);
}
printf("\n");

//affichage du tableau dans le sens inverse d'entree des donnes
printf("Le tableau inverse:\n");
for (i=taille-1;i>=0;i--)
{
    printf("%d\t",T[i]);
}
printf("\n");

printf("La sommes des elements entrer dans le tableaux est:%d\n",som);

// ici ont supprime tout les 0 qui se touve dans le tableau et ont le reafiiche
for (i=0;i<taille;i++)
{
    if (T[i]==0)
    {
        for (j=i;j<taille-1;j++)
        {
            T[j]=T[j+1];
        }
        cmp++;
    }
    else
    {
        if (T[i]>0)
        {
           TP[cmp2]=T[i];
           cmp2++;
        }
        else
        {
            if (T[i]<0)
            {
               TN[cmp1]=T[i];
               cmp1++;
            }
            
        }
        
        
        
    }
    
    
  
}

printf("Affichage du tableaux sans les zeros:\n");
for (i=0;i<(taille-cmp);i++)
{
    printf("%d\t",T[i]);
}
printf("\n");

printf("Affichage du tableaux des valeurs positives:\n");
for (i=0;i<cmp2;i++)
{
    printf("%d\t",TP[i]);
}
printf("\n");

printf("Affichage du tableaux des valeurs negatives:\n");
for (i=0;i<cmp1;i++)
{
    printf("%d\t",TN[i]);
}


free(T);
free(TP);
free(TN);

*/

/*
//utilisation des tableaux avec des pointeurs
#define Max 100
int i,n,T[Max];
int *p;
p=T; // ici p recoit l'adresse de T[0]
printf("Entrer les nombres d'elemennts que vous voulez entrer dans le tableaux:");
scanf("%d",&n);
printf("Nous allons maintenant remplie notre tableau:\n");
for (p=T;p<T+n;p++)
{
    printf("T[%d]=",(p-T+1));
    scanf("%d",p);
}

for (p=T;p<T+n;p++)
{
    printf("%d\t",*p);
    
}

*/

/*
// ce programme rempli un tableau et supprume tout les occurence d'un element a l'aide de la methode des pointeurs
#define Max 100
int *T;
int *p1,*p2,n,n1,cmp=0;
T=malloc(sizeof(int)*Max);
if (T==NULL)
{
   exit(1);
}
p1=T;
printf("Entrer le nombre d'element a entre dans votre tableau:");
scanf("%d",&n1);
printf("Entrer un nombre de votre choix:");
scanf("%d",&n);
printf("Nous allons remplie le tableau \n");
for (p1=T;p1<T+n1;p1++)
{
    printf("T[%d]=",p1-T+1);
    scanf("%d",p1);
}
for (p1=T;p1<T+n1;p1++)
{
    printf("%d\t",*p1);
} 

p1=T;
p2=T;
for (p1=T;p1<T+n1;p1++)
{ 
    *p2=*p1;
   if (*p2!=n)
   {
    p2++;
   }
   
} 

printf("\n");
for (p1=T;p1<p2;p1++)
{
    printf("%d\t",*p1);
} 
*/

/*
//ce programme demande a l'utilisateur d'entree un tableau et l'affiche en sens inverse en utilisant les pointeurs
#define Max 100
int *T;
int *p1,*p2,aide,n1;
//creation du tableau avec malloc
T=malloc(sizeof(int)*Max);
if (T==NULL)
{
   exit(1);
}
//remplissage du tableau
p1=T;
printf("Entrer le nombre d'element a entre dans votre tableau:");
scanf("%d",&n1);
printf("Nous allons remplie le tableau \n");
for (p1=T;p1<T+n1;p1++)
{
    printf("T[%d]=",p1-T+1);
    scanf("%d",p1);
}

//affichage du tableau
for (p1=T;p1<T+n1;p1++)
{
    printf("%d\t",*p1);
} 

//inversement du tableau
p2=T+n1-1;
p1=T;
while (p1<=p2-1)
{
    aide=*p1;
    *p1=*p2;
    *p2=aide;
    p1++;
    p2--;

}

//affichage du tableau inverser
printf("\n");
for (p1=T;p1<T+n1;p1++)
{
    printf("%d\t",*p1);
} 
*/

/*
//ce programme demande a l'utilisateur d'entree un tableau et calcul la sommme de ces elments en utilisant les pointeurs
#define Max 100
int *T;
int *p1,*p2,som=0,n1;
//creation du tableau avec malloc
T=malloc(sizeof(int)*Max);
if (T==NULL)
{
   exit(1);
}
//remplissage du tableau
p1=T;
printf("Entrer le nombre d'element a entre dans votre tableau:");
scanf("%d",&n1);
printf("Nous allons remplie le tableau \n");
for (p1=T;p1<T+n1;p1++)
{
    printf("T[%d]=",p1-T+1);
    scanf("%d",p1);
    som+=*p1;

}

//affichage du tableau
for (p1=T;p1<T+n1;p1++)
{
    printf("%d\t",*p1);
} 
printf("\n");
printf("La somme des elements entrer dans le tableau est de :%d",som);
*/

/*
//ce programme demande a l'utilisateur d'entree un tableau et range les elements par odres croissant en utilisant les pointeurs
#define Max 100
int *T;
int *p1,*p2,aide,n1;
//creation du tableau avec malloc
T=malloc(sizeof(int)*Max);
if (T==NULL)
{
   exit(1);
}
//remplissage du tableau
p1=T;
printf("Entrer le nombre d'element a entre dans votre tableau:");
scanf("%d",&n1);
printf("Nous allons remplie le tableau \n");
for (p1=T;p1<T+n1;p1++)
{
    printf("T[%d]=",p1-T+1);
    scanf("%d",p1);
}

//affichage du tableau
for (p1=T;p1<T+n1;p1++)
{
    printf("%d\t",*p1);
} 
printf("\n");


//ragement du tableau par ordre croissant
for (p1=T;p1<T+n1;p1++)
{
    for (p2=p1+1;p2<T+n1;p2++)
    {
        if (*p2<*p1)
        {
           aide=*p1;
           *p1=*p2;
           *p2=aide;
           
        }
        
    }
    
}
//affichage du tableau
for (p1=T;p1<T+n1;p1++)
{
    printf("%d\t",*p1);
} 
printf("\n");
*/ 

/*
// ce programme prend un tableau a deux dimension te le transforme en tableau de une dimension
int T[50][50],i,j,k=0,L[100];
printf("Nous allons remplie le tableaux:");
for (i=0;i<=2;i++)
{
   for (j=0;j<=3;j++)
   {
    printf("T[%d][%d]=",i+1,j+1);
    scanf("%d",&T[i][j]);
}
}

for (i=0;i<3;i++)
{
    for (j=0;j<4;j++)
    {
       printf("%d\t",T[i][j]);
    }
    
    printf("\n");
}


for (i=1;i<=3;i++)
{
    for (j=1;j<=4;j++)
    {
        
            L[i*4-j]=T[i-1][j-1];
    }
    
    
}

printf("\n");
for (k=0;k<12;k++)
{
    printf("%d\t",L[k]);
}
*/


/*
//ce programme demande d'entrer 5 mots et les affiche en sens inverse de leurs entre en utilisants les alocations dynamique et les fonctions de string.h
#define Max 100
char *M1,*M2,*M3,*M4,*M5;
char M6[]=" ";
//allocation de la memoire
M1=malloc(sizeof(char)*Max);
M2=malloc(sizeof(char)*Max);
M3=malloc(sizeof(char)*Max);
M4=malloc(sizeof(char)*Max);
M5=malloc(sizeof(char)*Max);
if (M1==NULL)
{
   printf("allocation refuser");
   exit(1);
}
if (M2==NULL)
{
   printf("allocation refuser");
   exit(1);
}
if (M3==NULL)
{
   printf("allocation refuser");
   exit(1);
}
if (M4==NULL)
{
   printf("allocation refuser");
   exit(1);
}
if (M5==NULL)
{
   printf("allocation refuser");
   exit(1);
}
    
    printf("Entrer un mot:");
    gets(M1);
    printf("Entrer un mot:");
    gets(M2);
    printf("Entrer un mot:");
    gets(M3);
    printf("Entrer un mot:");
    gets(M4);
    printf("Entrer un mot:");
    gets(M5);
//scanf("%s",M1); joue le meme role que gets(M1);

//ici je concate elements pr elements dans la chaine M5
strcat(M5,M6);
strcat(M5,M4);
strcat(M5,M6);
strcat(M5,M3);
strcat(M5,M6);
strcat(M5,M2);
strcat(M5,M6);
strcat(M5,M1);
//affichage de M5 apres concatenations 
printf("%s",M5);

//liberage de la memoire allouer
free(M1);
free(M2);
free(M3);
free(M4);
free(M5);
*/

/*
// ce code entre une chaine de caractere compte le nombre d'occurence de 'e' et inverse la chaine
#define Max 200
char *chaine,*chaine1;
int cmp=0,i,j=0;
//allocation de la memoire 
chaine=malloc(sizeof(char)*Max);
chaine1=malloc(sizeof(char)*Max);
if (chaine==NULL)
{
   printf("allocation refuser");
   exit(1);
}
if (chaine1==NULL)
{
   printf("allocation refuser");
   exit(1);
}
// entrer la chaine
printf("Entrer un chaine de votre choix:");
gets(chaine);
printf("La longuer de la chaine est de:%d\n",strlen(chaine));
//compte le nombre de 'e' dans la chaine 
for (i=0;i<strlen(chaine);i++)
{
    if (chaine[i]=='e')
    {
        cmp++;
    }
}
printf("La nombre d'occurence de 'e 'dans la chaine  est de:%d\n",cmp);
printf("La chaine entrer est de: %s\n",chaine);
//inverse la chaine
for (i=strlen(chaine)-1;i>=0;i--)
{
   chaine1[j]=chaine[i];
   j++;
}
chaine1[j]='\0';
printf("La chaine inverse de la chaine entrer est de: %s\n",chaine1);
free(chaine);
free(chaine1);
*/

/*
//ce programme recupere une chaine te supprime tous les occurences de 'e' contenue dans la chaine
#define Max 200
char *chaine;
int i,j,cmp=0;
//allocation de la memoire 
chaine=malloc(sizeof(char)*Max);
if (chaine==NULL)
{
   printf("allocation refuser");
   exit(1);
}
// entrer la chaine
printf("Entrer un chaine de votre choix:");
gets(chaine);
for (i=0;i<strlen(chaine);i++)
{
   if (chaine[i]=='e')
   {
    for (j=i;j<strlen(chaine)-1;j++)
    {
       chaine[j]=chaine[j+1];
    }
    
    cmp++;
   }
}
chaine[strlen(chaine)-cmp]='\0';
printf("le nombre de 'e' dans la chaine est de :%d\n",cmp);
printf("La nouvelle chaine est:%s",chaine);
free(chaine);
*/


/*
// ce programme recupere une chaine et calcule de nombre de caractere hors mis les espaces
#define Max 200
char *chaine;
int i,j,cmp=0;
//allocation de la memoire 
chaine=malloc(sizeof(char)*Max);
if (chaine==NULL)
{
   printf("allocation refuser");
   exit(1);
}
// entrer la chaine
printf("Entrer vos noms et vos prenoms:");
gets(chaine);

for (i=0;i<strlen(chaine);i++)
{
    if (chaine[i]!=' ')
    {
       cmp++;
    }
    
}
printf("Le nombre de caractere du nom et du prenom sans les espsces est:%d",cmp);
free(chaine);
*/

/*
//ce programme recupere deux chaine et les compare
#define Max 200
char *chaine,*chaine1;
int cmp=0,i,j=0;
//allocation de la memoire 
chaine=malloc(sizeof(char)*Max);
chaine1=malloc(sizeof(char)*Max);
if (chaine==NULL)
{
   printf("allocation refuser");
   exit(1);
}
if (chaine1==NULL)
{
   printf("allocation refuser");
   exit(1);
}
// entrer la chaine
printf("Entrer un chaine de votre choix:");
gets(chaine);
printf("Entrer un chaine de votre choix:");
gets(chaine1);
if (strcmp(chaine,chaine1)==0)
{
   printf("La chaine %s et la chaine %s sont equivalentes",chaine ,chaine1);
}
else
{
    if (strcmp(chaine,chaine1)<0)
    {
        printf("La chaine %s precede la chaine %s ",chaine ,chaine1);
    }
    else
    printf("La chaine %s precede la chaine %s ",chaine1 ,chaine);
 free(chaine);
 free(chaine1);
}
*/

/*
// ce programme lit deux chaine et effectue des oprration decrits si dessosus
#define Max 200
char *chaine,*chaine1,*chaine3;
int i;
//allocation de la memoire 
chaine=malloc(sizeof(char)*Max);
chaine1=malloc(sizeof(char)*Max);
chaine3=malloc(sizeof(char)*Max);
if (chaine==NULL)
{
   printf("allocation refuser");
   exit(1);
}
if (chaine1==NULL)
{
   printf("allocation refuser");
   exit(1);
}
if (chaine3==NULL)
{
   printf("allocation refuser");
   exit(1);
}


// entrer la chaine
printf("Entrer un chaine de votre choix:");
gets(chaine);
printf("Entrer un chaine de votre choix:");
gets(chaine1);
int p=strlen(chaine)/2;
int p1=strlen(chaine1)/2;

//***ce programme  lit deux chaînes de caractères chaine  et chaine1 et qui copie la première moitié de chaine et la 
//***première moitié de chaine1 dans une troisième chaîne chaine3,en utilisant les fonctions spéciales de <string.h>

//strncpy(chaine3,chaine,p);
//strncat(chaine3,chaine1,p1);
//chaine3[p+p1+1]='\0';
//printf("La chaine resultante est de :%s",chaine3);

//ce programme  lit deux chaînes de caractères chaine  et chaine1 et qui copie la première moitié de chaine et la 
//première moitié de chaine1 dans une troisième chaîne chaine3,en utilisant uniquement les fonctions gets et puts.

for (i=0;i<p;i++)
{
    chaine3[i]=chaine[i];
}
for (i=0;i<p1;i++)
{
   chaine3[p]=chaine1[i];
   p++;
}

chaine3[p+p1+1]='\0';
printf("La chaine resultante est de :%s",chaine3);

free(chaine);
free(chaine1);
free(chaine3);
*/

/*
//ce code recupere un tableau et calcul la moyenne de ces element en utilisant les ponteurs
int *T;
int *p,toplam=0;
double orta;
T=malloc(sizeof(int)*Max);
p=T;
printf("Diziden elementleri artalir\n");
for (p=T;p<T+10;p++)
{
    printf("T[%d]=",(p-T+1));
    scanf("%d",p);
    toplam+=*p;
}
orta=(double)toplam/10;
for (p=T;p<T+10;p++)
{
    printf("%d\t",*p);
}
printf("Ortalama:%.2f\n",orta);

free(T);
*/

/*
//ce code prend deux tableaux et echange les valeurs des indices paires du premieres avec ceux impaires du deuxieme en utilisnt les pointeurs.
int *T,*T1;
int *p,*p1,cmp=0;
double orta;
T=malloc(sizeof(int)*Max);
p=T;
T1=malloc(sizeof(int)*Max);
p1=T1;
for (p=T;p<T+10;p++)
{
    printf("T[%d]=",(p-T+1));
    scanf("%d",p);
}
printf("\n");
for (p1=T1;p1<T1+10;p1++)
{
    printf("T1[%d]=",(p1-T1+1));
    scanf("%d",p1);
}
printf("\n");
printf("Birinci diz\n");
for (p=T;p<T+10;p++)
{
    printf("%d ",*p);
}
printf("\n");
printf("Ikinci diz\n");
for (p1=T1;p1<T1+10;p1++)
{
    printf("%d ",*p1);
}
p1=T1+1;
p=T;
for (p=T;p<T+10;p+=2)
{
    cmp=*p;
    *p=*p1;
    *p1=cmp;
    p1=p1+2;

}
//p1=T1;
//p=T;
printf("\n");
printf("Birinci diz\n");
for (p=T;p<T+10;p++)
{
    printf("%d ",*p);
}
printf("\n");
printf("Ikinci diz\n");
for (p1=T1;p1<T1+10;p1++)
{
    printf("%d ",*p1);
}

free(T);
free(T1)
*/

/*
//ce programme trouve tous les diviseurs d'un nombre a
int a=12,i,cmp=0;
printf("les diviseurs de %d sont :",a);
for (i=1;i<=12;i++)
{
   if (a%i==0)
   {
    printf("%d ",i);
    cmp++;
   }
   
}
printf("\n");
printf("le nombre de diviseurs de %d est de :%d",a,cmp);
*/

/*
//ce programma calcule le pcm et le pgcd de deux nombres
int a,b,i,max,min,ppcm;
printf("entrer un nombre a:");
scanf("%d",&a);
printf("entrer un nombre b:");
scanf("%d",&b);
max=__max(a,b);
min=__min(a,b);
while (min!=0)
{
    i=min;
    min=max%min;
    max=i;
}

printf("Le pgcd(%d,%d) est :%d\n",a,b,max);
ppcm=(a*b)/max;
printf("Le ppcm(%d,%d) est :%d",a,b,ppcm);
*/ 
/*
int *T,*p;
T=malloc(sizeof(int)*Max);
p=T;
for (p=T;p<T+5;p++)
{
    printf("entrer un nombre:");
    scanf("%d",p);
}
for (p=T;p<T+5;p++)
{
    
    printf("%d ",*p);
}
*/


/*
//ce programme remplie un tableau par les elements d'une suite geometrique
int n;
float q,*T,*p;
T=malloc(sizeof(float)*Max);
if (T==NULL)
{
    exit(1);
}
printf("jusqu'a quelle valeur de n voulez vous deternimer les suite:");
scanf("%d",&n);
printf("entrer la raison de votre suite:");
scanf("%f",&q);
p=T;
//remplissage du tableau
for (p=T;p<T+n;p++)
{
    *p=pow(q,(p-T))*82;
}
//affichage du tableau
p=T;
for (p=T;p<T+n;p++)
{
    printf("%f ",*p);
}

free(T);
*/

//LES STRUCTURES
//ecrivons un programme de qui affiche les point d'un cercle et rectangle 










return 0 ;
}