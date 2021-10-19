// Problem: C. Mocha and Hiking
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-15 22:35:39

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
int a[10010];

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		
		int flag = 1; // 全都是1
		
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(!a[i]) flag = 0;
		}
		
		if(n == 1){
			if(a[1] == 0) cout << "1 2" << endl;
			else cout << "2 1" << endl;
			continue;
		}
		
		if(!a[n]){
			for(int i = 1; i <= n + 1; i++){
				cout << i << " ";
			}
			cout << endl;
		}
		else{
			if(flag){
				cout << n + 1 << " ";
				for(int i = 1; i <= n; i++){
					cout << i << " ";
				}
				cout << Endl;
				continue;
			}
			for(int i = 2; i <= n; i++){
				if(a[i] == 1 && a[i - 1] == 0){
					for(int j = 1; j <= i - 1; j++){
						cout << j << " ";
					}
					cout << n + 1 << " ";
					for(int j = i; j <= n; j++){
						cout << j << " ";
					}
					cout << endl;
					break;
				}
			}
		}
	}
}