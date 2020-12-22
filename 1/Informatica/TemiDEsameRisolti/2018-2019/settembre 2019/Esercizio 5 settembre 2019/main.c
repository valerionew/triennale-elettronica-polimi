//
//  main.c
//  Esercizio 5 settembre 2019
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 5 (9 punti).
(7 punti) Si definisca una funzione che, data una stringa s (e qualsiasi altro parametro ritenuto necessario), costruisca e restituisca all’ambiente chiamante una lista i cui nodi memorizzano i caratteri (senza ripetizioni) contenuti nella stringa più il numero di volte in cui tali caratteri si ripetono nella stringa. Si può assumere che la stringa contenga solo caratteri dell’alfabeto. Nella lista, i caratteri devono essere inseriti in ordine alfabetico.
Per esempio:
se s = "almanacco", il sottoprogramma restituisce la lista: <a,3> --> <c,2> --> <l,1> --> <m,1> --> <n,1> --><o,1>
Oltre a definire la funzione, si definisca opportunamente il tipo degli elementi della lista.
(2 punti) Scrivere un programma che acquisisce da riga di comando una stringa e richiama la funzione sviluppata al punto precedente. Quindi visualizza la lista costruita dal sottoprogramma (un elemento per riga) e termina.
Per esempio, se il nome del programma è “scomponi”, si riporta sotto un esempio di esecuzione: ./scomponi almanacco
a,3
c,2
......
o,1
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _nodo{
    char c;
    int occ;
    struct _nodo *next;
}nodo;

nodo *funzione( char *s){
    int occ[26], i;
    nodo *lista = NULL, *cur;
    for (i = 0; i < strlen(s); i++) {
        occ[s[i] - 96]++;
    }
    
    for (cur = lista, i = 0; cur != NULL; cur = cur -> next, i++) {
        if (cur == lista) {
            lista = malloc(sizeof(nodo));
            lista -> c = s[i] - 96;
            lista -> occ = occ[i];
            cur = lista -> next;
        }else{
            cur = malloc(sizeof(nodo));
            cur -> c = s[i] - 96;
            cur -> occ = occ[i];
        }
    }
    
    return lista;
}

int main(int argc, const char * argv[]) {
    
    nodo *lista, *cur;
    lista = funzione(argv[1]);
    
    for (cur = lista; cur != NULL; cur = cur -> next) {
        printf("%c,%d", cur -> c, cur -> occ);
    }
    
    return 0;
}
