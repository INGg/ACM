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
struct nope{
    long double summ;
    int id;
} d[N];

bool cmp(nope a, nope b){
    if(a.summ == b.summ){
        return a.id < b.id;
    }
    return a.summ < b.summ;
}

void solve(){
    for (int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        long double summ = 0;
        summ += a * 1.0;
        summ += b * 1.0;
        summ = summ / (summ + c * 1.0);
        d[i].id = i;
        d[i].summ = summ;
    }

    sort(d + 1, d + 1 + n, cmp);

    for (int i = 1; i < n; i++){
        cout << d[i].id << ' ';
    }
    cout << d[n].id << endl;
}

int main(){
    // cin >> T;
    while(cin >> n){
        solve();
    }
}