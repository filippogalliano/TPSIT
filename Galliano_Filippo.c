#include <stdio.h>
#include <stdlib.h>
#include <stdin.h>

typedef struct carta{       //struttura per le carte
    int numero;
    char seme;
    struct carta* next;
}Carta;

void push(Carta** head,Carta* elemento){        //funzione push che carica in una pila
    if(isEmpty(*head)){
        *head = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *head;
        *head = elemento;
    }
}
Carta* pop(Carta** head){           //funzione pop che toglie da una pila
    Carta* ret = *head;
    if(isEmpty(*head)) return NULL;
    *head = ret->next;
    return ret;
}

int isEmpty(Carta *struttura){
    if (struttura == NULL){
        return 1;
    }
    return 0;
}


void main(){
    Carta *cr = NULL;
    Carta *mazzo = NULL;
    Carta *bob = NULL;
    Carta *alice = NULL;

   
    for(int semi = 0 ; semi < 4 ; semi++){      //ciclo for che cicla i semi delle carte
        for (int num = 1 ; num < 14 ; num++){       //ciclo for che cicla il valore delle carte
            if(semi == 0){      //if che chiede se la carta è di cuori
                seme = 'C';
            }else{
                if(semi == 1){      //if che chiede se la carta e di quadri
                    seme = 'Q';
                }else{
                    if(semi == 2){      //if che chiede se la carta e di fiori
                        seme = 'F';
                    }else{
                        seme = 'P';
                    }
                }
            }
            cr = (Carta*) malloc (sizeof(Carta));   //malloc che crea un istanza per ogni carta
            push(&mazzo, &cr);      //push che carica nella pila del mazzo le carte una ad una
        }
    }
    for (int k = 0 ; k < 26 ; k++){         //for che cicla fino alla fine del mazzo
        int s = rand( )%1+2;        //random per vederea chi dare prima la carta
        if (s == 0){        //if che chiede se devo dare la carta prima a bob o alice
            pop(&mazzo);        //pop che toglie una carta dalla pila del mazzo
            push(&alice, &cr);      //push che da una carta ad alice
            pop(&mazzo);        //pop che toglie una carta dalla pila del mazzo
            push(&bob, &cr);        //push che da una carta a bob
        }else{
            pop(&mazzo);        //pop che toglie una carta dalla pila del mazzo
            push(&bob, &cr);        //push che da una carta a bob
            pop(&mazzo);        //pop che toglie una carta dalla pila del mazzo
            push(&alice, &cr);      //push che da una carta ad alice
        }

    }
    for (int q = 0 ; q < 26 ; q++){     //for che cicla tutte le carte di alice
        printf("%d %c", pop(&alice))        //stampa delle carte di alice
    }
}