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

const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int k;
char s[600];

bool vis[N]; // 判断这个数是不是质数
int cnt_prime;
int primes[N];

void init(){
 	for(int i = 2; i <= 1000; i++){
        if(!vis[i]){
            primes[cnt_prime++] = i;
        }
        for(int j = 0; primes[j] <= 1000 / i; j++){
            vis[i * primes[j]] = 1;
            if(i % primes[j] == 0) break; // 意味着primes[j]一定是i的最小质因子
        }
    }   
}

void solve(){
    cin >> k;
    scanf("%s", s + 1);
    
    for (int i = 1; i <= k; i++){
        if(vis[s[i] - '0']){
            cout << 1 << endl;
            cout << s[i] - '0' << endl;
            return;
        }
    }

    for (int i = 1; i <= k; i ++){
        for (int j = i + 1; j <= k; j++){
            int x = (s[i] - '0') * 10 + s[j] - '0';
            if(vis[x]){
                cout << 2 << endl;
                cout << x << endl;
                return;
            }
        }
    }
}

int main(){
    init();
    vis[1] = 1;
    cin >> T;
    while(T--){
        solve();
    }
}