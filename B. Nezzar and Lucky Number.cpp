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


int q, d;
int a;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> q >> d;
        
        while(q--){
            cin >> a;
            int t = 0;
            int x = d;

            if(x <= a){
                stringstream ss;
                ss << a;
                string s;
                ss >> s;
                if(s.find((char)(d + '0')) != -1){
                    cout << "YES" << endl;
                    continue;
                }
            }

            while(x <= a){
                stringstream ss;
                int y = a - x;
                ss << y;
                string s;
                ss >> s;
                // cout << (char)(d + '0') << endl;
                if(s.find((char)(d + '0')) != -1){
                    cout << "YES" << endl;
                    t = 1;
                    break;
                }
                else
                    x += 10;
            }
            if(t == 0)
                cout << "NO" << endl;
        }
        

    }
}