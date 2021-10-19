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

const int N = 3e5 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int T;
int a, b;

int base[N];

void init(){
    for (int i = 1; i <= 3e5; i++){
        base[i] = i ^ base[i - 1];
    }
}

int main(){
    init();
    cin >> T;
    while(T--){
        cin >> a >> b;

        int x = base[a - 1] ^ b;

        if(x == 0 && x != a){
            cout << a << endl;
        }
        else if(x == a){
            cout << a + 2 << endl;
        }
        else
            cout << a + 1 << endl;
    }
}