//
//  main.c
//  Esercizio 5 febbraio 2019
//
//  Created by Matteo Rigamonti on 20/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 5 (8 punti). Si vuole realizzare un correttore automatico in grado di individuare e correggere alcuni errori di battitura presenti in un testo. Il correttore sostituisce le vocali seguite dall’apostrofo con le corrispondenti vocali accentate. Quindi, parole come puo’, perche’, piu’, gia’, sono sostituite con può, benché, più, già (il verso degli accenti non è rilevante).
 Si scriva un programma in C, opportunamente organizzato in funzioni, che legga un testo da un file, una parola alla volta, corregga nelle parole lette le eventuali vocali apostrofate, e salvi tutte le parole (corrette o non) in un nuovo file.
 I nomi dei due file, quello da cui leggere il testo iniziale e quello in cui scrivere il testo corretto, devono essere specificati come argomenti della linea di comando (parametro del main).
 N.B.: Non si conosce la lunghezza massima delle parole memorizzate nel testo.
 */

#include <stdio.h>
#include <string.h>

char *correggi(char *word){
    int i;
    char c,d;
    for (i = 0; i < strlen(word) - 1; i++) {
        c = word[i];
        d = word[i + 1];
        
        if (d == 96) {
            c = c + 80; //trovare la regola per l'ascii e le lettere accentate
        }
    }
    return word;
}

int main(int argc, const char * argv[]) {
    
    char *word = NULL;
    FILE *fp1,*fp2;
    fp1 = fopen(argv[0], "r");
    fp2 = fopen(argv[1], "w");
    
    //leggo parola per parola
    while (feof(fp1)) {
        fscanf(fp1, "%s", word);
        correggi(word);
        fprintf(fp2, "%s ", word);
    }
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
