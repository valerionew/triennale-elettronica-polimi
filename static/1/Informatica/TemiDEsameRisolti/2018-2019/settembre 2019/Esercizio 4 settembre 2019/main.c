//
//  main.c
//  Esercizio 4 settembre 2019
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*

 Quesito 4 (7 punti). Si definisca una funzione che, ricevuto come parametro il puntatore a un file di testo, determini e visualizzi il numero di occorrenze nel file per ognuna delle 26 lettere minuscole dell’alfabeto inglese. Il file può memorizzare anche altri caratteri (per esempio quelli di punteggiatura, o numeri) che tuttavia devono essere ignorati.
 */

#include <stdio.h>

void funzione(FILE *fp){
    int occ[26],i;
    char c;
    while (feof(fp)) {
        fscanf(fp, "%c", &c);
        occ[c - 96]++;
    }
    for (i = 0; i < 26; i++) {
        printf("carattere: %c, occorrenze: %d\n", i + 96, occ[i]);
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
