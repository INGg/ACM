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

int T;
int m;
int a[3][N];
int s1[N];
int s2[N];

int main(){
    cin >> T;
    while(T--){
        memset(a, 0, sizeof(a));
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));

        cin >> m;
        for (int i = 1; i <= m; i++){
            cin >> a[1][i];
            s1[i] = s1[i - 1] + a[1][i];
        }

        for (int i = 1; i <= m; i++){
            cin >> a[2][i];
            s2[i] = s2[i - 1] + a[2][i];
        }

        // cout << s2[m - 1] << " " << s1[m] - s1[1] << endl;
        // int bob = max(s2[m - 1], s1[m] - s1[1]);
        int bob = 1e9 + 10;
        // cout << bob << endl;

        for (int i = 1; i <= m; i++){
            int ans1 = s1[m] - s1[i];
            int ans2 = s2[i - 1];
            cout << ans1 << " " << ans2 << endl;
// 
            bob = min(bob, max(ans1, ans2));
        }

        cout << bob << endl;
    }
}