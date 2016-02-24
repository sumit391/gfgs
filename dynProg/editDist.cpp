// Author : Sumit Chouhan
// ETH Zürich
// Date : 22/02/2016

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "../searchAndSort/mergeSort.h"
#include <algorithm>
using namespace std;

int minEdit(string a, string b){
	// Base Case	
	if (a.length()==0){
		return b.length();	
	}
	if (b.length()==0){
		return a.length();	
	}
	// Insert case	
	// minEdit(a.substr(0,a.length()),b.substr(0,b.length()-1))
	// Remove	
	// minEdit(a.substr(0,a.length()-1),b.substr(0,b.length()))
	// Replace	
	// minEdit(a.substr(0,a.length()-1),b.substr(0,b.length()-1))
	if (a.substr(a.length()-1,1)==b.substr(b.length()-1,1)){
		return minEdit(a.substr(0,a.length()-1),b.substr(0,b.length()-1));
	}
	else{
		return (1 + min(min(minEdit(a.substr(0,a.length()),b.substr(0,b.length()-1)),minEdit(a.substr(0,a.length()-1),b.substr(0,b.length()))),minEdit(a.substr(0,a.length()-1),b.substr(0,b.length()-1))));
	}	
}

int main(int argc, char **argv){
	string a, b;
	cin >> a; 
	cin >> b;
	cout << "Minimum Edits : " << minEdit(a, b) << endl;	
	return 0;
}

