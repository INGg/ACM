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

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int a[110][110];
int f[110][110];
int n;
int ans = -1;

void dfs(int i, int j, int l, int r, int summ){
	if(i == n){
		if(abs(l - r) <= 1)
			ans = max(summ, ans);
		re;	
	}
	
	dfs(i + 1, j, l + 1, r, summ + a[i + 1][j]);
	dfs(i + 1, j + 1, l, r + 1, summ + a[i + 1][j + 1]);
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			scanf("%d", a[i] + j);
		}
	}
	
	dfs(1, 1, 0, 0, a[1][1]);
	
	cout << ans;
	
	re 0;
}