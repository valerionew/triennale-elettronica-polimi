//
//  main.c
//  Esercizio 3
//
//  Created by Matteo Rigamonti on 09/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 3 (5 punti). Sia data una lista che memorizza una sequenza di interi. La lista contiene almeno due nodi. Dopo aver opportunamente definito il tipo dei nodi della lista, si scriva una funzione che riceve come parametro la testa della lista e ne modifica i valori sommando a ogni elemento il valore dell'elemento precedente. Il primo nodo rimane invariato.
 Per esempio, se la lista contiene i valori 5-> 1-> 3-> 9-> 8, allora la funzione la modifica in 5-> 6-> 4-> 12-> 17.

 */

#include <stdio.h>

typedef struct _nodo{
    int n;
    struct _nodo *next;
}nodo;

void funzione(nodo* lista){
    nodo *cur, *prec;
    
    for (prec = lista, cur = lista -> next; cur != NULL; prec = cur, cur = cur -> next) {
        cur -> n += prec -> n;
    }
}

void funzione_ricorsiva(int val, nodo* lista){
    
    int temp;
    temp = lista -> n;
    lista -> n += val;
    
    if (lista -> next == NULL) {
        lista -> n += val;
    }else{
        
        funzione_ricorsiva(temp, lista -> next);
        
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
