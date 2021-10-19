// Problem: 股票买卖 V
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1060/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-29 12:47:40

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

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n;
int w[N];
int f[N][3];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	
	f[0][1] = f[0][0] = -INF;
	f[0][2] = 0; // 入口是合法的；并且下一天能买
	
	for(int i = 1; i <= n; i++){
		f[i][0] = max(f[i - 1][2] - w[i], f[i - 1][0]);
		f[i][1] = f[i - 1][0] + w[i];
		f[i][2] = max(f[i - 1][2], f[i - 1][1]);
	}
	
	cout << max(f[n][1], f[n][2]);
	
	return 0;
}