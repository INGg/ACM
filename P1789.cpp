#include <iostream>
#include <cstdio>

using namespace std;

int a[105][105];
int n, m, k;

void fire(int x, int y){
    a[x][y] = 1;
    if(x + 1 <= n)
        a[x + 1][y] = 1;
    if(x + 2 <= n)
        a[x + 2][y] = 1;
    if(x - 1 > 0)
        a[x - 1][y] = 1;
    if(x - 2 > 0)
        a[x - 2][y] = 1;
    if(y + 1 <= n)
        a[x][y + 1] = 1;
    if(y + 2 <= n)
        a[x][y + 2] = 1;
    if(y - 1 > 0)
        a[x][y - 1] = 1;
    if(y - 2 > 0)
        a[x][y - 2] = 1;
    if(x + 1 <= n){
        if(y + 1 <= n)
            a[x + 1][y + 1] = 1;
        if(y - 1 > 0)
            a[x + 1][y - 1] = 1;
    }
    if(x - 1 > 0){
        if(y + 1 <= n)
            a[x - 1][y + 1] = 1;
        if(y - 1 > 0)
            a[x - 1][y - 1] = 1;
    }
}

void store(int x, int y){
    int top = x - 2;
    int under = x + 2;
    int left = y - 2;
    int right = y + 2;
    if(top < 0)
        top = 1;
    if(under > n)
        under = n;
    if(left < 0)
        left = 1;
    if(right > n)
        right = n;
    for (int i = top; i <= under; i++){
        for (int j = left; j <= right; j++){
            a[i][j] = 1;
        }
    }
}

int main(){
   
    cin >> n >> m >> k;
    int x, y;
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        fire(x, y);
    }

    for (int i = 1; i <= k; i++){
        cin >> x >> y;
        store(x, y);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(!a[i][j])
                ans++;
        }
    }
    cout << ans;
}