#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define re return
#define pb push_back
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
char ga[N][N];
char gaa[N][N];
char gb[N][N];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        scanf("%s", ga[i] + 1);
    }

    for (int i = 1; i <= n; i++){
        scanf("%s", gb[i] + 1);
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(ga[i][j] == 'X')
                ga[i][j] = 1;
            else
                ga[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(gb[i][j] == 'X')
                gb[i][j] = 1;
            else
                gb[i][j] = 0;
        }
    }

    // 求返图
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            gaa[i][j] = !ga[i][j];
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cnt1 += (ga[i][j] ^ gb[i][j]);
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cnt2 += (gaa[i][j] ^ gb[i][j]);
        }
    }

    if(cnt1 <= (n * m) / 2){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(ga[i][j] == 1)
                    printf("X");
                else
                    printf(".");
            }
            printf("\n");
        }
    }
    else{
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(gaa[i][j] == 1)
                    printf("X");
                else
                    printf(".");
            }
            printf("\n");
        }
    }
}