#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 32;

using namespace std;

char a[10][10], bakeup[10][10];
int n;

int bian(char n){
    if(n == '0')
        return '1';
    else
        return '0';
}

void turn(int x, int y){
    bakeup[x][y] = bian(bakeup[x][y]);
    bakeup[x - 1][y] = bian(bakeup[x - 1][y]);
    bakeup[x + 1][y] = bian(bakeup[x + 1][y]);
    bakeup[x][y + 1] = bian(bakeup[x][y + 1]);
    bakeup[x][y - 1] = bian(bakeup[x][y - 1]);
}

void debug(){
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5; j++){
            cout << bakeup[i][j] << " ";
        }
        cout << endl;
    }
}

void work(){
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }
    
    // int t = 0;
    int ans = 100;

    for (int i = 0; i < N; i++){ // 枚举第一行的可能

        int cnt = 0;
        memcpy(bakeup, a, sizeof(a));

        // debug();

        for (int j = 0; j < 5; j++){ //第一行的每一个操不操作
            if(i & (1 << j)){ //判断是不是第一行的方案数的二进制表示的每一位是不是该操作
                turn(1, j + 1); //下标是从1开始的，但是方案数的下标是从0开始的，要加1
                cnt++;
            }
        }

        for (int j = 2; j <= 5; j++){
            for (int k = 1; k <= 5; k++){
                if(bakeup[j - 1][k] == '0'){
                    turn(j, k);
                    // debug();
                    cnt++;
                }
            }
        }

        int t = 0;
        for (int j = 1; j <= 5; j++){
            if(bakeup[5][j] == '0'){
                t = 1;
                break;
            }
        }

        // debug();
        // cout << endl;

        if(!t)
            ans = min(ans, cnt);
    }
    // qwq???
    // 我不是，我是菜鸡

    if(ans > 6)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}

int main(){
    cin >> n;
    while(n--){
        work();
    }
    return 0;
}