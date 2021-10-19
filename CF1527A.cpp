// Problem: A. And Then There Were K
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/0
// Memory Limit: 256 MB
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

int T;
int bit[40];
int main(){
	cin >> T;
	bit[0] = 1;
	for(int i = 1; i < 31; i++){
		bit[i] = (bit[i - 1] << 1) + 1;
	}
	// cout << bit[1] << endl;
	while(T--){
		int n;
		cin >> n;
		int i;
		if(n == 1){
			cout << 0 << endl;
			continue;
		}
		for(i = 0; i < 31; i++){
			if(bit[i] >= n){
				break;
			}
		}
		cout << bit[i - 1] << endl;
	}
	re 0;
}