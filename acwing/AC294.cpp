// Problem: 炮兵阵地
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/294/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-06 11:05:05

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
#define pb push_back

using namespace std;

typedef pair<int, int> PII;

const int N = 110;
const int M = 15;
const int K = 1 << 11;

int n, m;
vector<int> stats;
int cnt[K];
int g[N];
int f[2][K][K];

bool check(int x){
	for(int i = 0; i < m; i++){
		if(((x >> i) & 1) && (((x >> (i + 1)) & 1) || (x >> (i + 2) & 1)))
			return 0;
	}
	return 1;
}

void init(){
	for(int i = 0; i < (1 << m); i++){
		if(check(i)){
			stats.pb(i);
			cnt[i] = __builtin_popcount(i);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c == 'H') g[i] += (1 << j);
		}
	}
	
	init();
	
	for(int i = 1; i <= n; i++){
		for(int x = 0; x < stats.size(); x++){
			for(int y = 0; y < stats.size(); y++){
				for(int z = 0; z < stats.size(); z++){
					
					int a = stats[x]; // i
					int b = stats[y]; // i - 1
					int c = stats[z]; // i - 2
					
					if((a & b) || (a & c) || (c & b)) continue;
					if((g[i] & a) || (g[i - 1] & b)) continue;
					if(i >= 2 && (g[i - 2] & c)) continue;
					
					f[i & 1][a][b] = max(f[i & 1][a][b], f[(i - 1) & 1][b][c] + cnt[a]);
				}
			}
		}
	}
	
	
	int ans = 0;
	
	// for(int i = 1; i <= n; i++){
		for(int j = 0; j < stats.size(); j++){
			for(int k = 0; k < stats.size(); k++){
				ans = max(ans, f[n & 1][stats[j]][stats[k]]);
			}
		}
	// }
	
	cout << ans << endl;
	
	return 0;
}