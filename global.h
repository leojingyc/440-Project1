#ifndef HEADER_FILE
#define HEADER_FILE
#include<stdio.h>
#include <stdlib.h>
#include<time.h>


//This function will allocate for a square dynamic 2-dimensional array and initialize to 0.
int** initial(int n){
	int **temp = (int**)malloc(n*sizeof(int*));
	for(int i = 0; i < n; i++){
		temp[i] = (int*)malloc(n*sizeof(int));
		for(int j = 0; j < n; j++) temp[i][j] = 0;
	}
	return temp;	
}
/*This function will generate a maze with a given dimension n and obstacle density p. 
"1" will represent the cell in the maze is occupied and "0" will represent the cell is empty.
To make it easier to distinguish wheather it is boundary of the maze, we will add a circle of "1" to the maze.
*/
int** mazeGenerator(int n, float p){
	int **mazeMap = initial(n + 2);
	int totalNumOccupied = n * n * p, temp = 0, randomnum, allcell = n*n;
	
	//Add boundary to the maze
	for(int i = 0; i < n + 2; i++){
		mazeMap[0][i] = 1; // top row
		mazeMap[n + 1][i] = 1; // bottom row
		mazeMap[i][0] = 1; //left side
		mazeMap[i][n + 1] = 1; // right side
	}

	int *a = (int*)malloc(totalNumOccupied*sizeof(int));
	for(int i = 0; i < totalNumOccupied; i++) a[i] = 0;
	srand((int)time(NULL));

	//Randomly generate totalNumOccupied different numbers between 1 to n*n
	while(temp < totalNumOccupied){
		randomnum = rand() % allcell + 1;
		int i;
		for(i = 0; i < temp; i++) if(a[i] == randomnum) break;
		if(i == temp){
			a[temp++] = randomnum; 
			
			//transform them to coordinate and set it to "1"
			if((randomnum % n) == 0) mazeMap[randomnum / n][n] = 1;
			else mazeMap[randomnum / n + 1][randomnum % n] = 1;
		}
	}
	return mazeMap;
}

void printMaze(int** maze, int dim){
	for(int i = 0; i < dim + 2; i++){
		for(int j = 0; j < dim + 2; j++) printf("%d ", maze[i][j]);
		printf("\n");
	}
}
#endif