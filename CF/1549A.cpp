// Problem: A. Gregor and Cryptography
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-08-01 22:38:44

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

const int N = 1e9 + 7;

int T;
int p; 

int main(){
	cin >> T;
	while(T--){
		cin >> p;
		// if(2 != p / 2)
			// cout << 2 << " " << p / 2 << endl;
		// else{
			cout << 2 << " " << p / 2 * 2 << endl;
		// }
	}
	return 0;
}