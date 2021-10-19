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

const int N = 150000 + 10;

int n, m, s;
int h[N], e[N], w[N], ne[N], idx;
int dis[N];
bool vis[N];

void add(int a, int b, int c){
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a] = idx ++;
}

int dj(int s){
	priority_queue<PII, vector<PII>, greater<PII>> q;
	
	memset(dis, 0x3f, sizeof(dis));
	
	dis[s] = 0;
	q.push({0, s}); // 插入距离和节点编号
	
	while(!q.empty()){
		auto t = q.top(); // 插入距离和节点编号
		q.pop();
		
		if(vis[t.y]) continue; // 如果距离已经确定，则跳过该点
		vis[t.y] = 1;
		
		for(int i = h[t.y]; i != -1; i = ne[i]){
			int j = e[i];
			if(dis[j] > t.x + w[i]){
				dis[j] = t.x + w[i];
				q.push({dis[j], j});
			}
		}
	}
	
	if(dis[n] == 0x3f3f3f3f) return -1;
	
	return dis[n];
}

int main(){
	memset(h, -1, sizeof(h));
	
	cin >> n >> m >> s;
	
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	
	cout << dj(s);
	
	re 0;
}