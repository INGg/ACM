// Problem: 迷宫
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1114/
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

int T;
int n;
char mapp[110][110];
bool vis[110][110];

void dfs(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= n || mapp[x][y] == '#' || vis[x][y]) return;
	vis[x][y] = 1;
	
	for(int i = 0; i < 4; i++){
		dfs(x + dx[i], y + dy[i]);
	}
}

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0; i < n; i++){
			scanf("%s", mapp[i]);
		}
		int ha, la, hb, lb;
		cin >> ha >> la >> hb >> lb;
		memset(vis, 0, sizeof(vis));
		dfs(ha, la);
		if(vis[hb][lb]){
			cout << "YES" << Endl;
		}
		else cout << "NO" << endl;
	}
	re 0;
}