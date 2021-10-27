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

void update(priority_queue<int>& ql, priority_queue<int, vector<int>, greater<int>>& qs){
    if(ql.size() < ((qs.size() + ql.size() + 1) / 2)){
        ql.push(qs.top());
        qs.pop();
    }
    else if(ql.size() > ((qs.size() + ql.size() + 1) / 2)){
        qs.push(ql.top());
        ql.pop();
    }
}

void add(priority_queue<int>& ql, priority_queue<int, vector<int>, greater<int>>& qs, int x){
    if(ql.empty() || x <= ql.top()){
        ql.push(x);
    }
    else{
        qs.push(x);
    }
    update(ql, qs);
}

void remove(priority_queue<int>& ql, priority_queue<int, vector<int>, greater<int>>& qs){
    ql.pop();
    update(ql, qs);
}

int main(){
    cin >> T;
    while(T--){
        priority_queue<int> ql;
        priority_queue<int, vector<int>, greater<int>> qs;

        while(scanf("%d", &n) && n){
            if(n == -1){
                cout << ql.top() << endl;
                remove(ql, qs);
            }
            if(n > 0){
                add(ql, qs, n);
            }
        }
        cout << endl;
    }
}