#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 3

// Questa funzione inizializza la tabella di gioco riempiendo tutte le celle con un valore che indica che sono vuote.
void CompletaLaTabella(char seq[][3]){
	for(int i=0; i<ROW; i++){
		
		for(int j=0; j<COL; j++){
			
			seq[i][j]= ' ';
		}
	}
}

// Questa funzione stampa la tabella di gioco a schermo, mostrando il contenuto attuale di ogni cella. 
void LaTabella(char seq[3][3]){
    for(int i=0; i<3; i++){
        printf("   %c   |   %c   |   %c   \n", seq[i][0], seq[i][1], seq[i][2]);

        if(i < 2){
            printf("-------+------+-------\n");
        }
    }
}
void StampaGuida(char seq[][3]){
	printf("Guida posizioni (riga colonna):\n");
	printf("\n");
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("(%d , %d )| ", i , j );
		}
		printf("\n");
		if(i<2){
			printf("-------+------+-------\n");
		}
	}
	printf("\n");
	printf("Inserisci: riga colonna\n");
}


// Questa funzione gestisce una mossa del giocatore, verificando la validit? della posizione e inserendo il simbolo nella tabella.
void LaMossa(char seq[][3] , int simbolo){
	int Row,Col;
		while (1){
		scanf("%d %d" , &Row , &Col);
		
		if(Row>3 || Row<0 || Col>3 || Col<0){
			printf("Devi scegliere un numero tra 0 e 2\n");
			continue;
		}
		
		if(seq[Row][Col] != ' '){
			printf("Casella occupata, scegli un altro spazio\n");
			continue;
		}
		
		break;
	}
	
	seq[Row][Col]=simbolo;
	
}

char ControllaVittoria(char seq[3][3]){
	if(seq[0][0]==seq[0][1] && seq[0][1]==seq[0][2] && seq[0][0]!= ' '){
		return seq[0][0];
	}
	if(seq[1][0]==seq[1][2] && seq[1][1]==seq[1][2] && seq[1][0]!=' '){
		return seq[1][1];
	}
	if(seq[2][0]==seq[2][1] && seq[2][1]==seq[2][2] && seq[2][0]!= ' '){
		return seq[2][1];
	}
	if(seq[0][0]==seq[1][0] && seq[1][0]==seq[2][0] && seq[0][0]!= ' '){
		return seq[0][0];
	}
	if(seq[0][1]==seq[1][1] && seq[1][1]==seq[2][1] && seq[0][1]!= ' '){
		return seq[0][1];
	}
	if(seq[0][2]==seq[1][2] && seq[1][2]==seq[2][2] && seq[0][2]!= ' '){
		return seq[0][2];
	}
	if(seq[0][0]==seq[1][1] && seq[1][1]==seq[2][2] && seq[0][0]!= ' '){
		return seq[0][0];
	}
	if(seq[0][2]==seq[1][1] && seq[1][1]==seq[2][0] && seq[0][2]!= ' '){
		return seq[0][2];
	}
	return ' ';
	
}
int ControllaPareggio(char seq[][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(seq[i][j]==' '){
				return 1;
			}
		}
	}
	return 0;
}



// Gioco Tris 
int main (void){
	
	char tabella[ROW][COL];
	char turno= 'X';
	char Vincitore;
	
	CompletaLaTabella(tabella); 
	LaTabella(tabella);
	StampaGuida(tabella);
	while(1){
		LaMossa(tabella , turno);
		LaTabella(tabella);
		Vincitore = ControllaVittoria(tabella);
		if(Vincitore!=' '){
			printf("Ha vinto il gioc %c\n" , Vincitore);
			break;
		}
		if(ControllaPareggio(tabella) == 0){
			printf("Pareggio\n");
			break;
		}
		if(turno == 'X'){
			turno = 'O';
		}
		else{
			turno = 'X';
		}
	}
	printf("\n");
	system("PAUSE");
	return 0;
}
