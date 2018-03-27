#include<iostream>
using namespace std;
int visit[100] = {0};//记录是否访问过
void dfs(int* number, int** edge, int begin,int n)
{
	visit[begin] = 1;
	cout << number[begin] << "*";
	for (int k = 0; k < n; k++)
	{
		if (edge[begin][k] == 1 && visit[k] == 0)
			dfs(number, edge, k,n);//递归依次调用
	}
}
int main()
{
	int n;//节点数目
	cin >> n;
	
	int *number ;//节点数组（1，2，3，4，5，6）
	number = new int[n];
	for (int i = 0; i < n; i++)
		number[i] = i + 1;
	
	int begin;//最初的给定起点
	cin >> begin;
	begin -= 1;
	
	int **edge;//边数组 二维
	edge = new int*[n];
	for (int i = 0; i < n; i++)
		edge[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> edge[i][j];
	
	for (int i = 0; i < n; i++)
	{
		if (visit[begin] == 0)
			dfs(number, edge, begin, n);
		if(visit[i]==0)
			dfs(number, edge, i, n);
	}
	system("pause");
}

