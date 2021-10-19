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

using namespace std;

int chu[100000 + 10];
// int d[100000 + 5][100000 + 5];
vector<vector<int>> d ;
queue<int> q;

int main(){
	
	int n;
	cin >> n;
	int start = 0;

	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x;
			vector<int> v;
			cin >> x;
			v.push_back(x);
			d.push_back(v);
			chu[x]++;
		}
	}
	
	for(int i = 1; i<= n; i++){
		if(!chu[i]){
			start = i;
			break;
		}
	}
	
	q.push(start);
	int zhong = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		// cout << d[now].size() << endl;
		int l = d[now].size();
		for (int i = 0; i < l; i++)
		{
			q.push(d[now][i]);
			zhong = d[now][i];
		}
	}
	cout << zhong;
}