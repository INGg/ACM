// Problem: P1331 海战
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1331
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

int r, c;
char m[1010][1010];
bool vis[1010][1010];

bool pd(int x, int y){
	char a = m[x][y];
	char b = m[x][y + 1];
	char c = m[x + 1][y];
	char d = m[x + 1][y + 1];
	if(a == '.' && b == '#' && c == '#' && d == '#')
		return 0;
		
	if(a == '#' && b == '.' && c == '#' && d == '#')
		return 0;
		
	if(a == '#' && b == '#' && c == '.' && d == '#')
		return 0;
		
	if(a == '#' && b == '#' && c == '#' && d == '.')
		return 0;
	return 1;
}

bool bfs(PII start){
	queue<PII> q;

	
	q.push(start);
	vis[start.x][start.y] = 1;
	
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			if(x < 0 || x >= r || y < 0 || y >= c) continue;
			// if(pd(x, y)) return 0;
			if(vis[x][y]) continue;
			if(m[x][y] == '.') continue;
			
			vis[x][y] = 1;
			
			q.push({x, y});
		}
	}
	return 1;
}

int main(){
	memset(vis, 0, sizeof(vis));
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		scanf("%s", m[i]);
	}

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if(i < r - 1 && j < c - 1){
				if(!pd(i, j)){
					cout << "Bad placement.";
					return 0;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(m[i][j] == '#' && !vis[i][j]){
				bfs({i, j});
				ans++;
			}
		}
	}
	
	printf("There are %d ships.", ans);

	re 0;
}