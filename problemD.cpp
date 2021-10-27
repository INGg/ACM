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
double n;
double p1, v1, p2, v2;
double eps = 1e-8;

void solve(){
    cin >> n >> p1 >> v1 >> p2 >> v2;

    double ans = 1e18;
    double time = 1e18;

    if(p1 > p2){
        swap(p1, p2);
        swap(v1, v2);
    }

    //p1往右，p2往左
    ans = min(ans, max((n - p1) / v1, p2 / v2));

    // p1单独走两个方向
    ans = min(ans, min((p1 + n) / v1, (n - p1 + n) / v1));
    // p2单独走两个方向
    ans = min(ans, min((p2 + n) / v2, (n - p2 + n) / v2));

    double l = p1;
    double r = p2;

    while(r - l > eps){
        double mid = (l + r) / 2.0;

        // p1
        double t1 = min((p1 + mid) / v1, (2.0 * mid - p1) / v1);
        // p2
        double t2 = min((p2 - mid + n - mid) / v2, (n - p2 + n - mid) / v2);

        ans = min(ans, max(t1, t2));

        // 当t1小于t2，说明p1移动的时间可以给p2多腾一点给p2，
        // 或者说，p1完成任务的花费时间少，让他多给p2分担一点使得最后能够整体最优
        if(t1 < t2)
            l = mid;
        else
            r = mid;
    }
    printf("%.10lf\n", ans);
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}