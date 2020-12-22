//
//  main.c
//  Esercizio 1 secondo itinere 2014
//
//  Created by Matteo Rigamonti on 31/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
Esercizio 1 – Liste dinamiche (8 punti)
Scrivere una funzione in C che data una lista dinamica la modifichi eliminando tutti gli elementi di posizione pari nella sequenza.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int val;
    struct _nodo *next;
}nodo;

void funzione(nodo *lista){
    int i;
    nodo *cur, *prec;
    for (cur = lista, prec = cur, i = 0; cur != NULL; prec = cur, cur = cur -> next, i++) {
        if (i % 2 == 0) {
            //elimina nodo
            if (cur == lista) {
                lista -> next = cur -> next;
                free(cur);
            }else{
                prec -> next = cur -> next;
                free(cur);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
