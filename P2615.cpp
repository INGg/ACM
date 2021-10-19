#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[45][45];
int n;

void debug(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    cin >> n;
    a[1][n / 2 + 1] = 1;
    int h = 1;
    int l = n / 2 + 1; //存k - 1的行与列
    for (int i = 2; i <= n * n; i++){
        if(h == 1 && l != n){
            a[n][l + 1] = i;
            h = n;
            l++;
            // debug();
            continue;
        }
        if(l == n && h != 1){
            a[h - 1][1] = i;
            h--;
            l = 1;
            // debug();
            continue;
        }
        if(h == 1 && l == n){
            a[h + 1][l] = i;
            h++;
            // debug();
            continue;
        }
        else{
            if(a[h - 1][l + 1] == 0){
                a[h - 1][l + 1] = i;
                h--;
                l++;
            }
            else{
                a[h + 1][l] = i;
                h++;
                l = l;
            }
            // debug();
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}