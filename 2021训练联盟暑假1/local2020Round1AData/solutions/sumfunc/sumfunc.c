
#include <stdio.h>
#include <stdlib.h>

#define in64(x) scanf("%lld", &x)
#define out64(x) printf("%lld\n", x)
#define out32(x) printf("%d\n", x)
#define MAX 100000

typedef long long int lli;

int main() {
    lli s, e, k, ans = 0;
    int n, printed = 0;
    in64(s);
    in64(e);
    in64(k);
    n = (int)(e - s + 1);
    int * vals = calloc(n, sizeof(int));
    int * isPrime = calloc(MAX, sizeof(int));
    for (int i = 0; i < MAX; i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 0; i * i < MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < MAX; j += i)
            isPrime[j] = 0;
        int cur = (int)(s % i);
        cur = i - cur;
        cur %= i;
        while (printed < k && cur < n) {
            if (!vals[cur]) {
                ans += i;
                printed++;
                vals[cur] = 1;
            }
            cur += i;
        }
        if (printed == k) break;
    }
    out64(ans);
    free(vals);
    free(isPrime);
    return 0;
}