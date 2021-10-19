#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, r;
int s[5000 + 10][5000 + 10]; // 前缀和数组

int w;
int x, y;
int mx, my;

int main(){
    cin >> n >> r;
    r = min(5001, r); //仔细观察r给的数据范围，是比5000大得多的；如果比5000还大的话，实际上是没有意义的，所以最大取到5001就可以；直接取5000是没意义的，因为这个题目轰炸的特性导致他如果取5000的话，边上的一圈是不能被覆盖掉的
    mx = my = r;
    while(n--){
        cin >> x >> y >> w;
        x++;
        y++;
        s[x][y] += w;
        mx = max(mx, x);
        my = max(my, y);
    }

    for (int i = 1; i <= mx; i++){
        for (int j = 1; j <= my; j++){
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = r; i <= mx; i++){
        for (int j = r; j <= my; j++){
            ans = max(ans, s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
        }
    }
    cout << ans;
    return 0;
}