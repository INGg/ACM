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
string s;

void solve(){
    cin >> n;
    cin >> s;

    if(n <= 1){
        cout << s << endl;
        return;
    }

    int flag = 0;
    for (int i = 0; i < n - 1; i++){
        if(s[i] == '1' && s[i + 1] == '0'){
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout << s << endl;
        re;
    }

    int k = 0;
    for (int i = n - 1; i >= 0; i--){
        if(s[i] == '0'){
            k = i;
            break;
        }
    }

    string ans = s.substr(k);

    // 看一组0之前有没有1
    for (int i = 0; i < k; i++){
        if(s[i] == '1'){
            ans = s.substr(0, i) + ans;
            break;
        }
    }

    cout << ans << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}