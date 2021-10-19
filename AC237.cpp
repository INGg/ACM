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
#define re return

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector<int> alls;

int f[2000000 + 10];

int find(int x){
	return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}

void init(int x){
	for(int i = 1; i <= x; i++){
		f[i] = i;
	}
}

int query(int p){
	if(f[p] == p) return p;
	else{
		int v = query(f[p]);
		f[p] = v;
		return v;
	}
}

void merge(int p1, int p2){ // 让p1的父亲是f2
	int f1 = query(p1);
	int f2 = query(p2);
	
	if(f1 != f2){
		f[f1] = f2;
	}
}

int n;
struct nope{
	int i;
	int j;
	int e;
}order[1000000 + 10];

bool cmp(nope a, nope b){
	return a.e > b.e;
}

void solve(){
	alls.clear();
	memset(order, 0, sizeof(order));
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &order[i].i, &order[i].j, &order[i].e);
		alls.push_back(order[i].i);
		alls.push_back(order[i].j);
	}
	
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	init(alls.size());
	
	sort(order + 1, order + 1 + n, cmp);
	
	int k = 1;
	
	while(1){
		if(!order[k].e) break;
		int xi = find(order[k].i);
		int xj = find(order[k].j);
		
		merge(xi, xj);
		
		k++;
	}
	
	int ok = 1;
	
	for(int i = k; i <= n; i++){
		int xi = find(order[i].i);
		int xj = find(order[i].j);
		if(query(xi) == query(xj)){
			ok = 0;
			break;
		}
	}
	
	if(ok){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}

int T;

int main(){
	cin >> T;
	while(T--){
		solve();
	}
	re 0;
}
