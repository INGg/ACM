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
    char a[N];

    void solve(){
        cin >> n;
        scanf("%s", a + 1);

        for (int i = 1; i <= n / 2; i++){
            if(a[i] == '0'){
                cout << i << " " << n << " " << i + 1 << " " << n << endl;
                return;
            }
        }

        for (int i = n / 2 + 1; i <= n; i++){
            if(a[i] == '0'){
                cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
                return;
            }
        }

        cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
    }

    int main(){
        cin >> T;
        while(T--){
            solve();
        }
    }