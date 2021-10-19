// Problem: P1314 [NOIP2011 提高组] 聪明的质监员
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1314
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

const int N = 200010;

int n, m;
ll s;

struct nope{
	int w;
	int v;
	int id;
}a[N];

PII qj[N];

ll summ[N];
ll cnt[N];

ll gety(int W){
	ll res = 0;
	for(int i = 1; i <= n; i++){
		if(a[i].w >= W){
			summ[i] = summ[i - 1] + a[i].v;
			cnt[i] = cnt[i - 1] + 1;
		}
		else{
			summ[i] = summ[i - 1];
			cnt[i] = cnt[i - 1];
		}
	}
	
	for(int j = 1; j <= m; j++){
		res += (cnt[qj[j].y] - cnt[qj[j].x - 1]) * (summ[qj[j].y] - summ[qj[j].x - 1]);
	}
	
	return res;
}

int main(){
	scanf("%d%d%lld", &n, &m, &s);
	
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a[i].w, &a[i].v);
		a[i].id = i;
	}
	
	// sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &qj[i].x, &qj[i].y);
	}
	
	int l = 1;
	int r = 1e6 + 1;
	
	while(l < r){
		int mid = (l + r) >> 1;
		if(gety(mid) >= s){ // 值如果变小
			r = mid - 1;
		}
		else{
			l = mid;
		}
	}
	
	printf("%lld",min(abs(s - gety(r + 1)), abs(s - gety(r))));
	re 0;
}



