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

int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db){
    auto t = q.front();
    q.pop();

    if(db.count(t))
        return da[t] + 1 + db[t];

    string state = t;
    // cout << t << endl;
    int k = t.find('0');
    int x = k / 3;
    int y = k % 3;

    for (int i = 0; i < 4; i++){
        int a = x + dx[i];
        int b = y + dy[i];

        if(a < 0 || a >= 3 || b < 0 || b >= 3)
            continue;

        swap(t[k], t[a * 3 + b]);

        if(db.count(t))
            return da[state] + 1 + db[t];

        if(!da.count(t)){
            da[t] = da[state] + 1;
            q.push(t);
        }

        swap(t[k], t[a * 3 + b]);
    }

    return -1;
}

int bfs(string start){
    queue<string> qa;
    queue<string> qb;
    unordered_map<string, int> da;
    unordered_map<string, int> db;
    string end = "123804765";

    if(start == end)
        return 0;

    qa.push(start);
    qb.push(end);
    da[start] = 0;
    db[end] = 0;

    int t;

    while(qa.size() && qb.size()){
        if(qa.size() <= qb.size())
            t = extend(qa, da, db);
        else
            t = extend(qb, db, da);
        if(t != -1)
            return t;
    }

    return t;
}

void solve(){
    string start;

    cin >> start;

    cout << bfs(start) << endl;
}

int main(){
    // cin >> T;
    T = 1;
    while(T--){
        solve();
    }
}