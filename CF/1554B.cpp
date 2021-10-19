// Problem: B. Cobb
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-01 10:36:16

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
int k;
int a[100010];

int main(){
	cin >> T;
	while(T--){
		memset(a, 0, sizeof(a));
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		int l = max(1, n - 2 * k);
		
		ll ans = -1e12;
		
		for(ll i = l; i <= n; i ++){
			for(ll j = i + 1; j <= n; j++){
				int x = (a[i] | a[j]);
				ans = max(ans, 1L * i * j - 1L * k * (ll)x);
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}