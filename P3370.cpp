// Problem: P3370 【模板】字符串哈希
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3370
// Memory Limit: 125 MB
// Time Limit: 500 ms
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
#define ull unsigned long long
using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

const int ull base = 131; // 一般选一个1w左右的数，这个随便
const int N = 10000 + 10;

int n;
ull h[N];

ull ha(char s[]){
	ull ans = 0;
	int l = strlen(s + 1);
	for(int i = 1; i <= l; i++){
		ans = ans * base + s[i];
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		char s[1510];
		scanf("%s", s + 1);
		h[i] = ha(s);
	}
	
	sort(h + 1, h + 1 + n);
	
	int ans = 1;
	for(int i = 2; i <= n; i++){
		if(h[i] != h[i - 1]){
			ans ++;
		}
	}
	
	cout << ans;
	
	return 0;
}