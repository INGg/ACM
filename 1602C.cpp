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

const int N = 2e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
int a[N];

void solve(){
    map<int, int> num;
    vector<int> ans;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 30; j++){
            if((a[i] >> j) & 1)
                num[j]++;
        }
    }
    for(int i = 1; i <= n; i++){
        bool flag = 1;
        for(int j = 0; j < 30; j++){
            if(num[j] % i != 0){
                flag = 0;
                break;
            }
        }
        if(flag)
            ans.pb(i);
    }
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}