// Problem: 股票买卖 IV
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1059/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-29 12:47:35

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

const int N = 100010;
const int M = 110;

int n, m;
int w[N];
int f[N][M][2];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	
	memset(f, -0x3f, sizeof(f));
	
	for(int i = 0; i <= n; i++) f[i][0][0] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			f[i][j][0] = max(f[i-1][j][0], f[i- 1][j][1]+w[i]);
			f[i][j][1] = max(f[i-1][j][1], f[i-1][j-1][0]-w[i]);
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= m; i++)
		ans = max(ans, f[n][i][0]);
		
	cout << ans;
	
	return 0;
}