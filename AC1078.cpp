// Problem: 迷宫问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1078/
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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int mapp[1010][1010];
PII dis[1010][1010];

void bfs(){
	queue<PII> q;
	q.push({n - 1, n - 1});
	dis[n - 1][n - 1] = {0, 0};
	memset(dis, -1, sizeof(dis));
	
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			if(x < 0 || x >= n || y < 0 || y >= n) continue;
			if(mapp[x][y]) continue;
			if(dis[x][y].x != -1) continue;
			
			dis[x][y] = f;
			q.push({x, y});
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", mapp[i] + j);
		}
	}
	
	bfs();
	
	PII end = {0, 0};
	
	while(1){
		cout << end.x << " " << end.y << endl;
		if(end.x == n - 1 && end.y == n - 1) break;
		end = dis[end.x][end.y];
	}
	
	return 0;
}