// 走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。
// 当小明走到出口时，如果他手中的宝贝恰好是 k 件，则这些宝贝就可以送给小明。

// 请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这 k 件宝贝。

#include <iostream>
#define ll long long

using namespace std;

const int MOD = 1000000007;

int n, m, k;
int w[55][55];
int f[55][55][15][15]; // f[x][y][k][c] 到xy中取k个最大价值为c的方案的方案数

int main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> w[i][j];
            w[i][j]++;
        }
    }

    f[1][1][1][w[1][1]] = 1;
    f[1][1][0][0] = 1;
     // f[x][y][k][c] 到xy中取k个最大价值为c的方案的方案数
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(i == 1 && j == 1)
                continue;
            for (int cnt = 0; cnt <= k; cnt++){
                for (int c = 0; c <= 13; c++){
                    //一定不拿
                    int &v = f[i][j][cnt][c];
                    v = (v + f[i - 1][j][cnt][c]) % MOD;
                    v = (v + f[i][j - 1][cnt][c]) % MOD;
                    //可以拿的话
                    if(cnt != 0 && w[i][j] == c){
                        for (int s = 0; s < w[i][j]; s++){
                            v = (v + f[i - 1][j][cnt - 1][s]) % MOD;
                            v = (v + f[i][j - 1][cnt - 1][s]) % MOD;
                        }
                    } 
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 13; i++)
        ans = (ans + f[n][m][k][i]) % MOD;
    cout << ans;
    return 0;
}