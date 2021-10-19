#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n;
	cin>>n;
	char a[10];
	while(n--)
	{
		memset(a,0,sizeof(a));
		cin>>a;
		if(strlen(a)==1 && a[0]!='9')
		{
			cout<<"0"<<endl;
			continue;
		}
		if(strlen(a)==1 && a[0]=='9')
		{
			cout<<'1'<<endl;
			continue;
		}
		int ans=0;
		for(i=0;i<strlen(a)-1;i++)
		{
			int v=pow(9,strlen(a)-(i+2));
			v=v*(a[i]-'0');
			ans+=v;
		}
		cout<<ans<<endl;
	}
	return 0;
}
