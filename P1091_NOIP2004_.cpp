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

const int N = 100 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int a[N];
int f[N];
int g[N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        f[i] = 1;
        for (int j = 1; j < i; j++){
            if(a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        }
    }

    reverse(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++){
        g[i] = 1;
        for (int j = 1; j < i; j++){
            if(a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, f[i] + g[n - i + 1] - 1);
    }

    cout << n - ans;
}