// Problem: Stack
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11253/K
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
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

const int N = 1e6;

int n, m;
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
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		modify(i, 1); // 表示当前数还能用几次
	}
	
	int flag = 0;
	
	for(int i = 1; i <= m; i++){
		int p, b;
		cin >> p >> b;
		h[p] = b;
		if(b > p){
			flag = 1;
		}
	}
	
	if(flag){
		cout << -1;
		return 0;
	}
	
	for(int i = n; i; i--){
		int k = h[i];
		if(!k) continue;
		int l = 1;
		int r = n;
		while(l < r){
			int mid = (l + r) / 2;
			if(query(mid) >= k){
				r = mid;
			}
			else l = mid + 1;
		}
		ans[i] = r;
		modify(i, -1);
	}
	
	int num = 0;
	
	for(int i = 1; i <= n; i++){
		if(!ans[i]){
			num++;
		}
		else{
			for(int j = ans[i] - 1, l = i - 1; j && num; j--){
				if(query(j) - query(j - 1)){ // 看看这个数有机会放吗
					ans[l] = j;
					l--;
					num--;
					modify(j, -1);
				}
			}
			if(num){
				for(int j = ans[i] + 1, l = i - 1; j <= n && num; j++){
					if(query(j) - query(j - 1)){
						while(ans[l]) l--;
						ans[l] = j;
						num--;
						modify(j, -1);
					}
				}
			}
			num = 0;
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}