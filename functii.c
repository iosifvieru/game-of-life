#include "header.h"
#include <time.h>

char* allocateArray(int __size){
	return (char*) malloc(__size * sizeof(char));
}

char** allocateMatrix(int __size){
	
	int i = 0;
	char** matrix = (char**) malloc(__size * sizeof(char*));
	
	for(i = 0; i < __size; i++){
		matrix[i] = allocateArray(__size);
	}
	
	return matrix;
}

void print(char** matrix, int __size){
	int i = 0, j = 0;
	for(i = 0; i < __size; i++){
		for(j = 0; j < __size; j++){
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}	
}

char** copyMatrix(char** matrix, int __size){
	char** tempMatrix = allocateMatrix(__size);
	int i = 0, j = 0;
	for(i = 0; i < __size; i++){
		for(j = 0; j < __size; j++){
			tempMatrix[i][j] = matrix[i][j];
		}
	}
	return tempMatrix;
}

char** evolve(char** matrix, int __size){
	// pt. parcurgere matrice
	int i = 0, j = 0;

	// nr. vecini
	int aliveCells = 0;
	char** copy = copyMatrix(matrix, __size);
	
	for(i = 1; i < __size - 1; i++){
		for(j = 1; j < __size - 1; j++){
			
//			if(matrix[i-1][j] == ALIVE){ aliveCells++; }
//			if(matrix[i+1][j] == ALIVE){ aliveCells++; }
//			if(matrix[i][j-1] == ALIVE){ aliveCells++; }
//			if(matrix[i][j+1] == ALIVE){ aliveCells++; }
//			if(matrix[i-1][j-1] == ALIVE){ aliveCells++; }	
//			if(matrix[i+1][j-1] == ALIVE){ aliveCells++; }				
//			if(matrix[i-1][j+1] == ALIVE){ aliveCells++; }	
//			if(matrix[i+1][j+1] == ALIVE){ aliveCells++; }	
			aliveCells = calculateNeighbours(matrix, i, j, __size);
	
			//if(matrix[i][j] == ALIVE){
			//	aliveCells--;
			//}		
			// rule 1:
			if(aliveCells < 2 && (matrix[i][j] == ALIVE)){
				copy[i][j] = DEAD;
			}

			// rule 2:
			if((aliveCells == 2 || aliveCells == 3) && matrix[i][j] == ALIVE){
				copy[i][j] = ALIVE;
			}

			// rule 3:
			if(aliveCells > 3 && (matrix[i][j] == ALIVE)){
				copy[i][j] = DEAD;
			}
			
			// rule 4:
			if(aliveCells == 3 && (matrix[i][j] == DEAD)) {
				 copy[i][j] = ALIVE; 
			}
		//	if(matrix[i][j] == ALIVE){
		//		copy[i][j] = (aliveCells == 2 || aliveCells == 3) ? ALIVE : DEAD;
		//	} else {
		//		copy[i][j] = (aliveCells == 3) ? ALIVE : DEAD;
		//	}
			//printf("ALIVE CELLS FOR MATRIX[%d][%d]: %d\n", i, j, aliveCells);
			aliveCells = 0;
			//matrix = copyMatrix(copy, __size);	
		//matrix = copyMatrix(copy, __size);
			matrix = copy;
			//freeMemory(copy, __size);			
		}	
	}
	matrix = copyMatrix(copy, __size);
	freeMemory(copy, __size);
	return matrix;
}


void freeMemory(char** matrix, int __size){
	int i = 0;
	for(i = 0; i < __size; i++){
		free(matrix[i]);
	}
	free(matrix);
}

void readInitialState(char** matrix, int __size){
	int x, y;

	scanf("%d", &x);

	// BUFFER FLUSH
	bufferFlush();	
	scanf("%d", &y);
	//bufferFlush();	
	
//	printf("COORDONATE: %d, %d", x, y);	
	matrix[x][y] = ALIVE;

	while(x != 0 || y != 0){
//		printf("AICI")
		
		//bufferFlush();
		matrix[x][y] = ALIVE;		

		scanf("%d", &x);
		bufferFlush();

		scanf("%d", &y);
	//	bufferFlush();
	}
}

void bufferFlush(){
	int c;
	while((c = getchar() ) != '\n' && c!= EOF);
}

int calculateNeighbours(char** matrix, int i, int j, int __size){
	int aliveCells = 0;
	int row = -1, col = -1;
	for(row = -1; row <= 1; ++row){
		for(col = -1; col <= 1; ++col){

			if(row == 0 && col == 0){
				//if(matrix[row][col] == ALIVE){
				//	aliveCells--;
				//}
				continue;
			}
			int ngbRow = i + row;
			int ngbCol = j + col;
			if(ngbRow >= 0 && ngbRow < __size && ngbCol >= 0 && ngbCol < __size){
				if(matrix[ngbRow][ngbCol] == ALIVE){
					aliveCells++;
				}	
			}
		}		
	}	
	return aliveCells;
}


int generateRandomNumber(){
	int rNR;
	srand((unsigned int)(time(NULL) + clock()));
	rNR = rand() % 100;
	return rNR;
}
