// Problem: 开心的金明
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/428/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-26 20:53:58

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
int v[30];
int w[30];
int f[30010];

int main(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		int vv, p;
		cin >> vv >> p;
		v[i] = vv;
		w[i] = vv * p;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= v[i]; j--){
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	
	cout << f[m];
	
	return 0;
}