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

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;

struct node{
	int k;
	int v;
}f[10000 + 10];

void init(){
	for(int i = 1; i <= 10000; i++){
		f[i].k = i;
		f[i].v = 0;
	}
}

int query(int p, int t){
	f[p].v += t;
	if(f[p].k == p){
		return p;
	}
	return query(f[p].k, t);
}

void merge(int p, int q){
	int p1 = query(p, 0);
	int p2 = query(q, 0);
	
	if(p1 != p2){
		f[p2].k = p1;
	}
}

int main(){
	cin >> n >> m;
	init();
	while(m--){
		int a, b ,c;
		cin >> a >> b >> c;
		if(a == 1){
			merge(b, c);
		}
		else{
			int x = query(b, c);
			x = 1;
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << f[i].v << " ";
	}
	
	re 0;
}