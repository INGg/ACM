// Problem: 能量项链
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/322/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-11 09:49:25

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
int a[210];
int f[210][210]; 

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= 2 * n; i++){ // 复制一遍
		a[i + n] = a[i];
	}
	
	for(int len = 3; len <= n + 1; len++){ // 得从3个开始，根据题意，三个点的珠子才能合并，中间一个点相同，最后合为一个点
		for(int i = 1; i <= 2 * n - len + 1; i++){
			int l = i;
			int r = i + len - 1;
			// f[l][r] = 
			for(int k = l + 1; k < r; k++){ // 这里相较于前面来说k要从l+1开始，个人理解是因为题目要求的是某一个珠子会对应的区间是两格，而不是石子那样的一格
				f[l][r] = max(f[l][r], f[l][k] + f[k][r] + (a[l] * a[k] * a[r]));
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 1; i <= 2 * n; i++){
		ans = max(ans, f[i][i + n]);
	}
	
	cout << ans << endl;
	
	return 0;
}