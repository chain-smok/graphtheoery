#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>

#include "graph.h"

using namespace std;

int row = 0, col = 0;

// Public Field
Graph::Graph(const char* data){ // 建構式(輸入為資料)
	int dataLen = strlen(data); // 取得資料長度

	stockStatus = (char*)malloc(sizeof(char) * dataLen + 1); // 輸入字串儲存空間初始化

	// 設定 股票狀態、全部變成大寫
	strcpy(stockStatus, data);
	int i = 0;
	for(i = 0; i < dataLen; i++){
		stockStatus[i] = toupper(stockStatus[i]);
	}

	// 設定 x, y 軸長度
	SetXAxis();
	SetYAxis();

	// 設定 graph 的 row, column
	row = yAxis + 1;
	col = xAxis + 3;

	// 畫布初始化
	painting = (char**)malloc(sizeof(char*) * row);
	for(i = 0; i < row; i++){
		painting[i] = (char*)malloc(sizeof(char) * col);
	}

	// 建立圖案
	DrawAxis();
	DrawLine();
}

Graph::~Graph(){
	free(stockStatus);
	delete stockStatus;
	delete &xAxis;
	delete &yAxis;
}

int Graph::getX(){ return xAxis; }
int Graph::getY(){ return yAxis; }

void Graph::Draw(){
	int i = 0, j = 0;

	// 繪製圖表
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			cout << painting[i][j];
		}
		cout << endl;
	}
}

void Graph::PrintStatus(){
	cout << stockStatus << endl;
}

// Private Field
void Graph::SetXAxis(){
	xAxis = strlen(stockStatus);
}

void Graph::SetYAxis(){
	int max = INT_MIN, min = INT_MAX;
	int sum = 0;

	int i = 0;
	for(i = 0; i < strlen(stockStatus); i++){
		switch(stockStatus[i]){
			case 'R':
				sum++;
				break;
			case 'F':
				sum--;
				break;
			default: break;
		}
		if(sum > max){ max = sum; }
		if(sum < min){ min = sum; }

	}

	yAxis = max - min + 1;
}

void Graph::DrawAxis(){
	int i = 0, j = 0;

	// 畫出 x ,y 軸線
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			if(i == row-1 && j == 0){
				painting[i][j] = '+';
			}else if(j == 0){
				painting[i][j] = '|';
			}else if(i == row-1){
				painting[i][j] = '-';
			}else{
				painting[i][j] = ' ';
			}
		}
	}
}

void Graph::DrawLine(){
	int startX = 2; // column
	int startY = 0; // row;
}
