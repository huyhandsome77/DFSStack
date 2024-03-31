#include "Graph.h"
#include<iostream>
using namespace std;
void Graph::input()
{
	memset(mxn, 0, sizeof(mxn));
	cout << "Nhap size ma tran n = ";
	cin >> SizeMxn;
	cout << "Nhap ma tran : " << endl;
	for (int i = 0; i < SizeMxn; i++)
	{
		for (int j = 0; j < SizeMxn; j++)
		{
			cin >> mxn[i][j];
		}
	}
}

bool Graph::checkValid(node& n1)
{ 
	if (n1.x >= 0 && n1.x < SizeMxn && n1.y >= 0 && n1.y < SizeMxn) { return true; };
	return false;
}

void Graph::DFSStack(int mxn[101][101], bool check[101][101], node& first)
{
	AdjList.push(first);
	check[first.x][first.y] = true;

	while (!AdjList.empty()) {
		node current = AdjList.top();
		AdjList.pop();
		for (int k = 0; k < 4; k++)
		{
			node next;
			next.x = current.x + dx[k];
			next.y = current.y + dy[k];
			if (checkValid(next))
			{
				if (mxn[next.x][next.y] == 1 && !check[next.x][next.y])
				{
					AdjList.push(next);
					check[next.x][next.y] = true;
				}
			}
		}
	}
}

void Graph::Solution()
{
	node n1, n2;
	cout << "Moi ban nhap toa do x1, y1 : ";
	cin >> n1.x >> n1.y;
	cout << "Moi ban nhap toa do x2, y2 : ";
	cin >> n2.x >> n2.y;
	DFSStack(mxn, check, n1);
	if (!checkValid(n1) || !checkValid(n2)) {
		cout << "Fail .Vui long nhap 2 diem hop le !";
		return;
	}
	if (check[n2.x][n2.y])
	{
		cout << "Co duong di tu (x1,y1) -> (x2,y2) ";
	}
	else
	{
		cout << "Khong co duong di !";
	}
}
