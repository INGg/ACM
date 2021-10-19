// Problem: P1596 [USACO10OCT]Lake Counting S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1596
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
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

int dx[8] = {-1,0,1,0,1,-1,1,-1};
int dy[8] = {0,1,0,-1,1,1,-1,-1};

int n, m;
char map[110][110];
bool vis[110][110];

void bfs(int xx, int yy){
	queue<PII> q;
	q.push({xx, yy});
	vis[xx][yy] = 1;
	
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			if(x < 0 || x >= n || y < 0 || y >= m) continue;
			if(map[x][y] == '.') continue;
			if(vis[x][y]) continue;
			
			q.push({x, y});
			vis[x][y] = 1;
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		scanf("%s", map[i]);
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == 'W' && !vis[i][j]){
				ans ++;
				bfs(i, j);
			}
		}
	}
	cout << ans;
}