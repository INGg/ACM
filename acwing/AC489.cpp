// Problem: 金明的预算方案
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/489/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-26 20:22:20

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
#define v first
#define w second

using namespace std;

typedef pair<int, int> PII;

const int M = 32010;
const int N = 66;

int n, m;
vector<PII> cong[N];
PII zhu[N];
int f[M];

int main(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		int v, p, q;
		cin >> v >> p >> q;
		if(q == 0){
			zhu[i] = {v, v * p};
		}
		else{
			cong[q].push_back({v, v * p});
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(zhu[i].v){
			for(int j = m; j >= 0; j--){
				for(int k = 0; k < (1 << (int)cong[i].size()); k ++){
					int v = zhu[i].v;
					int w = zhu[i].w;
					
					for(int u = 0; u < (int)cong[i].size(); u++){ // 看位数
						if((k >> u) & 1){
							v += cong[i][u].v;
							w += cong[i][u].w;
						}
					}
					
					if(j >= v) f[j] = max(f[j], f[j - v] + w);
				}
			}
		}
	}
	
	cout << f[m];
	
	return 0;
}