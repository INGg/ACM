// Problem: 山峰和山谷
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1108/
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
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int dx[8] = {-1,0,1,0,1,-1,1,-1};
int dy[8] = {0,1,0,-1,1,1,-1,-1};

int n;
int w[1010][1010];
bool vis[1010][1010];

void bfs(int xx, int yy, bool& is_h, bool& is_l){
	queue<PII> q;
	q.push({xx, yy});
	vis[xx][yy] = 1;
	
	int k = w[xx][yy];
	
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			
			if(x < 1 || x > n || y < 1 || y > n) continue;
			if(w[x][y] != k){
				if(w[x][y] > k) is_h = 1;
				else is_l = 1;
			}
			else if(!vis[x][y]){
				q.push({x, y});
				vis[x][y] = 1;
			}		
			
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", w[i] + j);
		}
	}
	
	int h = 0;
	int l = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!vis[i][j]){
				bool is_h = 0;
				bool is_l = 0;
				bfs(i ,j, is_h, is_l);
				if(!is_h) h++; // 只要没有比它高的就是山峰
				if(!is_l) l++; 
			}
		}
	}
	
	cout << h << " " << l << endl;
	
	re 0;
}