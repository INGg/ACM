// Problem: 最长公共子序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/899/
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

const int N = 1010;

int n, m;
char a[N];
char b[N];
int f[N][N];

int main(){
	cin >> n >> m;
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if(a[i] == b[j]){
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			}
		}
	}
	
	cout << f[n][m];
	
	return 0;
}