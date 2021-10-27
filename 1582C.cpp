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

const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
char s[N];
struct nope{
    int cnt;
    char c;
} cnt[60];
// int cnt[60];

bool check(){
    for (int i = 1; i <= n / 2; i++){
        if(s[i] != s[n - i + 1]){
            return 0;
        }
    }
    return 1;
}

void solve(){

    cin >> n;
    scanf("%s", s + 1);

    if(check()){
        cout << 0 << endl;
        return;
    }

    int ans = INF;

    for (int i = 0; i < 26; i++){
        bool flag = 1;
        int res = 0;
        int l = 1;
        int r = n;
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else{
                if (s[l] - 'a' == i){
                    res++;
                    l++;
                }
                else if(s[r] - 'a' == i){
                    res++;
                    r--;
                }
                else{
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
            ans = min(ans, res);
    }

    if(ans == INF)
        cout << -1 << endl;
    else
        cout << ans << Endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}