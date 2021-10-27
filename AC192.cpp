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

int n;
string A, B;
string a[N];
string b[N];

int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, string a[], string b[]){
    string t = q.front();
    q.pop();

    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < n; j++){
            if(t.substr(i, a[j].size()) == a[j]){
                string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
                if(db.count(state))
                    return da[t] + 1 + db[state];
                if(da.count(state))
                    continue;
                da[state] = da[t] + 1;
                q.push(state);
            }
        }
    }

    return 11;
}

int bfs(){
    queue<string> qa, qb;
    unordered_map<string, int> da, db;

    qa.push(A);
    da[A] = 0;
    qb.push(B);
    db[B] = 0;

    while(qa.size() && qb.size()){
        int t;
        if(qa.size() <= qb.size())
            t = extend(qa, da, db, a, b);
        else
            t = extend(qb, db, da, b, a);
        if(t <= 10)
            return t;
    }
    return 11;
}

int main(){
    cin >> A >> B;
    while(cin >> a[n] >> b[n])
        n++;

    int t = bfs();

    if(t > 10)
        cout << "NO ANSWER!";
    else
        cout << t;
}