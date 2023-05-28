#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int n,m;
int ans=0;
string s,ts,r;
void dfs(int x);
signed main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int t;
	t=read();
	for(int T=1;T<=t;T++){
		n=read();
		m=read();
		cin>>s>>ts;
 		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
void dfs(int x){
	if(x==n){
//		cout<<r<<endl;
		if(r==ts){
			ans++;
		}
		return ;
	}
//	cout<<s;
	if(s[x]=='-'){
		
//		getchar();
		char temp[405];
		for(int i=1;i<r.size();i++){
			temp[i-1]=r[i];
		}
		temp[r.size()-1]='\0';
		string lr=r;
		r=temp;
		dfs(x+1);
		r=lr;
//		cout<<r<<endl;
		for(int i=0;i<r.size()-1;i++){
			temp[i]=r[i];
		}
		temp[r.size()-1]='\0';
		r=temp;
		cout<<r<<endl;
		dfs(x+1);
	}else{
		r=r+s[x];
		dfs(x+1);
	}
}
