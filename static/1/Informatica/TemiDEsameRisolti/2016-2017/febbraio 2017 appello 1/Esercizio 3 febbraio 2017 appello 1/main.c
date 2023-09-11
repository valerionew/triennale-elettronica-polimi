//
//  main.c
//  Esercizio 3 febbraio 2017 appello 1
//
//  Created by Matteo Rigamonti on 26/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 3 (15 punti).
 Si vuole definire un programma in C, opportunamente strutturato in funzioni che, data una sequenza di valori interi letti da file, individui eventuali sotto-sequenze (di lunghezza minima 2) di valori consecutivi crescenti e le scriva in un secondo file. Per esempio, se nel file di input è memorizzata la sequenza 3, 5, 2, 4, 2, 8, 4, 3, 2
 allora il programma salva sul file di output le seguenti sotto-sequenze: 3, 5
 2, 4
 2, 8
 N.B.: Il programma deve essere realizzato in modo modulare, scomponendolo almeno nelle seguenti funzioni:
 1. La funzione main: deve ricevere come argomenti della linea di comando il nome dei due file (quello di
 input e quello di output) (3 punti);
 2. Una funzione che legga i valori dal file di input e li memorizzi in un’opportuna struttura dati (4 punti);
 3. Una funzione che riceva in input la struttura dati creata al punto precedente e memorizzi nel file di output le eventuali sotto-sequenze. (8 punti);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int val;
    struct _nodo *next;
}nodo;

nodo *read_f(FILE *fp){
    nodo *list = NULL, *cur;
    while (feof(fp)) {
        if (list == NULL) {
            list = malloc(sizeof(nodo*));
            fscanf(fp, "%d", &list -> val);
            cur = list -> next;
        }else{
            cur = malloc(sizeof(nodo*));
            fscanf(fp, "%d", &cur -> val);
            cur = cur -> next;
        }
    }
    
    return list;
}

void write_f(FILE *fp, nodo *lista){
    nodo *cur;
    
    for (cur = lista; cur != NULL; cur = cur -> next) {
        if (cur -> val < cur -> next -> val) {
            fprintf(fp, "%d,", cur -> val);
        }else{
            fprintf(fp, "\n");
        }
    }
}

int main(int argc, const char * argv[]) {
    
    FILE *fp1, *fp2;
    nodo *lista;
    
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    
    lista = read_f(fp1);
    write_f(fp2, lista);
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
