// Problem: 第 K 个数字
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/14301
// Memory Limit: 131072 MB
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

int T;
int n, k, m;
int a[100000 + 10];

int main(){
	cin >> T;
	while(T--){
		cin >> n >> k >> m;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		nth_element(a + 1, a + m, a + 1 + n);
		cout << *(a + m) << Endl;
	}
	re 0;
}