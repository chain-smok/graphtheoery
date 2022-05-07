#include <iostream>
#include "graph.cpp"
#include "graph.h"

using namespace std;

int main(){
	int T,i;
  char s[100];
	//Graph g = "RCRFCRFFCCRRC";
	//cout << g.getX() << endl;
	//cout << g.getY() << endl;
  while(cin>>T){
  for(i=1;i<=T;i++){
  cin>>s;
  //Graph g=new Graph(s);
  Graph g(s);
	g.Draw();
	//g.PrintStatus();
  }
}
	return 0;
}
