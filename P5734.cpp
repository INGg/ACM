#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>

using namespace std;

string s;
int n; // 操作数

int main(){
    cin >> n;
    cin >> s;
    int x;
    string ss;
    for (int i = 1; i <= n; i++){
        cin >> x;
        if(x == 1){
            cin >> ss;
            s += ss;
        }
        if(x == 2){
            int a, b;
            cin >> a >> b;
            s = s.substr(a, b);
        }
        if(x == 3){
            int a;
            string str;
            cin >> a >> str;
            s = s.insert(a, str);
        }
        if(x == 4){
            string str;
            cin >> str;
            cout << (int)s.find(str) << endl;
            continue;
        }
        cout << s << endl;
    }
    return 0;
}