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
int a[10];

void solve(){
    memset(a, 0, sizeof(a));
    set<int> s[7];

    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 5; j++){
            int x;
            cin >> x;
            if(x){
                s[j].insert(i);
                a[j]++;
            }
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            if(s[i].size() > 0 && s[j].size() > 0){
                std::set<int> diff;
                std::set_union(s[i].begin(), s[i].end(), s[j].begin(), s[j].end(), inserter(diff, diff.begin()));

                if (diff.size() == n && a[i] >= n / 2 && a[j] >= n / 2){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }

    cout << "NO" << Endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}