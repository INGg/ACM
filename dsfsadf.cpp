// Problem: 兔子跳
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3776/
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

int T;
int n;
ll x;
ll a[100000 + 10];

int main(){
	cin >> T;
	while(T--){
		cin >> n >> x;
		
		// int t1 = 0;
		// int t2 = 0;
		// int t3 = 0;
		int t4 = 0;
		
		memset(a, 0, sizeof(a));
		
		for(int i = 1; i <= n; i++){
			scanf("%lld", a + i);
			if(a[i] == x){
				t4 = 1;
			}
		}
		
		if(t4){
			cout << 1 << endl;
			continue;
		}
		
		sort(a + 1, a + 1 + n);
		
		if(a[n] * 2 >= x){
			cout << 2 << endl;
		}
		else if(a[n] > x){
			cout << 3 << endl;
		}
		else if(a[n] * 2 <= x){
			int cnt = 0;
			while(a[n] * 2 <= x){
				x -= a[n];
				cnt++;
			}
			// cnt = x / a[n];
			// x /= a[n];
			if(x % a[n] == 0) cout << cnt + 1;
			else cout << cnt + 2 << Endl;
			
		}
		// cout << endl;
	}
}