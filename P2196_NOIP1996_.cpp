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

const int N = 20 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int w[N];
int f[N];
int g[N][N];
int pre[N];
int ans;
int e;

void print(int s){
    if(pre[s] == 0){
        printf("%d", s);
        return;
    }
    print(pre[s]);
    printf(" %d", s);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }

    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(g[j][i] && f[j] > f[i]){
                f[i] = max(f[i], f[j]);
                pre[i] = j;
            }
        }

        f[i] += w[i];
        if(ans < f[i]){
            ans = f[i];
            e = i;
        }
    }
    print(e);
    cout << endl << ans;
}