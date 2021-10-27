#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll = long long;
using PII = pair <int, int>;
using vi = vector <int>;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
int t, n;
ll a[N], s[N], f[510][N];
ll get(int r, int l) {
	return s[r] - s[l - 1];
}
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
		int k = 0;
		while((k + 1) * (k + 2) / 2 <= n) {
			k++;
		}
		//printf("%d\n", k);
		int res = 1;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= k; j++) f[j][i] = -0x3f3f3f3f;
		for(int i = 1; i <= n; i++) f[1][i] = a[i];
		for(int r = 2; r <= k; r++) {
			bool ok = 0;
			ll mx = 0;
			for(int i = n; i >= 1; i--) {
				if(i - r + 1 < 1) break;
				if(i + r - 1 <= n) mx = max(mx, f[r - 1][i + r - 1]); // 当前枚举的长度为r，上一个区间长度为r-1，
				if(mx > get(i, i - r + 1)) {
					ok = 1; f[r][i] = get(i, i - r + 1);
                    // break;
                }
			}
			if(!ok) break;
			res = r;
		}
//		for(int r = 1; r <= k; r++) {
//			for(int i = 1; i <= n; i++) printf("%lld ", f[r][i]);
//			puts("");
//		}

        // int ans = 0;
        // for (int i = 1; i <= k; i++){
        //     if(f[1][i] > 0){
        //         ans++;
        //     }
        // }

        printf("%d\n", res);
	}
	return 0;
}