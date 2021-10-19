// Problem: 武士风度的牛
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/190/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Powered by CP Editor (https://cpeditor.org)

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

int dx[8] = {-1, -2, -2, -1, +1, +1, +2, +1};
int dy[8] = {-2, -1, +1, +2, +2, +2, -1, -2};

int n, m;
char mapp[150][150];
int dis[150][150];

int bfs(int sx, int sy){
	queue<PII> q;
	q.push({sx, sy});
	
	memset(dis, -1, sizeof(dis));
	
	dis[sx][sy] = 0;
	
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			if(x < 0 || x >= n || y < 0 || y >= m) continue;
			if(mapp[x][y] == '*') continue;
			if(dis[x][y] != -1) continue;
						dis[x][y] = dis[f.x][f.y] + 1;
			if(mapp[x][y] == 'H') return dis[x][y];
			q.push({x, y});
		}
	}
}

int main(){
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		scanf("%s", mapp[i]);
	}
	
	int sx, sy;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mapp[i][j] == 'K'){
				sx = i;
				sy = j;
				break;
			}
		}
	}
	
	// cout << sx << " " << sy << Endl;
	
	cout << bfs(sx, sy);
	
	return 0;
}