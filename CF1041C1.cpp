#include <bits/stdc++.h>

using namespace std;

int a[200005];
int t[200006];
int n, m, d, mx;
map<int , int > ans;
set<int> s;
int main(){
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i], t[i] = a[i];
    sort(a, a + n);
    ans[a[0]] = ++mx;
    s.insert(0);
    for (int i = 1; i < n; i++){
        auto it = s.begin();
        cout << *it << endl;
        if(a[i] - a[*it] > d)
            ans[a[i]] = ans[a[*it]], s.erase(it);
        else
            ans[a[i]] = ++mx;
        s.insert(i);
    }
    cout << mx;
}