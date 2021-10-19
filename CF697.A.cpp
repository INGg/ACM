#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#define ll unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;
    ll n;
    while(t--){
        scanf("%lld", &n);
        if ((int)log2(n) == log2(n)){ //质因数分解，每个数都能质因数分解，如果这个数分解出来只能为2的幂次，那他肯定不符合题意
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}