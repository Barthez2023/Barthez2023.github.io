#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//creation du type booleen
typedef enum{
    false,
    true
}bool;
//definition de la pile
typedef struct StackElement 
{
    int value;
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
Stack satck_addvalue(Stack sta ,int n){
    StackElement *element;
    element=malloc(sizeof(*element));
    if (element==NULL)
    {
        fprintf(stderr,"Allocation echouer!!!");
        exit(EXIT_FAILURE);
    }
    element->value=n;
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
       printf("[%d]\n",sta->value);
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
int stack_top(Stack sta){
    if(stack_isempty(sta)){
        printf("La pile n'a pas de sommet elle es vide\n");
        return 0;
    }
    return sta->value;
}
//************************************************************************************
//cette fonction permet de faire la somme des elemnts de la piles
int stack_sum(Stack sta){
    int som=0;
    if(stack_isempty(sta)){
        printf("La pile ne contient aucun element\n");
        return 0;
    }
    while(!stack_isempty(sta)){
        som+=sta->value;
        sta=sta->next;
    }
    return som;
}
//************************************************************************************
//cette fonction permet de de rechercher le plus grand element de la pile
int stack_Max(Stack sta){
    int max;
    if(stack_isempty(sta)){
        printf("La pile ne contient aucun element\n");
        return 0; 
        
    }
    max=sta->value;
    sta=sta->next;
    while(!stack_isempty(sta)){
        if(max<sta->value){
            max=sta->value;
        }
        else
            sta=sta->next;
    }
    return max;
}
//************************************************************************************
//cette fonction permet de de rechercher le plus petit  element de la pile
int stack_Min(Stack sta){
    int min;
    if(stack_isempty(sta)){
        printf("La pile ne contient aucun element\n");
        return 0; 
        
    }
    min=sta->value;
    sta=sta->next;
    while(!stack_isempty(sta)){
        if(min>sta->value){
            min=sta->value;
        }
        else
            sta=sta->next;
    }
    return min;
}
//************************************************************************************
//cette fonction permet de determiner la longueur de la pile de la pile
int stack_Length(Stack sta){
    int length=0;
    if(stack_isempty(sta)){
        printf("La pile ne contient aucun element\n");
        return 0;  
    }
    while(!stack_isempty(sta)){
        length+=1;
        sta=sta->next;
    }
    return length;
}






int main(){
Stack sta;
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
//ont essaie de faire la somme des elemnts de la pile
printf("La somme des element de la pile est:%d\n",stack_sum(sta));
//insertion des donnees dans la pile
sta=satck_addvalue(sta ,20);
sta=satck_addvalue(sta,30);
sta=satck_addvalue(sta,200);
sta=satck_addvalue(sta,300);
sta=satck_addvalue(sta,400);
sta=satck_addvalue(sta,500);
sta=satck_addvalue(sta,600);
//on essaie d'afficher la pile pour voir s'il elle contient des donnes
stack_display(sta);
//on essaie de recuperer le sommet de la pile 
printf("Le sommet de la pile est:%d\n",stack_top(sta));
//ont essaie de faire la somme des elemnts de la pile
printf("La somme des element de la pile est:%d\n",stack_sum(sta));
//ont essaie de recuperer le plus grand element de la pile
printf("L'element max de cette pile est :%d\n",stack_Max(sta));
//ont essaie de recuperer le plus petit element de la pile
printf("L'element min de cette pile est :%d\n",stack_Min(sta));
//ont essaie d'afficher la taille de la pile autrement dit le nombre d'element contenue dans la pile
printf("Le nombre d'element contenu dans la  pile est :%d\n",stack_Length(sta));
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
//ont essaie de faire la somme des elemnts de la pile
printf("La somme des element de la pile est:%d\n",stack_sum(sta));
//ont essaie de recuperer le plus grand element de la pile
printf("L'element max de cette pile est :%d\n",stack_Max(sta));
//ont essaie de recuperer le plus petit element de la pile
printf("L'element min de cette pile est :%d\n",stack_Min(sta));
//ont essaie d'afficher la taille de la pile autrement dit le nombre d'element contenue dans la pile
printf("Le nombre d'element contenu dans la  pile est :%d\n",stack_Length(sta));

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