// Author : Sumit Chouhan
// ETH Zürich
// Date : 16/02/2016

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "../searchAndSort/mergeSort.h"

using namespace std;

class edge{
	int w,start,end;
	public:
		void setVal(int, int, int);
}

class graph{
	vector<edge> E;
	int ver,edges;
	public:
		void setVal(int, int);
		void setValE(vector<edge>)	
		void constKMST();
}

void edge::setVal(int wT, int startT, int endT){
	w = wT; start = startT; end = endT;
}
void graph::setVal(vector<edge> ET, int verT, int edgesT){
	ver = verT; edges = edgesT;
}
void graph::setValE(vector<edge> ET){
	E = ET;
}
void graph::constKMST(){
	// sort by weight
	
}

int main(int argc, char **argv){
	int ver,edges;
	cin >> ver >> edges;
	graph g;
	g.setVal(ver, edges);
	vector<edge> E(edges);	
	int w,start,end;
	for (int i=0;i<edges;i++){
		cin >> w >> start >> end;
		E[i].setVal(w, start, end);
	}		
	g.setValE(E);
	return 0;
}

