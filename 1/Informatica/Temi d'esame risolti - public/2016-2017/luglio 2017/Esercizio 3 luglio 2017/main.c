//
//  main.c
//  Esercizio 3 luglio 2017
//
//  Created by Matteo Rigamonti on 27/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*

 Quesito 3. (10 punti). Si definisca una funzione che, data una lista dinamica L contenente una sequenza di valori interi, la modifichi inserendo un valore val in una posizione k contata a partire dalla fine dalla sequenza. Se k = 1 val dovrà essere inserito in ultima posizione; se k = 2 in penultima posizione e così via. La funzione riceve L, val e k come parametri e restituisce il puntatore alla lista L.
 Esempio: se L = <1 6 2 3 1 10> e i valori letti in input sono val=3, k=4, dopo l’inserimento di val L = <1 6 2 3 4 1 10>.
 N.B.: Nella valutazione della soluzione si terrà conto del numero di scansioni effettuate su L per determinare la posizione in cui inserire il nuovo valore. E’ infatti possibile definire una soluzione efficiente, in grado di determinare la posizione dell’inserimento con una sola scansione della lista.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int n;
    struct _nodo *next;
}nodo;

nodo *funzione(nodo *lista, int val, int k){
    if (lista == NULL) {
        return NULL;
    }else{
        
        lista = funzione(lista -> next, val, k);
        k--;
        if (k == 0) {
            nodo *cur = NULL;
            cur = malloc(sizeof(nodo*));
            cur -> n = val;
            cur -> next = lista -> next -> next;
            lista -> next = cur;
        }
        
    }
    return lista;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
