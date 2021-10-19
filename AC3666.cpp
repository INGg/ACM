// Problem: 打印数字菱形
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3666/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
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

int main(){
	int n;
	cin >> n;
	int x = n * 2;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= x; j++){
			cout << " ";
		}
		x -= 2;
		if(i == 1){
			cout << 0 << endl;
			for(int j = 1; j <= x; j++){
				cout << " ";
			}
			x -= 2;
		}
		for(int j = 0; j <= i; j++){
			cout << j << " ";
		}
		for(int j = i - 1; j >= 0; j--){
			cout << j << " ";
		}
		cout << Endl;
	}
	
	x = 2;
	for(int i = n - 1; i >= 1; i--){
		for(int j = 1; j <= x; j++){
			cout << " ";
		}
		x += 2;
		// if(i == 1){
			// cout << 0 << endl;
			// for(int j = 1; j <= x; j++){
				// cout << " ";
			// }
			// x -= 2;
		// }
		for(int j = 0; j <= i; j++){
			cout << j << " ";
		}
		for(int j = i - 1; j >= 0; j--){
			cout << j << " ";
		}
		cout << Endl;
	}
	for(int i = 1; i <= x; i++){
		cout << " ";
	}
	cout << 0;
	re 0;
}