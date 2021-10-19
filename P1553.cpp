#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

string s;
stringstream str;

int main(){
    #define int unsigned long long
    cin >> s;
    if(s.find(".") != -1){
        int a;
        int b;
        s[s.find(".")] = ' ';
        str << s;
        str >> a >> b;
        int aa = 0;
        int bb = 0;
        while(a){
            aa = aa * 10 + a % 10;
            a /= 10;
        }
        while(b){
            bb = bb * 10 + b % 10;
            b /= 10;
        }
        printf("%lld.%lld", aa, bb);
    }
    else if(s.find('/') != -1){
        int a;
        int b;
        s[s.find("/")] = ' ';
        str << s;
        str >> a >> b;
        int aa = 0;
        int bb = 0;
        while(a){
            aa = aa * 10 + a % 10;
            a /= 10;
        }
        while(b){
            bb = bb * 10 + b % 10;
            b /= 10;
        }
        printf("%lld/%lld", aa, bb);
    }
    else if(s.find('%') != -1){
        int a;
        s[s.find("%")] = ' ';
        str << s;
        str >> a;
        int aa = 0;
        while(a){
            aa = aa * 10 + a % 10;
            a /= 10;
        }
        printf("%lld%%", aa);
    }
    else{
        int a;
        str << s;
        str >> a;
        int aa = 0;
        while(a){
            aa = aa * 10 + a % 10;
            a /= 10;
        }
        printf("%lld", aa);
    }
    return 0;
}