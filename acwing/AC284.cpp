// Problem: 石子合并
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/284/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-10 15:33:39

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
int a[310];
int s[310];
int f[310][310];

int main(){
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	
	for(int len = 2; len <= n; len++){
		// if(len == 1)
		for(int i = 1; i <= n - len + 1; i++){
			int l = i;
			int r = i + len - 1;
			f[l][r] = 1e8;
			for(int k = l; k < r; k++){
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
			}
		} 
	}
	
	cout << f[1][n];
	
	return 0;
}