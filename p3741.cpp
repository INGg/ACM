#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>

using namespace std;

string s;
int n;

int main(){
    cin >> n >> s;
    // 1 一定是 0
    // 2 一定是 1
    // 3个以上就先找出现在vk有几个，然后再找符合条件：v后面的位置不是k（那就是v）且v不是最后一个
    int ans = 0;
    // if(n == 1){
    //     cout << 0;
    //     return 0;
    // }
    // if(n == 2){
    //     cout << 1;
    //     return 0;
    // }

    int now = s.find("VK");
    while(now != -1){
        s[now] = 'X';
        s[now + 1] = 'X';
        now = s.find("VK", now + 1);
        ans++;
    }
    if(s.find("VV") != -1 || s.find("KK") != -1)
        ans++;

    cout << ans;
    return 0;
}