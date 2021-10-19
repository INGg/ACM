#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <vector>
#define ll long long
#define re return

using namespace std;

string s;
int a[30][30];
int n;
int suml[30][30];
int sumh[30][30]; 

void debug(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s;
        for (int j = 0; j < n; j++){
            if(s[j] == 'W')
                a[i][j + 1] = 1;
            else
                a[i][j + 1] = -1;
        }
    }
    // debug();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            sumh[i][j] = sumh[i][j - 1] + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            suml[i][j] = suml[i][j - 1] + a[j][i];
        }
    }
    
    int flag = 1;
    for (int i = 1; i <= n; i++){
        if(sumh[i][n] != 0 || suml[i][n] != 0){
            flag = 0;
            break;
        }
    }
    if(flag)
    for (int i = 1; i <= n; i++){
        for (int j = 3; j <= n; j++){
            cout << sumh[i][j] - sumh[i][j - 3] << " " << suml[i][j] - suml[i][j - 3] << endl;
            if(sumh[i][j] - sumh[i][j - 3] == 3 || sumh[i][j] - sumh[i][j - 3] == -3 || suml[i][j] - suml[i][j - 3] == 3 || suml[i][j] - suml[i][j - 3] == -3){
                flag = 0;
                break;
            }
        }
    }

    cout << flag;
    re 0;
}