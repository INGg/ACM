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
int n;
int a[N];
int backup[N];
int st[N][3];

void debug(){
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << Endl;
}

void work(int l, int r, int d){
    vector<int> v1;
    for (int i = l + d; i <= r; i++)
        v1.pb(a[i]);
    for (int i = l; i < l + d; i++)
        v1.pb(a[i]);
    for (int i = 0; i < v1.size(); i++){
        a[l++] = v1[i];
    }
}

void slove(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    memcpy(backup, a, sizeof(a));
    sort(backup + 1, backup + 1 + n);

    int cnt = 0;

    for (int i = 1; i <= n; i++){
        if(backup[i] == a[i])
            continue;
        for (int j = i + 1; j <= n; j++){
            if(backup[i] == a[j]){
                // cout << i << ' ' << n << " " << j - i << endl;
                st[cnt][0] = i;
                st[cnt][1] = n;
                st[cnt][2] = j - i;

                work(i, n, j - i);

                cnt++;
                break;
            }
        }
        // debug();
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++){
        for (int j = 0; j < 3; j++){
            cout << st[i][j] << " ";
        }
        cout << endl;
    }
    // debug();
}

int main(){
    cin >> T;
    while(T--)
        slove();
}
