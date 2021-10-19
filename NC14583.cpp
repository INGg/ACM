// Problem: 糖糖别胡说，我真的不是签到题目
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/14583
// Memory Limit: 262144 MB
// Time Limit: 4000 ms
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
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

// 第 i 秒的时候，第 i 只糖糖就可以消灭掉所有排在他前面的和他不是同一组的且能力值小于他的糖糖

int T;
int n, m;
PII tt[50010];
int d[50010]; // 差分数组

int main(){
	cin >> T;
	while(T--){
		memset(d, 0, sizeof(d));
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> tt[i].x >> tt[i].y;
		}
		
		for(int i = 1; i <= m; i++){
			int x;
			cin >> x;
			d[1] ++;
			d[x + 1] --;
		}
		
		for(int i = 1; i <= n; i++){
			d[i] += d[i - 1];
			tt[i].y += d[i];
		}
		
		int max0 = -1;
		int max1 = -1;
		
		int num = 0;
		
		for(int i = n; i >= 1; i--){
			if(tt[i].x == 1){
				max1 = max(max1, tt[i].y);
			}
			else{
				max0 = max(max0, tt[i].y);
			}
			
			if(tt[i].x == 1 && max0 > tt[i].y) num ++;
			if(tt[i].x == 0 && max1 > tt[i].y) num ++;
		}
		cout << n - num << endl;
	}
	return 0;
}