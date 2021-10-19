// Problem: [NOIP2005]校门外的树
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/16649
// Memory Limit: 262144 MB
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
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int l, m;
PII qj[110];
int tr[10000];

int main(){
	cin >> l >> m;
	for(int i = 1; i <= m; i++){
		cin >> qj[i].x >> qj[i].y;
	}
	
	
	for(int i = 0; i <= l; i++) tr[i] = 1;
	
	for(int i = 1; i <= m; i++){
		for(int j = qj[i].x; j <= qj[i].y; j++){
			tr[j] = 0;
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= l; i++){
		if(tr[i]){
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}