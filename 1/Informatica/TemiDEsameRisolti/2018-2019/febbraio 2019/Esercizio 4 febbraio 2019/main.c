//
//  main.c
//  Esercizio 4 febbraio 2019
//
//  Created by Matteo Rigamonti on 20/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 4 (6 punti). Si supponga di avere, già presente in memoria, una lista dinamica che memorizza una sequenza di interi. Dopo aver dichiarato in modo opportuno il tipo del nodo e la lista, si scriva una funzione in C che riceve come parametro la testa della lista e un intero x e modifica la lista eliminando i valori che in essa ricorrono un numero di volte maggiore o uguale a x.
 Esempio: data la lista 3 -> 5 -> 8 -> 4 -> 8 -> 5 ->3 -> 8 e dato x = 3, la funzione modifica la lista nel seguente modo: 3 -> 5 -> 4 -> 5 -> 3
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int n;
    struct _nodo *next;
}nodo;

void funzione(nodo *head, int max_occ){
    nodo *cur, *prec;
    int occ[10],i;
    
    for (cur = head; cur != NULL; cur = cur -> next) {
        occ[cur -> n]++;
    }
    
    for (i = 0; i < 10; i++) {
        if (occ[i] > max_occ) {
            for (cur = head, prec = head; cur != NULL; prec = cur, cur = cur -> next) {
                if (cur -> n == i) {
                    //elimino cur
                    prec -> next = cur -> next;
                    free(cur);
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
