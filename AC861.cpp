// Problem: 染色法判定二分图
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/862/
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

const int N = 1e5 + 10, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int u, int v){
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx++;
}

bool dfs(int u, int c){
	color[u] = c;
	
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		
		if(!color[j]){
			if(!dfs(j, 3 - c)) return 0;
		}
		else if(color[j] == c) return 0;
	}
	
	return 1;
}

int main(){
	memset(h, -1, sizeof(h));
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	
	bool t = 1;
	for(int i = 1; i <= n; i++){
		if(!color[i]){
			if(!dfs(i, 1)){
				t = 0;
				break;
			}
		}
	}
	
	if(t){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
}