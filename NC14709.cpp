// Problem: 奇♂妙拆分
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/14709
// Memory Limit: 65536 MB
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

int fenjie(int n){
	int cnt = 1;
	for(int i = 1; i < n / i; i++){
		if(n % i == 0){
			n /= i;
			cnt++;
		}
	}
	
	return cnt;
}

int T;
int n;

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		cout << fenjie(n) << endl;
	}
	re 0;
}