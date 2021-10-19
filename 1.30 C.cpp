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

bool check(ll k, ll n){ //1 v win
    ll v = 0;
    ll p = 0;
    while(n > 0){
        if(n < k){
            v += n;
            break;
        }
        else{
            v += k;
            n -= k;
        }
        p += n / 10;
        n -= n / 10;
    }
    if(v >= p)
        return 1;
    else
        return 0;
}

int main(){
    ll n;
    scanf("%lld", &n);
    ll l = 1;
    ll r = n;
    
    while(l < r){
        ll mid = (l + r) / 2;
        // cout << 1 << endl;
        if(check(mid, n))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
    re 0;
}