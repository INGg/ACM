// Problem: 数组去重
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3806/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-14 19:00:20

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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
int a[55];
int b[55];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		reverse(a + 1, a + 1 + n);
		set<int> s;
		memset(b, 0, sizeof(b));
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(!s.count(a[i])){
				b[i] = a[i];
				cnt++;
				s.insert(a[i]);
			}
		}
		cout << s.size() << endl;
		for(int i = n; i >= 1; i--){
			if(b[i]) cout << b[i] << " ";
		}
		
		cout << endl;
	}
}