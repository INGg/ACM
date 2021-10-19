// Problem: C - Win or Freeze
// Contest: Virtual Judge - Codeforces Beta Round #107(Div2) [Cloned]
// URL: https://vjudge.net/contest/439203#problem/C
// Memory Limit: 262 MB
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

bool is_prime(ll n){
	if(n < 2) return 1;
	for(ll i = 2; i * i <= n; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}


int main(){
	ll n;
	cin >> n;
	int t = is_prime(n);
	if(t){
		cout << 1 << endl << 0;
		return 0;
	}
	
	ll x = n;
	vector<ll> ans;
	int cnt = 0;
    for (ll i = 2; i <= x / i && cnt < 5; i ++ )
        if (x % i == 0 && cnt < 5)
        {
            while (x % i == 0 && cnt < 5)
				 x /= i, ans.push_back(i), cnt++;
        }
	if (x > 1) ans.push_back(x);
	// sort(ans.begin(), ans.end());
    int l = ans.size();
	
	if(l <= 2){
		// for(int i = 0; i < 2; i++){
			// cout << ans[i] << endl;
		// }
		cout << 2 << endl;
		re 0;
	}
	
	cout << 1 << endl;
	
	cout << ans[0] * ans[1];
	re 0;
}