#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
// #define ll unsigned long long

using namespace std;

int n;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int y = n % 2020;
        int x = (n - y) / 2020 - y;
        // cout << x << endl;
        if(x >= 0){ //如果小于0的话，就说明
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}