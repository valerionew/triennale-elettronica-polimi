//
//  main.c
//  Esercizio 4 primo itinere 2014
//
//  Created by Matteo Rigamonti on 31/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 4 - Struct (7 punti).
 1. Si definisca in C un tipo di dati in grado di rappresentare i dati della carriera di uno studente universitario:
 - Dati anagrafici: matricola (un valore intero), nome, cognome, indirizzo.
 - Dati sugli esami: lista degli esami nella carriera dello studente (si supponga che gli esami siano 30). Per ogni esame è necessario memorizzare il codice (un intero), il nome dell’esame e la votazione conseguita (un intero). Per gli esami non sostenuti si riporta il valore -1, per quelli non superati il valore -2.
 2. Si scriva una funzione in C che riceve come parametri una struttura dati del tipo definito al punto 1 (che rappresenta i dati di un singolo studente) il codice di un esame e il voto conseguito dallo studente in questo esame. Quindi, modifica la struttura dati aggiungendo il nuovo voto conseguito dallo studente. Infine, restituisce all’ambiente chiamante la struttura dati aggiornata.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _studente{
    int matricola;
    char nome[41];
    char cognome[51];
    char indirizzo[101];
}studente;

typedef struct _esame{
    int codice;
    char nome[41];
    int voto;
    struct _esame *next;
}esame;

struct carriera{
    studente student;
    esame *lista_esami;
};

struct carriera funzione(studente stud, esame exam){
    struct carriera carriera_stud;
    
    carriera_stud.student = stud;
    carriera_stud.lista_esami = malloc(sizeof(esame*));
    carriera_stud.lista_esami -> codice = exam.codice;
    strcpy(carriera_stud.lista_esami -> nome, exam.nome);
    
    if (exam.voto < 18) {
        carriera_stud.lista_esami -> voto = -2;
    }else if(exam.voto == -1){
        carriera_stud.lista_esami -> voto = -1;
    }else{
        carriera_stud.lista_esami -> voto = exam.voto;
    }
    carriera_stud.lista_esami = carriera_stud.lista_esami -> next;
    
    return carriera_stud;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
