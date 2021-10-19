#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    string s;
    cin >> s;
    int l = s.size();
    for (int i = 0; i < l; i++){
        cout << (char)toupper(s[i]);
    }
    return 0;
}