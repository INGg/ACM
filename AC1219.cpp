// 判断一个数在哪一行

#include <iostream>

using namespace std;

int w, n, m;

int a[10000 + 10][10000 + 10];

int r1, r2;
int c1, c2;
int r;

void debug(){
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= w; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    cin >> w >> m >> n;
    int f1 = 0;
    int f2 = 0;
    int f3 = 0; //是否枚举完
    int num = 1;
    for(int i = 1;; i++){
        if(i % 2 == 1)
            for(int j = 1; j <= w; j++){
                a[i][j] = num++;
                if(a[i][j] == m){
                    f1 = 1;
                    r1 = i;
                    c1 = j;
                }
                if(a[i][j] == n){
                    f2 = 1;
                    r2 = i;
                    c2 = j;
                }
            }
        else{
            for(int j = w; j >= 1; j--){
                a[i][j] = num++;
                if(a[i][j] == m){
                    f1 = 1;
                    r1 = i;
                    c1 = j;
                }
                if(a[i][j] == n){
                    f2 = 1;
                    r2 = i;
                    c2 = j;
                }
            }
        }
        r = i;
        if(f1 && f2) break;
        // if(num > n) break;
    }
    // debug();
    cout << abs(r1 - r2) + abs(c1 - c2);
    
    return 0;
}