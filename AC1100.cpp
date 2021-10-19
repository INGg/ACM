// Problem: 城堡问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1100/
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

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int n, m;
int mapp[55][55];
bool vis[55][55];

int bfs(int xx, int yy){
	queue<PII> q;
	q.push({xx, yy});
	vis[xx][yy] = 1;
	
	int res = 0;
	
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		res++;
		
		for(int i = 0; i < 4; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			int k = mapp[f.x][f.y] >> i & 1;
			if(x < 1 || x > n || y < 1 || y > m) continue;
			if(k) continue;
			if(vis[x][y]) continue;
			
			q.push({x, y});
			vis[x][y] = 1;
		}
	}
	return res;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mapp[i][j];
		}
	}
	
	int maxs = 0;
	int cnt = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!vis[i][j]){
				cnt++;
				maxs = max(maxs, bfs(i, j));
			}
		}
	}
	
	cout << cnt << endl << maxs;
	re 0;
}