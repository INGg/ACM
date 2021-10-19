// Problem: 装满的油箱
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/178/
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// Code by: ING__
// 
// Edited on 2021-08-17 21:55:08

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
#define ll long long
#define ull unsigned long long
#define re return
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;
const int M = 1e4 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int h[N], ne[M * 2], e[M * 2], we[M * 2], wp[N], idx;

void add(int a, int b, int c){
	e[idx] = b;
	ne[idx] = h[a];
	we[idx] = c;
	h[a] = idx++; 
}

int n, m, q;
int dis[N][110]; // 到达x城市，剩余y油量，花了多少钱
bool st[N][110];

struct nope{
	int d, u, c;
	
	bool operator< (const nope &W)const{
		return d > W.d;
	}
};

int bfs(int c, int start, int end){
	memset(dis, 0x3f, sizeof(dis));
	memset(st, 0, sizeof(st));
	
	priority_queue<nope> q; // x 现在所在的点的编号，y 剩余油量
	
	q.push({0, start, 0});
	dis[start][0] = 0;
	
	while(q.size()){
		auto t = q.top();
		q.pop();
		
		if(t.u == end) return t.d;
		
		if(st[t.u][t.c]) continue;
		st[t.u][t.c] = 1;
		
		if(t.c + 1 <= c && dis[t.u][t.c + 1] > t.d + wp[t.u]){
			dis[t.u][t.c + 1] = wp[t.u] + t.d;
			q.push({dis[t.u][t.c + 1], t.u, t.c + 1});
		}
		
		for(int i = h[t.u]; i != -1; i = ne[i]){
			int j = e[i];
			
			if(t.c >= we[i]){
				if(dis[j][t.c - we[i]] > t.d){
					dis[j][t.c - we[i]] = t.d;
					q.push({t.d, j, t.c - we[i]});
				}
			}
		}
	}
	return -1;
}

int main(){
	memset(h, -1, sizeof(h));
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> wp[i];
	}
	
	for(int i = 1; i <= m; i++){
		int u, v, d;
		cin >> u >> v >> d;
		add(u, v, d);
		add(v, u, d);
	}
	
	cin >> q;
	
	while(q--){
		int c, start, end;
		cin >> c >> start >> end;
		int t = bfs(c, start, end);
		if(t != -1) cout << t << endl;
		else cout << "impossible" << endl;
	}
}