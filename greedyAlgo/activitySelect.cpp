// Author : Sumit Chouhan
// ETH Zürich
// Date : 15/02/2016

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "../searchAndSort/mergeSort.h"

using namespace std;


int main(int argc, char **argv){
	int noOfAct;
	cin >> noOfAct;
	vector<int> start(noOfAct);
	vector<int>	end(noOfAct);
	for (int i=0;i<noOfAct;i++){
		cin >> start[i];		
	}
	for (int i=0;i<noOfAct;i++){
		cin >> end[i];		
	}	
	end = mainMerge(end);
	int flag = 0;	
	cout << end[0] << " " << flag << endl;
	for (int i=1;i<noOfAct;i++){
		if (start[i]>=end[flag]){
			cout << end[flag] << " " << i << endl;
			flag=i;
		}		
	}
	return 0;
}

