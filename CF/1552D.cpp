// Problem: D. Array Differentiation
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-02 17:54:27

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
ll a[15];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		set<ll> s;
		for(int i = 0; i < (1 << n); i++){
			ll summ = 0;
			for(int j = 0; j < n; j++){
				if((i >> j) & 1){
					summ += a[j];
				}
			}
			s.insert(summ);
		}
	
		if(s.size() < (1 << n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}