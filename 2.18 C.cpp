#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#define ll long long
#define re return

using namespace std;

int a[200000 + 10];
int t[200000 + 10];
map<int,int> ans;
int n, m, d;
set<int> s;
int day = 0;

int main(){
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; i++){
        scanf("%d", a + i);
        t[i] = a[i];
    }
    sort(a, a + n);
    
    for (int i = 0; i < n; i++){
        if(s.size() == n)
            break;
        if(!s.count(a[i])){
            day++;
            s.insert(a[i]);
            ans[a[i]] = day;
            int x = upper_bound(a + i, a + n, a[i] + d) - a; //找到下一个比a[i]大d的数
            for (int j = x; j < n; j++){
                // cout << a[j] << endl;
                if(!s.count(a[j])){ //集合中有没有这个元素，如果没有
                    s.insert(a[j]);
                    ans[a[j]] = day;
                    j = upper_bound(a + j + 1, a + n, a[j] + d) - a; //找下一个比当前找到这个要大d的数在哪
                    j--;
                }
            }
        }
    }

    cout << day << endl;
    for (int i = 0; i < n; i ++){
        printf("%d ", ans[t[i]]);
    }
    return 0;
}

// 10 5 7 4 6 3 2 1 9 8
//  2 1 1 2 2 1 2 1 1 2 
//  2 3 2 2 1 1 2 1 1 3 