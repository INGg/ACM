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

const int N = 1e3 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int a[N];

int main(){
	cin >> n;

	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}

	ll ans = 0;
	for (int i = 1; i <= n; i += 2){
		ll zuo = a[i];
		ll duo = 0;

		for (int j = i + 1; j <= n; j++){
			if(j & 1){
				duo += a[j];
			}
			else{
				ll tmp = a[j];

				ll x = min(tmp, duo);

				duo -= x;
				tmp -= x;

				if(!duo){
					x = min(zuo, tmp);
					ans += x;
					zuo -= x;
					tmp -= x;

					if(j != i + 1)
						ans++;

					if(tmp)
						break;
				}
			}
		}
	}
	cout << ans;
}