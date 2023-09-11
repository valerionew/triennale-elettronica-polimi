//
//  main.c
//  Esercizio 5 luglio 2019
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 5 (6 punti). Scrivere un sottoprogramma che riceve in ingresso il puntatore a un file che memorizza una sequenza di numeri interi positivi, uno per ogni riga. Per ogni valore letto dal file, il sottoprogramma calcola la cifra che compare più di frequente, quindi stampa a video il numero letto dal file e la cifra con maggiori occorrenze. Nel caso ci siano più cifre con lo stesso numero di occorrenze, restituisce la cifra con valore più alto. Per esempio, se il file memorizza i seguenti valori:
144360
14433660
2005
allora il sottoprogramma stampa:
Numero letto: 144360 - Cifra più frequente: 4 Numero letto: 14433660 - Cifra più frequente: 6 Numero letto: 20005 - Cifra più frequente: 0
 */

#include <stdio.h>

void funzione(FILE *fp){
    int n, i, occ[10], max = 0, max_index = 0;
    
    while (feof(fp)) {
        
        fscanf(fp, "%d", &n);
        printf("Numero Letto: %d", n);
        
        while (n / 10 > 0) {
            occ[n / 10]++;
            n /= 10;
        }
        for (i = 0; i < 10; i++) {
            if (occ[i] > max) {
                max = occ[i];
                max_index = i;
            }
        }
        printf("Cifra più frequente: %d", max_index);
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
