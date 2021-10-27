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

const int N = 9;
const int M = 1 << N;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

// int T;
int one[M], mapp[M];
char s[100];
int row[N], col[N], cel[3][3];

void draw(int x, int y, int t, bool is_set){
    if(is_set)
        s[x * N + y] = '1' + t;
    else
        s[x * N + y] = '.';

    int v = (1 << t);
    if(!is_set)
        v = -v;

    row[x] -= v;
    col[y] -= v;
    cel[x / 3][y / 3] -= v;
}

void init(){
    for (int i = 0; i < N; i++){
        row[i] = col[i] = (1 << N) - 1;
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cel[i][j] = (1 << N) - 1;
        }
    }
}

int lb(int x){
    return x & -x;
}

int get(int x, int y){
    return row[x] & col[y] & cel[x / 3][y / 3];
}

bool dfs(int cnt){
    if(!cnt)
        return 1;

    int minn = 10;
    int x, y;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(s[i * N + j] == '.'){ // 求出来最小扩展的那个方案应该放在哪
                int state = get(i, j);
                if(one[state] < minn){
                    minn = one[state];
                    x = i, y = j;
                }
            }
        }
    }

    int state = get(x, y);
    for (int i = state; i; i -= lb(i)){
        int t = mapp[lb(i)];
        draw(x, y, t, 1);
        if(dfs(cnt - 1))
            return 1;
        draw(x, y, t, 0);
    }

    return 0;
}

void solve(){
    init();

    int cnt = 0; // 表示有多少个空位
    for (int i = 0, k = 0; i < N; i++){
        for (int j = 0; j < N; j++, k++){
            if(s[k] != '.'){
                int t = s[k] - '1';
                draw(i, j, t, 1);
            }
            else
                cnt++;
        }
    }

    dfs(cnt);

    puts(s);
}

int main(){
    for (int i = 0; i < N; i++)
        mapp[1 << i] = i;

    for (int i = 0; i < (1 << N); i++){
        for (int j = 0; j < N; j++){
            one[i] += ((i >> j) & 1);
        }
    }

    while (cin >> s && s[0] != 'e'){
        solve();
    }
}