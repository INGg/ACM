// Problem: D1. Mocha and Diana (Easy Version)
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/D1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-15 22:35:42

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
#define ull unsigned long long
#define re return
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m1, m2;
// 结构体版
struct ufss{
	int f[2010];
	
	void init(){
		for(int i = 1; i <= n; i++){
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

	void merge(int p1,int p2){
		int f1 = query(p1);
		int f2 = query(p2);
		if(f1 != f2){
			f[f1] = f2;
		}
	}
	
	bool pd(int p1, int p2){
		if(query(p1) == query(p2)) return true;
			else return false;
	}
    
    int count(int n){
        int ans = 0;
        for(int i = 1; i <= n; i++) if(f[i] == i) ans++;
        
	}
}u1, u2;

int main(){
	cin >> n >> m1 >> m2;
	u1.init();
	u2.init();
	
	for(int i = 1; i <= m1; i++){
		int a, b;
		cin >> a >> b;
		u1.merge(a, b);
	}
	
	for(int i = 1; i <= m2; i++){
		int a, b;
		cin >> a >> b;
		u2.merge(a, b);
	}
	
	vector<PII> ans;
	
	for(int i = 1; i <= n; i++){
		for(int j =i + 1; j <= n; j ++){
			if(!u1.pd(i, j) && !u2.pd(i, j)){
				u1.merge(i, j);
				u2.merge(i, j);
				ans.push_back({i, j});
			}
		}
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i].x << " " << ans[i].y << endl;
	return 0;
}