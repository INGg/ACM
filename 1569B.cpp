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
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define re return
#define pb push_back
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 50 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
char a[N];
char s[N][N];

void solve(){
	cin >> n;
	scanf("%s", a + 1);
	memset(s, '=', sizeof(s));
	queue<int> q;
	int two = 0;
	for (int i = 1; i <= n; i++){
		if(a[i] == '2'){
			two++;
			q.push(i);
		}
	}

	q.push(q.front());
	q.pop();

	if(two < 3 && two != 0){
		cout << "NO" << Endl;
		return;
	}

	for (int i = 1; i <= n; i++){
		if(a[i] == '1'){
			for (int x = 1; x <= n; x++){
				if(x != i){
					s[i][x] = s[x][i] = '=';
				}
			}
		}
		else{
			int id = q.front();
			s[i][id] = '+';
			s[id][i] = '-';
			q.pop();
		}
	}

	cout << "YES" << Endl;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if(i == j)
				cout << 'X';
			else
				cout << s[i][j];
		}
		cout << endl;
	}
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}