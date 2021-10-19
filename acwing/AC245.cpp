// Problem: 谜一样的牛
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/245/
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

int n;
int tr[N];
int ans[N];
int h[N];

int lb(int x){
    return x & -x;
}

void modify(int p, int v){
    for(; p <= n; p +=lb(p)){
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
	cin >> n;
	
	modify(1, 1);
	for(int i = 2; i <= n; i++){
		cin >> h[i];
		modify(i, 1); // 表示当前数还能用几次
	}
	
	// vector<int> ans;
	
	for(int i = n; i >= 1; i--){
		int k = h[i] + 1;
		int l = 1;
		int r = n;
		while(l < r){
			int mid = (l + r) >> 1;
			if(query(mid) >= k){
				r = mid;
			}
			else l = mid + 1;
		}
		ans[i] = r;
		modify(r, -1);
	}
	
	for(int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}