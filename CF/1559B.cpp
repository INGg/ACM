// Problem: B. Mocha and Red and Blue
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-15 22:35:35

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
char a[110];

char zhuan(char c){
	if(c == 'R') return 'B';
	else return 'R';
}

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		scanf("%s", a + 1);
		
		char b[110];
		
		int s = 0;
		
		for(int i = 1; i <= n; i++){
			if(a[i] != '?'){
				s = i;
				break;
			}
		}
		b[s] = a[s];
		for(int i = s - 1; i >= 1; i--){
			b[i] = zhuan(b[i + 1]);
		}
		for(int i = s + 1; i <= n; i++){
			if(a[i] == '?'){
				b[i] = zhuan(b[i - 1]);
			}
			else b[i] = a[i];
		}
		
		for(int i = 1; i <= n; i++){
			cout <<  b[i];
		}
		cout << endl;
	}
}