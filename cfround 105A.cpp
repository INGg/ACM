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
string s;
int t[55];

bool check(int l){
    int cnt = 0;
    for (int i = 0; i < l; i++){
        if(!t[i])
            cnt++;
        else{
            if(!cnt)
                return false;
            else{
                cnt--;
            }
        }
    }
    if (cnt != 0)
        return 0;
    return 1;
}

int main(){
    cin >> T;
    while(T--){
        cin >> s;
        int l = s.size();
        int flag = 0;
        for (int a = 0; a <= 1; a++){ // 0代表左括号，1代表右括号
            for (int b = 0; b <= 1; b++){
                for (int c = 0; c <= 1; c++){
                    
                    for (int i = 0; i < l; i++){
                        if(s[i] == 'A')
                            t[i] = a;
                        if(s[i] == 'B')
                            t[i] = b;
                        if(s[i] == 'C')
                            t[i] = c;
                    }
                    flag |= check(l);
                }
            }
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    re 0;
}