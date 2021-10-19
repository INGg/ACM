// Problem: C. Mikasa
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-01 11:03:35

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
int m;

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		int p = m + 1;
		int ans = 0;
		for(int i = 30; i >= 0; i--){
			int a = (n >> i) & 1;
			int b = (p >> i) & 1;
			if(a && !b) break;
			if(!a && b) ans |= (1 << i);
		}
		cout << ans << endl;
	}
}