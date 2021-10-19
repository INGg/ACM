// Problem: D. Diane
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-01 13:58:37

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

const int N = 1e5 + 10;

int T;
int n;

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		if(n == 1){
			cout << (char)'a' << endl;
		}
		else{
			for(int i = 1; i <= n / 2; i ++){
				cout << (char)'a';
			}
			if(n % 2 == 0){
				cout << (char)'b';
				for(int i = n / 2 + 2; i <= n; i++){
					cout << (char)'a';
				}
				cout << endl;
			}
			else{
				cout << "bc";
				for(int i = n / 2 + 3; i <= n; i++){
					cout << (char)'a';
				}
				cout << endl;
			}
		}
	}
	return 0;
}