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

struct nope{
	int id;
	int x;
} a[1000 + 10];

int n;

bool cmp(nope a, nope b){
	return a.x < b.x;
}

int main(){
	cin >> n;
	
	int cnt = 0;
	
	for(int i = 1; i <= n; i++){
		int c;
		cin >> c;
		for(int j = 1; j <= c; j++){
			int x;
			cin >> x;
			a[++cnt].x = x;
			a[cnt].id = i;
		}
	}
	
	// cout << cnt << Endl;
	
	sort(a + 1, a + 1 + cnt, cmp);

	// for(int i = 1; i <= cnt; i++){
		// cout << a[i].x << " ";
	// }
	
	// cout << endl;
	
	for(int i = 1; i <= cnt; i++){
		cout << (char)(a[i].id - 1 + 'A');
	}
}