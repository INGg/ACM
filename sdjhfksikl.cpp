#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    while(k--){
        stack<int> s;
        int now = 1;
        int t = 1;
        int a[1000 + 10] = {0};
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == now)
            {
                now++;
                while(!s.empty() && s.top() == now){
                    now++;
                    s.pop();
                }
            }
            else{
                s.push(a[i]);
                if(s.size() > m){
                    t = 0;
                    break;
                }
            }
            
        }
        if(t && s.empty()){ 
        //如果不判断是不是为空的话，就想给的的样例中3、1、5、4、2、6、7 
        //3、1、5、4、2、6、7，放上1 2就拿不到3号箱了，因为这个样例能正好放满货架而不会break
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}