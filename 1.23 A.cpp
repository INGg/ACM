#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int n;

struct nope{
    int s;
    int d;
} d[1000 + 10];

// int main(){
//     cin >> n;
//     for (int i = 1; i <= n; i++){
//         cin >> d[i].s >> d[i].d;
//     }

//     int now = d[1].s;
//     int ans = d[1].s;
//     for (int i = 2; i <= n; i++){
//         int x = 0;
//         while(now >= d[i].s + d[i].d * x){
//             x++;
//         }
//         // cout << x << endl;
//         ans = (d[i].s + d[i].d * x);
//         now = d[i].s + d[i].d * x;
//     }
//     cout << ans;
//     return 0;
// }

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> d[i].s >> d[i].d;
    }

    int ans = 0;
    int num = 1;
    while(num <= n){
        ans++; //天数加一
        if(ans - d[num].s >= 0 && (ans - d[num].s) % d[num].d == 0){ // (ans - d[j].s) / d = x,
            num++;
        }
    }
    cout << ans << endl;
    return 0;
}