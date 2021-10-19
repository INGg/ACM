#include <iostream>

using namespace std;

int b[7];
int f[55][55][55][55];
int a[380];
int n, m;

int main(){
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        b[x] ++;
    }
    
    f[0][0][0][0] = a[1];
    for(int i = 0; i <= b[1]; i++){
        for(int j = 0; j <= b[2]; j++){
            for(int k = 0; k <= b[3]; k++){
                for(int l = 0; l <= b[4]; l++){
                    int id = 1 * i + 2 * j + 3 * k + 4 * l + 1; // 下标从1开始的，我用了这些的牌但是它从1开始往前的，注意定义是用的是牌的个数
                    if(i != 0) f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l] + a[id]);
                    if(j != 0) f[i][j][k][l] = max(f[i][j][k][l], f[i][j - 1][k][l] + a[id]);
                    if(k != 0) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k - 1][l] + a[id]);
                    if(l != 0) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l - 1] + a[id]);
                }
            }
        }
    }
    
    cout << f[b[1]][b[2]][b[3]][b[4]];
    return 0;
}