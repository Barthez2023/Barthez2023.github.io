#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//creation du type booleen
typedef enum{
    false,
    true
}bool;
// definition de la structures joueur
typedef struct Player
{    
    char nom[50];
    int niveau;
    
}Player;
//definition de la pile
typedef struct StackElement 
{
    Player pp;
    struct StackElement *next;
}StackElement,*Stack;

//*************************************************************************************//
//cette fonction permet de creer une pile
Stack new_stack(void){
   return NULL;
}

//************************************************************************************//
//cette fonction permet de tester si une piles est vide ou pas
int  stack_isempty(Stack sta){
    if (sta==NULL)
       return 1;
    return 0;
}

//************************************************************************************//
//cette fonction permet d'ajouter les elements dans une piles
Stack satck_addvalue(Stack sta ,Player p){
    StackElement *element;
    element=malloc(sizeof(*element));
    if (element==NULL)
    {
        fprintf(stderr,"Allocation echouer!!!");
        exit(EXIT_FAILURE);
    }
    strcpy(element->pp.nom,p.nom);
    element->pp.niveau=p.niveau;

    element->next=sta;

return element;
}

//************************************************************************************//
//cette fonction permet d'afficher la pile
void stack_display(Stack sta){
     if (stack_isempty(sta))
     {
        printf("la pile ne contient pas d'element en d'autre terme elle est vide\n");
     }
    while (!stack_isempty(sta))
    {
       printf("[Nom: %s , Niveau: %d]\n",sta->pp.nom,sta->pp.niveau);
       sta=sta->next;
    } 
}
//************************************************************************************//
//cette fonction permet d'enlever un element de la pile(deipler la pile c'est a dire le dernier element entrer vas tere le premier a etre depiler)
Stack depile(Stack sta){
    StackElement *element;
    if(stack_isempty(sta))
        return new_stack();
    element=sta->next;
    free(sta);
    return element;
}
/*
voici la premiere version de la fonction qui permeet de vider lapile mais ont peut aussi utiliser la fonction depile pour le faire
************************************************************************************
//cette fonction permet de vider la pile
Stack clear_stack(Stack sta){
    StackElement *element;
    if (stack_isempty(sta))
        return new_stack();
    element=sta->next;
    free(sta);
    return clear_stack(element);
}*/
//************************************************************************************
//cette fonction permet de vider la pile
Stack clear_stack(Stack sta){
    if (stack_isempty(sta))
        return new_stack();
    while(!stack_isempty(sta)){
        sta=depile(sta);
    }
    return new_stack();
}
//************************************************************************************
//cette fonction permet de recuperer le prermier element de la pile et de 'afficher
Player stack_top(Stack sta){
    Player p0={"null",0};
    if(stack_isempty(sta)){
        printf("La pile n'a pas de sommet elle es vide\n");
        return p0;
    }
    return sta->pp;
}
int Good_player_level(Stack sta){
    int max;
    max=sta->pp.niveau;
    sta=sta->next;
    while(!stack_isempty(sta)){
        if(max<sta->pp.niveau){
            max=sta->pp.niveau;
        }
        else
            sta=sta->next;
    }
    return max;
}
char * Good_player_name(Stack sta){
    char *name=NULL;
    int max;
    max=sta->pp.niveau;
    sta=sta->next;
    while(!stack_isempty(sta)){
        if(max<sta->pp.niveau){
            max=sta->pp.niveau;
            if(name!=NULL){
                free(name);
            }
            name=malloc(strlen(sta->pp.nom) + 1);
            strcpy(name,sta->pp.nom);
        }
        else
            sta=sta->next;
    }
    return name;
}


int main(){
Stack sta;
Player p1={"Ali",2};
Player p2={"Bernard",8};
Player p3={"Russel",1};
Player p4={"Jean",12};
Player p5={"Ristin",5};
Player p6={"Jules",4};
Player p7={"Gabi",15};
//creation nouvelle pile
sta=new_stack();
//teste si la pile est vide ou pas
if (stack_isempty(sta))
{
    printf("the stack is empty\n");
}
else
printf("the stack is not empty\n");
//on essaie d'afficher la pile pour voir s'il elle contient des donnes
stack_display(sta);
//on essaie de recuperer le sommet de la pile 
printf("Le sommet de la pile est:%d\n",stack_top(sta));
//insertion des donnees dans la pile
sta=satck_addvalue(sta ,p1);
sta=satck_addvalue(sta,p2);
sta=satck_addvalue(sta,p3);
sta=satck_addvalue(sta,p4);
sta=satck_addvalue(sta,p5);
sta=satck_addvalue(sta,p6);
sta=satck_addvalue(sta,p7);
//on essaie d'afficher la pile pour voir s'il elle contient des donnes
stack_display(sta);
//ont essaie de recuperer le plus grand niveau de la pile
printf("Le plus grand niveau de cette pile est :%d\n",Good_player_level(sta));
//ont essaie de recuperer le nom du plus grand niveau de la pile
printf("Le nom du plus grand niveau de cette pile est :%s\n",Good_player_name(sta));
//on essaie de recuperer le sommet de la pile 
printf("Le sommet de la pile est:%d\n",stack_top(sta));
//ont essaie d'afficher la taille de la pile autrement dit le nombre d'element contenue dans la pile
//printf("Le nombre d'element contenu dans la  pile est :%d\n",stack_Length(sta));
//teste si la pile est vide ou pas
if (stack_isempty(sta))
{
    printf("the stack is empty\n");
}
else
printf("the stack is not empty\n");
//ont vas depiler la pile
sta=depile(sta);
sta=depile(sta);
sta=depile(sta);
//ont affiche la pile apres avoir depiler le premier element
stack_display(sta);
//on essaie de recuperer le sommet de la pile 
printf("Le sommet de la pile est:%d\n",stack_top(sta));
//ont essaie d'afficher la taille de la pile autrement dit le nombre d'element contenue dans la pile
//printf("Le nombre d'element contenu dans la  pile est :%d\n",stack_Length(sta));

//vide la pile
sta=clear_stack(sta);
//teste si la pile est vide ou pas
if (stack_isempty(sta))
{
    printf("the stack is empty\n");
}
else
printf("the stack is not empty\n");














}