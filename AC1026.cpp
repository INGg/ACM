// Problem: 装箱问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1026/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Powered by CP Editor (https://cpeditor.org)

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
int v[35];
int w[35];
int f[20010];

int main(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		w[i] = v[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= v[i]; j--){
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	
	cout << m - f[m];
	
	return 0;
}