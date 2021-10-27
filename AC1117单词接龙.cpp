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

const int N = 25 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
string word[N];
int g[N][N];
int used[N];
char start;
int ans;

void dfs(string dr, int num){
    ans = max(ans, (int)dr.size());

    used[num]++;

    for (int i = 1; i <= n; i++){
        if(g[num][i] && used[i] < 2){
            dfs(dr + word[i].substr(g[num][i]), i);
        }
    }

    used[num]--;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> word[i];
    }
    cin >> start;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            string a = word[i];
            string b = word[j];
            for (int k = 1; k < min(a.size(), b.size()); k++){ // k 从1开始我们要满足题目中第一个条件，重合长度必须大于等于1
                if(a.substr(a.size() - k) == b.substr(0, k)){
                    g[i][j] = k;
                    break; // 贪心来想我们要让重合部分尽可能的小来保证连接起来尽可能的大
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if(word[i][0] == start)
            dfs(word[i], i);
    }

    cout << ans << endl;
}