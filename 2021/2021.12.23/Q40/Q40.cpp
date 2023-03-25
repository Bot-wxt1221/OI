#include <iostream>
#include <cstdio>
using namespace std;
int a[40];
int ans=0;
void dfs(int step);
unsigned short two(int *);
int main(){
//	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	dfs(0);
	cout<<ans;
	return 0;
}
void dfs(int step){
	if(step==16){
		for(int i=1;i<=16;i++){
			a[32-i+1]=a[i];
		}
//		for(int i=1;i<=32;i++){
	//		cout<<a[i]<<' ';
//		}
//		cout<<endl;
		int d[4];
		d[0]=two(a+1),d[1]=two(a+9),d[2]=two(a+17),d[3]=two(a+25);
		bool b[10];
		for(int i=0;i<=9;i++){
			b[i]=0;
		}
		for(int i=0;i<4;i++){
			while(d[i]!=0){
				if(b[d[i]%10]==1){
					return;
				}
				b[d[i]%10]=1;
				d[i]=d[i]/10;
			}
		}
		for(int i=0;i<=9;i++){
			if(b[i]==0){
				return;
			}
		}
		printf("%d.%d.%d.%d\n",two(a+1),two(a+9),two(a+17),two(a+25));
		ans++; 
		return;
	}
	for(int i=0;i<=1;i++){
		a[step]=i;
		dfs(step+1);
	}
}
unsigned short two(int *a){
	return a[0]*128+a[1]*64+a[2]*32+a[3]*16+a[4]*8+a[5]*4+a[6]*2+a[7];
}
