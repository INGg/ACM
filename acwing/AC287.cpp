// Problem: 没有上司的舞会
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/287/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-28 12:36:05

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

const int N = 6010;

int n;
int happy[N];
int h[N], e[N], ne[N], idx;
int f[N][2];
bool vis[N];

void add(int a, int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(int u){
	f[u][1] = happy[u];
	
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		
		dfs(j);
		
		f[u][1] += f[j][0];
		f[u][0] += max(f[j][1], f[j][0]);
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> happy[i];
	}
	
	memset(h, -1, sizeof(h));
	
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		add(b, a);
		vis[a] = 1;
	}
	
	int start = 1;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			start = i;
			break;
		}
	}
	
	dfs(start);
	
	cout << max(f[start][0], f[start][1]);
	
	return 0;
}