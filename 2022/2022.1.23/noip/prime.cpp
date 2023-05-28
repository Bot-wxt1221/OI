#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
char a[125],c12[125];
bool b[65536];
char c1[125];
int chu(char *a1,int b,char *c){
	int a[130],lena,i,x=0,lenc;
	char c2[130];
  	memset(a,0,sizeof(a));
  	memset(c,0,sizeof(c));
  	memset(c2,0,sizeof(c2));
  	lena=strlen(a1);
  	for (i=0;i<=lena-1;i++)
		a[i+1]=a1[i]-48;
	for (i=1;i<=lena;i++)                               //°´Î»Ïà³ý
	{
		c2[i]=(x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	for(int i=1;i<=lena;i++){
		c[i-1]=c2[i]+'0';
	}
	return x;
}
void init(){
	for(int i=2;i<=65535/2;i++){
		for(int j=2;i*j<=65535;j++){
			b[i*j]=1;
		}
	}
}
signed main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	cin>>c12;
	init();
	for(int i=2;i<=65535;i++){
		for(int j=0;j<=124;j++){
			a[j]=c12[j];
		}
		if(b[i]!=0){
			continue;
		}
		int x=0,temp=-1;
		while(x==0){
			temp++;
			x=chu(a,i,c1);
			for(int i=0;i<124;i++){	a[i]=c1[i];}
		}
		if(temp){
			cout<<i<<' '<<temp<<endl;
		}
	}
	return 0;
}

