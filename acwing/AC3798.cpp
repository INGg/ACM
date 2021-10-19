// Problem: 计算abc
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3798/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-07 19:00:22

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

int a[6];
int b[6];

int main(){
	for(int i = 1; i <= 4; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + 4);
	
	for(int i = 1; i <= 3; i++){
	b[i] = a[4] - a[i];
	}
	
	sort(b + 1, b + 1 + 3);
	
	for(int i = 1; i <= 3; i++){
		cout << b[i] << " ";
	}
}