#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int n, m, d;
int a;
set<int> s;
map<int, int> ans;
int day = 1;
int t[200000 + 10];

int main(){
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a);
        s.insert(a);
        t[i] = a;
    }
    int now = *s.begin();
    s.erase(s.begin());
    ans[now] = day;

    for (int i = 2; i <= n; i++){
        int x;
        x = now + d + 1;
        auto it = s.lower_bound(x);
        if(it != s.end()){
            ans[*it] = day;
            now = *it;
            s.erase(it);
            continue;
        }
        it = s.begin();
        ans[*it] = ++day;
        now = *it;
        s.erase(it);
    }
    cout << day << endl;
    for (int i = 1; i <= n; i++){
        cout << ans[t[i]] << " ";
    }
    return 0;
}