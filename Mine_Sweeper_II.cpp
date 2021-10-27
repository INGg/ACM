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

int dx[8] = {-1,0,1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};

int n, m;
char A[N][N];
char B[N][N];

int suma;
int sumb;
int a[N][N]; // 当前的数值
int b[N][N];

struct nope
{
    PII id;
    int v; // 修改它对答案有什么影响

    bool operator< (const nope& t) const{
        return v < t.v;
    }
};

void turn(int x, int y){
    if(B[x][y] == '.')
        B[x][y] = 'X';
    else
        B[x][y] = '.';
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        scanf("%s", A[i] + 1);
    }
    for (int i = 1; i <= n; i++){
        scanf("%s", B[i] + 1);
    }

    // init
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(A[i][j] == '.'){
                int cnt = 0;
                for (int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x <= 0 || x > n || y <= 0 || y > m)
                        continue;

                    if(A[x][y] == 'X')
                        cnt++;
                }
                a[i][j] = cnt;
                suma += cnt;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(B[i][j] == '.'){
                int cnt = 0;
                for (int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x <= 0 || x > n || y <= 0 || y > m)
                        continue;

                    if(B[x][y] == 'X')
                        cnt++;
                }
                b[i][j] = cnt;
                sumb += cnt;
            }
            else{
                // 表示这个X影响的个数
                int cnt = 0;
                for (int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x <= 0 || x > n || y <= 0 || y > m)
                        continue;

                    if(B[x][y] == '.')
                        cnt++;
                }
                b[i][j] = cnt;
            }
        }
    }

    // 加入维护
    set<nope> s;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            nope e;
            // 修改它能对答案产生什么样的影响
            if(B[i][j] == '.'){ // 要变成X
                int summ = 0;
                for (int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x <= 0 || x > n || y <= 0 || y > m)
                        continue;

                    if(B[x][y] == '.'){
                        summ += b[x][y] + 1;
                    }
                }
                summ -= b[i][j];
                e.id = {i, j};
                e.v = summ; // 
            }
            else{ // X
                e.id = {i, j};
                e.v = -b[i][j];
            }

            s.insert(e);
        }
    }

    int num = (n * m) / 2;
    int cha = suma - sumb;
    while(num--){
        auto it = s.lower_bound(cha);
        turn(*it.id.x, *it.id.y);
        if(*it.v == cha){     
            break;
        }
        else{
            nope e = *it;

            int op;
            if(B[e.id.x][e.id.y] == 'X')
                op = -1;
            else
                op = 1;
            for (int k = 0; k < 8; k++){
                int x = e.id.x + dx[k];
                int y = e.id.y + dy[k];

                if(x <= 0 || x > n || y <= 0 || y > m)
                    continue;

                
            }

        }

        cha = suma - sumb;
    }

    for (int i = 1; i <= n; i++){
        printf("%s", B[i]);
    }

    return 0;
}