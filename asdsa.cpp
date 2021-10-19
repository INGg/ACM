#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=2e5+10;
ll dp[N],f[N];
int main(){
	ll r,g;
	cin>>r>>g;
	int n;
	for(int i =1000;;i--){
		if(i*(i+1)/2<=(r+g)){
			n=i;break;
		}
	}
	int cur=0;
	bool flag=1;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=r;j++) {
			f[j]=dp[j];
			dp[j]=0;
		}
		
		for(int j=0;j<=r;j++){
			if((i-1)*i/2+i-j<=g)	dp[j]+=f[j];
			if(j-i>=0) 	dp[j]=(dp[j]+f[j-i])%mod;
		}
	}
	ll ans=0;
	for(int i=0;i<=r;++i) {
		ans=(ans+dp[i])%mod;
	}
	printf("%lld\n",ans);
}