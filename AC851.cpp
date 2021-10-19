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

const int N = 1e5 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int vis[N], dis[N];

void add(int a, int b, int c){
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a] = idx ++;
}

int spfa(int s){
	
	// 初始化！
	queue<int> q;
	
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	
	dis[s] = 0;
	q.push(s);
	vis[s] = 1;
	
	while(!q.empty()){
		int f = q.front();
		q.pop();
		vis[f] = 0; // 不在队列里
		
		for(int i = h[f]; i != -1; i = ne[i]){
			int j = e[i];
			
			if(dis[j] > dis[f] + w[i]){
				dis[j] = dis[f] + w[i];
				if(!vis[j]){
					q.push(j);
					vis[j] = 1;
				}
			}
		}
	}
	
	return dis[n];
}

int main(){
	memset(h, -1, sizeof(h));
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	
    int t = spfa(1);

    if (t == 0x3f3f3f3f) puts("impossible");
    
    else printf("%d\n", t);
}