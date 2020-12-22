//
//  main.c
//  Esercizio 4 settembre 2015
//
//  Created by Matteo Rigamonti on 11/08/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 4 – Liste dinamiche in C (10 punti)
 Si vuole gestire in C una lista dinamica in cui ogni elemento memorizza un valore intero, il puntatore all’elemento successivo, il puntatore all’elemento della lista con valore minimo. L’inserimento di nuovi elementi avviene in testa. A ogni inserimento, è necessario ricalcolare il minimo della lista e, in caso di nuovo valore, aggiornare i puntatori corrispondenti negli elementi della lista.
 1. Definire in C le strutture dati per rappresentare ogni singolo nodo e la lista.
 2. Codificare la funzione di inserimento, definendo opportuni parametri e valori di ritorno. Si consiglia di
 strutturare il codice della funzione in modo che faccia uso di altre funzioni ausiliarie.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int val;
    struct _nodo *next;
    struct _nodo *min;
}nodo;

nodo *funzione(nodo *lista, int val){
    //inserisco in fondo, intanto controllo il minimo
    nodo *cur, *min = NULL;
    int flag = 0;
    for (cur = lista; cur != NULL; cur = cur -> next){
        if (val < lista -> min -> val) {
            min = cur;
            flag = 1;
        }
    }
    //alloco memoria per il nodo, inserendolo in fondo
    cur = malloc(sizeof(nodo));
    cur -> val = val;
    //cur -> next = NULL;
    if (flag == 1) {
        for (cur = lista; cur != NULL; cur = cur -> next) {
            cur -> min = min;
        }
    }
    return lista;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
