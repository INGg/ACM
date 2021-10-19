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
struct nope
{
    int x;
    int id;
}a[N];

bool cmp(nope a, nope b){
    return a.x < b.x;
}

bool is_prime(int x){
    if(x == 0 || x == 1)
        return 0;
    if(x == 2)
        return 1;
    for (int i = 2; i <= x / i; i++){
        if(x % i == 0)
            return 0;
    }
    return 1;
}

void solve(){
    ll summ = 0;

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x;
        summ += a[i].x;
        a[i].id = i;
    }

    sort(a + 1, a + 1 + n, cmp);

    if(!is_prime(summ)){
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            cout << i << ' ';
        }
        cout << endl;
    }
    else{
        for (int i = 1; i <= n; i++){
            if(!is_prime(summ - a[i].x)){
                cout << n - 1 << endl;
                for (int j = 1; j <= n; j++){
                    if(j != i){
                        cout << a[j].id << ' ';
                    }
                }
                cout << endl;
                return;
            }
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}