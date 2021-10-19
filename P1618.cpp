#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int p[10];
int a = 1, b = 2, c = 3;

void fen_jie(int a){
    p[a % 10]++;
    p[a / 10 % 10]++;
    p[a / 100]++;
}

int check(int x, int y, int z){
    if(y > 987 || z > 987)
        return 0;
    fen_jie(x);
    fen_jie(y);
    fen_jie(z);
    for (int i = 1; i <= 9; i++){
        if(!p[i])
            return 0;
    }
    return 1;
}

int main(){
    // cin >> a >> b >> c;
    int t = 0;
    for (int i = 123; i <= 987; i++){
        int x = i;
        int y = i * b / a;
        int z = i * c / a;
        if(check(x,y,z)){
            cout << x << " " << y << " " << z << endl;
            t = 1;
        }
        memset(p, 0, sizeof(p));
    }
    if(!t)
        cout << "No!!!";
    return 0;
}