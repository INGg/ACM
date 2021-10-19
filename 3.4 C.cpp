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

char yuan[5][5] = {
    {'a', 'e', 'i', 'o', 'u'},
    {'e', 'i', 'o', 'u', 'a'},
    {'i', 'o', 'u', 'a', 'e'},
    {'o', 'u', 'a', 'e', 'i'},
    {'u', 'a', 'e', 'i', 'o'}};
// char c = 'a';
int k;
string s;
char ans[10005][10005];

int main(){
    cin >> k;
    if (k < 25){
        cout << -1;
        re 0;
    }
    for (int i = 5; i <= sqrt(k); i++){
        // cout << i << endl;
        if(k / i * i == k){
            for (int h = 1; h <= i; h++){
                for (int l = 1; l <= k / i; l++){
                    // cout << (h - 1) % 5 << " " << (l - 1) % 5 << endl;
                    ans[h][l] = yuan[(h - 1) % 5][(l - 1) % 5];
                }
            }

            for (int h = 1; h <= i; h++){
                for (int l = 1; l <= k / i; l++){
                    // cout << ans[h][l] << " ";
                    s += ans[h][l];
                }
                // cout << endl;
            }
            cout << s;
            re 0;
        }
    }
    cout << -1;
    re 0;
}