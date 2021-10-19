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

int T;

int main(){
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        int ans = 1;
        string s;
        cin >> s;
        int i = s.find_first_of('*');
        int j;
        while(1){
            j = min(n - 1, i + k);
            for (; i < j && s[j] == '.'; j--);
            if(i == j)
                break;
            ans++;
            i = j;
        }
        cout << ans << endl;
    }
    re 0;
}