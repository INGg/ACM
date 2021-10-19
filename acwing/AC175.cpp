// Problem: 矩阵距离
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/175/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-12 18:07:57

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define ll long long
#define re return
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
char mapp[1010][1010];
int dis[1010][1010];

void bfs(){
	queue<PII> q;
	memset(dis, -1, sizeof(dis));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mapp[i][j] == '1') dis[i][j] = 0, q.push({i, j});
		}
	}
	
	while(!q.empty()){
		PII f = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			if(x > n || x < 1 || y > m || y < 1) continue;
			if(dis[x][y] != -1) continue;
			
			dis[x][y] = dis[f.x][f.y] + 1;
			q.push({x, y});
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%s", mapp[i] + 1);
	}
	
	bfs();
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
}