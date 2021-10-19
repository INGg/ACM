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

const int N = 100000 + 10;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
#define int ll

unordered_map<ll, set<ll>> belong1;
unordered_map<ll, set<ll>> belong2;

int n, m, l;

signed main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int id;
        double x, y, z;
        cin >> id >> x >> y >> z;
    }

    for (int i = 1; i <= m; i++){
        int id, idx;
        cin >> id >> idx;
        if(idx == 102){
            int x, y;
            cin >> x >> y;
            belong1[x].insert(y);
            belong1[y].insert(x);

            belong2[x].insert(id);
            belong2[y].insert(id);
        }
        else{
            int x, y, z;
            cin >> x >> y >> z;

            belong1[x].insert(y);
            belong1[x].insert(z);
            belong1[y].insert(x);
            belong1[y].insert(z);
            belong1[z].insert(x);
            belong1[z].insert(y);

            belong2[x].insert(id);
            belong2[y].insert(id);
            belong2[z].insert(id);
        }
    }

    cin >> l;
    for (int i = 1; i <= l; i++){
        if(i != 1)
            cout << endl;

        int id;
        cin >> id;
        cout << id << endl;

        set<ll> &out1 = belong1[id];
        if(!out1.size()){
            cout << "[]" << Endl;
        }
        else{
            cout << '[';
            for(auto j : out1){
                if(j != *out1.begin())
                    cout << ',';
                cout << j;
            }
            cout << "]\n";
        }

        set<ll> &out2 = belong2[id];
        if(!out2.size()){
            cout << "[]";
        }
        else{
            cout << '[';
            for(auto j : out2){
                if(j != *out2.begin())
                    cout << ',';
                cout << j;
            }
            cout << "]";
        }
    }
}