#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long

using namespace std;

int n;
ll x[100000 + 10];
ll y[100000 + 10];

//离原点最远的那个点
//y = -x + b
// b = y + x = ans

long double len(ll x, ll y){
    return (sqrt(x * x + y * y));
}

int main(){
    scanf("%d", &n);
    // int l = 1000000000 + 10;
    // int r = 0;
    // int top = -1;
    // ll mx = -1;
    // ll my = -1;
    // long double maxx = -1;
    ll ans = -1;
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld", x + i, y + i);
        ans = max(x[i] + y[i], ans);
    }

    // cout << mx <<
    cout << ans << endl;
    return 0;
}