#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>

using namespace std;

string s;
string txt;

int main(){
    cin >> s;
    getchar();
    getline(cin, txt);
    for (int i = 0; i < txt.size(); i++){
        txt[i] = toupper(txt[i]);
    }
    for (int i = 0; i < s.size(); i++){
        s[i] = toupper(s[i]);
    }
    txt = ' ' + txt + ' '; //给文本两端加上空格，方便匹配
    s = ' ' + s + ' '; // 更好的确定单词的定义，两端有空格的中间是字符的字符串
    int ans = 1;
    int now = txt.find(s);
    int first = now;
    if(now == -1){
        cout << -1;
    }
    else{
        while(now != -1){
            ans++;
            now = txt.find(s, now + 1);
        }
        cout << ans - 1 << " " << first;
    }
    return 0;
}