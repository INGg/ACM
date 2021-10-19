// Problem: 整数划分
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/902/
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

const int N = 1010;
const int MOD = 1e9 + 7;

int n;
int f[N][N];

int main(){
	cin >> n;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= i; j++){
			f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % MOD;
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += f[n][i];
	}
	cout << ans;
	return 0;
}