//
//  main.c
//  Esercizio 5
//
//  Created by Matteo Rigamonti on 09/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 5 (8 punti).
 (6 punti) Si definisca una funzione che, ricevuto come parametro il puntatore a un file di testo (e qualsiasi altro parametro ritenuto necessario), determini quale dei 26 caratteri minuscoli dell’alfabeto compare nel file con maggiore frequenza. Il programma restituisce all’ambiente chiamante il carattere e la sua frequenza.
 (2 punti) Scrivere un programma che acquisisce il nome del file di testo da riga di comando. Quindi, dopo aver aperto il file, richiama la funzione definita al punto precedente e stampa i valori restituiti.
 */

#include <stdio.h>

struct car{
    char c;
    int occ;
};

struct car funzione(FILE *fp){
    int i, max = 0;
    char carattere;
    
    struct car ret;
    
    //fp = fopen(filename, "r");
    int occ[26]; //array che conta le occorrenze
    
    while (feof(fp)) {
        fscanf(fp, "%c", &carattere);
        carattere -= 96;
        occ[carattere]++;
    }
    
    for (i = 0; i < 26; i++) {
        if (occ[i] > max) {
            max = occ[i];
        }
    }
    ret.c = i + 96;
    ret.occ = max;
    
    return ret;
}

int main(int argc, const char * argv[]) {
    
    FILE *fp;
    fp = fopen(argv[0], "r");//leggo da riga di comando
    printf("Carattere: %c\nOccorrenze: %d\n", funzione(fp).c, funzione(fp).occ);
    fclose(fp);
    
    return 0;
}
