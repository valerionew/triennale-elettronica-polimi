//
//  main.c
//  Esercizio 2 febbraio 2015
//
//  Created by Matteo Rigamonti on 31/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 2 – File e liste dinamiche (14 punti)
 Una compagnia di assicurazioni memorizza i dati sulle polizze RC-auto e sugli incidenti dei propri clienti in due file distinti.
 Il file con le informazioni sulle polizze memorizza:
 - nome del cliente
 - la targa del veicolo (stringa di 7 caratteri)
 - la classe di merito: un intero tra 0 e 10
 Il file con le informazioni sugli incidenti memorizza:
 - la targa del veicolo coinvolto nell’incidente
 - la data dell’incidente (in un formato a scelta)
 - un carattere (“S” o “N”) che indica se il veicolo è stato responsabile dell’incidente (“S”) o lo ha subito (“N”).
 La compagnia di assicurazione periodicamente aggiorna le classi di merito dei clienti in base alle informazioni pervenute sugli incidenti: se il veicolo è stato responsabile di un incidente, la classe di merito viene incrementata di 1 fino a un massimo di 10.
 1. (7 punti) Si scriva una funzione in C che riceve come parametro il nome di un file che memorizza le informazioni sugli incidenti e, in base ai dati letti dal file, costruisce e restituisce all’ambiente chiamante una lista dinamica che per ogni veicolo (rappresentato dalla sola targa) memorizza il numero degli incidenti in cui il veicolo è stato responsabile.
 2. (7 punti) Si scriva una funzione in C che riceve come parametri la lista creata al punto precedente e un file che memorizza le informazioni sulle polizze e crea un nuovo file in cui si riversano le informazioni sulle varie polizze con la classe di merito aggiornata.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _polizze{
    char nome[51];
    char targa[7];
    int classe;
    struct _polizze *next;
}polizze;

typedef struct _incidente{
    char targa[7];
    char data[12];
    char resp;
}incidente;

typedef struct _nodo{
    char targa[7];
    int num;
    struct _nodo *next;
}nodo;

nodo *funzione(char *filename){
    FILE *fp;
    fp = fopen(filename, "r");
    
    nodo *lista = NULL, *cur;
    
    char targa_letta[7], data_letta[12], resp_letta;
    
    while (feof(fp)) {
        fscanf(fp, "%s", targa_letta);
        fscanf(fp, "%s", data_letta);
        fscanf(fp, "%c", &resp_letta);
        
        if (lista == NULL) {
            lista = malloc(sizeof(nodo*));
            strcpy(lista -> targa, targa_letta);
            
            if (resp_letta == 'S') {
                lista -> num++;
            }
            cur = lista -> next;
        }else{
            cur = malloc(sizeof(nodo*));
            strcpy(cur -> targa, targa_letta);
            if (resp_letta == 'S') {
                cur -> num++;
            }
        }
    }
    return lista;
}

void write_f(FILE *fp, FILE *fpw, nodo *lista){
    nodo *cur;
    polizze *listap = NULL, *curp;
    //fpw = fopen(argv[1], "w"); nel main
    while (feof(fp)) {
        if (listap == NULL) {
            listap = malloc(sizeof(polizze*));
            fscanf(fp, "%s", listap -> nome);
            fscanf(fp, "%s", listap -> targa);
            fscanf(fp, "%d", &listap -> classe);
            curp = listap -> next;
        }else{
            curp = malloc(sizeof(polizze*));
            fscanf(fp, "%s", curp -> nome);
            fscanf(fp, "%s", curp -> targa);
            fscanf(fp, "%d", &curp -> classe);
            curp = curp -> next;
        }
    }
    
    for (cur = lista; cur != NULL; cur = cur -> next) {
        for (curp = listap; curp != NULL; curp = curp -> next) {
            if (strcmp(curp -> targa, cur -> targa)) {
                if (cur -> num > 0) {
                    curp -> classe--;
                }
            }
        }
    }
    
    for (curp = listap; curp != NULL; curp = curp -> next) {
        fprintf(fpw, "%s ", curp -> nome);
        fprintf(fpw, "%s ", curp -> targa);
        fprintf(fpw, "%d ", curp -> classe);
        fprintf(fpw, "\n");
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
