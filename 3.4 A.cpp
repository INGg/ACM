#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <vector>
#define ll long long
#define re return

using namespace std;

int T;
int a1[110];
int a2[110];

void solve(){
    int n;
    cin >> n;
    int one = 0;
    int two = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == 1) {
            one++;
        }
        else
            two++;
    }
    if(one != 0){
        if(one % 2 == 1){
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    else{
        if(two % 2 == 0){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    
}

int main(){
    cin >> T; 
    while(T--){
        solve();

    }
    re 0;
}