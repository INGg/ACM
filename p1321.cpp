#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>

using namespace std;

string s;

int ffind(string str){
    int now = s.find(str); //先来找一遍已经有的boy
    int ans = 0;
    int l = str.size();
    while(now != -1){
        ans++;
        for (int i = 0; i < l; i++){
            s[now + i] = 'X';
        }
        now = s.find(str, now + 1);
    }
    return ans;
}

int main(){
    cin >> s;
    int boy = 0;
    int girl = 0;
    boy += ffind("boy");
    boy += ffind("bo");
    boy += ffind("oy");
    boy += ffind("b");
    boy += ffind("o");
    boy += ffind("y");

    girl += ffind("girl");
    girl += ffind("gir");
    girl += ffind("gi");
    girl += ffind("irl");
    girl += ffind("rl");
    girl += ffind("g");
    girl += ffind("i");
    girl += ffind("r");
    girl += ffind("l");


    cout << boy << endl
         << girl;
    return 0;
}