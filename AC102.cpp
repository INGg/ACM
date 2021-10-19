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
int f;
int a[100000 + 10];
double s[100000 + 10];

bool check(double av){
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i] - av;
	}
	
	double minn = 20000;
	
	for(int i = 0, j = f; j <= n; j++, i++){
		minn = min(minn, s[i]);
		if(s[j] - minn >= 0){
			return 1;
		}
	}
	return 0;
}

int main(){
	cin >> n >> f;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	double l = 1;
	double r = 2000;
	
	while(r - l > 1e-6){
		double mid = (l + r) / 2;
		if(check(mid)){ // 存在一个区间，使得他们的平均值大于等于mid
			l = mid;
		}
		else{
			r = mid;
		}
	}
	
	cout << int(r * 1000);
	
	re 0;
}