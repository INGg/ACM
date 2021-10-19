// Problem: 环形石子合并
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1070/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-10 16:50:06

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

const int N = 410;

int n;
int a[N];
int s[N];
int f[N][N];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i + n] = a[i];
	}
	
	for(int i = 1; i <= 2 * n; i++){
		s[i] = s[i - 1] + a[i];
	}
	
	int ans = 1e8;
	
	for(int len = 2; len <= n; len++){ // min
		for(int i = 1; i <= 2 * n - len + 1; i++){
			int l = i;
			int r = i + len - 1;
			f[l][r] = 1e8;
			for(int k = l; k < r; k++){
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		ans = min(ans, f[i][i + n - 1]);
	}
	cout << ans << endl;
	
	ans = 0;
	memset(f, 0, sizeof(f));
	
	for(int len = 2; len <= n; len++){ // max
		for(int i = 1; i <= 2 * n - len + 1; i++){
			int l = i;
			int r = i + len - 1;
			// f[l][r] = -1e8;
			for(int k = l; k < r; k++){
				f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		ans = max(ans, f[i][i + n - 1]);
	}
	cout << ans << endl;
}