//
//  main.c
//  Esercizio 2 febbraio 2016 appello 1
//
//  Created by Matteo Rigamonti on 27/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 2. Liste dinamiche (10 punti)
 Sia data una lista dinamica che memorizza dati riguardanti le quotazioni in borsa di alcune aziende. Gli elementi della lista rispettano la seguente definizione di tipo:
 typedef struct nodo{
 char nomeAzienda[41]; float quotazione; float variazione; struct nodo * next;
 } aziendaQuot;
 **La lista è ordinata in base al nome dell’azienda.**
 Si definisca una funzione in C che riceve come parametri la testa della lista, il nome di un’azienda e un valore per l’ultima quotazione in borsa dell’azienda, e cerchi nella lista il nodo riguardante l’azienda:
 - Se il nodo esiste, la funzione aggiorna il valore della quotazione e memorizza inoltre la variazione (differenza) rispetto al valore precedente nel campo variazione.
 - Se il nodo non esiste, lo crea e lo inserisce nella posizione opportuna della lista, rispettando l’ordinamento alfabetico. La variazione in tal caso sarà uguale a 0.
 La funzione restituisce il puntatore alla testa della lista (che potrebbe essere modificato da un inserimento in testa).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
    char nome_azienda[41];
    float quotazione;
    float variazione;
    struct _nodo *next;
}az_quot;

az_quot *funzione(az_quot *head, char nome[41], int quot){
    az_quot *cur, *cur2;
    int n;
    for (cur = head; cur != NULL; cur = cur -> next) {
        n = strcmp(cur -> nome_azienda, nome);
        if (n == 0) {
            cur -> quotazione += quot;
            cur -> variazione = quot;
            return head;
        }else if(n > 0 && nome[0] == cur -> nome_azienda[0]){
            //inserisci
            cur2 = malloc(sizeof(az_quot*));
            strcpy(cur2 -> nome_azienda, nome);
            cur2 -> quotazione = quot;
            cur2 -> variazione = 0;
            cur2 = cur -> next;
            cur2 -> next = cur -> next -> next;
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
