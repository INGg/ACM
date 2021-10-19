// Problem: 最大分数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3796/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-05 21:58:52

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
int n, m;
int a[110];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		
		memset(a, 0, sizeof(a));
		
		int summ = 0;
		int cnt = 0;
		
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			if(x < 0) a[cnt++] = -x;
		}
		
		sort(a, a + cnt, cmp);
		
		for(int i = 0; i < m; i++){
			summ += a[i];
		}
		
		
		cout << summ << endl;
	}
}