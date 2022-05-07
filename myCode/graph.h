#ifndef GRAPH_H
#define GRAPH_H

#include <cstddef>

// 圖表物件
class Graph{
	public:
		Graph(const char* data); // 建構式(輸入為資料)
		~Graph(); // 釋放記憶體

		int getX(); // 取得 x 軸
		int getY(); // 取得 y 軸
		void PrintStatus(); // 寫出輸入文字
		void Draw(); //畫出圖案
	private:
		int xAxis = -1; // x 軸
		int yAxis = -1; // y 軸

		char* stockStatus = NULL; // 表示股票狀態的文字
		char** painting = NULL; // 表示要畫出的圖案

		void SetXAxis(); // 設定 x 軸
		void SetYAxis(); // 設定 y 軸
		void DrawAxis(); // 畫出 x, y 軸
		void DrawLine(); // 畫線
};

#endif
