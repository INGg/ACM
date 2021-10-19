#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#define ll long long
#define ull unsigned long long

using namespace std;

string cola = "cocacola";
string s;

int main(){
    cin >> s;
    int cnt = 0;

    for (int i = 0; i < s.size(); i++){
        if(s[i] != cola[i])
            cnt++;
    }

    if(cnt & 1)
        cout << (cnt + 1) / 2;
    else
        cout << cnt / 2;
}