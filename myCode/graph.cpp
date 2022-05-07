#include <iostream>
#include <cstring>
#include <cmath>

#include "graph.h"

using namespace std;

// Public Field
Graph::Graph(const char* data){ // 建構式(輸入為資料)
	int dataLen = strlen(data); // 取得資料長度

	stockStatus = (char*)malloc(sizeof(char) * dataLen +1); // 給定陣列空間

	strcpy(stockStatus, data);
	xAxis = dataLen;
	SetYAxis();
}

Graph::~Graph(){
	free(stockStatus);
	delete stockStatus;
	delete &xAxis;
	delete &yAxis;
}

int Graph::getX(){ return xAxis; }
int Graph::getY(){ return yAxis; }

void Graph::DrawGraph(){
	cout << "draw" << endl;
	
	/*
	char** graph = NULL;

	int graph_x = xAxis*2 + 1;

	graph = (char*)malloc(sizeof(char) * graph_x);
	int i = 0;
	for(i = 0; i < ){
	}
	*/
}

// Private Field
void Graph::SetYAxis(){
	int times_r = 0; // 出現 R 的次數
	int times_f = 0; // 出現 F 的次數
	int i = 0;
	for(i = 0; i < xAxis; i++){
		if((char)*(stockStatus + i) == 'R'){ times_r++; }
		if((char)*(stockStatus + i) == 'F'){ times_f++; }
	}
	
	if(times_r > times_f){ yAxis = times_r; }
	else{ yAxis = times_f; }
}
