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

int n, m;
vector<int> alls; // 存储所有待离散化的值
int f[N];
int d[N];

// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}

void init(){
    for (int i = 1; i <= 10000; i++){
        f[i] = i;
    }
}

int query(int p){
    if(f[p] == p)
        return p;
    else{
        int v = query(f[p]);
        d[p] ^= d[f[p]];
        return v;
    }
}

void merge(int p1, int p2, int ans){
    int f1 = query(p1);
    int f2 = query(p2);

    if(f1 != f2){
        f[f1] = f2;
        d[f1] = d[p1] ^ d[p2] ^ ans;
    }
}

struct nope{
    int l, r, ans;
} a[N];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        char op[5];

        cin >> a[i].l >> a[i].r;
        scanf("%s", op);
        if(op[0] == 'e')
            a[i].ans = 0;
        else
            a[i].ans = 1;
        alls.pb(a[i].l - 1);
        alls.pb(a[i].r);
    }

    sort(alls.begin(), alls.end());                           // 将所有值排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end()); // 去掉重复元素

    init();

    for (int i = 1; i <= m; i++){
        int l = find(a[i].l - 1);
        int r = find(a[i].r);

        int fl = query(l);
        int fr = query(r);

        if(fl == fr){
            if((d[l] ^ d[r]) != a[i].ans){
                cout << i - 1;
                return 0;
            }
        }
        else{
            merge(l, r, a[i].ans);
        }
    }

    cout << m;
}