// Problem: B. Running for Gold
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-02 17:54:20

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

int T;
int n;
int r[50010][10];

int main(){
	cin >> T;
	while(T--){
		
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 5; j++){
				cin >> r[i][j];
			}
		}
		
		if(n == 1){
			cout << 1 << endl;
			continue;
		}
		
		int ans = 1;
		
		for(int i = 2; i <= n; i++){
			int cnt = 0;
			for(int j = 1; j <= 5; j++){
				if(r[i][j] < r[ans][j]){
					cnt++;
				}
			}
			if(cnt >= 3){
				ans = i;
			}
		}
		
		int backup = ans;
		ans = n;
		
		for(int i = n - 1; i >= 1; i--){
			int cnt = 0;
			for(int j = 1; j <= 5; j++){
				if(r[i][j] < r[ans][j]){
					cnt++;
				}
			}
			if(cnt >= 3){
				ans = i;
			}
		}
		
		if(ans != backup){
			cout << -1 << endl;
		}
		else cout << ans << Endl;
	}
}