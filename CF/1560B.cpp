// Problem: B. Who's Opposite?
// Contest: Codeforces - Codeforces Round #739 (Div. 3)
// URL: https://codeforces.com/contest/1560/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-18 22:37:14

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
ll a, b, c;

int main(){
	cin >> T;
	while(T--){
		cin >> a >> b >> c;
		if(a < b) swap(a, b);
		
		ll summ = (a - b) * 2;
		
		if(c > summ || summ < a) cout << -1 << endl;
		else{
			if(c + summ / 2 > summ) cout << c - summ / 2 << endl;
			else cout << (c + summ / 2) << endl;
		}
	}
}