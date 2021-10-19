// Problem: 多重背包问题 III
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/6/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-24 15:03:09

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
int q[20010];
int f[20010];
int g[20010];

int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		memcpy(g, f, sizeof(f));
		
		int s, v, w;
		cin >> v >> w >> s;
		for(int j = 0; j <= v; j++){
			int hh = 0;
			int tt = -1;
			
			for(int k = j; k <= m; k += v){
				if(hh <= tt && q[hh] < k - s * v) hh++;
				while(hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt--;
				if(hh <= tt) f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);
				q[++tt] = k;
			}
		}
	}
	
	cout << f[m];
	
	return 0;
}