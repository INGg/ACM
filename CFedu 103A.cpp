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

int main(){
    int t;
    cin >> t;
    ll n = 4, k = 10;
    while(t--){
        cin >> n >> k;
        if(n <= k){
            if(k % n == 0){
                cout << k / n << endl;
            }
            else{
                cout << k / n + 1 << endl;
            }
        }
        else{
            if(n % k == 0){
                cout << 1 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }
    }
    re 0;
}