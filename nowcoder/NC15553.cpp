// Problem: 数学考试
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/15553
// Memory Limit: 65536 MB
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

int T;
int n;
int k;
ll s[200010];

int main(){
	cin >> T;
	while(T--){
		cin >> n >> k;
		
	
		for(int i = 1; i <= n; i++){
			ll x;
			cin >> x;
			s[i] = s[i - 1] + x;
		}
		
		ll ans = -1e18;
		ll maxx = -1e18;
		for(int i = k; i <= n - k; i++){
			maxx = max(maxx, s[i] - s[i - k]);
			ans = max(ans, maxx + s[i + k] - s[i]);
		}
		
		cout << ans << endl;
	}
	re 0;
}