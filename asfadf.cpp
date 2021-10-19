/**
 *    author:  s26
 *    created: 10/10/21 17:09
**/

//#define LOCAL

#include<bits/stdc++.h>
#include <cstdio>
using namespace std;

#define taskname ""

int N;
bool flag=0;

char a[110][110];

void dfs(int x,int y) {
	if(x<0||y<0||x>=2||y>=N||a[x][y]=='1') return;
	if(flag) return;
	if(x==1&&y==N-1) {
		puts("YES"); flag=1;
	}
	dfs(x,y+1);
	dfs(x+1,y+1);
	dfs(x-1,y+1);
}

void run() {
	cin>>N; flag=0;
	cin>>a[0]>>a[1];
	dfs(0,0);
	if(!flag) puts("NO");
}

int main(int argc,char **argv) {
	#ifdef LOCAL
		freopen(taskname".in","r",stdin);
		freopen(taskname".out","w",stdout);
	#endif
	int T; cin>>T;
	while(T--) {
		run();
	}
}