#include <iostream>

#include "graph.h"

using namespace std;

int main(){
	
	Graph g = "RCRFCRFFCCRRC";
	//cout << g.getX() << endl;
	//cout << g.getY() << endl;
	g.Draw();
	g.PrintStatus();
	
	return 0;
}
