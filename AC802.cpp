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

vector<int> alls;

int find(int x) // 找到第一个大于等于x的位置
{
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}

struct nope{
	int l;
	int r;
}o[300000 + 10];

struct node{
	int x;
	int c;
}add[300000 + 10];

int a[300000 + 10];
int s[300000 + 10];
int n, m;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> add[i].x >> add[i].c;
		alls.push_back(add[i].x);
	}
	
	for(int i = 1; i <= m; i++){
		cin >> o[i].l >> o[i].r;
		alls.push_back(o[i].l);
		alls.push_back(o[i].r);
	}
	
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	for(int i = 1; i <= n; i++){
		int x = find(add[i].x);
		a[x] += add[i].c;
	}
	
	for(int i = 1; i <= alls.size(); i++){
		s[i] = s[i - 1] + a[i];
	}
	
	for(int i = 1; i <= m; i++){
		int l = find(o[i].l);
		int r = find(o[i].r);
		
		cout << s[r] - s[l - 1] << endl;
	}
	re 0;
}