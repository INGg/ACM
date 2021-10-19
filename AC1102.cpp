// Problem: 抓住那头牛
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1102/
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

const int N = 2e5 + 10;

int n, k;
int dis[N];

int bfs(){
	queue<int> q;
	q.push(n);
	memset(dis, -1, sizeof(dis));
	dis[n] = 0;
	
	while(!q.empty()){
		int f = q.front();
		q.pop();

		if(f == k) return dis[f];
		
		if(f + 1 < N && dis[f + 1] == -1){
			dis[f + 1] = dis[f] + 1;
			q.push(f + 1);
		}
		
		if(f - 1 > 0 && dis[f - 1] == -1){
			dis[f - 1] = dis[f] + 1;
			q.push(f - 1);
		}
		
		if(f * 2 < N && dis[f * 2] == -1){
			dis[f * 2] = dis[f] + 1;
			q.push(f * 2);
		}
		
	}
}

int main(){
	cin >> n >> k;
	cout << bfs() << endl;
	re 0;
}