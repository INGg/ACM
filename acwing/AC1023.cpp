// Problem: 货币系统
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1023/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-26 10:02:39

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
int v[20];
ll f[3010];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	
	f[0] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int j = v[i]; j <= m; j++){
			f[j] += f[j - v[i]];
		}
	}
	
	cout << f[m];
	
	return 0;
}