// Problem: B. Gregor and the Pawn Game
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-01 23:05:48

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

const int N = 2e5 + 10;
char a[N];
char b[N];
bool vis[N];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		scanf("%s", a + 1);
		scanf("%s", b + 1);
		reverse(a + 1, a + 1 + n);
		reverse(b + 1, b + 1 + n);
	}
}