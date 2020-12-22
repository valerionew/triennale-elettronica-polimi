//
//  main.c
//  Esercizio 4 luglio 2019
//
//  Created by Matteo Rigamonti on 23/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 4 (10 punti).
(8 punti) Si definisca un sottoprogramma che data una stringa s e un carattere ch (e qualsiasi altro parametro ritenuto necessario), restituisca all’ambiente chiamante una lista i cui nodi memorizzano stringhe costituite dai caratteri che in s sono compresi tra due occorrenze di ch (queste occorrenze escluse). Tali stringhe, se esistono, hanno una dimensione massima N predefinita. Nel caso in cui s non contenga due occorrenze del carattere ch, il sottoprogramma restituisce una lista vuota.
Si garantisce che, se ch è presente almeno due volte in s, il numero di caratteri compreso tra le due occorrenze non superi mai la lunghezza predefinita N.
 Per esempio:
 - se s = "almanacco" e ch ='a', il sottoprogramma restituisce la lista: “lm"--> “n”
 - se s = "uno-due-tre" e ch ='i' il sottoprogramma restituisce una lista vuota.
 Oltre a definire la funzione, si definisca opportunamente il tipo degli elementi della lista.
 
 (2 punti) Scrivere un programma che acquisisce da riga di comando una stringa e un carattere e richiama il sottoprogramma sviluppato al punto precedente. Quindi visualizza la lista costruita dal sottoprogramma (un elemento per riga) e termina. Nel caso di lista vuota, il sottoprogramma stampa il messaggio “Lista vuota”. Per esempio, se il nome del programma è “ritaglia”, si riportano sotto due esempi di esecuzione: ./ritaglia almanacco a
 lm n
 ./ritaglia uno-due-tre i Lista vuota
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5

typedef struct _nodo{
    char *str;
    struct _nodo *next;
}nodo;

nodo *funzione(char *s, char ch){
    //verifico se c'è ch
    int i,j, flag = 0;
    char *s2 = NULL;
    nodo *lista = NULL, *cur;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            for (j = i + 1; j < strlen(s); j++) {
                if (j - i > N) {
                    printf("errore, superato N");
                    return NULL;
                }
                if (s[j] == ch) {
                    flag = j;
                }
            }
            if (flag > 0) {
                
                for (j = i; j < strlen(s); j++) {
                    s2[j - i] = s[j];
                }
                
                if (lista == NULL) {
                    lista = malloc(sizeof(nodo*));
                    strcpy(lista -> str, s2);
                    cur = lista -> next;
                }else{
                    cur = malloc(sizeof(nodo*));
                    strcpy(cur -> str, s2);
                    cur = cur -> next;
                }
            }
        }
    }
    if (i == strlen(s) && lista == NULL) {
        printf("lista vuota");
        return NULL;
    }
    return lista;
}

int main(int argc, const char * argv[]) {
    
    nodo *lista, *cur;
    lista = funzione(argv[1], argv[2]);
    
    printf("%s %s %s", argv[0], argv[1], argv[2]);
    
    if (lista == NULL) {
        printf("lista vuota");
    }else{
        for (cur = lista; cur != NULL; cur = cur -> next) {
            printf("\n");
            printf("%s", cur -> str);
        }
    }
    
    return 0;
}
