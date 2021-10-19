// Problem: A. Ezzat and Two Subsequences
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-09 22:36:47

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
int a[100000 + 10];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		sort(a + 1, a + 1 + n);
		
		ll summ = 0;
		for(int i = 1; i < n; i++){
			summ += a[i];
		}
		
		printf("%.9lf\n", 1.0 * summ / (n - 1) + a[n]);
	}
	return 0;
}