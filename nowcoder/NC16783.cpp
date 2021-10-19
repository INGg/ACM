// Problem: [NOIP1998]拼数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/problem/16783
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
string num[55];

bool cmp(string a, string b){
	return a + b > b + a;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	
	sort(num + 1, num + 1 + n, cmp);
	
	for(int i = 1; i <= n; i++){
		cout << num[i];
	}
}