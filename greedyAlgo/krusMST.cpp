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
	int w,start,end,visitedFlag;
	public:
		void setValE(int, int, int);
		void setValV(bool);
		int getValW();
		int getValStart();
		int getValEnd();
		bool getValVisited();
};

class graph{
	vector<edge> E;
	int ver,edges;
	public:
		void setVal(int, int);
		void setValE(vector<edge>);	
		void constKMST();
		void sortG();
		void print();	
		bool checkCycle(vector<edge>, int);
};

void edge::setValE(int wT, int startT, int endT){
	w = wT; start = startT; end = endT; visitedFlag = false;
}
void edge::setValV(bool b){
	visitedFlag = b;
}

bool edge::getValVisited(){
	return visitedFlag;
}
int edge::getValW(){
	return w;
}
int edge::getValStart(){
	return start;
}
int edge::getValEnd(){
	return end;
}
void graph::setVal(int verT, int edgesT){
	ver = verT; edges = edgesT;
}
void graph::setValE(vector<edge> ET){
	E = ET;
}
void graph::sortG(){
	int size = E.size();
	int flag = 0; int sw1,sw2,sw3;
	int sw4,sw5,sw6;

	for (int i=size;i>0;i--){
		sw1=E[0].getValW();sw2=E[0].getValStart();sw3=E[0].getValEnd();flag=0;
		for (int j=1;j<i;j++){
			if (E[j].getValW()>sw1){
				sw1=E[j].getValW();sw2=E[j].getValStart();sw3=E[j].getValEnd();
				flag=j;			
			}
		}
		sw4 = E[i-1].getValW();sw5 = E[i-1].getValStart();sw6 = E[i-1].getValEnd();
		E[flag].setValE(sw4, sw5, sw6);
		E[i-1].setValE(sw1, sw2, sw3);
	}
	/*for (int i=0;i<size-1;i++){
		for (int j=1;j<size;j++){
			if (E[j].getValW()<E[i].getValW()){
				sw1=E[j].getValW();sw2=E[j].getValStart();sw3=E[j].getValEnd();
				sw4 = E[i].getValW();sw5 = E[i].getValStart();sw6 = E[i].getValEnd();
				E[j].setValE(sw4, sw5, sw6);
				E[i].setValE(sw1, sw2, sw3);
				//sw1=sw4;sw2=sw5;sw3=sw6;
				//flag = i;			
			}	
		}
	}*/
}
void graph::print(){	
	for (int i=0;i<E.size();i++){
		cout << E[i].getValW() << " " << E[i].getValStart() << " " << E[i].getValEnd() << endl;
	}
}
bool graph::checkCycle(vector<edge> e, int count){
	int start = e[count].getValStart();
	int end = e[count].getValEnd();
	e[count].setValV(true);
	int chkEnd = 0;
	for (int i=0;i<count-1;i++){e[i].setValV(false);}
	for (int i = 0;i<count;i++){
		if (((e[i].getValStart()==start)||(e[i].getValEnd()==start)||(e[i].getValStart()==end)||(e[i].getValEnd()==end))&&(e[i].getValVisited()==false)){
			// if we reach end, then we have a cycle
			e[i].setValV(true);
			chkEnd = e[i].getValEnd();
			if (chkEnd == end){return false;}
			if (e[i].getValStart()==start) {start = e[i].getValEnd();} else {start = e[i].getValStart();} 					
		}	
	}
	return true;
}
void graph::constKMST(){
	vector<edge> tree(E.size());
	vector<edge> temp(E.size());	
	int count=0;
	tree[0] = E[0];
	int flag = 	0;
	cout << E[0].getValW() << " " << E[0].getValStart() << " " << E[0].getValEnd() << endl;
	//E[0].setValV(true);	
	while (count < ver-1){
		temp = tree; int tCount = count;tCount++;		
		flag++; temp[tCount] = E[flag];
		if (checkCycle(temp, tCount)){
			cout << E[flag].getValW() << " " << E[flag].getValStart() << " " << E[flag].getValEnd() << endl;
			count++;
			tree[count] = E[flag];
		}
	}
	
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
		E[i].setValE(w, start, end);
	}		
	g.setValE(E);
	//g.print();
	g.sortG();
	g.print();
	cout << endl;	
	//g.setValE(E);
	g.constKMST();
	return 0;
}

