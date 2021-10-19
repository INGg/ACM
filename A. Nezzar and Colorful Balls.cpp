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

int a[200];

int main(){
    int t;
    int n;
    cin >> t;
	// freopen("D.out","w",stdout);    
    while(t--){
        cin >> n;
        int ans = 0;
        int x;
        for (int i = 1; i <= n; i++){
            cin >> x;
            a[x]++;
            ans = max(ans, a[x]);
        }
        cout << ans << endl;
        memset(a, 0, sizeof(a));
    }
    re 0;
}