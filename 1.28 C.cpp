#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#define ll unsigned long long
#define re return

using namespace std;

typedef pair<int,int>p;

map<p, int> m; //地图

struct nope
{
    int x, y;
}ax[6],bx[6], ay[6],by[6];

bool cmp(nope a, nope b){
    return a.x < b.x;
    // return a.y < b.y;
}

bool cmp1(nope a, nope b){
    return a.y < b.y;
}

int main(){
    // freopen("D.out","w",stdout);
    for (int i = 1; i <= 4; i++){
        cin >> ax[i].x >> ax[i].y;
        ay[i].x = ax[i].x;
        ay[i].y = ax[i].y;
    }

    for (int i = 1; i <= 4; i++){
        cin >> bx[i].x >> bx[i].y;
        by[i].x = bx[i].x;
        by[i].y = bx[i].y;
    }

    // int num1 = abs(a[1].x - a[2].x) + abs(a[1].y - a[2].y);
    // int num2 = sqrt(pow(abs(b[1].x - b[2].x), 2) + pow(abs(b[1].y - b[2].y), 2)) * sqrt(2); //对角线长

    // cout << num1 << " " << num2 << endl;

    sort(ax + 1, ax + 1 + 4, cmp);
    sort(ay + 1, ay + 1 + 4, cmp1);
    for (int i = ax[1].x; i <= ax[3].x; i++){
        for (int j = ay[1].y; j <= ay[3].y; j++){
            m[p(i, j)] = 1;
        }
    }

    sort(bx + 1, bx + 1 + 4, cmp);
    sort(by + 1, by + 1 + 4, cmp1);
    // for (int i = 1; i <= 4; i++){
    //     cout << by[i].x << " " << by[i].y << endl;
    // }

    // cout << endl;

    // for (int i = 1; i <= 4; i++){
    //     cout << bx[i].x << " " << bx[i].y << endl;
    // }

    int cnt = 0;
    int t = 0;
    for (int i = bx[1].x; i <= bx[2].x; i++){
        for (int j = by[2].y - cnt; j <= by[2].y + cnt; j++){
            if(m[p(i, j)]){
                t = 1;
                break;
            }
        }
        cnt ++;
    }

    if(t == 1){
        cout << "YES" << endl;
    }
    else{
        cnt = 0;
        for (int i = bx[4].x; i >= bx[3].x; i--){
            for (int j = by[2].y - cnt; j <= by[2].y + cnt; j++){
                if(m[p(i, j)]){
                    t = 1;
                    break;
                }
            }
            cnt++;
        }
        if(t == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
        // 1 3
        // 3 5
        // 3 1
        // 5 3

    // for (int i = 1; i <= 100; i++){
    //     for (int j = 100; j >= -10; j--){
    //         cout << m[p(i,j)] << " ";
    //     }
    //     cout << endl;
    // }

    re 0;
}