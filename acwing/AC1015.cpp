// Problem: 机器分配
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1015/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-26 17:49:35

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

const int N = 20;

int n, m;
int w[N][N];
int f[N][N];
int way[N];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> w[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k <= m; k++){
				if(j >= k){
					f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
				}
			}
		}
	}
	
	cout << f[n][m] << endl;
	
	int j = m;
	for(int i = n; i; i--){
		for(int k = 0; k <= j; k++){
			if(f[i][j] == f[i - 1][j - k] + w[i][k]){
				way[i] = k;
				j -= k;
				break;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << i << ' ' << way[i] << Endl;
	}
	
	return 0;
}