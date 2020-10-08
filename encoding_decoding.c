#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define LUNG 20			//lunghezza massima della stringa
#define ASCII 48		//costante codice ascii

int menu(){		
	int x;
	printf("1. ENCODING ...");
	printf("\n2. DECODING ...");
	scanf("%d", &x);
	return x;
}

void main(){
	char lettere[LUNG];		//inizializzazione di una stringa
	int cnt = 1;
	int temp;
	
	switch(menu()){
		case 1:
			printf("\nInserisci una sequenza di 20 lettere al massimo ... ");
			scanf("%s", lettere);
			for(int k = 0 ; k < LUNG ; k++){		//for che cicle per tutta la stringa
				if(lettere[k] == lettere[k + 1]){		//if che chiede se un carattere è uguiale al successivo
					cnt++;
				}else{
					printf("%d%c", cnt, lettere[k]);		//stampa della stringa encodificata
					cnt = 1;
				}
			}
		break;
		
		case 2:
			printf("\nInserisci una sequenza di numeri e lettere ... ");
			scanf("%s", lettere);
			for(int k = 0 ; k < LUNG ; k++){		//for che cicla per tutta la stringa
				if(lettere[k] > '0' && lettere[k] <= '9'){		//if che chiede se il carattere è un numero o no
					temp = lettere[k] - ASCII;		//trasformo il carattere nel numero corrispondente del codice ascii
					for(int j = 0 ; j < temp ; j++){		//for che cicla fino a che non ha stampato tutti i caratteri
						printf("%c", lettere[k + 1]);
					}
				}
			}
		break;
	}

    //termina programma
	printf("\nPremi INVIO per uscire.");
	getch();
}