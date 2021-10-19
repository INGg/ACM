// Problem: [NOIP2006]明明的随机数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/16669
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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
set<int> s;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	
	cout << s.size() << Endl;
	
	for(auto i : s){
		cout << i << " ";
	}
	
	return 0;
}