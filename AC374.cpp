// Problem: 棋盘覆盖
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/374/
// Memory Limit: 64 MB
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

const int N = 110;

pair<int, PII> h[N], e[N], ne[N];
int idx;

int n;
int t;

void add(PII u, PII v){
	e[idx] = u;
	ne[idx] = h[idx];
	h[]
}

int main(){
	
}