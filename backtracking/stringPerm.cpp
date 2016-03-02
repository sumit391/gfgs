// Author : Sumit Chouhan
// ETH Zürich
// Date : 15/02/2016

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void stringPerm(string temp, string c){
	int n = c.size();
	if (n == 0){
		cout << temp << endl;
	}
	else{
		for (int i = 0; i < n; i++){
			stringPerm(temp + c[i], c.substr(0, i) + c.substr(i+1, n));
		}
	}
}
// string permutations
int main(int argc, char **argv) {
	string c;
	cin >> c;
	stringPerm("", c);	
	return 0;
}

