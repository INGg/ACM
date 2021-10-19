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

const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct nope
{
    int x;
    int id;
};

bool cmp(nope a, nope b){
    return a.x < b.x;
}

int T;
int n, k;
nope a[N];
int col[N];
int num[N];
int vis[N];

int main(){
    cin >> T;
    while(T--){
        // memset(s, 0, sizeof(s));
        memset(col, 0, sizeof(col));
        memset(vis, 0, sizeof(vis));
        memset(num, 0, sizeof(num));

        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> a[i].x;
            a[i].id = i;
            num[a[i].x]++;
        }

        int x = 0;
        int cnt = 0;

        for (int i = 1; i <= n; i++){
            if(num[i] >= k)
                cnt++;
            else
                x += num[i];
        }

        cnt += x / k;
        // cout << cnt << endl;

        for (int i = 1; i <= n; i++){
            vis[a[i].x]++;
            if(vis[a[i].x] > k)
                a[i].x = INF;
        }

        sort(a + 1, a + 1 + n, cmp);

        int id = 1;
        for (int i = 1; i <= cnt; i++){
            for (int j = 1; j <= k; j++){
                col[a[id++].id] = j;
            }
        }

        for (int i = 1; i <= n; i++){
            printf("%d%c", col[i], " \n"[i == n]);
        }
    }
}