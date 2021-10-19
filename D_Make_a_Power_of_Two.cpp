#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> PII;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
int t, a[N];
int main() {
	scanf("%d", &t);
	while (t--) {
		int res = 0x3f3f3f3f;
		ll n;
		scanf("%lld", &n);
		string sn;
		while (n) {
			sn += (n % 10) + '0';
			n /= 10;
		}
		int l1 = sn.size();
		for (int i = 0; i < l1 / 2; i++) {
			swap(sn[i], sn[l1 - i - 1]);
		}
		for (ll u = 1; u <= 63; u++) {
			ll x = 1ll << (u - 1);
			string sx;
			while (x) {
				sx += (x % 10) + '0';
				x /= 10;
			}
			int l2 = sx.size();
			for (int i = 0; i < l2 / 2; i++) {
				swap(sx[i], sx[l2 - i - 1]);
			}
			//cout << sx << " ";
			int ans = 0, tmp = -1, i;
			for(i = 0; i < l1; i++) {
				if(sn[i] == sx[tmp + 1]) tmp++; // 匹配，有多少个匹配成功的，没匹配上的就删数
				if(tmp == l2 - 1) break;
			}
			//cout << tmp << "\n";
			if(tmp == l2 - 1) { // 说明不用加数了
				res = min(res, l1 - tmp - 1);
			}
			else {
				res = min(res, l1 - tmp + l2 - tmp - 2);
			}
			//printf("%lld %d\n", 1ll << (u - 1), res);
		}
		printf("%d\n", res);
	}
	return 0;
}