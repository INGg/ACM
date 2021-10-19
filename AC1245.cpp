#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>

using namespace std;

int n;
string s;

bool check(int a){
    stringstream ss;
    ss << a;
    ss >> s;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == '2' || s[i] == '0' || s[i] == '1' || s[i] == '9')
            return true;
    }
    return false;
}

int main(){
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if(check(i)){
            ans += i;
        }
    }
    cout << ans;
    return 0;
}