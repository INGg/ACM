
#include <stdlib.h>
#include <stdio.h>

typedef long long int lli;

#define in32(x) scanf("%d", &x)
#define out64(x) printf("%lld\n", x)
#define out32(x) printf("%d\n", x)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define oo 987654321
typedef struct Edge Edge;
typedef struct AL AL;

struct Edge {
    int i, j;
    lli cap, flow, carry;
    Edge * rev;
};

struct AL {
    int size, cap;
    Edge ** arr;
};

int sink, source;
AL ** adj;
int * dist, * q, N2;
lli * pool;

void ALExpand(AL * al) {
    al->arr = realloc(al->arr, (al->cap *= 2) * sizeof(Edge *));
}

void ALAdd(AL * al, Edge * e) {
    if (al->size == al->cap)
        ALExpand(al);
    al->arr[al->size++] = e;
}

AL * ALCreate() {
    AL * ret = calloc(1, sizeof(AL));
    ret->cap = 2;
    ret->arr = calloc(ret->cap, sizeof(Edge *));
    ret->size = 0;
    return ret;
}

void createGraph(int n) {
    source = n;
    sink = n + 1;
    n += 2;
    N2 = n;
    adj = calloc(n, sizeof(AL *));
    for (int i = 0; i < n; i++)
        adj[i] = ALCreate();
    dist = calloc(N2, sizeof(int));
    pool = calloc(N2, sizeof(lli));
    q = calloc(N2, sizeof(int));
}

Edge * createEdge(int i, int j, int cap) {
    Edge * ret = calloc(1, sizeof(Edge));
    ret->i = i;
    ret->j = j;
    ret->cap = cap;
    ret->flow = 0;
    ret->carry = 0;
    ret->rev = NULL;
    return ret;
}

void add(int i, int j, lli val) {
    Edge * fwd = createEdge(i, j, val);
    Edge * rev = createEdge(j, i, 0);
    fwd->rev = rev;
    rev->rev = fwd;
    ALAdd(adj[i], fwd);
    ALAdd(adj[j], rev);
}

lli augment() {
    int stkSize = 0;
    int fptr, bptr;
    for (int i = 0; i < N2; i++) dist[i] = oo;
    pool[sink] = dist[source] = fptr = bptr = 0;
    pool[q[bptr++] = source] = oo;
    while (bptr > fptr && q[fptr] != sink) {
        int cur = q[fptr++];
        for (int i = 0; i < adj[cur]->size; i++) {
            Edge * e = adj[cur]->arr[i];
            if (dist[e->i] < dist[e->j])
                pool[e->j] += e->carry = MIN(e->cap - e->flow, pool[e->i]);
            
            //out64(pool[e->j]);
            //out64(pool[e->i]);
            //out64(e->cap);
            //out64(e->flow);
            
            if (dist[e->i] + 1 < dist[e->j] && e->cap > e->flow)
                dist[q[bptr++] = e->j] = dist[e->i] + 1;
        }
    }
    //out64(pool[sink]);
    if (pool[sink] == 0) return 0;
    bptr = fptr = 0;
    for (int i = 0; i < N2; i++) pool[i] = 0;
    pool[q[bptr++] = sink] = oo;
    AL * stk = ALCreate();
    while (bptr > fptr) {
        int cur = q[fptr++];
        for (int i = 0; i < adj[cur]->size; i++) {
            Edge * e = adj[cur]->arr[i];
            if (!pool[e->i]) break;
            int f = e->rev->carry = MIN(pool[e->i], e->rev->carry);
            if (dist[e->i] > dist[e->j] && f) {
                if (!pool[e->j]) q[bptr++] = e->j;
                pool[e->i] -= f;
                pool[e->j] += f;
                ALAdd(stk, e->rev);
            }
        }
    }
    lli res = pool[source];
    for (int i = 0; i < N2; i++) pool[i] = 0;
    pool[source] = (int)res;
    while (stk->size) {
        Edge * e = stk->arr[--stk->size];
        lli f = MIN(e->carry, pool[e->i]);
        pool[e->i] -= f; pool[e->j] += f;
        e->flow += f;
        e->rev->flow -= f;
    }
    free(stk->arr);
    free(stk);
    return res;
}

lli getFlow() {
    lli res = 0, f = 1;
    while (f) res += (f = augment());
    return res;
}

int main() {
    int N, M;
    in32(N);
    createGraph(N + 100);
    lli ans = 0;
    for (int i = 0; i < N; i++) {
        int price, has;
        in32(price);
        in32(has);
        ans += price * has;
        add(source, i, price);
    }
    in32(M);
    for (int i = 0; i < M; i++) {
        int num, price, card;
        in32(num);
        in32(price);
        ans += price;
        add(N + i, sink, price);
        for (int j = 0; j < num; j++) {
            in32(card);
            add(card - 1, N + i, oo);
        }
    }
    ans -= getFlow();
    out64(ans);
    for (int i = 0; i < N + 100 + 2; i++) {
        for (int j = 0; j < adj[i]->size; j++)
            free(adj[i]->arr[j]);
        free(adj[i]->arr);
        free(adj[i]);
    }
    free(adj);
    free(pool);
    free(dist);
    free(q);
    return 0;
} 
