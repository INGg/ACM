#include <iostream>
#include <algorithm>

using namespace std;

int t;
int r, c;
int w[100 + 10][110];
int f[110][110];

int main(){
    cin >> t;
    while(t--){
        cin >> r >> c;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                cin >> w[i][j];
            }
        }
        
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
            }
        }
        cout << f[r][c] << endl;
    }
}