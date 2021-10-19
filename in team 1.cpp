#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

ll a[7];
ll summ[7]; //前缀和
ll ans = 0;

bool cmp(int a, int b){
    return a > b;
}

void debug(){
    for (int i = 1; i <= 5; i++){
        cout << a[i] << endl;
    }
    cout << endl;
}

int main(){
    for (int i = 1; i <= 5; i++){
        scanf("%lld", a + i);
    }

    sort(a + 1, a + 6, cmp);
    // debug();
    ans = a[1];
    ll x = ans;

    for (int i = 2; i <= 5; i++){
        if(x - a[i] > 0){
            x -= a[i];
            continue;
        }
        else{
            ans += abs(x - a[i]);
            x = abs(x - a[i]);
            // if(x == 0 && summ[i] <= 1)
            //     break;
            
        }
    }
    // cout << ans << endl;
    cout << ans - x;
    return 0;
}