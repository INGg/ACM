// Problem: 最短Hamilton路径
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/93/
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// Code by: ING__
// 
// Edited on 2021-08-05 09:06:15

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
int f[(int)((1 << 20) + 5)][25];
int w[25][25];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> w[i][j];
		}
	}
	
	memset(f, 0x3f, sizeof(f)); // 没更新是不合法的
	f[1][0] = 0; // 初始化，考虑定义，到达第0个点的二进制路径是1，花费为0
	
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if((i >> j) & 1){
				for(int k = 0; k < n; k++){
					if((i >> k) & 1){
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
					}
				}
			}
		}
	}
	
	cout << f[(1 << n) - 1][n - 1];
	
	return 0;
}