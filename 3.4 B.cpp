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

int n;
string s;
int num[26];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s;
        num[s[0] - 'a']++;
    }

    int x = 0;

    for (int i = 0; i < 26; i++){
        int a = num[i] / 2;
        int b = num[i] - a;
        x += (b * (b - 1) / 2) + (a * (a - 1) / 2);
    }

    cout << x;
    re 0;
}