// BFS 康拓展开

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int fact[9];
bool st[362880];

struct nope{
    string s;
    int step;
};

int per_hax(string s){
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        int dt = 0;
        for(int j = 0; j < i; j++){
            if(s[j] > s[i])
                dt++;
        }
        ans += dt * fact[i]; 
    }
    return ans;
}

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int bfs(nope s){
    queue<nope> q;
    
    st[per_hax(s.s)] = 1;
    q.push(s);
    
    string end = "12345678x";
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        
        // printf("%d ",t.step);       //print调试法
        // cout << t.s <<endl;
        
        if(t.s == end) return t.step;
        
        int k = t.s.find('x');
        int x = k / 3;
        int y = k % 3;
        
        for(int i = 0; i < 4; i++){
            int a = x + dx[i];
            int b = y + dy[i];
            
            if(a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            
            nope nxt;
            
            swap(t.s[k], t.s[a * 3 + b]);
            
            nxt.step = t.step + 1;
            nxt.s = t.s;
            int hax = per_hax(t.s);
            
            if(!st[hax]){
                st[hax] = 1;
                q.push(nxt);
            }
            
            swap(t.s[k], t.s[a * 3 + b]);
        }
    }
    return -1;
}

int main(){
    fact[0] = 1;
    for(int i = 1; i < 9; i++) fact[i] = fact[i - 1] * i;
    
    string start;
    
    char c;
    while(cin >> c){
        start += c;
    }
    
    nope s;
    s.s = start;
    s.step = 0;
    
    cout << bfs(s) << endl;
    
    return 0;
}
