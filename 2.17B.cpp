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

ll a, b, x, y;

int main(){
    cin >> a >> b >> x >> y;
    ll g = __gcd(x, y);
    x = x / g;
    y = y / g;
    ll ans = min(a / x, b / y);
    // while (w <= a && h <= b){
    //     ans++;
    //     w = x * i;
    //     h = y * i;
    //     i++;
    // }
    cout << ans;
    re 0;
}