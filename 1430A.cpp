#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define re return
#define pb push_back
#define Endl "\n"
#define endl "\n"
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct nope{
    int x, y, z;
}a[1010];

int T;
int n;

int main(){
    for (int l = 8; l <= 1000; l++){
        int flag = 0;
        for (int i = 0; i <= l / 3; i++)
        {
            for (int j = 0; j <= l / 5; j++)
            {
                for (int k = 0; k <= l / 7; k++)
                {
                    if (3 * i + 5 * j + k * 7 == l)
                    {
                        a[l].x = i;
                        a[l].y = j;
                        a[l].z = k;
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
    }

    cin >> T;
    while(T--){
        cin >> n;
        if(n < 3 || n == 4)
            cout << -1 << endl;
        else if(n == 3)
            cout << "1 0 0" << endl;
        else if(n == 5)
            cout << "0 1 0\n";
        else if(n == 7)
            cout << "0 0 1\n";
        else if(n == 6)
            cout << "2 0 0" << endl;
        else{
            cout << a[n].x << " " << a[n].y << " " << a[n].z << endl;
        }
    }
}