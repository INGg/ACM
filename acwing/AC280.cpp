// Problem: 数字组合
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/280/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-25 23:38:38

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
int a[110];
int f[10010];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	f[0] = 1; // f[0][0] 当一个都不选的时候，恰好选0个构成和为0的方案数为1
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= a[i]; j--){
			f[j] += f[j - a[i]];
		}
	}
	
	cout << f[m];
	
	return 0;
}