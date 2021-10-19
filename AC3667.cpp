// Problem: 数组补全
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3667/
// Memory Limit: 256 MB
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

int n, k, p, x, y;

int main(){
	cin >> n >> k >> p >> x >> y;
	
	int summ = 0;
	int a = 0;
	int b = 0;
	
	for(int i = 1; i <= k; i++){
		int xx;
		cin >> xx;
		summ += xx;
		if(xx >= y){
			b++;
		}
		else{
			a++;
		}
	}
	
	if(a > n / 2){
		cout << -1 << endl;
		return 0;
	}
	
	summ += (n / 2 - a) + (n / 2 + 1 - b) * y;
	
	if(summ > x){
		cout << -1 << endl;
		return 0;
	}
	else{
		for(int i = 1; i <= n / 2 - a; i++){
			cout << 1 << " ";
		}
		for(int i = 1; i <= n / 2 + 1 - b; i++){
			cout << y << " ";
		}
	}
	return 0;
}