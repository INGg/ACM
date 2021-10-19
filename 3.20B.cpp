#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#define ll long long
#define re return

using namespace std;

struct date
{
    int h;
    int m;
};


struct nope
{
    string name;
    // string id;
    int body;
    // int time;
    int last;
    int id;
}a[1000 * 30 + 10];

set<map<string, nope>> s;
map<string, nope> m;

int main(){
    int D;
    int P;
    cin >> D >> P;
    int t, s;
    int num = 0; //现在出现的是第几人
    while(D--){
        cin >> t >> s;
        nope x;
        string id;
        date d;
        for (int i = 1; i <= t; i++){
            cin >> x.name >> id >> x.body;
            scanf("%d:%d", d.h, d.m);
            x.time = d.h * 100 + d.m;
            m[id] = 
        }
    }
}