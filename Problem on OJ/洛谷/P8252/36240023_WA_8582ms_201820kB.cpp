#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
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
set<int>a[1000005];
set <int> b[1000005];
int main(){
//	freopen("discuss.in","r",stdin);
//	freopen("discuss.out","w",stdout);
	int t,n;
	t=read();
	for(int T=1;T<=t;T++){
		n=read();
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
		for(int i=1;i<=n;i++){
			int J=read();
			for(int j=1;j<=J;j++){
				int temp=read();
				a[temp].insert(j);
				b[i].insert(temp);
			}
		}
		bool next=1;
		for(int i3=1;i3<=n&&next;i3++)
		for(int mi2=0;mi2<a[i3].size()&&next;mi2++){
			std::set<int>::iterator aa=a[i3].begin();
			for(int temp=1;temp<=mi2;temp++){
				aa++;
			}
			int i2=*aa,j2;
			for(int j3=1;j3<=n;j3++){
				for(int mj2=0;mj2<a[j3].size()&&next;mj2++){
					aa=a[j3].begin();
			for(int temp=1;temp<=mi2;temp++){
				aa++;
			}
			j2=*aa;
			}
				for(int m=1;m<=n&&next;m++){
					if(a[m].find(i2)!=a[m].end()&&a[m].find(j2)!=a[m].end()){
						if(!includes(b[i2].begin(),b[i2].end(),b[j2].begin(),b[j2].end())){
							if(!includes(b[j2].begin(),b[j2].end(),b[i2].begin(),b[i2].end())){
								next=0;
								cout<<"Yes"<<endl<<i2<<' '<<j2<<endl;
							}
						}
					}
				}
			}
				
			}if(next){
			cout<<"No"<<endl;
		}
		}
		

	return 0;
}
