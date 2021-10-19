#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

int T;
int n;
int w[100005];
struct Node
{
    int num, a;

    bool operator < (const Node b) const
    {
        return a < b.a;
    }
} node[100005];
int fa[100005], mark[100005];
int tot, head[100005];
struct Edge
{
    int from, to, next;
} edge[200005];
int ans[100005];
std:: vector<int> out[100005];

void Addedge(int u, int v)
{
    edge[++ tot] = (Edge) {u, v, head[u]};

    head[u] = tot;
}

void Dfs(int u, int add)
{
    //printf("%d---\n", u);

    ans[u] = add + 1;

    for(int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;

        Dfs(v, add + mark[u]);
    }
}

struct UnionFindSet
{
    void Init()
    {
        for(int i = 1; i <= n; i ++) fa[i] = i;
    }

    int Find(int x)
    {
        return fa[x] == x ? x : fa[x] = Find(fa[x]);
    }
} ufs;

int main()
{
    scanf("%d", &T);
    while(T --)
    {
        tot = 0;

        memset(head, 0, sizeof(head));
        memset(mark, 0, sizeof(mark));
        memset(ans, 0, sizeof(ans));

        for(int i = 0; i <= n; i ++) out[i].clear();

        scanf("%d", &n);

        for(int i = 1; i < n; i ++)
        {
            int u, v;

            scanf("%d%d", &u, &v);

            out[u].push_back(v);
            out[v].push_back(u);
        }

        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &node[i].a);

            w[i] = node[i].a;

            node[i].num = i;
        }

        std:: sort(node + 1, node + n + 1);

        ufs.Init();

        for(int i = 1; i <= n; i ++)
        {
            int u = node[i].num;

            for(int j = 0, sz = out[u].size(); j < sz; j ++)
            {
                int v = out[u][j];

                if(w[u] < w[v]) continue;


                int fv = ufs.Find(v);


                Addedge(u, fv);

                fa[fv] = u;
                mark[u] = 1;
            }
        }

        Dfs(node[n].num, 0);

        for(int i = 1; i <= n; i ++) printf("%d\n", ans[i]);
    }

    return 0;
}
