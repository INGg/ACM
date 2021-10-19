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

const int N = 50 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n;
char s[N];

void solve(){
    memset(s, 0, sizeof(s));
    cin >> n;
    scanf("%s", s + 1);

    if(n == 1){
        cout << "-1 -1" << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            int a = 0;
            int b = 0;
            for (int k = i; k <= j; k++){
                if(s[k] == 'a')
                    a++;
                if(s[k] == 'b')
                    b++;
            }
            if(a == b){
                cout << i << " " << j << endl;
                return;
            }
        }
    }

    cout << "-1 -1" << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}