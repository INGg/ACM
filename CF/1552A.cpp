// Problem: A. Subsequence Permutation
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-02 17:54:16

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
int n;
char s[50];
char ss[50];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		scanf("%s", s + 1);
		
		
		for(int i = 1; i <= n; i++){
			ss[i] = s[i];
			// cout << ss[i];
		}
		// cout << Endl;
		
		sort(ss + 1, ss + 1 + n);
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(ss[i] != s[i]){
				ans ++;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}