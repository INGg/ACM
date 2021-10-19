
#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

#define in32(x) scanf("%d", &x)
#define in64(x) scanf("%lld", &x)
#define out64(x) printf("%lld\n", x)

int main() {
    lli ans = 0;
    int n;
    in32(n);
    int ** points;
    points = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        points[i] = calloc(2, sizeof(int));
        in32(points[i][0]);
        in32(points[i][1]);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                if (points[i][0] < points[j][0] && 
                    points[j][0] < points[k][0] &&
                    points[i][1] > points[j][1] &&
                    points[k][1] > points[i][1])
                    ans++;
            }

    out64(ans);
    return 0;
}
