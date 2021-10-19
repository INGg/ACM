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

const int N = 30000 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m;
int f[N];
int d[N]; // i前面有多少个
int size[N]; // 以i为根节点的集合的大小

void init(){
    for (int i = 1; i <= 30000; i++){
        f[i] = i;
        size[i] = 1;
    }
}

int query(int p){
    if(f[p] == p)
        return f[p];
    else{
        int v = query(f[p]);
        d[p] += d[f[p]];
        f[p] = v;
        return v;
    }
}

void merge(int p1, int p2){
    int f1 = query(p1);
    int f2 = query(p2);

    if(f1 != f2){
        f[f1] = f2;
        d[f1] = size[f2];
        size[f2] += size[f1];
    }
}

int main(){
    init();
    cin >> m;
    while(m--){
        char op[2];
        int i, j;
        scanf("%s", op);
        cin >> i >> j;

        if(op[0] == 'M'){
            merge(i, j);
        }
        else{
            if(query(i) != query(j))
                cout << -1 << endl;
            else
                cout << max(abs(d[i] - d[j]) - 1, 0);
        }
    }
}