// Problem: 最长公共上升子序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/274/
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

const int N = 3010;

int n;
int a[N];
int b[N];
int f[N][N];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", b + i);
	}
	
	for(int i = 1; i <= n; i++){
		int maxx = 1;
		for(int j = 1; j <= n; j++){
			f[i][j] = f[i - 1][j];
			if(a[i] == b[j]){ // 包含a[i]
				// f[i][j] = max(f[i][j], 1);
				// for(int k = 1; k < j; k++){
					// if(b[k] < a[i]){
						// f[i][j] = max(f[i][j], f[i - 1][k] + 1);
					// }
				// }
				f[i][j] = max(f[i][j], maxx);

			}
			if(b[j] < a[i]) maxx = max(maxx, f[i - 1][j] + 1);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
	cout << ans;
	return 0;
}