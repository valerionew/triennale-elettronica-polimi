//
//  main.c
//  Esercizio 1 febbraio 2017 appello 1
//
//  Created by Matteo Rigamonti on 26/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 1 (5 punti). Sia data una lista dinamica, L1, che memorizza una sequenza di valori interi. Si definisca una funzione che, ricevuta in ingresso L1, crei e restituisca una nuova lista dinamica, L2, i cui elementi memorizzano i valori (senza ripetizioni) presenti in L1 e per ognuno di essi il numero di volte in cui compare in L1. Per esempio, se L1 memorizza la sequenza:
5 0 -3 2 0 0 121 -18 5
la funzione costruirà e restituirà la seguente lista:
(5, 2) -> (0, 3) -> (-3, 1) -> (2,1) -> (121,1) -> (-18,1)
N.B.: Oltre a definire la funzione, si definiscano opportunamente i tipi che rappresentano gli elementi delle due liste.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo1{
    int val;
    struct _nodo1 *next;
}nodo1;

typedef struct _nodo2{
    int val;
    int occ;
    struct _nodo2 *next;
}nodo2;

nodo2 *funzione(nodo1 *L1){
    int flag = 0;
    nodo2 *L2 = NULL, *cur2, *cur3;
    nodo1 *cur;
    
    for (cur = L1; cur != NULL; cur = cur -> next) {
        if (L2 == NULL) {
            L2 = malloc(sizeof(nodo2*));
            L2 -> val = L1 -> val;
            L2 -> occ = 0;
            L2 -> occ++;
            cur2 = L2 -> next;
        }else{
            for (cur3 = L2; cur3 != NULL; cur3 = cur3 -> next) {
                if (cur3 -> val == cur -> val) {
                    cur3 -> occ++;
                    flag = 1;
                }
            }
            if (flag != 1) {
                cur2 = malloc(sizeof(nodo2*));
                cur2 -> val = cur -> val;
                cur2 -> occ++;
            }
        }
    }
    return L2;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
