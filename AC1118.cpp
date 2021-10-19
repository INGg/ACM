// Problem: 马走日
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1118/
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

using namespace std;

typedef pair<int, int> PII;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
bool vis[15][15];

int res = 0;

void dfs(int sx, int sy, int cnt){
	
	if(cnt == n * m){
		res ++;
		return;
	} 
	
	vis[sx][sy] = 1;
	
	for(int i = 0; i < 8; i++){
		int x = sx + dx[i];
		int y = sy + dy[i];
		
		if(x < 0 || x >= n || y < 0 || y >= m) continue;
		if(vis[x][y]) continue;
		
		dfs(x, y, cnt + 1);
	}
	
	vis[sx][sy] = 0;
}

int T;

int main(){
	cin >> T;
	while(T--){
		int x, y;
		cin >> n >> m >> x >> y;
		
		res = 0;
		memset(vis, 0, sizeof(vis));
		dfs(x, y, 1);
		
		cout << res << Endl;
	}
	
	re 0;
}