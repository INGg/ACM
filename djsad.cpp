// Problem: 矩阵消除游戏
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/200190
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
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

int n, m, k;
int a[30][30];
int s[30][30];
int sumh[35];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	
	cin >> n >> m >> k;
	
	int summ = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", a[i] + j);
			summ += a[i][j];
		}
	}

	
	if(k >= n || k >= m){
		cout << summ;
		return 0;
	}
	
	int ans = 0;
	
	// 二进制子集枚举
	for(int i = 0; i < (1 << m); i++){ // 先确定要选哪几列
		int h = k - __builtin_popcount(i); // 还能选 h 行
		
		memset(sumh, 0, sizeof(sumh));
		
		int res = 0;
		
		for(int x = 1; x <= n; x++){
			for(int j = 0; j < m; j++){
				if((i >> j) & 1){
					res += a[x][j + 1];
					sumh[x] -= a[x][j + 1];
				}
				else{
					sumh[x] += a[x][j + 1];
				}
			}
		}
		
		sort(sumh + 1, sumh + 1 + n, cmp);
		
		for(int j = 1; j <= h; j++){
			res += sumh[j];
		}
		
		ans = max(ans, res);
	}
	cout << ans;
	re 0;
}