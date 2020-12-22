//
//  main.c
//  Esercizio 3 febbraio 2018
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
Quesito 3 (6 punti).
Scrivere un programma in linguaggio C, completo di opportune dichiarazioni, che legge da un file una sequenza di valori interi di lunghezza indefinita e, per ogni valore letto, memorizza in un secondo file il valore stesso e il numero di ripetizioni. I nomi dei due file sono specificati dall’utente come argomenti della linea di comando. Esempio: supponendo che il file di input contenga i seguenti valori
10 6 2 6 2 10 10
il programma dovrà scrivere nel file di output: valore 10: 3 ripetizioni
valore 6: 2 ripetizioni
valore 2: 2 ripetizioni
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int num, i;
    int occ[100];
    FILE *fp, *fp2;
    fp = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    
    while (feof(fp)) {
        fscanf(fp, "%d", &num);
        occ[num]++;
    }
    
    for (i = 0; i < 100; i++) {
        if (occ[i > 0]) {
            fprintf(fp2, "valore %d: %d ripetizioni\n", i, occ[i]);
        }
    }
    
    fclose(fp);
    return 0;
}
