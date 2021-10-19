// Problem: C. Infinity Table
// Contest: Codeforces - Codeforces Round #739 (Div. 3)
// URL: https://codeforces.com/contest/1560/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-18 22:37:18

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
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define re return
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e9;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int k;
vector<ll> base;

int main(){
	ll _;
	for(ll i = 1; i * i <= N; i++){
		base.push_back(i * i);
		_ = i;
	}
	_++;
	base.push_back(_*_);
	
	
	cin >> T;
	while(T--){
		cin >> k;
		
		if(k == 1 || k == 2 || k == 3 || k == 4){
			if(k == 1) cout << "1 1" << endl;
			if(k == 2) cout << "1 2" << endl;
			if(k == 3) cout << "2 2" << endl;
			if(k == 4) cout << "2 1" << endl;
			continue;
		}
		
		ll r = lower_bound(base.begin(), base.end(), k) - base.begin() + 1;
		// cout <<r << Endl;
		
		ll flag = 0; // not found
		ll b = base[r - 1];
		if(b - (ll)sqrt(b) + 1 == k){
			b = sqrt(b);
			cout << b << " " << b << endl;
			continue;
		}
		// cout << base[r - 1] << endl;
		for(ll i = b, c = 1; i >= b - (ll)(sqrt(b)) + 2; i--, c++){
			if(i == k){
				cout << r << " " << c << endl;
				flag = 1;
				break;
			}
		}
		if(flag) continue;
		ll sb = sqrt(b);
		for(ll i = b - (ll)sqrt(b), rr = r - 1; i >= b - sb * 4 + 2; i--, rr--){
			if(i == k){
				cout << rr << " " << sb << endl;
				flag = 1;
				continue;
			}
		}
	}
}