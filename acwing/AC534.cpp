// Problem: 货币系统
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/534/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-27 21:30:38

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

int T;
int n;
int a[110];
int f[25010];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		sort(a + 1, a + 1 + n);
		
		memset(f, 0, sizeof(f));
		f[0] = 1;
		
		int m = a[n];
		
		int ans = 0;
		
		for(int i = 1; i <= n; i++){
			if(!f[a[i]]) ans++; // 看前i - 1个数有没有表示成功这个数
			for(int j = a[i]; j <= m; j++){
				f[j] += f[j - a[i]];
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}