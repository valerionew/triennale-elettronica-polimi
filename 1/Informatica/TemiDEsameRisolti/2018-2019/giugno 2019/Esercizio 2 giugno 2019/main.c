//
//  main.c
//  Esercizio 2 giugno 2019
//
//  Created by Matteo Rigamonti on 20/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 2 (6 punti). Sia data una lista dinamica, L1, che memorizza una sequenza di valori interi. Si definisca una funzione che, ricevuta in ingresso L1, crei e restituisca all’ambiente chiamante una nuova lista dinamica, L2, i cui elementi memorizzano i valori senza ripetizioni presenti in L1 e, per ogni valore, il numero di volte in cui compare in L1. La lista L2 deve essere costruita in modo che i nodi siano ordinati in ordine crescente in base al primo valore del nodo. Per esempio, se L1 memorizza la sequenza:
 2 -->0-->3-->2-->0-->3 -->121-->18-->0 la funzione costruirà la seguente lista:
 (0, 3) --> (2, 2) --> (3, 2) --> (18,1) --> (121,1)
 Oltre a definire la funzione, si definiscano opportunamente i tipi che rappresentano gli elementi delle due liste.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo1{
    int n;
    struct _nodo1 *next;
}nodo1;

typedef struct _nodo2{
    int n;
    int occ;
    struct _nodo2 *next;
}nodo2;

nodo2 *funzione(nodo1 *head){
    int i;
    nodo1 *cur1;
    nodo2 *cur2 = NULL, *head2 = NULL;
    
    for (cur1 = head, i = 0; cur1 != NULL; cur1 = cur1 -> next, i++, cur2 = cur2 -> next) {
        
        if (cur1 -> n == i) {
            if (cur1 == head) {
                
                cur2 = malloc(sizeof(nodo2));
                cur2 -> n = i;
                cur2 -> occ++;
                head2 = cur2;
                
            }
            //creo un nodo di L2 e aggiungo
            cur2 = malloc(sizeof(nodo2));
            cur2 -> n = i;
            cur2 -> occ++;
        }
    }
    
    return head2;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
