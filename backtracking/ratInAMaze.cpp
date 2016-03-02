// Author : Sumit Chouhan
// ETH Zürich
// Date : 02/03/2016

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;



int mazeRec(vector <vector<int> > maze, int a, int b, vector <vector<int> > &path, int num){
	if ((a == (num-1))&&(b == (num-1))){
		path[a][b] = 1;
		return 1;
	}
	// checking if maze is safe
	if ((a<=(num-1))&&(b<=(num-1))&&(maze[a][b]==1)){		
		path[a][b] = 1;
		if (mazeRec(maze,a+1,b,path,num)){
			return 1;
		}
		if (mazeRec(maze,a,b+1,path,num)){
			return 1;
		}
		path[a][b] = 0;
		return 0;
	}
	return 0;
}

void mazeSolver( vector <vector<int> > maze, int num){
	vector < vector<int> > path(num, vector<int>(num));
	for (int i = 0;i<num;i++){
		for (int j =0;j<num;j++){
			path[i][j] = 0;
		}
	}
	//path[0][0] = 1;
	int res = mazeRec(maze, 0, 0, path, num);
	if (res){
		for (int i = 0;i<num;i++){
			for (int j =0;j<num;j++){
				cout << path[i][j] << " ";
			}cout << endl;
		}
	}
}


int main(int argc, char **argv) {
	int num;
	cin >> num;
	vector <vector<int> > maze(num, vector<int>(num));
	for (int i = 0;i<num;i++){
		for (int j =0;j<num;j++){
			//cout << i << j << endl;
			cin >> maze[i][j];
		}
	}
	mazeSolver(maze, num);
	return 0;
}

