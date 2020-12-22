//
//  main.c
//  Esercizio 3 luglio 2016
//
//  Created by Matteo Rigamonti on 31/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*Esercizio 3. Uso di File e Liste Dinamiche (16 punti)
Si vuole definire un interprete in grado di individuare errori nell’uso delle parentesi in un testo. Si supponga di dover controllare l’uso di tre tipi di parentesi, utilizzate per delimitare parti di testo:
 le parentesi tonde: “(” e “)”
 le parentesi quadre: “[” e “]”
 le parentesi graffe “{” e “}”
Si scriva un programma che:
 Legge da un file di testo una sequenza di caratteri da analizzare e memorizza i singoli caratteri in una lista
dinamica
 Quindi verifica se la sequenza di caratteri letta da file è “ben parentesizzata”. Una stringa è ben
parentesizzata quando sono soddisfatte le due condizioni seguenti:
1. Per ogni parentesi aperta (di uno dei tre tipi possibili) deve esserci nel seguito della stringa una
parentesi chiusa dello stesso tipo;
2. Ogni parentesi chiusa deve essere stata aperta in precedenza con una parentesi dello stesso tipo.
Esempi di stringhe:
 La stringa “]xxx(y)[” non è ben parentesizzata, perché non soddisfa nessuna delle due condizioni.
 “]xxx(y)[aa]” non è ben parentesizzata perché, pur soddisfacendo la condizione 1, non soddisfa la 2 a causa della prima parentesi quadra - che è chiusa senza che prima ce ne sia una aperta.
 La stringa “(xx[y]” non soddisfa la prima condizione, mentre la stringa “x+(y-z)+1} ” non soddisfa la seconda condizione.
 Sono invece ben parentesizzate le stringhe: “{xxxx[y(zz])}ww ”, “([{x]}) ”, “xxyyzz ”. Sono quindi valide sia stringhe che non contengono parentesi, sia quelle che non rispettano l’annidamento delle parentesi, come nella stringa “([{x]})” in cui l’ordine di chiusura delle parentesi non corrisponde a quello di apertura, purché le parentesi siano aperte e chiuse rispettando le due condizioni.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    char c;
    struct _nodo *next;
}nodo;

nodo *read_f(FILE *fp){
    nodo *lista = NULL, *cur;
    while (feof(fp)) {
        if (lista == NULL) {
            lista = malloc(sizeof(nodo*));
            fscanf(fp, "%c", &lista -> c);
            cur = lista -> next;
        }else{
            cur = malloc(sizeof(nodo*));
            fscanf(fp, "%c", &cur -> c);
            cur = cur -> next;
        }
    }
    return lista;
}

void funzione(nodo *lista){
    nodo *cur;
    int flag_tonde = 0, flag_quadre = 0, flag_graffe = 0;
    for (cur = lista; cur != NULL; cur = cur -> next) {
        //per ogni parentesi aperta dev'essercene una chiusa dello stesso tipo
        if (cur -> c == '(') {
            flag_tonde++;
        }
        if (cur -> c == ')') {
            flag_tonde--;
        }
        if (cur -> c == '[') {
            flag_quadre++;
        }
        if (cur -> c == ']') {
            flag_tonde--;
        }
        if (cur -> c == '{') {
            flag_graffe++;
        }
        if (cur -> c == '}') {
            flag_tonde--;
        }
        if (flag_tonde < 0 || flag_quadre < 0 || flag_graffe < 0) {
            printf("stringa non ben parentesizzata");
        }
    }
    if (flag_tonde != 0 || flag_quadre != 0 || flag_graffe != 0) {
        printf("stringa non ben parentesizzata");
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
