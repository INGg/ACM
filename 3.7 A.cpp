#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define pf(x) (x) * (x)
#define eps 1e-7
using namespace std;

int n;
struct point{
    double x;
    double y;
}o, a[5000 + 10];

struct nope{
    double x;
    double y;
    double z;
} x[5000];

double r;

double dis(point a, point b){
    return sqrt(pf(a.x - b.x) + pf(a.y - b.y));
}

void get(point a, point b, point c){
    double a11 = b.x - a.x;
    double a12 = b.y - a.y;
    double b1 = (pf(b.x) - pf(a.x) + pf(b.y) - pf(a.y)) * 0.5;
    double a21 = c.x - a.x;
    double a22 = c.y - a.y;
    double b2 = (pf(c.x) - pf(a.x) + pf(c.y) - pf(a.y)) * 0.5;

    o.x = (b1 * a22 - a12 * b2) / (a11 * a22 - a12 * a21);
    o.y = (a11 * b2 - b1 * a21) / (a11 * a22 - a12 * a21);
    r = dis(o, a);
}

double solve(int wei){
    if(wei == 1){
        for (int i = 1; i <= n; i ++){
            a[i].x = x[i].x;
            a[i].y = x[i].y;
        }
    }
    else if (wei == 2){
        for (int i = 1; i <= n; i++){
            a[i].x = x[i].x;
            a[i].y = x[i].z;
        }
    }
    else{
        for (int i = 1; i <= n; i++){
            a[i].x = x[i].y;
            a[i].y = x[i].z;
        }
    }

    random_shuffle(a + 1, a + 1 + n);
    o = a[1];
    r = 0;
    for(int i = 2; i <= n; i++){
        if(dis(a[i], o) - r > eps){
            o = a[i];
            r = 0;
            for(int j = 1; j <= i - 1; j++){
                if(dis(a[j], o) - r> eps){
                    o.x = (a[i].x + a[j].x) / 2;
                    o.y = (a[i].y + a[j].y) / 2;
                    r = dis(o, a[j]);
                    for(int k = 1; k <= j - 1; k++){
                        if(dis(a[k], o) - r>eps){
                            get(a[i], a[j], a[k]);
                        }
                    }   
                }
            }
        }
    }
    return r;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i].x >> x[i].y >> x[i].z;
    }
   
    // double xy = solve(1);
    // double ans = xy;
    // double xz = solve(2);
    // ans = min(xz, ans);
    // double yz = solve(3);
    // ans = min(yz, ans);
    // printf("%lf\n%lf\n%lf\n", xy, xz, yz);
    double ans = min(solve(1), min(solve(2), solve(3)));

    printf("%.10lf", ans * 2);
    return 0;
}