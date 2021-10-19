#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define ll long long

using namespace std;

// double a[1000 + 10];

struct nope
{
    int pa;
    int id;
    int g;
}a[4];

bool cmp(nope a, nope b){
    return a.pa < b.pa;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    string s;
}