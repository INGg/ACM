// Problem: 传纸条
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/277/
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
int w[55][55];
int f[55][55][55][55];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", w[i] + j);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= n; k++){
				for(int l = 1; l <= m; l++){
					int a = f[i - 1][j][k - 1][l];
					int b = f[i - 1][j][k][l - 1];
					int c = f[i][j - 1][k - 1][l];
					int d = f[i][j - 1][k][l - 1];
					f[i][j][k][l] = max(f[i][j][k][l], max(a, max(b, max(c, d)))) + w[i][j] + w[k][l];
					if(i == k && j == l) f[i][j][k][l] -= w[i][j];
				}
			}
		}
	}
	cout << f[n][m][n][m];
	return 0;
}