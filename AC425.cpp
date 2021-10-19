// Problem: 采药
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/425/
// Memory Limit: 128 MB
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

int n, m;
int v[110];
int w[110];
int f[1010];

int main(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		cin >> v[i] >> w[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= v[i]; j--){
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	
	cout << f[m];
	
	re 0;
}