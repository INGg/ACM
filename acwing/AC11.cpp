// Problem: 背包问题求方案数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/11/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-27 12:34:36

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

const int N = 1010;
const int mod = 1e9 + 7;

int n, m;
int v[N];
int w[N];
int f[N]; // 不同体积对应的最大价值
int g[N]; // 不同体积对应的方案数

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> v[i] >> w[i];
	}
	
	
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	g[0] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= v[i]; j--){
			int maxx = max(f[j], f[j - v[i]] + w[i]);
			int s = 0;
			if(f[j] == maxx) s += g[j];
			if(f[j - v[i]] + w[i] == maxx) s = (g[j - v[i]] % mod + s % mod) % mod;
			f[j] = maxx;
			g[j] = s;
		}
	}
	
	int id = 0;
	
	for(int i = 0; i <= m; i++){
		if(f[i] > f[id]){
			id = i;
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= m; i++){
		if(f[i] == f[id]){
			ans = (ans % mod + g[i] % mod) % mod;
		}
	}
	
	cout << ans << Endl;
	
	return 0;
}