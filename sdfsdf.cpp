#include <iostream>

using namespace std;

struct stack{
    int s[2000 + 10];
    int cnt = 0;
    int v;

    void pop(){
        if(cnt > 0)
            cnt--;
    }

    bool empty(){
        if(cnt > 0)
            return true;
        else
            return false;
    }

    int top(){
        return s[cnt];
    }

    void push(int n){
        s[++cnt] = n;
    }

    int nsize(){
        return cnt;
    }
    
    void init(){
        for (int i = 0; i <= 2000; i++){
            s[i] = 0;
        }
    }
}s;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    while(k--){
        s.init();
        
        if(t){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}