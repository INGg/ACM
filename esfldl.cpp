#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#define ll unsigned long long
#define re return

using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        ll n;
        ll summ = 0;
        int h;
        cin >> n;
        int t = 0;
        for (ll i = 1; i <= n; i++){
            scanf("%d", &h);
            summ += h;
            if(summ < i * (i - 1) / 2){
                t = 1;
            }
        }
        if(t)
            printf("NO\n");
        else
            printf("YES\n");
    }
}

// 999999997
// 999999998
// 999999999
// 1000000000

// 3999999994
// 4000000000