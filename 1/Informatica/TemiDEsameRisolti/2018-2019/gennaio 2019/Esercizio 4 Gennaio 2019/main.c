//
//  main.c
//  Esercizio 4 Gennaio 2019
//
//  Created by Matteo Rigamonti on 19/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 4 (8 punti). Si supponga di avere, già presente in memoria, una lista dinamica che memorizza una sequenza di interi. Dopo aver dichiarato in modo opportuno il tipo del nodo e la lista, si scriva una funzione in C che riceve la lista come parametro e restituisce la media dei valori della lista senza considerare però i duplicati. Esempio: data la lista
 848533
 la funzione restituirà il valore 5, cioè la media di 8, 4, 5 e 3.
 */

#include <stdio.h>

typedef struct _nodo{
    int n;
    struct _nodo *next;
}nodo;

int media(nodo *head){
    int sum = 0, dim = 0, i;
    int occ[10];
    nodo *cur;
    for (cur = head; cur != NULL; cur = cur -> next) {
        occ[cur -> n]++;
        dim++;
    }
    for (i = 0; i < dim; i++) {
        if (occ[i] > 0) {
            sum += i;
        }
    }
    return sum/dim;
}

int media_ali(nodo *head){
    int sum = 0, dim = 0, i;
    nodo *cur;
    
    for (cur = head, i = 1; cur != NULL; cur = cur -> next) {
        if (cur -> n == i) {
            sum += i;
            i++;
        }
    }
    
    return sum/dim;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
