//
//  main.c
//  Esercizio 3 febbraio 2015
//
//  Created by Matteo Rigamonti on 31/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 3 – Funzioni ricorsive (8 punti)
 1. (4 punti) Si scriva una funzione ricorsiva che, data una lista dinamica che memorizza valori interi, stampi i soli
 valori di posizione pari nella lista. Il primo elemento della lista è in posizione 1.
 2. (4 punti) Si scriva una funzione ricorsiva in C che, dato un array di interi, calcoli e restituisca come valore di ritorno il valore massimo dell’array.
 */

#include <stdio.h>
#define N 10

typedef struct _nodo{
    int val;
    struct _nodo *next;
}nodo;

void funzione(nodo *lista, int index){ //dal main passo funzione(lista, 1);
    if (lista == NULL) {
        printf("fine");
    }else{
        if (index % 2 == 0) {
            printf("%d", lista -> val);
        }
        funzione(lista -> next, index + 1);
    }
}

int max_arr(int array[N], int i){
    if (i == N - 1) {
        if (array[i] > array[i - 1]) {
            return array[i];
        }
        return array[i - 1];
    }else{
        if (array[i] > max_arr(array, i + 1)) {
            return array[i];
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
