#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define ll long long
#define re return

using namespace std;

int n;
int T;

struct nope
{
    ll a;
    ll b;
    ll id;
}x[200000 + 10];
ll sumb[200000 + 10];

// int a[200000 + 10];
// int b[200000 + 10];

bool cmp(nope a, nope b){
    re a.a < b.a;
    re a.b < b.b;
}

void debug(){
    for (int i = 1; i <= n; i++){
        printf("%lld a: %lld b: %lld\n", x[i].id, x[i].a, x[i].b);
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            scanf("%lld", &x[i].a);
            x[i].id = i;
        }
        for (int i = 1; i <= n; i++){
            scanf("%lld", &x[i].b);
        }
        sort(x + 1, x + 1 + n, cmp);
        // debug();
        ll sa = 0;
        ll sb = 0;
        for (int i = 1; i <= n; i++){
            sumb[i] = sumb[i - 1] + x[i].b;
        }
        ll ans = sumb[n];
        for (int i = 1; i <= n; i++){
            sa = max(x[i].a, sa);
            sb = sumb[n] - sumb[i];
            ans = min(max(sa, sb), ans);
        }
            cout << ans << endl;
    }
    re 0;
}