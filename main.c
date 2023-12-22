#include "header.h"
#include <unistd.h>

int main(void){

	int __size = 30;
	int i = 0, j = 0;

	char** matrix = allocateMatrix(__size);

	for(i = 0; i < __size; i++){
		for(j = 0 ; j < __size; j++){
			int nr = rand() % 7;
			if(nr == 1){
				matrix[i][j] = ALIVE;
			}		
			else {
				matrix[i][j] = DEAD;
			}
//			matrix[i][j] = DEAD;
		}
	}

	//readInitialState(matrix, __size);
	
	system("clear");

	while(true){
		print(matrix, __size);
		matrix = evolve(matrix, __size);
	
		usleep(50000);
		system("clear");
	}
	print(matrix, __size);
	freeMemory(matrix, __size);
	
	return 0;
}
