// Problem: 导弹防御系统
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/189/
// Memory Limit: 64 MB
// Time Limit: 3000 ms
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

const int N = 55;

int n;
int q[N];
int up[N];
int down[N];

int ans;

void dfs(int u, int s, int x){ // 第u个数，上升的个数，下降的个数
	if(s + x >= ans) return; // 不加等于会超时，剪枝
	if(u == n + 1){
		ans = min(ans, s + x);
		return;
	}
	
	int k = 1;
	while(k <= s && up[k] >= q[u]) k++;
	int t = up[k];
	up[k] = q[u];
	dfs(u + 1, max(s, k), x);
	up[k] = t;
	
	k = 1;
	while(k <= x && down[k] <= q[u]) k++;
	t = down[k];
	down[k] = q[u];
	dfs(u + 1, s, max(x, k));
	down[k] = t;
}

int main(){
	while(scanf("%d", &n) != EOF && n != 0){
		for(int i = 1; i <= n; i++){
			scanf("%d", q + i);
		}
		
		ans = n;
		
		dfs(1, 0, 0);
		
		printf("%d\n", ans);
	}
	return 0;
}