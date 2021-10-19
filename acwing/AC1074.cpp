// Problem: 树的最长路径
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1074/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-12 14:42:50

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

const int N = 10000 + 10;
const int M = N * 2;

int n;
int e[M], ne[M], w[M], h[M], idx;

void add(int a, int b, int c){
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a]= idx++;
}

int ans;

int dfs(int u, int fa){
	
	int d1 = 0;
	int d2 = 0;
	
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		
		if(j == fa) continue;
		
		int d = dfs(j, u) + w[i];
		
		// dis = max(dis, d);
		
		if(d >= d1) d2 = d1, d1 = d;
		else if(d >= d2) d2 = d;
	
	}
	
	ans = max(ans, d1 + d2);
	
	return d1; // 相当于返回当一路走到底，不以u为挂点的最长的路径
}

int main(){
	cin >> n;
	
	memset(h, -1, sizeof(h));
	
	for(int i = 1; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		
		add(a, b, c);
		add(b, a, c);
	}
	
	int t = dfs(1, -1);
	
	cout << ans << endl;
}