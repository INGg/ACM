// Problem: 混合背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/7/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-27 21:53:47

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

const int N = 1010;

int n, m;
int f[N];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int v, w, s;
		cin >> v >> w >> s;
		if(s == 0){
			for(int j = v; j <= m; j++){
				f[j] = max(f[j], f[j - v] + w);
			}
		}
		else{
			if(s == -1){ // 看成特殊的多重背包
				s = 1;
			}
			
			// 多重背包二进制优化
			for(int k = 1; k <= s; k *= 2){
				for(int j = m; j >= k * v; j--){
					f[j] = max(f[j], f[j - k * v] + w * k);
				}
				s -= k;
			}
			
			if(s){
				for(int j = m; j >= s * v; j--){
					f[j] = max(f[j], f[j - s * v] + w * s);
				}
			}
		}
	}
	
	cout << f[m];
	
	return 0;
}