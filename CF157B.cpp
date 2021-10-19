// Problem: B. Trace
// Contest: Codeforces - Codeforces Round #110 (Div. 2)
// URL: https://codeforces.com/problemset/problem/157/B
// Memory Limit: 256 MB
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

int n;
int r[1010];

const double pi = 3.1415926536;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> r[i];
	}
	
	sort(r + 1, r + 1 + n);
	
	double ans = 0;
	
	for(int i = n; i >= 1; i -= 2){
		ans += r[i] * r[i] - r[i - 1] * r[i - 1];
	}
	
	printf("%.10lf", ans * pi);
	
	return 0;
}