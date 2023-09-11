//
//  main.c
//  Esercizio 3 gennaio 2018
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 3 (12 punti). Si vuole definire un programma in C in grado di guidare e tracciare i movimenti di un robot in una certa area. L’area in cui il robot può muoversi è descritta da una matrice M, di dimensione NxN. In particolare, il valore memorizzato in ciascun elemento M[i][j] rappresenta la quota del quadratino di superficie alle coordinate <i, j>. A partire da una posizione iniziale M[x][y], i cui indici possono essere impostati tramite input da tastiera, si vogliono tracciare le coordinate di tutte le posizioni visitate dal robot, considerando che il robot può muoversi secondo le seguenti regole:
 - A ogni passo, può scegliere di spostarsi di un solo quadratino nelle 8 direzioni possibili e facendo attenzione a non oltrepassare i limiti dell’area.
 - Per evitare pendenze difficili da affrontare, il robot sceglie la posizione di quota minima tra quelle adiacenti (in caso di più posizioni con lo stesso valore minimo, il robot sceglie l’ultimo ispezionato).
 - Il robot non può ritornare su posizioni già visitate.
                  
 - Il robot si ferma se tutte le posizioni adiacenti hanno una quota superiore a un certo valore q; comunque, il robot si ferma dopo un numero massimo di mosse, m. I due valori q e m sono specificati tramite input da tastiera.
 Il programma deve acquisire i dati della mappa da un file e deve scrivere le coordinate del percorso del robot in un secondo file. I nomi dei file devono essere specificati dall’utente come argomenti della linea di comando.
 Il file della mappa è organizzato nel seguente modo (e si può assumere che non contenga errori):
 - La prima riga memorizza le dimensioni della matrice.
 - Ogni riga del file memorizza una riga della matrice.
 - I valori in ogni riga, inclusa la prima, sono separati da un singolo spazio.
 Il programma deve essere definito in modo modulare e deve essere completo di ogni sua parte, inclusa la parte dichiarativa globale.
 */

#include <stdio.h>
#define N 5
#define M 10

struct pos{
    int x;
    int y;
    int quota;
};

struct pos ispeziona(int start_x, int start_y, int dim, int mat[dim][dim]){
    
    struct pos result, min;
    
    result.quota = 0;
    result.x = -1;
    result.y = -1;
    
    min = result;
    
