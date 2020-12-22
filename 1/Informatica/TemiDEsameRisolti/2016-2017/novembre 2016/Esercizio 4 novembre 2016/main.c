//
//  main.c
//  Esercizio 4 novembre 2016
//
//  Created by Matteo Rigamonti on 25/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 4 (8 punti).
Sia data una stringa memorizzata in un array. Si supponga che la stringa sia inizializzata in modo esplicito e non debba essere letta in input (per l’inizializzazione si può usare l’esempio sotto riportato). Si scriva un programma in C che, operando solo sull’array a disposizione (senza utilizzare strutture dati aggiuntive), sostituisca nella stringa le eventuali sotto-sequenze di elementi delimitati da parentesi tonde (parentesi aperta all’inizio della sequenza, parentesi chiusa alla fine della sequenza) con un solo asterisco, cioè “*”. Il programma quindi stampa la nuova sequenza così ottenuta.
 Per esempio, data la sequenza iniziale {a, b, (, a, c, g,), b, e, a, (, x, x,), f, \0}, alla fine l’array conterrà la seguente sequenza {a, b, (, *,), b, e, a, (, *,), f, \0}.
 NB.:
 1. La sequenza di caratteri inizialmente memorizzata nell’array non potrà contenere coppie di parentesi che si “intersecano”; per ogni parentesi aperta, esiste una parentesi chiusa; tra due parentesi tonde è sempre incluso almeno un carattere.
 2. Non è necessario leggere in input la sequenza; l’array può essere inizializzato in modo esplicito, usando per esempio la sequenza sopra riportata.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char s1[16] = {'a', 'b', '(', 'a', 'c', 'g',')','b', 'e', 'a', '(', 'x', 'x',')', 'f', '\0'};
    int i,j, count = 0;

    
    count = 0;
    for (i = 0; i < 16; i++) {
        if (s1[i] == '(') {
            for (j = i + 1; s1[j] != ')'; j++) {
                count++;
            }
            
            for (j = i + 1; j < 16; j++) {
                s1[j] = s1[j + count - 1];
            }
            s1[i + 1] = '#';
        }
        count = 0;
    }
    for (i = 0; i < 16 - 3; i++) {
        printf("%c", s1[i]);
    }
    printf("\n");
    
    return 0;
}
