#include<bits/stdc++.h>
using namespace std;
#define LL long long
int che(string a,string b){
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i])return 0;
	}
	return 1;
}
int che (string a,string b,string c){
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i]||a[i]==c[i]||b[i]==c[i])return 0;
	}
	return 1;
}
int main(){
	string a,b,c;
	cin>>a>>b>>c;
	int n1,n2,n3;
	n1=n2=n3=0;
	int l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]=='A')n1++;if(a[i]=='B')n2++;if(a[i]=='C')n3++; 
		if(b[i]=='A')n1++;if(b[i]=='B')n2++;if(b[i]=='C')n3++; 
		if(c[i]=='A')n1++;if(c[i]=='B')n2++;if(c[i]=='C')n3++; 
	}
	if(n1!=n2||n1!=n3||n2!=n3){
		cout<<-1;
		return 0;
	}
	int ans=1e9;
	string b1=b,b2=b;
	for(int i=1;i<=l;i++){
		if(min(l-i,i)>ans)break;
		b1=b2;b2=b1[l-1];b2+=b1;
		b2.pop_back();
		if(che(b2,a)==1){
			string c1=c,c2=c;
			for(int j=1;j<=l;j++){
				c1=c2;c2=c1[l-1];c2+=c1;
				c2.pop_back();
				//cout<<a<<" "<<b2<<" "<<c2<<" "<<i<<" "<<j<<endl;
				if(che(c2,b2,a)==1){
					int nm=min(i,l-i)+min(j,l-j);
					if(nm<ans)ans=nm;
				
				}
			}
		}
	}
	b1=a,b2=a;
	for(int i=1;i<=l;i++){
		if(min(l-i,i)>ans)break;
		b1=b2;b2=b1[l-1];b2+=b1;
		b2.pop_back();
		if(che(b2,b)==1){
			string c1=c,c2=c;
			for(int j=1;j<=l;j++){
				c1=c2;c2=c1[l-1];c2+=c1;
				c2.pop_back();
				//cout<<a<<" "<<b2<<" "<<c2<<" "<<i<<" "<<j<<endl;
				if(che(c2,b2,b)==1){
					int nm=min(i,l-i)+min(j,l-j);
					if(nm<ans)ans=nm;
					
				}
			}
		}
	}
	b1=b,b2=b;
	for(int i=1;i<=l;i++){
		if(min(l-i,i)>ans)break;
		b1=b2;b2=b1[l-1];b2+=b1;
		b2.pop_back();
		if(che(b2,c)==1){
			string c1=a,c2=a;
			for(int j=1;j<=l;j++){
				c1=c2;c2=c1[l-1];c2+=c1;
				c2.pop_back();
				//cout<<a<<" "<<b2<<" "<<c2<<" "<<i<<" "<<j<<endl;
				if(che(c2,b2,c)==1){
					int nm=min(i,l-i)+min(j,l-j);
					if(nm<ans)ans=nm;
				
				}
			}
		}
	}
	if(ans==1e9)ans=-1;
	cout<<ans<<endl;
}
