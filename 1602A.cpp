#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
string s1;
string s2;

int main(){
    cin >> T;
    while(T--){
        cin >> s1;
        s2 = s1;
        sort(s1.begin(), s1.end());
        if(s1.size() == 2){
            cout << s1[0] << ' ' << s1[1] << endl;
            continue;
        }

        for (int i = 0; i < s2.size(); i++){
            if(s1[0] == s2[i]){
                s2 = s2.substr(0, i) + s2.substr(i + 1);
                break;
            }
        }

        cout << s1[0] << ' ' << s2 << endl;
    }
}