// Problem: P1049 [NOIP2001 普及组] 装箱问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1049
// Memory Limit: 125 MB
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

int n;
int w[35];
int v;
int f[20010];

int main(){
	cin >> v >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = v; j >= w[i]; j--){
			f[j] = max(f[j], f[j - w[i]] + w[i]);
		}
	}
	
	cout << v - f[v];
	
}