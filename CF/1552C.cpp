// Problem: C. Maximize the Intersections
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-02 17:54:23

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
#define pb push_back

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n, k;
bool vis[510];
vector<PII> save;
vector<int> unsave;

int xj(PII x, PII y){
	if(x.x > y.x) swap(x, y);
	return x.y > y.x && x.y < y.y;
}

int main(){
	cin >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1; i <= k; i++){
			int a, b;
			cin >> a >> b;
			
			if(a > b) swap(a, b);
			
			vis[a] = 1;
			vis[b] = 1;
			
			save.pb({a, b});
		}
		
		for(int i = 1; i <= 2 * n; i++){
			if(!vis[i]) unsave.pb(i);
		}
		
		for(int i = 0; i < n - k; i++){
			save.pb(make_pair(unsave[i], unsave[i + n - k]));
		}
		
		int ans = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				ans += xj(save[i], save[j]);
			}
		}
		
		cout << ans << Endl;
		
		save.clear();
		unsave.clear();
		memset(vis, 0, sizeof(vis));
	}
}