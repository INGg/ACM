#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int n;
int m;

int hui_wen[99999999 - 11111111];
int cnt = 0;

void make_hui_wen(){
    for (int i = 1000; i <= 9999; i++){
        // if(check(i))
        int x = i;
        int y = i;
        while(y){
            x = x * 10 + y % 10;
            y /= 10;
        }
        // cout << x << endl;
        hui_wen[++cnt] = x;
    }
}

bool check_date(int a){
    int m = a / 100 % 100;
    int d = a % 100;
    if(m == 0 || m > 12 || d == 0 || d > 31)
        return false;

    if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return false;

    int flag = 0;
    int y = a / 10000;
    // cout << y << endl;
    if(y % 100 == 0){
        if (y % 400 == 0)
            flag = 1;
    }
    else if(y % 4 == 0)
        flag = 1;

    if(m == 2){
        if(flag == 1 && d > 29)
            return false;
        if(flag == 0 && d > 28)
            return false;
    }
    return true;
}

int main(){
    make_hui_wen();
    // cout << check_date(13900931) << endl;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if(hui_wen[i] < n)
            continue;
        if(hui_wen[i] > m)
            break;
        
        if(check_date(hui_wen[i]))
            // cout << hui_wen[i] << endl,
            ans++;
    }
    cout << ans;
    return 0;
}