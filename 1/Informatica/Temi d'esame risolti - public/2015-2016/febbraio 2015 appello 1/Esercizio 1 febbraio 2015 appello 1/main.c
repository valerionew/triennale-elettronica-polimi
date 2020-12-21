//
//  main.c
//  Esercizio 1 febbraio 2015 appello 1
//
//  Created by Matteo Rigamonti on 27/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 1. Gestione dei File e Matrici (14 punti)
 La soluzione di un cruciverba può essere memorizzata in un file organizzato nel seguente modo:
 - La prima riga contiene due numeri interi: il numero di righe e il numero di colonne del cruciverba;
 - Le righe successive corrispondono alle righe del cruciverba; le caselle nere sono codificate come asterischi.
 Di seguito si riporta un esempio di schema di cruciverba memorizzato nel file:
 SUGLI*
 ODIATI
 TIRI*N
 TRI*CD
 OE*POI
 Definire un programma in C in grado di leggere dal file lo schema del cruciverba e scrivere in un secondo file, chiamato parole.txt, l’elenco delle parole, sia orizzontali, sia verticali, che hanno bisogno di una definizione (cioè le sole parole di lunghezza >=2). Il file parole.txt dovrà memorizzare prima tutte le parole orizzontali (una per riga), quindi una riga vuota, e infine tutte le parole verticali (una per riga). Per esempio, dato lo schema del cruciverba riportato sopra, il file parole.txt dovrà memorizzare:
 SUGLI
 ODIATI
 TIRI
 TRI
 CD
 OE
 POI
 SOTTO
 UDIRE
 GIRI
 LAI
 IT
 CO
 INDI
 Si scriva un programma in C che riceve come argomento sulla linea di comando il nome del file che memorizza lo schema del cruciverba; quindi scrive nel file parole.txt l’elenco delle parole di lunghezza >= 2, così come illustrato nell’esempio precedente. Si assuma che la dimensione massima di un cruciverba sia 20 × 20.
 Il programma deve essere realizzato in modo modulare, scomponendolo almeno nelle seguenti funzioni:
 1. La funzione main con passaggio come argomento della linea di comando del nome del file con lo schema del cruciverba (3 punti);
 2. Una funzione che legge il cruciverba dal file trasferendone il contenuto in un’opportuna struttura dati (4 punti);
 3. Una o più funzioni per la ricerca delle parole nella struttura dati costruita al punto precedente e scrittura nel file parole.txt (7 punti).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
    char *s;
    struct _nodo *next;
}nodo;

nodo *funzione(FILE *fp){
    nodo *lista = NULL, *cur;
    char *s = NULL;
    while (feof(fp)) {
        if (lista == NULL) {
            lista = malloc(sizeof(nodo*));
            fscanf(fp, "%s", s);
            lista -> s = malloc(strlen(s) * sizeof(char));
            strcpy(lista -> s, s);
            cur = lista -> next;
        }else{
            cur = malloc(sizeof(nodo*));
            fscanf(fp, "%s", s);
            cur -> s = malloc(strlen(s) * sizeof(char));
            strcpy(cur -> s, s);
            cur = cur -> next;
        }
    }
    return lista;
}

void write_f(FILE *fp, nodo *lista){
    nodo *cur;
    for (cur = lista; cur != NULL; cur = cur -> next) {
        fprintf(fp, "%s", cur -> s);
    }
}

int main(int argc, const char * argv[]) {
    
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    
    write_f(fp2, funzione(fp1));
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
