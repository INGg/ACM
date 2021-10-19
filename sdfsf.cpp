// Problem: 噩梦
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/179/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-19 16:15:57

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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n, m;
char g[810][810];
int dm[810][810];
int dg[810][810];
bool stm[810][810];
bool stg[810][810];

int dis(PII a, PII b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}

struct nope{
    int x, y, z;
};

int extend(queue<nope>& q, int d1[][810], int d2[][810], int step, bool st[][810], PII g1, PII g2){
	if(step == 3){
		for(int i = 0; i < 4; i++){
			if(dx[i] == 1) dx[i] += 2;
			if(dy[i] == 1) dy[i] += 2;
			if(dx[i] == -1) dx[i] -= 2;
			if(dy[i] == -1) dy[i] -= 2;
		}
	}
	
	for(int _ = 0, qs = q.size(); _ < qs; _++){
		
		auto t = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x = t.y + dx[i];
			int y = t.z + dy[i];
			
			if(x < 0 || x >= n || y < 0 || y >= m) continue;
			if(g[x][y] == 'X') continue;
			if(dis(make_pair(x, y), g1) <= 2 * t.x || dis(make_pair(x, y), g2) <= 2 * t.x) continue;
			if(st[x][y]) continue;
			
			if(d2[x][y]) return d1[x][y] + 1 + d2[x][y];
			
			d1[x][y] = d1[t.x][t.y] + 1;
		}
	}
	
	return -1;
}

int bfs(){
	memset(dm, 0, sizeof(dm));
	memset(dg, 0, sizeof(dg));	
	memset(stg, 0, sizeof(stg));
	memset(stm, 0, sizeof(stm));	
	
	queue<nope> qm, qg;
	PII g1 = {-1, -1}, g2 = {-1, -1};
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] == 'M') qm.push({0, i, j}), stm[i][j] = 1;
			if(g[i][j] == 'G') qg.push({0, i, j}), stg[i][j] = 1;
			if(g[i][j] == 'Z'){
				if(g1 == make_pair(-1, -1)) g1 = make_pair(i, j);
				else g2 = make_pair(i, j);
			}
		}
	}
	
	while(qm.size() && qg.size()){
		
		int t;
		if(qm.size() <= qg.size()) t = extend(qm, dm, dg, 3, stm, g1, g2);
		else t = extend(qg, dg, dm, 1, stg, g1, g2);
		
		if(t != -1) return t;
	}
	
	return -1;
}

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 0; i < n; i++) scanf("%s", g[i]);
		
		int step = bfs();
		
		cout << step << endl;
	}
}