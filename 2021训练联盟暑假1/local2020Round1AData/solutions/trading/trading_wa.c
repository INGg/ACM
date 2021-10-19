
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define in32(x) scanf("%d", &x)
#define out32(x) printf("%d\n", x)
#define out64(x) printf("%lld\n", x)

#define MAX_TRIES 500

typedef long long int lli;

lli ans;
int N, M, * price, * count, * s_price, ** map;

int hasSet(int index, int * has) {
    for (int i = 0; i < N; i++)
        if (map[index][i] && !has[i])
            return 0;
    return 1;
}
lli comp(int * has) {
    lli ret = 0;
    for (int i = 0; i < N; i++) {
        if (has[i] && !count[i])
            ret -= price[i];
        if (!has[i] && count[i])
            ret += price[i];
    }
    for (int i = 0; i < M; i++)
        if (hasSet(i, has))
            ret += s_price[i];
    return ret;
}

void goForIt(int seed) {
    srand(seed + time(0));
    int * has = calloc(N, sizeof(int));
    int * has2 = calloc(N, sizeof(int));
    lli tans = 0;
    for (int i = 0; i < N; i++)
        has[i] = rand()&1;
    int * perm = calloc(N, sizeof(int));
    for (int i = 0; i < N; i++) {
        perm[i] = i;
    }
    tans = comp(has);
    int we = MAX_TRIES;
    int good = 1;
    while (good) {
        good = 0;
        // single
        for (int i = 0; i < N; i++){
            int j = (rand() % N + N) % N;
            if (j != i) {
                perm[i] ^= perm[j];
                perm[j] ^= perm[i];
                perm[i] ^= perm[j];
            }
            has[perm[i]] ^= 1;
            lli tmp = comp(has);
            if (tmp > tans) {
                tans = tmp;
                good = 1;
                break;
            }
            has[perm[i]] ^= 1;
        }

        // group
        for (int j = 0; j < M; j++) {
            if (hasSet(j, has)) {
                for (int i = 0; i < N; i++)
                    has2[i] = has[i];
                for (int i = 0; i < N; i++)
                    has2[i] ^= map[j][i];
                lli tmp = comp(has2);
                if (tmp > tans) {
                    tans = tmp;
                    int * tmp = has;
                    has = has2;
                    has2 = tmp;
                    good = 1;
                    break;
                }
            } else {
                for (int i = 0; i < N; i++)
                    has2[i] = has[i];
                for (int i = 0; i < N; i++)
                    if (map[j][i])
                        has2[i] = 1;
                lli tmp = comp(has2);
                if (tmp > tans) {
                    tans = tmp;
                    int * tmp = has;
                    has = has2;
                    has2 = tmp;
                    good = 1;
                    break;
                }
            }
        }
    }
    if (tans > ans) ans = tans;
    free(perm);
    free(has);
    free(has2);
}

int main() {
    ans = 0;

    int card, i, j, total;
    in32(N);
    in32(M);
    price = calloc(N, sizeof(int));
    count = calloc(N, sizeof(int));
    for (i = 0; i < N; i++) {
        in32(price[i]);
        in32(count[i]);
    }

    s_price = calloc(M, sizeof(int));
    map = calloc(M, sizeof(int *));
    for (i = 0; i < M; i++) {
        in32(total);
        in32(s_price[i]);
        map[i] = calloc(N, sizeof(int));
        while (total-->0) {
            in32(card);
            map[i][card - 1] = 1;
        }
    }

    for (int i = 0; i < MAX_TRIES; i++)
        goForIt(i);
    out64(ans);
    free(s_price);
    free(price);
    free(count);
    for (int i = 0; i < M; i++)
        free(map[i]);
    free(map);
    return 0;
}