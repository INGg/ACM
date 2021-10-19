// Problem: 电路维修
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/177/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-15 16:48:14

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
#include <unordered_map>
#include <deque>
#define ll long long
#define ull unsigned long long
#define re return
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int T;
int n, m;
char g[510][510];
int dis[510][510];
bool st[510][510];

int bfs(){
	memset(dis, 0x3f, sizeof(dis));
	memset(st, 0, sizeof(st));
	
	deque<PII> q;
	
	dis[0][0] = 0;
	q.push_back({0, 0});
	
	char cs[] = "\\/\\/";
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
    int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};
	
	while(q.size()){
		auto t = q.front();
		q.pop_front();
		
		if(st[t.x][t.y]) continue;
		st[t.x][t.y] = 1;
		
		for(int i = 0; i < 4; i++){
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			if(x < 0 || x > n || y < 0 || y > m) continue;
			
			int gx = t.x + ix[i];
			int gy = t.y + iy[i];
			int w = dis[t.x][t.y] + (g[gx][gy] != cs[i]);
			if(dis[x][y] > w){
				dis[x][y] = w;
				if(g[gx][gy] != cs[i]) q.push_back({x, y});
				else q.push_front({x, y});
			}
		}
	}
	return dis[n][m];
}

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 0; i < n; i++) scanf("%s", g[i]);
		
		if((n + m) % 2 == 1){
			cout << "NO SOLUTION" << endl;
		}
		else{
			cout << bfs() << endl;
		}
	}
	return 0;
	
}