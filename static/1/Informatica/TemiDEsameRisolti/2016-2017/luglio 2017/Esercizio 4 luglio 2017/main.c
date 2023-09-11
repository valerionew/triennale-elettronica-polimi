//
//  main.c
//  Esercizio 4 luglio 2017
//
//  Created by Matteo Rigamonti on 27/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 4. (10 punti)
 Una matrice si dice sparsa se la maggior parte dei suoi elementi ha uno stesso, unico valore dominante. Per esempio, la seguente matrice di dimensione 3x4 è sparsa e ha valore dominante pari a 4:
 4442
 4144
 0443
 Sia dato un file che memorizza una matrice sparsa (di dimensione massima 100x100) nel seguente modo:
 - la prima riga contiene il numero di righe, il numero di colonne e il valore dominante.
 - Le righe successive contengono l’indice di riga, l’indice di colonna e il valore di ciascun elemento
 diverso dal valore dominante.
 Per esempio, per la matrice riportata sopra, il file con la rappresentazione compatta conterrà i seguenti dati:
 344
 032
 111
 200
 223
 Si scriva un programma in C, completo di dichiarazioni e opportunamente strutturato in funzioni, che prende come parametro sulla riga di comando il nome di due file. Il primo file è quello da cui leggere la rappresentazione compatta della matrice sparsa. Il programma deve quindi scrivere sul secondo file la matrice in forma estesa.
 */

#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct _nodo{
    int val;
    int x;
    int y;
    struct _nodo *next;
}nodo;

nodo *read_f(FILE *fp){
    int rows, cols, dom;
    nodo *lista = NULL, *cur;
    fscanf(fp, "%d%d%d", &rows, &cols, &dom);
    
    while (feof(fp)) {
        if (lista == NULL) {
            lista = malloc(sizeof(nodo));
            fscanf(fp, "%d%d%d", &lista -> x, &lista -> y, &lista -> val);
            cur = lista -> next;
        }else{
            cur = malloc(sizeof(nodo));
            fscanf(fp, "%d%d%d", &cur -> x, &cur -> y, &cur -> val);
            cur = cur -> next;
        }
    }
    return lista;
}

void write_f(nodo *lista, FILE *fp){
    nodo *cur;
    int rows, cols, dom,i,j;
    rows = lista -> x;
    cols = lista -> y;
    dom = lista -> val;
    int mat[rows][cols];
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            mat[i][j] = dom;
        }
    }
    
    for (cur = lista -> next; cur != NULL; cur = cur -> next) {
        mat[cur -> x][cur ->y] = cur -> val;
    }
}

int main(int argc, const char * argv[]) {
    
    FILE *fp1, *fp2;
    
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    
    write_f(read_f(fp1), fp2);
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
