#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        int l = s.size();
        for (int i = 0; i < l; i++){
            if(i % 2 == 0){
                if(s[i] > 'a')
                    s[i] = 'a';
                else
                    s[i] = 'b';
            }
            else{
                if(s[i] < 'z')
                    s[i] = 'z';
                else
                    s[i] = 'y';
            }
        }
        cout << s << endl;
    }
    return 0;
}