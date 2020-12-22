//
//  main.c
//  Esercizio 2 secondo itinere 2014
//
//  Created by Matteo Rigamonti on 31/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 2 – Funzioni in C e lettura da file (12 punti)
 Il quadrato di Polibio è una tecnica di cifratura del testo inventata dal celebre storico greco. La chiave per cifrare il testo è data da una matrice, char key[5][5], che memorizza in un ordine casuale le 25 lettere dell'alfabeto (I e J usano la stessa codifica). Per ottenere la cifratura di una parola, si sostituisce ogni lettera con le relative coordinate nella matrice, giustapposte in modo da formare un numero intero di due cifre.
 Sia per esempio data la matrice key sotto riportata, in cui per semplicità le lettere sono memorizzate in ordine alfabetico. In base a tale matrice, la cifratura della parola mare è: <32, 11, 42, 15>.
    1  2   3   4   5
 1  A   B   C   D   E
 2  F   G   H   I,J K
 3  L   M   N   O   P
 4  Q   R   S   T   U
 5  V   W   X   Y   Z
 Infatti: M = key[3,2]; A = key[1,1]; R = key [4,2], E = key[1,5].
 N.B.: Le coordinate usate nella cifratura partono da 1, mentre gli indici per scandire la matrice devono partire da 0!
 Supponendo di dover cifrare un testo contenuto in un file, definire una funzione avente il seguente prototipo:
 void polybius(FILE *fp, char key[][5], int *cifratura)
 che, a partire da:
 - il file puntato da fp, che contiene un testo lungo massimo N caratteri (spazi inclusi), con N costante nota
 a priori e definita nella parte dichiarativa del programma;
 - la matrice quadrata key di dimensione 5 x 5 che contiene la chiave di cifratura,
 costruisca l’array di interi, cifratura, in modo che questo memorizzi, secondo lo schema sopra descritto, la cifratura del testo letto dal file. Gli eventuali spazi presenti nel testo sono codificati nell’array con il valore 0. Si assuma inoltre che nel testo non siano inclusi segni di punteggiatura e caratteri diversi da quelli presenti nella matrice.
 */

#include <stdio.h>
#include <stdlib.h>
#define N 10

void polybius(FILE *fp, char key[][5], int *cifratura){
    char c;
    int i,j,k = 0;
    while (feof(fp)) {
        fscanf(fp, "%c", &c);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (c == key[i][j]) {
                    cifratura = realloc(cifratura, k + 1);
                    cifratura[k] = i * 10 + j;
                    k++;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
