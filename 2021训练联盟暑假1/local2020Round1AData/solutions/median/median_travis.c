
#include <stdlib.h>
#include <stdio.h>

#define in32(x) scanf("%d", &x)

typedef long long int lli;

lli rec(int, int, int);
void printWord(int, int, int, lli);

lli *** memo;

int main() {
    int N, K;
    in32(N);
    in32(K);
    memo = calloc(N + 1, sizeof(lli**));
    for (int i = 0; i <= N; i++) {
        memo[i] = calloc(N + 1, sizeof(lli*));
        for (int j = 0; j <= N; j++) {
            memo[i][j] = calloc(K + 1, sizeof(lli*));
            for (int k = 0; k <= K; k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    lli numStrings = rec(N, 0, K);
    //printf("%lld\n", numStrings);
    if ((numStrings&1)== 0) {
        lli index1 = (numStrings>>1) - 1;
        lli index2 = (numStrings>>1);
        printWord(N, 0, K, index1);
        printf("\n");
        printWord(N, 0, K, index2);
    } else {
        lli index1 = (numStrings>>1);
        printWord(N, 0, K, index1);
    }
    printf("\n");

    return 0;
}

lli rec(int len, int bs, int inv) {
    if (len == 0 && inv == 0) return 1;
    if (len == 0 || inv < 0) return 0;
    if (memo[len][bs][inv] != -1)
        return memo[len][bs][inv];
    lli ans = 0;
    
    ans += rec(len - 1, bs + 1, inv);
    ans += rec(len - 1, bs, inv - bs);
    memo[len][bs][inv] = ans;
    return ans;
}

void printWord(int len, int bs, int inv, lli index) {
    //printf("\n%d %d %d %lld\n", len, bs, inv, index);
    if (len == 0) return;
    if (len == 0 && inv == 0) return;
    lli ans = 0;
    
    ans = rec(len - 1, bs, inv - bs);
    //printf("%lld %lld\n", index, ans);
    if (ans <= index) {
        printf("B");
        printWord(len - 1, bs + 1, inv, index - ans);
        return;
    }

    printf("A");
    printWord(len - 1, bs, inv - bs, index);
}
