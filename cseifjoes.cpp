#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define pf(x) (x) * (x)
#define eps 1e-12

using namespace std;

int n;
struct point{
    double x;
    double y;
}o, a[100000 + 10];

double r;

double dis(point a, point b){
    return sqrt(pf(a.x - b.x) + pf(a.y - b.y));
}

void get(point n, point m, point l){
    double x1 = n.x;
    double x2 = m.x;
    double x3 = l.x;
    
    double y1 = n.y;
    double y2 = m.y;
    double y3 = l.y;
    
    double a1 = x1 - x2;
    double a2 = x1 - x3;
    double b1 = y1 - y2;
    double b2 = y1 - y3;
    double c1 = (y1 * y1 - y2 * y2 + x1 * x1 - x2 * x2);
    double c2 = (y1 * y1 - y3 * y3 + x1 * x1 - x3 * x3);
    // delete x1, x2, x3, y1, y2, y3;

    o.x = (c1 * b2 - b1 * c2) / (a1 * b2 - b1 * a2);
    o.y = (a1 * c2 - c1 * a2) / (a1 * b2 - b1 * a2);
    
    r = dis(o, n);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }
    random_shuffle(a + 1, a + 1 + n);
    o = a[1];
    r = 0;
    for(int i = 2; i <= n; i++){
        if(dis(a[i], o) > r + eps){
            o = a[i];
            r = 0;
            for(int j = 1; j <= i - 1; j++){
                if(dis(a[j], o) > r + eps){
                    o.x = (a[i].x + a[j].x) / 2;
                    o.y = (a[i].y + a[j].y) / 2;
                    r = dis(o, a[j]);
                    for(int k = 1; k <= j - 1; k++){
                        if(dis(a[k], o) > r + eps){
                            get(a[i], a[j], a[k]);
                        }
                    }
                }
            }
        }
    }
    printf("%10f %10f %10f", r, o.x, o.y);
    return 0;
}








