// Problem: 大胖子走迷宫
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/2550/
// Memory Limit: 256 MB
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

int n, k;
char m[310][310];
bool vis[310][310];
PII start;
PII end;

struct nope{
	int x, y, t;
};

bool check(nope s){
	int x = s.x;
	int y = s.y;
	int t = s.t;
	
	int r; // 半径
	if(t < k){
		r = 2;
	}
	else if(t < 2 * k){
		r = 1;
	}
	else r = 0;
	
	for(int i = x - r; i <= x + r; i++){
		for(int j = y - r; j <= y + r; j++){
			if(i < 1 || i > n || j < 1 || j > n || m[i][j] == '*') return 0;
		}
	}
	
	return 1;
}

int bfs(){
	memset(vis, 0, sizeof(vis));
	queue<nope> q;
	q.push({3, 3, 0});
	
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			int t = f.t + 1;
			
			if(x < 1 || x > n || x < 1 || y > n) continue;
			
			if(vis[x][y]) continue;
			
			if(!check(f)) continue;
			
			if(x == n - 2 && y == n - 2) return t;
			
			vis[x][y] = 1;
			q.push({x, y, t});
		}
		
	}
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		scanf("%s", m[i] + 1);
	}
	
	cout << bfs();
	
	return 0;
	
}