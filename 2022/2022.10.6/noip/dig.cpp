#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
inline int read(){
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
char temp[10];
int di,mi;
class dist{
	public:
		int km;
		dist(){
			km=0;
		}
}a[200005];
class time{
	public:
		int min;
		time(){
			min=0;
		}
}b[200005];
bool cmp(dist a,dist b){
	return a.km<b.km;
}
bool cmp2(time a,time b){
	return a.min<b.min;
}
int main(){
	freopen("dig.in","r",stdin);
	freopen("dig.out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",temp);
		if(temp[0]=='D'){
			a[++di].km=read();
		}else{
			b[++mi].min=read();
		}
	}
	a[++di].km=m;
	stable_sort(a+1,a+di+1,cmp);
	stable_sort(b+1,b+mi+1,cmp2);
	int minto=1;
	double time=0;
	int mz=0;
	for(int i=1;i<=di;i++){
		double spend=(a[i].km-a[i-1].km)*(mz+1);
		while(time+spend>=b[minto].min&&time<=b[minto].min&&minto<=mi){
			mz++;
			spend=(a[i].km-a[i-1].km-(b[minto].min-time)/(long double)(mz))*(mz+1);
			time=b[minto].min;
			minto++;
		}
		time+=spend;
		mz++;
	}
	printf("%.0lf",floor(time));
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/



