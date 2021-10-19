// Problem: 红与黑
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1115/
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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
char mapp[25][25];
bool vis[25][25];

int dfs(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= m || mapp[x][y] == '#' || vis[x][y]) return 0;
	
	int res = 1;
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		res += dfs(x + dx[i], y + dy[i]);
	}
	return res;
}

int main(){
	while(cin >> m >> n, m || n){
		
		for(int i = 0; i < n; i++){
			scanf("%s", mapp[i]);
		}
		
		memset(vis, 0, sizeof(vis));
		
		int x, y;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mapp[i][j] == '@'){
					x = i;
					y = j;
					break;
				}
			}
		}
		
		cout << dfs(x, y) << endl;
	}
}