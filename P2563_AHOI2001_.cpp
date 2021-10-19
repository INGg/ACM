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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
ll f[250];
vector<int> primes;

void init(){
    for (int i = 2; i <= 200; i++){
        int flag = 1;
        for (int j = 2; j <= i / j; j++){
             if(i % j == 0){
                 flag = 0;
                 break;
             }
        }
        if(flag)
            primes.pb(i);
    }
}

void solve(){
    // memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < primes.size(); i++){
        for (int j = primes[i]; j <= 200; j++){
            f[j] += f[j - primes[i]];
        }
    }
}

int main(){
    init();
    solve();
    while(cin >> n)
        cout << f[n] << endl;
}