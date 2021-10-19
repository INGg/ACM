// Problem: E1. Erase and Extend (Easy Version)
// Contest: Codeforces - Codeforces Round #726 (Div. 2)
// URL: https://codeforces.com/contest/1537/problem/E1
// Memory Limit: 256 MB
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

int n, k;
char s[6000];

int main(){
	cin >> n >> k;
	scanf("%s", s);
	int minn = min(n, k);
	int id = n + 1;
	for(int i = minn - 1; i >= 1; i--){
		if(n % (i) == 0 && k % i == 0){
			cout << i << endl;
			if(s[0] < s[i - 1]){
				
				id = i;
				break;
			}
		}
	}
	
	// cout << id << endl;
	
	for(int i = 1, j = 0; i <= k; i ++, j = (j + 1) % (id)){
		cout << s[j];
	}
	
	return 0;
}