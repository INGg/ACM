#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int T;

int get_time(){
    string s;
    getline(cin, s);
    int day = 0;
    int h1, m1, s1, h2, m2, s2;
    if(s.back() != ')')
        sscanf(s.c_str(), "%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
    else
        sscanf(s.c_str(),"%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &day);
    return h2 * 3600 + m2 * 60 + s2 - (h1 * 3600 + m1 * 60 + s1) + day * 24 * 3600;
}

int main(){
    cin >> T;
    char c = getchar();
    while(T--){
        int ans = (get_time() + get_time()) / 2;
        int h = ans / 3600;
        int m = ans % 3600 / 60;
        int se = ans % 60;
        printf("%02d:%02d:%02d\n", h, m, se);
    }
    return 0;
}