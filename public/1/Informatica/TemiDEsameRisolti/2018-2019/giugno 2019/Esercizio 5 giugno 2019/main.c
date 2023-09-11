//
//  main.c
//  Esercizio 5 giugno 2019
//
//  Created by Matteo Rigamonti on 20/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 5 (8 punti). Un file di testo memorizza in formato testuale una sequenza di valori interi positivi secondo la seguente convenzione:
 - Ogni riga rappresenta un singolo valore;
 - In una riga, ogni cifra del numero è rappresentata dalla parola corrispondente;
 - Ogni riga è terminata dalla stringa “***”.
 Un esempio di questa rappresentazione è il seguente:
 cinque due cinque ***
 due uno ***
 sei zero sei ***
 Tale file memorizza in formato testuale i valori numerici 525, 21 e 606.
 Si scriva un programma in C, opportunamente organizzato in funzioni che, ricevuto il nome del file come parametro sulla linea di comando, interpreti opportunamente il testo memorizzato nel file trasformandolo nei valori interi corrispondenti, quindi calcoli e stampi a video la media di tali valori.
 Per esempio, per il file riportato sopra, il programma deve stampare l’intero 384.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int converti(char *s){
    if (strcmp(s, "zero")) {
        return 0;
    }
    if (strcmp(s, "uno")) {
        return 1;
    }
    if (strcmp(s, "due")) {
        return 2;
    }
    if (strcmp(s, "tre")) {
        return 3;
    }
    if (strcmp(s, "quattro")) {
        return 4;
    }
    if (strcmp(s, "cinque")) {
        return 5;
    }
    if (strcmp(s, "sei")) {
        return 6;
    }
    if (strcmp(s, "sette")) {
        return 7;
    }
    if (strcmp(s, "otto")) {
        return 8;
    }
    if (strcmp(s, "nove")) {
        return 9;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int num = 0, count_num = 0, sum = 0, count_rows = 0;
    char *string = NULL;
    FILE *fp;
    fp = fopen(argv[1], "r");
    
    while (feof(fp)) {
        while (!strcmp(string, "***")) {
            fscanf(fp, "%s", string);
            num = converti(string);
            count_num++;
            sum += pow(num, count_num);
        }
        count_num = 0;
        count_rows++;
    }
    
    fclose(fp);
    
    printf("%d", sum / count_rows);
    
    return 0;
}
