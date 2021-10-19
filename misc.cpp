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

const int N = 1e5 + 10;
const ll mod = 1435756429;

ll n, k;
ll b[N];
ll f[N];
ll res;

void work() {
    memset(b, 0, sizeof(b));
    memset(f, 0, sizeof(f));
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        b[x] = 1;
    }

    f[0] = 1;
    if (!b[1] && b[2] && b[3]) {
        f[1] = 1;
    }
    if (b[1] && !b[2] && b[3]) {
        f[2] = 1;
    }
    if (b[1] && b[2] && !b[3]) {
        f[3] = 1;
    }
    if (!b[1] && !b[2] && b[3]) {
        f[1] = 1;
        f[2] = 2;
    }
    if (!b[1] && b[2] && !b[3]) {
        f[1] = 1;
        f[3] = 2;
    }
    if (b[1] && !b[2] && !b[3]) {
        f[2] = 1;
        f[3] = 2;
    }
    if (!b[1] && !b[2] && !b[3]) {
        f[1] = 1;
        f[2] = 2;
        f[3] = 4;
    }

    for (int i = 4; i <= n; i++) {
        if(!b[i])
            f[i] = (((!b[i - 1]) * f[i - 1]) % mod + ((!b[i - 2]) * f[i - 2]) % mod + ((!b[i - 3]) * f[i - 3]) % mod) % mod;
    }
    // re 0;
    res = (res + f[n]) % mod;
    printf("0xGame{%lld}", res);
}

int main(){
    for (int i = 1; i <= 10; i++)
        work();
}