#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>

using namespace std;

int num[128];

string txt;

int main(){
    getline(cin, txt);
    num['a'] = num['d'] = num['g'] = num['j'] = num['m'] = num['p'] = num['t'] = num['w'] = 1;
    num['b'] = num['e'] = num['h'] = num['k'] = num['n'] = num['q'] = num['u'] = num['x'] = 2;
    num['c'] = num['f'] = num['i'] = num['l'] = num['o'] = num['r'] = num['v'] = num['y'] = 3;
    num['s'] = num['z'] = 4;
    num[' '] = 1;
    int ans = 0;
    for (int i = 0; i < txt.size(); i++){
        ans += num[txt[i]];
    }
    cout << ans;
    return 0;
}