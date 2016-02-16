// Author : Sumit Chouhan
// ETH Zürich
// Date : 15/02/2016

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


// MergeSort Routine
void mergeV(vector<int> &arr, int l, int m, int r){
	
	int n1 = m-l+1;
	int n2 = r-m;
	vector<int> tempA(n1);
	vector<int> tempB(n2);	
	for (int i=0;i<n1;i++){
		tempA[i]=arr[l+i];			
	}
	for (int i=0;i<n2;i++){
		tempB[i]=arr[m+1+i];
	}
	int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (tempA[i] <= tempB[j])
        {
            arr[k] = tempA[i];
            i++;
        }
        else
        {
            arr[k] = tempB[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = tempA[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = tempB[j];
        j++;
        k++;
    }
}

void merge(vector<int> &num, int l, int r){
	int m=0;	
	if (r>l){
		m = ceil((l+r)/2);
		merge(num, l, m);
		merge(num, m+1, r);
		mergeV(num, l, m, r);
	}
}


int main(int argc, char **argv) {
	int a;
    cin >> a;
	//cout << a;
	vector<int> num(a);	
	for (int i=0;i<a;i++){
		cin >> num[i];
		//cout << num[i];
	}    
	int l=0,r=a-1;
	//m = num.size()/2;
	merge(num, l, r);
	for (int i=0;i<a;i++){
		cout << num[i] <<" ";
	}	
	return 0;
}

