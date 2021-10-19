// Problem: 潜水员
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/1022/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-25 16:49:41

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

int n, m1, m2;
int v1[1010];
int v2[1010];
int w[1010];

int f[110][110];

int main(){
	cin >> m1 >> m2; // o2 n2
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> v1[i] >> v2[i] >> w[i];
	}
	
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = m1; j >= 0; j--){
			for(int k = m2; k >= 0; k--){
				f[j][k] = min(f[j][k], f[max(0, j - v1[i])][max(0, k - v2[i])] + w[i]);
			}
		}
	}
	
	cout << f[m1][m2];
	
	return 0;
}