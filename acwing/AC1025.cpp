// Problem: 买书
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1025/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-26 09:40:55

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

int n;
int v[] = {10, 20, 50, 100};
int f[1010];

int main(){
	cin >> n;
	
	f[0] = 1;
	
	for(int i = 0; i < 4; i++){
		for(int j = v[i]; j <= n; j++){
			f[j] += f[j - v[i]];
		}
	}
	
	cout << f[n];
	
	return 0;
}