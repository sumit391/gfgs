// Author : Sumit Chouhan
// ETH Zürich
// Date : 24/02/2016

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void kMPSearch(string pat, string txt){
	for (int i = 0;i<txt.length();i++){
		if (pat[0]==txt[i]){
			if((i+pat.length()-1)>txt.length()){				
				break;
			}
			if (!pat.compare(txt.substr(i,pat.length()))){
				cout << "Pattern found at index " << i << endl;			
			}
		}	
	}
}

// naive pattern search
int main(int argc, char **argv) {
	string text, pattern; 
	cin >> text >> pattern;
	cout << text << endl;
	cout << pattern << endl;	
	kMPSearch(pattern, text);
	return 0;
}

