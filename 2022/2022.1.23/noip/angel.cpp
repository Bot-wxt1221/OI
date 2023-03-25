#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[1005];
int c[10005];
long long chu(char a1[],int b,int c[])
{
  	memset(a,0,sizeof(a));
  	memset(c,0,sizeof(c));
  	int lena=strlen(a1),x=0,lenc=1;
  	for (int i=0;i<=lena-1;i++)
		a[i+1]=a1[i]-48;
	for (int i=1;i<=lena;i++)                           
	{
		c[i]=(x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	while (c[lenc]==0&&lenc<lena) 	lenc++;
	return x;
}
int main(){
	freopen("angel.in","r",stdin);
	freopen("angel.out","w",stdout);
	char n[1005];
	int m;
	cin>>m>>n;
	cout<<chu(n,m,c);
}
