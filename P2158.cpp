// Problem: P2158 [SDOI2008]仪仗队
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2158
// Memory Limit: 125 MB
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

const int N = 4e4 + 10;

int n;
int cnt_prime;
int prime[N];
ll phi[N];
bool vis[N];

void get_phi(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!vis[i]){
            prime[cnt_prime++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; prime[j] <= n / i; j++){
            vis[prime[j] * i] = 1;
            if(i % prime[j] == 0){
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}

int main(){
	cin >> n;
	
	if(n == 1){
		cout << 0;
		return 0;
	}
	
	get_phi(n);
	
	ll res = 0;
	for(int i = 2; i < n; i++) res += phi[i]; // 因为坐标下标是从0开始的，最大的坐标是5
	cout << res * 2 + 3;
}