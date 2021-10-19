#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define ll long long
#define re return

const int N = 1 << 16;

//飞行员兄弟

using namespace std;

typedef pair<int, int> PII; 

//所有把手
//- 打开 +关闭
char a[10][10];
char bakeup[10][10];

int xia_biao(int x,int y){
    return x + y * 4;
}

void turn_one(int x,int y){
    if(a[x][y] == '-')
        a[x][y] = '+';
    else
        a[x][y] = '-';
}

void turn_all(int x, int y){
    for (int i = 0; i < 4; i++){
        turn_one(x, i);
        turn_one(i, y);
    }
    turn_one(x, y);
}

int main(){

    vector<PII> ans;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cin >> a[i][j];
        }
    }

    memcpy(bakeup, a, sizeof(a));

    for (int num = 0; num < N; num++){ // 方案数

        vector<PII> cnt;
        

        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if(num & 1 << xia_biao(i, j)){ //子集枚举
                    turn_all(i, j);
                    cnt.push_back({i, j});
                }
            }
        }

        bool t = 0;
        for (int i = 0; i < 4; i ++){
            for (int j = 0; j < 4; j++){
                if(a[i][j] == '+'){
                    t = 1;
                    break;
                }
            }
        }

        if(!t){
            if(ans.empty() || ans.size() > cnt.size())
                ans = cnt;
        }

        memcpy(a, bakeup, sizeof(bakeup));
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size();i++){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
    re 0;
}