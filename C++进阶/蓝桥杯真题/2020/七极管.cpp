#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int board[7][7] = {
	{0, 1, 0, 0, 0, 1, 0},
	{1, 0, 1, 0, 0, 0, 1},
	{0, 1, 0, 1, 0, 0, 1},
	{0, 0, 1, 0, 1, 0, 0},
	{0, 0, 0, 1, 0, 1, 1},
	{1, 0, 0, 0, 1, 0, 1},
	{0, 1, 1, 0, 1, 1, 0}
};

int choose[7];  // ��ǰ������ 
int visited[7]; // �Ѿ������Ķ����� 

void dfs(int k){
	for (int i = 0; i < 7; i++){
		if (board[k][i] == 1 && visited[i] != 1 && choose[i] == 1){
			visited[i] = 1;
			dfs(i);
		}
	}
} 

int main()
{
	int x, j, k, ans = 127;
	for (int i = 1; i <= 127; ++i){
		memset(choose, 0, sizeof(choose));
		memset(visited, 0, sizeof(visited));
		x = i, j = 0;
		while (x){
			if (x % 2) choose[j] = 1; // ת��Ϊ������,���ֻ��һ����ȫ����1���� 
			x /= 2;
			j++;
		}
		k = 0;
		while (choose[k] == 0) k++; // ��һ��ͷ���� 
		visited[k] = 1;
		dfs(k); // ������ȱ��� 
		// ������˶�
		for (j = 0; j < 7; ++j){
			if (choose[j] != visited[j])	break;
		}
		if (j < 7)	ans--; // �ų��� 
	} 
	cout << ans << endl;
	
	return 0;
}
