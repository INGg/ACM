// Problem: P1902 刺杀大使
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1902
// Memory Limit: 125 MB
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
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int a[1010][1010];
int vis[1010][1010];
int n, m;
PII start;

bool check(int hr){
	queue<PII> q;

	memset(vis, 0, sizeof(vis));
	q.push(start);
	vis[start.x][start.y] = 1;
	
	while(!q.empty()){
		PII f = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = f.x + dx[i];
			int ny = f.y + dy[i];
			
			if(nx < 1 || nx > m || ny < 1 || ny > n || a[nx][ny] > hr) continue;
			
			if(vis[nx][ny]) continue;
			
			if(nx == n) return 1;
			
			vis[nx][ny] = 1;
			
			q.push({nx, ny});
		}
	}
	return 0;
}

int main(){
	cin >> n >> m;
	
	int l = 0;
	int r = -1;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d",a[i] + j);
			r = max(r, a[i][j]);
		}
	}
	
	int x = 9999;
	for(int i = 1; i <= m; i++){
		if(x > a[2][i]){
			x = a[2][i];
			start = {2, i};	
		}
	}
	
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	
	cout << l;
	re 0;
}