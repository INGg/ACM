// Problem: D. Make a Power of Two
// Contest: Codeforces - Codeforces Round #739 (Div. 3)
// URL: https://codeforces.com/contest/1560/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-19 01:41:24

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

const int N = 1e5 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
ll n;
string base[70];

bool check2(ll x){
	if(x & (x - 1) == 0) return 1;
	else return 0;
}

string tostr(ll x){
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	return s;
}

void init(){
	for(int i = 0; i < 64; i++){
		ll x = (1ll << i);
		base[i] = tostr(x);
	}
}

int cmp(string s, string s2){
	int j = 0;
	int cnt = 0;
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] == s2[j]){
			j++;
			cnt++;
		}
	}
	
	return s.size() - cnt + s2.size() - cnt;
}

int main(){
	init();
	
	cin >> T;
	while(T--){
		cin >> n;
		if(check2(n)) cout << 0 << endl;
		else{
			int ans = 0x3f3f3f3f;
			string x = tostr(n);
			for(int i = 0; i < 64; i++){
				ans = min(ans, cmp(x, base[i]));
			}
			cout << ans << Endl;
		}
	}
}