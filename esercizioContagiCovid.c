#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 20
#define DIM 50


typedef struct regione{ 
    char data[LUNG];
    char stato[LUNG];
    int codice_regione;
    char denominazione_regione[LUNG];
    float lat;
    float longit;
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi;
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
}Regione;

int leggiFile (Regione *regioni, char nomeFile[]) {
    char *x = (char*)malloc(sizeof(char)*200);
    int k = 0 ;
    FILE *file ;
    file = fopen (nomeFile, "r") ;

    while(fgets(x, 200, file)) {      
        strcpy((regioni+k)->data ,strtok(temp,","));
        strcpy((regioni+k)->stato ,strtok(NULL,","));
        (regioni+k)->codice_regione=atoi(strtok(NULL,","));
        strcpy((regioni+k)->denominazione_regione,strtok(NULL,","));
        (regioni+k)->lat=atof(strtok(NULL,","));
        (regioni+k)->longit=atof(strtok(NULL,","));
        (regioni+k)->ricoverati_con_sintomi=atoi(strtok(NULL,","));
        (regioni+k)->terapia_intensiva=atoi(strtok(NULL,","));
        (regioni+k)->totale_ospedalizzati=atoi(strtok(NULL,","));
        (regioni+k)->isolamento_domiciliare=atoi(strtok(NULL,","));
        (regioni+k)->totale_casi=atoi(strtok(NULL,","));
        (regioni+k)->variazione_totale_positivi=atoi(strtok(NULL,","));
        (regioni+k)->nuovi_positivi=atoi(strtok(NULL,","));
        (regioni+k)->dimessi_guariti=atoi(strtok(NULL,","));
        (regioni+k)->deceduti=atoi(strtok(NULL,","));
        (regioni+k)->casi_da_sospetto_diagnostico=atoi(strtok(NULL,","));
        (regioni+k)->casi_da_screening=atoi(strtok(NULL,","));
        (regioni+k)->totale_casi=atoi(strtok(NULL,","));
        (regioni+k)->tamponi=atoi(strtok(NULL,","));
        (regioni+k)->casi_testati=atoi(strtok(NULL,","));
        k++;
    }
    return k ;

    free(regioni) ;
}

void ordinaRicoveratiTerapiaIntensiva (Regione *reg, int dim) {            
    for (int s = dim - 1; s > 0; s--) { 
        for (Regione *t = regioni; t - regioni < s; t++) {
            if (t->terapia_intensiva < (t + 1)->terapia_intensiva) {
                Regione cont ;
                cont = *t ;
                *t = *(t + 1) ;
                *(t + 1) = cont ;
            }
        }
    }
    free(regioni) ;
}

int numeroRicoverati (Regione *regioni, int dim) {
    int somma = 0 ;
    
    for (int s = 0; s < dim; s++) {
        somma = somma + (regioni + k) -> terapia_intensiva;
    }
    
    free(regioni) ;
    return somma ;
}

void ordinaCasiTotali (Regione *regioni, int dim) {
    for (int s = dim - 1; s > 0; s--) {
        for (Regione *t = regioni; t - regioni < s; t++) {
            if (t -> totale_casi > (i + 1) -> totale_casi) {                
                Regione cont ;
                cont = *t;
                *t = *(t + 1) ;
                *(t + 1) = cont ;
            }
        }
    }
    free(regioni) ;
}




int main() {
    Regione *regione = (Regione*) malloc(sizeof(Regione)*50);
    
    char nomeFile[DIM] = "contagi.csv" ;
    int dim = leggiFile (regione, nomeFile) ;

    ordinaRicoveratiTerapiaIntensiva(regione, dim) ;
    printf ("TOTALE PERSONE RICOVERATE: %d\n", calcoloRicoverati(regione, dim));
    ordinaCasiTotali(regione, dim) ;

    free(regione) ;
}