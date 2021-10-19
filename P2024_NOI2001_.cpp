#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 50000 + 10;

int n, m;
int f[N];
int d[N];

void init(){
    for (int i = 1; i <= n; i++){
        f[i] = i;
    }
}

int query(int p){
    if(f[p] != p){
        int v = query(f[p]);
        d[p] += d[f[p]];
        f[p] = v;
    }
    return f[p];
}

int main(){
    cin >> n >> m;
    init();

    int ans = 0;

    while(m--){
        int op, x, y;
        cin >> op >> x >> y;

        if(x > n || y > n){
            ans++;
            continue;
        }

        int fx = query(x);
        int fy = query(y);

        if(op == 1){
            
            if(fx == fy && (d[x] - d[y]) % 3){
                ans++;
            }
            else if(fx != fy){
                f[fx] = fy;
                d[fx] = d[y] - d[x];
            }

        }
        else{
            if(x == y){
                ans++;
                continue;
            }

            if(fx == fy && (d[x] - d[y] - 1) % 3){
                ans++;
            }
            else if(fx != fy){
                f[fx] = fy;
                d[fx] = d[y] - d[x] + 1;
            }
        }
    }
    cout << ans << endl;
}