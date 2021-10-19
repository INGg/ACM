// Problem: P1141 01迷宫
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1141
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

using namespace std;

typedef pair<int, int> PII;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
char mapp[1010][1010];
int vis[1010][1010];
int ans[100010];

void dfs(int x, int y, int num, int i){ // 遍历x, y，当前的数字是num，我们是从i次能遍历到的
	 if(x < 0 || x >= n || y < 0 || y >= n || vis[x][y] != -1 || mapp[x][y] - '0' != num) return;
	 
	 vis[x][y] = i;
	 ans[i]++;
	 
	 for(int j = 0; j < 4; j++){
	 	dfs(x + dx[j], y + dy[j], !num, i);
	 }
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		scanf("%s", mapp[i]);
	}
	memset(vis, -1, sizeof(vis));
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		if(vis[x][y] != -1){
			ans[i] = ans[vis[x][y]];
		}
		else{
			dfs(x, y, mapp[x][y] - '0', i);
		}
	}
	
	for(int i = 1; i <= m; i++){
		cout << ans[i] << endl;
	}
	
	re 0;
}