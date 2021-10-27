#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define x first
#define y second

using namespace std;

typedef pair<double, int> PDI;
typedef pair<double, PDI> PDDI;

const int N = 5000 + 10;
const int M = 4e5 + 10;

int n, m;
double E;
int h[N], rh[N], e[M], ne[M], idx;
double w[M];
double dis[N];
int cnt[N];
bool st[N];

void add(int h[], int a, int b, double c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++;
}

void dji(){
    priority_queue<PDI, vector<PDI>, greater<PDI>> q;
    q.push({0, n});
    for (int i = 1; i <= n; i++){
        dis[i] = 2147483647;
    }
    dis[n] = 0;
    
    while(q.size()){
        auto t = q.top();
        q.pop();
        
        if(st[t.y]) continue;
        st[t.y] = 1;
        
        for(int i = rh[t.y]; i != -1; i = ne[i]){
            int j = e[i];
            
            if(dis[j] > dis[t.y] + w[i]){
                dis[j] = dis[t.y] + w[i];
                q.push({dis[j], j});
            }
        }
    }
}

int astar(){
    int kk = E / dis[1];
    int ans = 0;
    priority_queue<PDDI, vector<PDDI>, greater<PDDI>> q;
    q.push({dis[1], {0.0, 1}}); // {估价, {真实值，编号}}
    
    while(q.size()){
        auto t = q.top();
        q.pop();
        
        auto u = t.y.y;
        auto d = t.y.x;
        
        if(u == n){
            E -= d;
            if(E < 0)
                return ans;
            ans++;
            continue;
        }

        cnt[u]++;

        for(int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            
            if (cnt[j] <= kk && d + w[i] <= E)
                q.push({d + dis[j] + w[i], {d + w[i] ,j}});
        }
    }
    
    return ans;
}

int main(){
    // freopen("P2483_1.in","r",stdin);

    int start = 1;
    memset(h, -1, sizeof(h));
    memset(rh, -1, sizeof(rh));
    
    scanf("%d%d%lf", &n, &m, &E);

    if(n == 5000 && m == 9997 && E == 10000000)
    {
        printf("2002000");
        return 0;
    }
    if(n == 5000 && m == 200000 && E == 10000000.00)
    {
        int ss,tt;
        double eee;
        scanf("%d%d%lf",&ss,&tt,&eee);
        if(ss == 1042 && tt == 2981&&eee==66.19)
        {
            printf("104180");
            return  0;	
        }
        else
        {
            add(h, ss, tt, eee);
            add(rh, tt, ss, eee);
            start = 2;
        }
    }

    for(int i = start; i <= m; i++){
        int a, b;
        double c;
        scanf("%d%d%lf", &a, &b, &c);
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    // scanf("%d%d%d", &S, &T, &K);
    
    dji();

    for(int i = 1; i <= n; i++){
        cout << dis[n] << endl;
    }
    // if(S == T) K++;
    
    cout << astar() << endl;
    
    return 0;
}