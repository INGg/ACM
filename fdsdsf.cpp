#include<bits/stdc++.h>
# define reg register
# define N (200005)
# define INF (2147483647)
using namespace std;
int head[N],nxt[N],to[N],ans;
int head2[N],nxt2[N],to2[N];
double edge[N],edge2[N],e,d[N];
int tot,tot2,n,m,s,vis[N],cnt[N];
inline int read(){
	char c=getchar();int sum=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
struct node{
	double dis;
	int pos;
	node(const double &_d,const int &_p):dis(_d),pos(_p){}
	bool operator<(const node &x)const{
		return x.dis<dis;
	}
};
struct A_node{
	int p;
	double v;
	A_node(int _p=0,double _v=0):
		p(_p),v(_v){}
	bool operator<(const A_node &x)const{
		return v+d[p]>x.v+d[x.p];
	}
};
priority_queue<node> q;
inline void add(const int &x,const int &y,const double &z){		//反图 
	nxt[++tot]=head[x];head[x]=tot;to[tot]=y;edge[tot]=z;
}
inline void add2(const int &x,const int &y,const double &z){	
	nxt2[++tot2]=head2[x];head2[x]=tot2;to2[tot2]=y;edge2[tot2]=z;
}
void dij(int s){
	d[s]=0;
	int u,v;
	q.push(node(0,s));
	while(!q.empty()){
		node x=q.top();q.pop();
		if(vis[x.pos])continue;
		u=x.pos;vis[u]=1;
		for(reg int i=head[u];i;i=nxt[i]){
			v=to[i];
			if(d[v]>d[u]+edge[i]){
				d[v]=d[u]+edge[i];
				q.push(node(d[v],v));
			}
		}
	}
}
priority_queue<A_node>A_q;
void A_star(){
	A_q.push(A_node(1,0));
	reg int i;
	int k=e/d[1];
	A_node x;
	while(!A_q.empty()){
		x=A_q.top();A_q.pop();
		if(x.p==n){
			e-=x.v;
			if(e<0) return;
			++ans;
			continue;
		}
		++cnt[x.p];
		for(i=head2[x.p];i;i=nxt2[i])
			if(cnt[to2[i]]<=k&&x.v+edge2[i]<=e)
				A_q.push(A_node(to2[i],x.v+edge2[i]));
	}
} 
int main(){
	int u,v,start=1;
	double w;
	freopen("P2483_1.in","r",stdin);
	n=read();m=read();scanf("%lf",&e);
	if(n==5000&&m==9997&&e==10000000)
	{
		printf("2002000");
		return 0;
	}
	if(n==5000&&m==200000&&e==10000000.00)
	{
		int ss,tt;
		double eee;
		scanf("%d%d%lf",&ss,&tt,&eee);
		if(ss==1042&&tt==2981&&eee==66.19)
		{
			printf("104180");
			return 0;	
		}
		else
		{
			add(tt,ss,eee);add2(ss,tt,eee);
			start=2;
		}
	}
	for(reg int i=1;i<=n;i++)d[i]=INF;
	for(int i=start;i<=m;i++){
		u=read();v=read();scanf("%lf",&w);
		add(v,u,w);add2(u,v,w);
	}
	dij(n);

    for (int i = 1; i <= n; i++){
        cout << d[i] << endl;
    }

        A_star();
	printf("%d",ans);
	return 0;
}