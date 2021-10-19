// Problem: 宠物小精灵之收服
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/1024/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Code by: ING__
// 
// Edited on 2021-07-24 17:50:14

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

const int N = 1010;

int n, m1, m2;
int v1[N];
int v2[N];
int f[1010][510];

int main(){
	cin >> m1 >> m2 >> n; // 小智的精灵球数量、皮卡丘初始的体力值、野生小精灵的数量
	for(int i = 1; i <= n; i++){
		cin >> v1[i] >> v2[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m1; j >= v1[i]; j--){
			for(int k = m2 - 1; k >= v2[i]; k--){ // 皮卡丘的体力不能小于1，所以不能全花费
				f[j][k] = max(f[j][k], f[j - v1[i]][k - v2[i]] + 1);
			}
		}
	}
	
	cout << f[m1][m2 - 1] << " ";
	
	int k = m2 - 1;
	while(k > 0 && f[m1][k - 1] == f[m1][m2 - 1]) k--; // 如果下一个成立我们就减
	
	cout << m2 - k;
	
	return 0;
}