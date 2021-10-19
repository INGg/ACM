// Problem: ★★飞马分隔符★★
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/16520/F
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

const int N = 1e5 + 10;

#define ull unsigned long long
const int ull base = 131; // 一般选一个1w左右的数，这个随便

char s[N];
ull h[N]; // 存哈希值，h[i]表示字符串第i个的前缀的值
ull bit[N]; //
ull feima[25];

void init(){
	bit[0] = 1;
	for(int i = 1; i <= N; i++){
		bit[i] = bit[i - 1] * base; // 存base的i次方
	}
}

void hax(){
	int l = strlen(s + 1);
	for(int i = 1; i <= l; i++){
		h[i] = h[i - 1] * base + s[i];
	}
}

ull get(int l, int r){
	return h[r] - h[l - 1] * bit[r - l + 1];
}

void feima_hax(){
	char f[] = {0, 'F','e', 'i', 'M', 'a'};
	for(int i = 1; i <= 5; i++){
		feima[i] = feima[i - 1] * base + f[i];
	}
}

ull get_f(){
	return feima[5] - feima[0] * bit[5 - 1 + 1];
} 

int T;
int n;

int main(){
	init();
	feima_hax();
	cin >> T;
	while(T--){
		cin >> n;
		
		memset(s, 0, sizeof(s));
		scanf("%s", s + 1);
		
		hax();
		
		int ans = 0;
		
		for(int i = 1; i <= n - 4; i++){
			if(s[i] == 'F'){
				int j = i + 4;
				if(get(i, j) == get_f()){
					ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	re 0;
}