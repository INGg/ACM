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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int n, m, k;

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m >> k;

        int tot = n * m / 2;

        if(n % 2){
            tot -= m / 2; // 放 m / 2 个横着的使其变成行列全为偶数的情况
            k -= m / 2; // 因为放的是横着的
        }
        if(m % 2){
            tot -= n / 2; // 放n / 2个竖着的使其变成了行列全偶数的情况
        }

        if(k < 0 || k > tot || k & 1){
            cout << "NO\n";
        }
        else
            cout << "YES\n";
    }
}