// Problem: 大盗阿福
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/1051/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-29 00:03:23

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

const int N = 1e5 + 10;

int T;
int n;
int w[N];
int f[N][2];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> w[i];
		}
		
		memset(f, 0, sizeof f);
		f[1][1] = w[1];
		f[1][0] = 0;
		for(int i = 2; i <= n; i++){
			f[i][0] = max(f[i - 1][1], f[i - 1][0]);
			f[i][1] = f[i - 1][0] + w[i];
		}
		
		cout << max(f[n][0], f[n][1]) << Endl;
	}
	return 0;
}