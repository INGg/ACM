                    #include <iostream>
                    #include <cstdio>
                    #include <cmath>
                    #include <ctype.h>
                    #include <algorithm>
                    #include <cstring>
                    #include <map>
                    #include <set>
                    #include <sstream>
                    #define ll long long
                    #define re return

                    using namespace std;

        ll a[100000 + 10];
        ll summ[100000 + 10];
        ll wei[100000 + 10];

        void work()
        {
            ll n, k;
            cin >> n >> k;
            
            for (ll i = 1; i <= n; i++){
                cin >> a[i];
                summ[i] = (summ[i - 1] + a[i] % k) % k;
                wei[summ[i]] = i; //统计最后一个
            }

            ll ans = -1;
            for (ll i = 1; i <= n; i++){
                    if(summ[i] == 0){
                        ans = max(ans, i);
                    }
                    else{
                        if(wei[summ[i]] != i) ans = max(ans, wei[summ[i]] - i);
                    } 
            }
            cout << ans << endl;
            memset(summ, 0, sizeof(summ));
            memset(wei, 0, sizeof(wei));
            memset(a, 0, sizeof(a));
            //qing kong
        }

        int main(){
            int t;
            cin >> t;
            while(t--){
                work();
            }
            re 0;
        }