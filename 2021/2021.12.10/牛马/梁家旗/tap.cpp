#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int f[105];
int main(){
	freopen("tap.in","r",stdin);
	freopen("tap.out","w",stdout);
	f[0]=0;
	f[1]=0;
	f[2]=1;
	f[3]=2;
	f[4]=4;
	f[5]=f[4]+f[3]*f[2]+f[3]+f[2]*f[2];
	int n;cin>>n;
//	f[6]=f[5]+f[4]+f[3]*f[3]+f[4]*f[2]+f[2]*f[2]*f[2]+f[2]*f[3];
	for(int j=6;j<=n;j++){
	f[j]+=f[j-1]+f[j-2];
	for(int i=1;i<=j/2;i++){
		f[j]+=f[i]*f[j-i];
	}
	for(int i=1;i<=(j-1)/2;i++) f[j]+=f[i]*f[j-1-i];
	f[j]+=1;
	}cout<<f[n];
}

