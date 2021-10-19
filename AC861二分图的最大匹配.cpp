// Problem: 二分图的最大匹配
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/863/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;
const int M = 1e5 + 10;

int n1, n2;
int m;
int match[N];
bool vis[N];

int h[N], e[M], ne[M], idx;

void add(int u, int v){
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx++;
}

bool dfs(int x){
	for(int i = h[x]; i != -1; i = ne[i]){
		int j = e[i];
		if(!vis[j]){ // 之前没有考虑过
			vis[j] = 1;
			if(!match[j] || dfs(match[j])){ // 可以为j匹配好的匹配另一个
				match[j] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	memset(h, -1, sizeof(h));
	
	cin >> n1 >> n2 >> m;
	
	while(m--){
		int x, y;
		cin >> x >> y;
		add(x, y);
	}
	
	int ans = 0;
	for(int i = 1; i <= n1; i++){
		memset(vis, 0, sizeof(vis));
		if(dfs(i)) ans ++;
	}
	
	cout << ans;
	
	return 0;
}