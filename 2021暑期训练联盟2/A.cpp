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

const int N = 1010;

int n, m, p;
PII judger[N];
PII yumao[N];
PII jy[N];
double disy[N];
double disj[N];

double get_dis(PII a, PII b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct node{
	int u, v;
	double w;
};

vector<node> a;

bool cmp(node a, node b){
	return a.w < b.w;
}

bool vis[N][2]; // 0 表示裁判，1表示仓库

int main(){
	cin >> n >> m >> p;
	
	for(int i = 1; i <= n; i++){
		cin >> judger[i].x >> judger[i].y;
	}
	
	for(int i = 1; i <= m; i++){
		cin >> jy[i].x >> jy[i].y;
	}
	
	for(int i = 1; i <= p; i++){
		cin >> yumao[i].x >> yumao[i].y;
	}
	
	double ans = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			node x;
			x.u = i;
			x.v = j;
			x.w = get_dis(judger[i], jy[j]);
			a.emplace_back(x);
		}
	}
	
	sort(a.begin(), a.end(), cmp);
	
	for(auto i : a){
		int u = i.u;
		int v = i.v;
		double w = i.w;
		if(vis[u][0] || vis[v][1]){
			continue;
		}
		ans += i.w;
		vis[u][0] = vis[v][1] = 1;
	}
	
	memset(vis, 0, sizeof(vis));
	a.clear();
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= p; j++){
			node x;
			x.u = i;
			x.v = j;
			x.w = get_dis(judger[i], yumao[j]);
			a.emplace_back(x);
		}
	}
	
	sort(a.begin(), a.end(), cmp);
	
	for(auto i : a){
		int u = i.u;
		int v = i.v;
		double w = i.w;
		if(vis[u][0] || vis[v][1]){
			continue;
		}
		ans += i.w;
		vis[u][0] = vis[v][1] = 1;
	}
	
	printf("%.10lf", ans);
	
	return 0;
}