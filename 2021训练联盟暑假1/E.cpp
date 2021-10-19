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

ll s, e, k;

const int N = 1e6 + 10;

bool vis[N]; // 判断这个数是不是质数
int cnt_prime;
int primes[N];

void get_prime(int n){
 	for(int i = 2; i <= n; i++){
        if(!vis[i]){
            primes[cnt_prime++] = i;
        }
        for(int j = 0; primes[j] <= n / i; j++){
            vis[i * primes[j]] = 1;
            if(i % primes[j] == 0) break; // 意味着primes[j]一定是i的最小质因子
        }
    }   
}

vector<ll> ans;

int main(){
	cin >> s >> e >> k;
	get_prime(300);
	for (ll i = s; i <= e; i++){
		int flag = 0;
		for (int j = 0; j < cnt_prime; j++){
			// if(i < primes[j])
				// break;
			if(i % primes[j] == 0){
				flag = 1;
				ans.push_back(primes[j]);
				break;
			}
		}
		if(!flag){
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());

	ll res = 0;
	for (int i = 0; i < k; i++){
		res += ans[i];
	}

	cout << res;

	return 0;
}