#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <vector>
#define ll long long
#define re return

using namespace std;

int T;

int main(){
    // freopen("Z.out","w",stdout);
    cin >> T;
    int n, k;
    while(T--){
        cin >> n >> k;
        // int cnt = 0;
        set<int> s;
        for (int i = k + 1; i <= n; i++){
            s.insert(i);
        }

        for (int i = 1; i <= k / 2; i++){
            s.insert(k - i);
        }

            cout << s.size() << endl;
        for (auto i = s.begin(); i != s.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
    re 0;
}