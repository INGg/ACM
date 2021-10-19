#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#define ll long long
#define re return

using namespace std;

#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long

int chu[100000 + 10];
int d[100000 + 10][100000 + 10];

int main(){
	queue<int> q;
	int n;
	cin >> n;
	int start = 0;

	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> d[i][j];
			chu[d[i][j]]++;
		}
	}
	
	for(int i = 1; i<= n; i++){
		if(!chu[i]){
			start = i;
			break;
		}
	}
	
	q.push(start);
	for(int i = 1; i <= n; i++){
		int j = 1;
		int next = q.front();
		q.pop();
		while(d[next][j++]){
			q.push(d[next][j]);
		}
	}
	cout << q.front();
    re 0;
}