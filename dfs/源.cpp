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
			dfs(number, edge, k,n);//??????
	}
}
int main()
{
	int n;
	cin >> n;
	int *number ;//节点数组（1，2，3，4，5，6）
	number = new int[n];
	for (int i = 0; i < n; i++)
		number[i] = i + 1;
	int begin;
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
		//cout << "次数" <<endl<< i << endl;
		if(visit[i]==0)
			dfs(number, edge, i, n);
	}
	//cout << "number" << endl;
	//for(int i=0;i<n;i++)
	//cout << number[i];
	system("pause");
}

