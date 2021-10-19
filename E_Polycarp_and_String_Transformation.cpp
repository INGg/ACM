#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int st[128];
int cnt[128];

int main(){
    cin >> T;
    while(T--){
        memset(st, 0, sizeof(st));
        memset(cnt, 0, sizeof(cnt));

        string str;
        cin >> str;

        string sx; // shun xu
        for (int i = str.size() - 1; i >= 0; i--){
            if(!cnt[str[i]])
                sx += str[i];
            cnt[str[i]]++;
        }

        int flag = 1;
        reverse(sx.begin(), sx.end());
        int summ = 0;

        for (int i = 0; i < sx.size(); i++){
            if(cnt[sx[i]] % (i + 1)){
                flag = 0;
                break;
            }
            summ += cnt[sx[i]] / (i + 1);
        }

        if(!flag){
            cout << -1 << endl;
            continue;
        }

        string s = str.substr(0, summ);
        // cout << s << endl;
        string t = s; // 复原
        for (int i = 0; i < sx.size(); i++){
            st[sx[i]] = 1;
            for (int j = 0; j < s.size(); j++){
                if(!st[s[j]])
                    t += s[j];
            }
            // cout << t << endl;
        }

        // cout << sx << endl;

        if(str != t)
            cout << -1 << endl;
        else
            cout << s << " " << sx << endl;
    }
}