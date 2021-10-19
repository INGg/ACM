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
char s[N];
int a[N];

int main(){
    cin >> T;
    while(T--){
        scanf("%d", &n);
        scanf("%s", s + 1);

        for (int i = 1; i <= n; i++){
            if(s[i] == 'U')
                a[i] = 1;
            if(s[i] == 'D')
                a[i] = -1;
            if(s[i] == 'L')
                a[i] = 100000;
            if(s[i] == 'R')
                a[i] = -100000;
        }

        map<ll, int> m;
        ll pre = 0;
        ll ans = 0;

        m[pre]++;

        for (int i = 1; i <= n; i++){
            pre += a[i];
            if(m.find(pre) != m.end())
                ans += m[pre];
            m[pre]++;
        }

        printf("%lld\n", ans);
    }
}