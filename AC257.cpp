// Problem: 关押罪犯
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/259/
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

using namespace std;

typedef pair<int, int> PII;

const int N = 2e4 + 10;
const int M = 1e5 + 10;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

struct nope{
	int a, b, c;
}a[M];

bool cmp(nope a, nope b){
	return a.c > b.c;
}

void init(){
	memset(h, -1, sizeof(h));
	memset(color, 0, sizeof(color));
	idx = 0;
}

void add(int u, int v){
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx++;
}

bool dfs(int u, int c){
	color[u] = c;
	
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!color[j]){
			if(!dfs(j, 3 - c)) return 0;
		}
		else if(color[j] == c) return 0;
	}
	
	return 1;
}

bool check(int mid){
	init();
	
	for(int i = 1; i <= m; i++){
		if(a[i].c <= mid) break;
		add(a[i].a, a[i].b);
		add(a[i].b, a[i].a);		
	}
	
	
	int t = 1;
	for(int i = 1; i <= n; i++){
		if(!color[i]){
			if(!dfs(i, 1)){
				t = 0;
				break;
			}
		}
	}
	
	if(t){
		return 1;
	}
	else return 0;
}

int main(){
	cin >> n >> m;
	
	int maxx = 0;
	
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
		maxx = max(maxx, a[i].c);
	}
	
	sort(a + 1, a + 1 + m, cmp);
	
	int l = 0;
	int r = maxx;
	
	while(l < r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			r = mid;
		}
		else l = mid + 1;
	}
	
	cout << l << endl;
	
	return 0;
}