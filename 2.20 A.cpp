#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define ll long long
#define re return

using namespace std;

int n;
struct nope{
    int id;
    char face;
} a[200000 + 10];

int main(){
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        a[i + 1].face = s[i];
    }

    for (int i = 1; i <= n; i++){
        cin >> a[i].id;
    }

    int ans = -1;
    for (int i = 1; i < n; i++){
        if(a[i].face == 'R' && a[i + 1].face == 'L'){
            if(ans == -1)
                ans = (a[i + 1].id - a[i].id) / 2;
            ans = min(ans, (a[i + 1].id - a[i].id) / 2);
        }
    }
    cout << ans;
    re 0;
}