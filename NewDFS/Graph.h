#pragma once
#include<iostream>
#include<stack>
using namespace std;
class Graph
{
	struct node {
		int x;
		int y;
	};
	stack <node> AdjList; // danh sach ke
	int mxn[101][101];
	bool check[101][101];
	int dx[4] = { -1,0,0,1 };
	int dy[4] = { 0,-1,1,0 };
	int SizeMxn;
public:
	
	void input();
	bool checkValid(node& n1);
	void DFSStack(int mxn[101][101], bool check[101][101], node& first);
	void Solution();

};

