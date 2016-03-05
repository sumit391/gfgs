// Author : Sumit Chouhan
// ETH Zürich
// Date : 02/03/2016

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


vector<int> findEmptyCell(vector < vector<int> > grid){
	vector<int> result(2);
	result[0] = 0;
	result[1] = 0;	
	for (int i=0;i<9;i++){
		for (int j=0;j<9;j++){
			if (grid[i][j]==0){
				result[0]=i;result[1]=j;
				return result;
			}
		}
	}
	return result;
}

bool checkGrid(vector < vector<int> > grid, vector<int> cell, int num){
	// check the sudoku conditions
	// check row
	int rowChk = 0;
	int colChk = 0;
	int boxChk = 0;
	for(int i=0;i<9;i++){
		if(grid[cell[0]][i]==num){
			rowChk = 1;
		}
	}
	// check column
	for(int i=0;i<9;i++){
		if(grid[i][cell[1]]==num){
			colChk = 1;
		}
	}
	// check box
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[i+cell[0] - cell[0]%3][j+cell[0] - cell[0]%3]==num){
				boxChk = 1;
			}
		}	
	}
	if ((rowChk==1)||(colChk==1)||(boxChk==1)){
		return false;
	}
	return true;
}


bool sudokuSolver(vector < vector<int> > &grid){
	// finding an empty cell, if you cannot find an empty cell
	// then sudoku is solved
	
	vector<int> cell(2);
	cell = findEmptyCell(grid);
	if (cell[0]==0){
		return true;
	} 
	for (int i=1;i<10;i++){
		// check if the cell is free to enter i with respect to the conditions
		if(checkGrid(grid, cell, i)){
			// assign num to the cell
			grid[cell[0]][cell[1]] = i;
			if(sudokuSolver(grid)){
				return true;
			}
			grid[cell[0]][cell[1]] = 0;
		}
	}
	return false;
}



int main(int argc, char **argv) {
	vector < vector<int> > grid (9, vector<int>(9));
	for (int i=0;i<9;i++){
		for (int j=0;j<9;j++){
			cin >> grid[i][j];
		}
	}	
	if(sudokuSolver(grid)){
		cout << "Solved!" << endl;
		for (int i=0;i<9;i++){
			for (int j=0;j<9;j++){
				cout<< grid[i][j] << " ";
			}cout << endl;
		}
	}
	return 0;
}

