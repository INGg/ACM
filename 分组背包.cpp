#include<iostream>
#include<algorithm>
#include <cstring>

using namespace std;

const int N = 15;

int f[100000 + 10],v[N][N],w[N][N];
int T;

void init(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            v[i][j] = w[i][j] = 0;
        }
    }
    for (int i = 0; i < 100000 + 10; i++){
        f[i] = 0;
    }
}

void work(int num){
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> v[i][j] >> w[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 3; k >= 0; k--)
                if(v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
        }
    }
    printf("Budget #%d: Maximum of %d lives saved.\n", num, f[m]);
    if(num != T)
        printf("\n");
}

int main(){
    
    cin >> T;
    for(int i = 1; i <= T; i++){
        work(i);
    }
    return 0;
}