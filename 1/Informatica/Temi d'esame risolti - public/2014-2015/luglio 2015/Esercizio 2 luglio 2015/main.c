//
//  main.c
//  Esercizio 2 luglio 2015
//
//  Created by Matteo Rigamonti on 06/08/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 2 – Funzioni in C e lettura da file (10 punti)
 Si supponga di avere a disposizione un file che memorizza una sequenza (di lunghezza ignota) di valori interi. Nel file i diversi valori sono separati da uno spazio.
 Si scriva una funzione in C che riceve come parametri il nome del file (una stringa) e due valori interi, v1 e v2 (con v1 minori v2), e modifichi il file nel modo seguente:
 - i valori minori di v1 devono essere memorizzati tutti all’inizio del file.
 - i valori maggiori o uguali a v1 e minori di v2 devono essere memorizzati tutti al centro del file.
 - i valori maggiori o uguali a v2 devono essere memorizzati alla fine del file.
 L’ordine all’interno di ciascuna partizione del file deve rimanere lo stesso che nel file iniziale; cioè le partizioni non devono essere ordinate.
 Per esempio, se il file iniziale contiene la sequenza:
 2 5 21 8 10 1 4 16 3
 e i valori di v1 e v2 sono rispettivamente 3 e 9, il file diventa 2 1 5 8 4 3 21 10 16
 N.B.: è possibile far uso di strutture dati di appoggio per creare le tre partizioni prima di memorizzarle nel file.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int val;
    struct _nodo *next;
}nodo;

void funzione(char *filename, int v1, int v2){
    nodo *lista1 = NULL, *cur1;
    nodo *lista2 = NULL, *cur2;
    nodo *lista3 = NULL, *cur3;
    FILE *fp1,*fp2;
    int n;
    fp1 = fopen(filename, "r");
    fp2 = fopen("nome_file_dest", "w");
    
    while (feof(fp1)) {
        fscanf(fp1, "%d", &n);
        if (n < v1) {
            if (lista1 == NULL) {
                lista1 = malloc(sizeof(nodo*));
                lista1 -> val = n;
                cur1 = lista1 -> next;
            }else{
                cur1 = malloc(sizeof(nodo*));
                cur1 -> val = n;
                cur1 = cur1 -> next;
            }
        }else if(n > v2){
            if (lista3 == NULL) {
                lista3 = malloc(sizeof(nodo*));
                lista3 -> val = n;
                cur3 = lista3 -> next;
            }else{
                cur3 = malloc(sizeof(nodo*));
                cur3 -> val = n;
                cur3 = cur3 -> next;
            }
        }else{
            if (lista2 == NULL) {
                lista2 = malloc(sizeof(nodo*));
                lista2 -> val = n;
                cur2 = lista2 -> next;
            }else{
                cur2 = malloc(sizeof(nodo*));
                cur2 -> val = n;
                cur2 = cur2 -> next;
            }
        }
    }
    
    for (cur1 = lista1; cur1 != NULL; cur1 = cur1 -> next) {
        fprintf(fp2, "%d", cur1 -> val);
    }
    for (cur2 = lista2; cur2 != NULL; cur2 = cur2 -> next) {
        fprintf(fp2, "%d", cur2 -> val);
    }
    for (cur3 = lista3; cur3 != NULL; cur3 = cur3 -> next) {
        fprintf(fp2, "%d", cur3 -> val);
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
