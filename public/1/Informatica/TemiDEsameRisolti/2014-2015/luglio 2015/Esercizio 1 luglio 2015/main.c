//
//  main.c
//  Esercizio 1 luglio 2015
//
//  Created by Matteo Rigamonti on 05/08/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 1 – Liste dinamiche (10 punti)
 Sia data una lista dinamica che memorizza una sequenza di abbreviazioni (per esempio, “SI”, “MI”, “PC”) e per ognuna di esse le corrispondenti parole estese (per esempio, “Sistema Informativo”, “Milano”, “Per Conoscenza”). Ogni nodo della lista è quindi una struttura definita nel seguente modo:
 struct nodo {
     char sigla[2];
     char parola[20];
     struct nodo *next;
 }
 Si scriva una funzione in C che riceve come parametri il puntatore alla testa della lista (la lista non deve essere creata, si suppone che esista già in memoria), una abbreviazione e la parola corrispondente e ricerca l’abbreviazione nella lista; quindi:
 1. Se la sigla non è presente nella lista, inserisce in coda alla lista un nuovo elemento per memorizzare la sigla e la parola estesa ricevute come parametro e restituisce 0; per esempio, se la lista contiene le coppie sopra citate (<“SI”, “Sistema Informativo” >, <“MI”, “Milano” >, <“PC”, Per Conoscenza>) e la sigla da cercare è “CC”, allora la funzione restituirà il valore 0.
 2. Se la coppia <sigla, parola> è presente nella lista, la funzione restituisce 1; per esempio se la funzione riceve come parametri “SI” e “Sistema Informativo” allora restituisce il valore 1;
 3. Se la sigla è contenuta nella lista ma è associata a una parola differente, la funzione restituisce 2; per esempio, data la lista precedente, se la funzione riceve come parametri “SI” e “Sicurezza Informatica”, allora restituisce il valore 2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
    char sigla[2];
    char parola[20];
    struct _nodo *next;
}nodo;

int funzione(nodo *lista, char input_sigla[2], char input_parola[20]){
    nodo *cur;
    int found = 0;
    for (cur = lista; cur != NULL; cur = cur -> next) {
        if (strcmp(cur -> sigla, input_sigla)) {
            found = 1;
            if (strcmp(cur -> parola, input_parola)) {
                return 1;
            }else{
                return 2;
            }
        }
    }
    if (found == 0) {
        cur = malloc(sizeof(nodo*));
        strcpy(cur -> sigla, input_sigla);
        strcpy(cur -> parola, input_parola);
    }
    return 0;
}

//secondo modo
int funzione2(nodo *lista, char input_sigla[2], char input_parola[20]){
    nodo *cur;
    for (cur = lista; cur != NULL; cur = cur -> next) {
        if (strcmp(cur -> sigla, input_sigla)) {
            if (strcmp(cur -> parola, input_parola)) {
                return 1;
            }else{
                return 2;
            }
        }
    }
    cur = malloc(sizeof(nodo*));
    strcpy(cur -> sigla, input_sigla);
    strcpy(cur -> parola, input_parola);
    return 0;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
