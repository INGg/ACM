#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct nope
{
    int a;
    int b;
}a[10000 + 10];

int p, d;

int main(){
    cin >> p >> d;
    for (int i = 1; i <= p; i++){
        int id, aa, bb;
        cin >> id >> aa >> bb;
        a[id].a += aa;
        a[id].b += bb;
    }

    int suma = 0;
    int sumb = 0;
    int v = 0;
    for (int i = 1; i <= d; i++){
        v += a[i].a + a[i].b;
        if(a[i].a > a[i].b){
            cout << "A ";
            cout << a[i].a - ((a[i].b + a[i].a) / 2 + 1);
            cout << " " << a[i].b;
            suma += (a[i].a - ((a[i].b + a[i].a) / 2 + 1));
            sumb += (a[i].b);
        }
            
        else{
            cout << "B " << a[i].a << " ";
            cout << a[i].b - ((a[i].b + a[i].a) / 2 + 1);
            sumb += (a[i].b - ((a[i].b + a[i].a) / 2 + 1));
            suma += (a[i].a);
        }

        cout << endl;
    }
    printf("%.10lf", abs(sumb - suma) * 1.0 / ((v) * 1.0));
    return 0;
}