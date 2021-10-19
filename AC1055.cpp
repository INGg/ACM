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

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int a[100000 + 10];

int main(){
	int n;
	cin >> n;
	for(int i =  1; i <= n; i++){
		cin >> a[i];
	}
	
	
	int ans = 0;
	int now = 0;
	int buy = 0;
	int len = 1;
	// int sell = 0;
	// 求一个最长上升子序列的头尾，并且长度大于2，
	for(int i = 2; i <= n + 1; i++){
		if(a[i] > a[i - 1]){
			len++;
			continue;
		}
		if(len <= 1){
			len = 1;
			continue;
		}
		else{
			ans += (a[i - 1] - a[i - len]);
			len = 1;
		}
	}
	cout << ans;
	return 0;
}