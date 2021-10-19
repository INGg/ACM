// Problem: 小国王
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1066/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-05 10:07:04

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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

const int N = 12; // 扩容别太大
const int M = 110;
const int K = (1 << N);

int n, m;
ll f[N][M][K];
// 定义：前i行，已经摆了j个国王，且第i行的状态是k

vector<int> stats;
vector<int> head[K];
int cnt[K]; // 每个合法的状态对应的有几个1

bool check(int x){ // 检查连续1
	for(int i = 0; i < n - 1; i++){
		if(((x >> i) & 1) && ((x >> (i + 1)) & 1))
			return 0;
	}
	return 1;
}

void init(){ // 预处理
	for(int i = 0; i < (1 << n); i++){ // 预处理每一种可能的情况是否合法
		if(check(i)){ // 首先得满足当前自己行是没有相邻的
			stats.pb(i);
			cnt[i] = __builtin_popcount(i); // 看二进制有多少个1
		}
	}
	
	for(int i = 0; i < stats.size(); i++){ // 看一行内合法的数据之间如果做转移能不能行
		for(int j = 0; j < stats.size(); j++){
			int a = stats[i];
			int b = stats[j];
			if(((a & b) == 0) && check(a | b)){
				head[i].pb(j);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	init();
	
	f[0][0][0] = 1; // 初始化
	for(int i = 1; i <= n + 1; i++){ // 这里为什么要写 n + 1是有巧妙的解法的，详情请看下放解释
		for(int j = 0; j <= m; j++){
			for(int x = 0; x < stats.size(); x++){
				for(int y = 0; y < head[x].size(); y++){
					int c = cnt[stats[x]];
					if(j >= c){
						f[i][j][stats[x]] += f[i - 1][j - c][stats[head[x][y]]];
					}
				}
			}
		}
	}
	
	cout << f[n + 1][m][0];
    /*
    我们考虑集合的定义，相当于我们在n+1行前用了全部的棋子所有的已经摆好了
    但最后一行(n+1行)内没有摆任何一个棋子，那么也就满足了题意
    如果用n的话，这样也是可以的：
    ll ans = 0;
	for(int i = 0; i < (1 << n); i++){
		ans += f[n][m][i];
	}
	
	cout << ans;
	*/
	return 0;
}