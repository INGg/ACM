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

const int N = 200000 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n, k;
ll a[N];

int main(){
    cin >> T;
    while(T--){
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);

        int pos = n;
        while(k--){
            a[pos - 1] += a[pos];
            pos--;
        }
        cout << a[(pos + 1) / 2] << endl;
    }
}