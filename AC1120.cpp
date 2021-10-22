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

const int N = 12;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
int a[N];
int ans = 10;
bool st[N];
int group[N][N];

bool check(int g[], int gn, int v){
    for (int i = 1; i < gn; i++){
        if(__gcd(a[g[i]], v) > 1){
            return 0;
        }
    }
    return 1;
}

// 当前组数、当前组要用的元素编号，用了多少数，从哪开始枚举
void dfs(int gc, int gn, int tn, int start){
    if(gc >= ans)
        return;
    if(tn == n)
        ans = gc;

    int flag = 0;
    for (int i = start; i <= n; i++){
        if(!st[i] && check(group[gc], gn, a[i])){
            st[i] = 1;
            group[gc][gn] = i; // 放下标
            dfs(gc, gn + 1, tn + 1, i + 1);
            st[i] = 0;
            flag  = 1;
        }
    }

    if(!flag){
        dfs(gc + 1, 1, tn, 1);
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dfs(1, 1, 0, 1);

    cout << ans << endl;
}