    if (start_x == 0) {
        if (start_y == 0) {
            min.quota = mat[0][0];
            min.x = 0;
            min.y = 0;
            if (mat[1][0] < min.quota) {
                min.quota = mat[1][0];
                min.x = 1;
                min.y = 0;
            }else if(mat[1][1] < min.quota){
                min.quota = mat[1][1];
                min.x = 1;
                min.y = 1;
            }else if(mat[0][1] < min.quota){
                min.quota = mat[0][1];
                min.x = 0;
                min.y = 1;
            }
            if (min.x == 0 && min.y == 0) {
                return result;
            }
            return min;
        }else if(start_y == dim){
            min.quota = mat[0][dim];
            min.x = 0;
            min.y = dim;
            if (mat[0][dim] < min.quota) {
                min.quota = mat[0][dim];
                min.x = 0;
                min.y = dim;
            }else if(mat[1][dim - 1] < min.quota){
                min.quota = mat[1][dim - 1];
                min.x = 1;
                min.y = dim - 1;
            }else if(mat[1][dim] < min.quota){
                min.quota = mat[0][dim];
                min.x = 1;
                min.y = dim;
            }
            if (min.x == 0 && min.y == dim) {
                return result;
            }
            return min;
        }else /*qui studio i casi in cui y != 0 e y != dim*/{
            
        }
    }else if(start_x == dim){
        if (start_y == 0) {
            min.quota = mat[dim][0];
            min.x = dim;
            min.y = 0;
            if (mat[dim][1] < min.quota) {
                min.quota = mat[dim][1];
                min.x = dim;
                min.y = 1;
            }else if(mat[dim - 1][1] < min.quota){
                min.quota = mat[dim - 1][1];
                min.x = dim - 1;
                min.y = 1;
            }else if(mat[dim - 1][0] < min.quota){
                min.quota = mat[0][1];
                min.x = dim - 1;
                min.y = 0;
            }
            if (min.x == dim && min.y == 0) {
                return result;
            }
            return min;
        }else if(start_y == dim){
            min.quota = mat[dim][dim];
            min.x = dim;
            min.y = dim;
            if (mat[dim][dim - 1] < min.quota) {
                min.quota = mat[dim][dim - 1];
                min.x = dim;
                min.y = dim - 1;
            }else if(mat[dim - 1][dim - 1] < min.quota){
                min.quota = mat[dim - 1][dim - 1];
                min.x = dim - 1;
                min.y = dim - 1;
            }else if(mat[dim - 1][dim] < min.quota){
                min.quota = mat[dim - 1][dim];
                min.x = dim - 1;
                min.y = dim;
            }
            if (min.x == dim && min.y == dim) {
                return result;
            }
            return min;
        }else/*qui studio i casi in cui y != 0 e y != dim*/{
            
        }
    }else{ /*qui studio i casi in cui ci si trova in centro*/
        min.quota = mat[start_x][start_y];
        min.x = start_x;
        min.y = start_y;
        
        if (mat[start_x - 1][start_y - 1] < min.quota) {
            min.quota = mat[start_x - 1][start_y - 1];
            min.x = start_x - 1;
            min.y = start_y - 1;
        }else if(mat[start_x - 1][start_y] < min.quota){
            min.quota = mat[start_x - 1][start_y];
            min.x = start_x - 1;
            min.y = start_y;
        }else if(mat[start_x - 1][start_y + 1] < min.quota){
            min.quota = mat[start_x - 1][start_y + 1];
            min.x = start_x - 1;
            min.y = start_y + 1;
        }else if(mat[start_x][start_y - 1] < min.quota){
            min.quota = mat[start_x][start_y - 1];
            min.x = start_x;
            min.y = start_y - 1;
        }else if(mat[start_x][start_y + 1] < min.quota){
            min.quota = mat[start_x][start_y + 1];
            min.x = start_x;
            min.y = start_y + 1;
        }else if(mat[start_x + 1][start_y - 1] < min.quota){
            min.quota = mat[start_x + 1][start_y - 1];
            min.x = start_x + 1;
            min.y = start_y - 1;
        }else if(mat[start_x + 1][start_y] < min.quota){
            min.quota = mat[start_x + 1][start_y];
            min.x = start_x + 1;
            min.y = start_y;
        }else if(mat[start_x + 1][start_y + 1] < min.quota){
            min.quota = mat[start_x + 1][start_y + 1];
            min.x = start_x + 1;
            min.y = start_y + 1;
        }
        
        if (min.quota == mat[start_x][start_y]) {
            return result;
        }
    }
    return min;
}

int main(int argc, const char * argv[]) {
    
    int dim, i,j, start_x, start_y;
    FILE *fp1, *fp2;
    struct pos posizione;
    
    posizione.x = 0;
    posizione.y = 0;
    
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    
    fscanf(fp1, "%d", &dim);
    int mat[dim][dim];
    
    for (i = 0; i < dim || !feof(fp1); i++) {
        for (j = 0; j < dim; j++) {
            fscanf(fp1, "%d", &mat[i][j]);
        }
    }
    
    printf("inserire i valori di inizio di x e y");
    scanf("%d\n%d", &start_x, &start_y);
    
    i = 0;
    while (posizione.x >= 0 || posizione.y >= 0 || i > M) {
        posizione = ispeziona(start_x, start_y, dim, mat);
        start_x = posizione.x;
        start_y = posizione.y;
        i++;
    }
    
    return 0;
}
