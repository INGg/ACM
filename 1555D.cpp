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

int n, m;
char s[N];
int pre[N][7];
char tar[N][7];
/*
abcabc
acbacb
bacbac
bcabca
cbacba
cabcab
*/

void init(){
    int _ = 1;
    string c = "abc";
    for (int i = 1; i <= n; i++){ // abc
        tar[i][_] = c[(i - 1) % 3];
    }
    for (int i = 1; i <= n; i++){
        // cout << tar[i][_] << " ";
        pre[i][_] = pre[i - 1][_] + (s[i] != tar[i][_]);
    }
    // cout << endl;
    _++;

    c = "acb";
    for (int i = 1; i <= n; i++){ // bac
        tar[i][_] = c[(i - 1) % 3];
    }
    for (int i = 1; i <= n; i++){
        // cout << tar[i][_] << " ";
        pre[i][_] = pre[i - 1][_] + (s[i] != tar[i][_]);
    }
    // cout << endl;
    _++;

    c = "bac";
    for (int i = 1; i <= n; i++){ // abc
        tar[i][_] = c[(i - 1) % 3];
    }
    for (int i = 1; i <= n; i++){
        // cout << tar[i][_] << " ";
        pre[i][_] = pre[i - 1][_] + (s[i] != tar[i][_]);
    }
    // cout << endl;
    _++;

    c = "bca";
    for (int i = 1; i <= n; i++){ // abc
        tar[i][_] = c[(i - 1) % 3];
    }
    for (int i = 1; i <= n; i++){
        // cout << tar[i][_] << " ";
        pre[i][_] = pre[i - 1][_] + (s[i] != tar[i][_]);
    }
    // cout << endl;
    _++;

    c = "cab";
    for (int i = 1; i <= n; i++){ // abc
        tar[i][_] = c[(i - 1) % 3];
    }
    for (int i = 1; i <= n; i++){
        // cout << tar[i][_] << " ";
        pre[i][_] = pre[i - 1][_] + (s[i] != tar[i][_]);
    }
    // cout << endl;
    _++;

    c = "cba";
    for (int i = 1; i <= n; i++){ // abc
        tar[i][_] = c[(i - 1) % 3];
    }
    for (int i = 1; i <= n; i++){
        // cout << tar[i][_] << " ";
        pre[i][_] = pre[i - 1][_] + (s[i] != tar[i][_]);
    }
    // cout << endl;
    _++;

}

int main(){
    cin >> n >> m;
    scanf("%s", s + 1);

    init();

    while(m--){
        int l, r;
        cin >> l >> r;
        if(l == r)
            cout << 0 << endl;
        else if(l + 1 == r){
            if(s[l] != s[r])
                cout << 0 << Endl;
            else
                cout << 1 << endl;
        }
        else{
            int ans = N + 1e4;
            for (int i = 1; i <= 6; i++)
                ans = min(ans, pre[r][i] - pre[l - 1][i]);
            cout << ans << Endl;
        }
    }
}