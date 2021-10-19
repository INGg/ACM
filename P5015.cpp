#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctype.h>

using namespace std;

char s[100];

int main(){
    fgets(s, sizeof(s), stdin);
    int l = strlen(s);
    int ans = 0;
    for (int i = 0; i < l; i++){
        if(isalnum(s[i])){
            ans++;
        }
    }
    cout << ans;
}