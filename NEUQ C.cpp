#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#define ll long long
#define re return

using namespace std;

ll make(ll n){
    return (n * (n + 1)) / 2;
}

int main(){
    int n;
    ll ans = 0;
    ll a[100000 + 10];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll dp[100000 + 10];
    memset(dp, 0, sizeof(dp));
    a[n + 1] = -1;
    for (int i = 1; i <= n + 1; i++){
        if(a[i] >= a[i - 1]){
            dp[i] = dp[i - 1] + 1;
        }
        else{
            ans += make(dp[i - 1]);
            dp[i] = 1;
        }   
    }
    cout << ans;
    re 0;
}