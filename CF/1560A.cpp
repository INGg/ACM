// Problem: A. Dislike of Threes
// Contest: Codeforces - Codeforces Round #739 (Div. 3)
// URL: https://codeforces.com/contest/1560/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-18 22:37:11

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
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define re return
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int k;
vector<int> ans;

int main(){
	for(int i = 1; i <= 100000; i++){
		if(i % 3 != 0 && i % 10 != 3){
			ans.push_back(i);
			// cout << i << endl;
		}
	}
	
	cin >> T;
	while(T--){
		cin >> k;
		cout << ans[k - 1] << endl;
	}
}