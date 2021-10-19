// Problem: 一个简单的整数问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/248/
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
ll tr[N];

int lb(int x){
    return x & -x;
}

void modify(int p, int v){
    for(; p <= N; p +=lb(p)){
        tr[p] += v;
	}
}

int query(int p){
    int res = 0;
    for(; p; p -= lb(p)){
		res += tr[p];
    }
    return res;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		modify(i, x);
		modify(i + 1, -x);
	}
	while(m--){
		char op[2];
		scanf("%s", op);
		if(op[0] == 'C'){
			int l, r, d;
			cin >> l >> r >> d;
			modify(l, d);
			modify(r + 1, -d);
		}
		else{
			int x;
			cin >> x;
			cout << query(x) << endl;
		}
	}
}