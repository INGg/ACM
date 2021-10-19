// Problem: 背包问题求具体方案
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/12/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-26 16:08:54

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
int v[1010];
int w[1010];
int f[1010][1010];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> v[i] >> w[i];
	}
	
	for(int i = n; i >= 1; i--){
		for(int j = 0; j <= m; j++){
			f[i][j] = f[i + 1][j];
			if(j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
		}
	}
	
	int i = 1;
	int j = m;
	
	while(i <= n){
		if(j >= v[i] && f[i + 1][j - v[i]] + w[i] >= f[i + 1][j]){
			cout << i << " ";
			j -= v[i];
			i++;
		}
		else i++;
	}
	
	return 0;
}