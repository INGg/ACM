// Problem: 一个简单的整数问题2
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/244/
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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

const int N = 1e5 + 10;

int n, m;
int a[N];
ll tr1[N]; // b[i]
ll tr2[N]; // i b[i]

int lb(int x){
	return x & -x;
}

ll query(ll tr[], int p){
	ll res = 0;
	for(; p; p -= lb(p)){
		res += tr[p];
	}
	return res;
}

void modify(ll tr[], int p, ll v){
	for(; p <= N; p += lb(p)){
		tr[p] += v;
	}
}

ll summ(int x){
	return (x + 1) * (query(tr1, x)) - query(tr2, x);
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++){
		int b = a[i] - a[i - 1];
		modify(tr1, i, b);
		modify(tr2, i, (ll)i * b);
	}
	
	while(m--){
		char op[2];
		scanf("%s", op);
		int l, r;
		if(op[0] == 'Q'){
			cin >> l >> r;
			cout << summ(r) - summ(l - 1) << endl;
		}
		else{
			int v;
			cin >> l >> r >> v;
			
			modify(tr1, l, v);
			modify(tr1, r + 1, -v);
			
			modify(tr2, l, l * v);
			modify(tr2, r + 1, -(r + 1) * v);
		}
	}
	
	return 0;
}