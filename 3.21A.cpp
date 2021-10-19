#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

stack<int> ys;
// stack<char> op;

int n;
char s[300];
string ss;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    char c;
    while(cin >> c){
        ss += c;
    }

    for (int i = 0; i <= ss.size(); i++)
    {
        if(ss[i] == '*'){
            if(!ys.empty()){
                int x = ys.top();
                ys.pop();
                int y = ys.top();
                ys.pop();
                ys.push(x & y);
            }
        }
        else if(ss[i] == '+'){
            if(!ys.empty()){
                int x = ys.top();
                ys.pop();
                int y = ys.top();
                ys.pop();
                ys.push(x | y);
            }
        }
        else if(ss[i] == '-'){
            if(!ys.empty()){
                int x = ys.top();
                ys.pop();
                ys.push(!x);
            }
        }
        else if(s[ss[i] - 'A'] == 'T'){ //一定放他们后面，避免负数下标
            ys.push(1);
        }
        else if(s[ss[i] - 'A'] == 'F'){
            ys.push(0);
        }
    }
    if(ys.top() == 1){
        cout << 'T';
    }
    else
        cout << 'F';
    return 0;
}