// Problem: 构造字符串
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3807/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-14 19:08:43

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
int n, k;
char a[100000 + 10];
char t[100000 + 10];
bool st[34];

char get_min(){
	for(int i = 0; i < 26; i++){
		if(st[i]) return (char)(i + 'a');
	}
	return -1;
}

char get_next(int t){
	for(int i = t + 1; i < 26; i++){
		if(st[i]) return (char)(i + 'a');
	}
	return -1;
}

int main(){
	cin >> T;
	while(T--){
		cin >> n >> k;
		scanf("%s", a + 1);
		memset(st, 0, sizeof(st));
		
		for(int i = 1; i <= n; i++){
			st[a[i] - 'a'] = 1;
		}
		
		if(k > n){
			char c = get_min();
			for(int i = 1; i <= n; i++){
				cout << a[i];
			}
			for(int i = 1; i <= k - n; i++){
				cout << c;
			}
			cout << endl;
		}
		else{
			for(int i = k; i >= 1; i--){
				char c = get_next(a[i] - 'a');
				if(c != -1){
					t[i] = c;
					for(int j = 1; j <= i - 1; j++){
						t[j] = a[j];
					}
					break;
				}
				t[i] = get_min();
			}
			for(int i = 1; i <= k; i++){
				cout << t[i];
			}
			cout << endl;
		}
	}
}