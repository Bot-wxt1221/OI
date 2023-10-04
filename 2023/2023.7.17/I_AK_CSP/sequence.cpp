#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
class big_num{
	public:
		int a[65];
		int now=0;
		big_num(){
			memset(a,0,sizeof(a));
		}
		void print(){
			bool fir=0;
			for(int i=now;i>=1;i--){
				if(a[i]==0&&!fir){
					continue;
				}
				if(fir==0){
					fir=1;
					printf("%d",a[i]);
					continue;
				}
				fir=1;
				printf("%09d",a[i]);
			}
			if(!fir){
				printf("0");
			}
			return ;
		}
};
big_num operator +(big_num a,big_num b){
	for(int i=1;i<=std::max(a.now,b.now);i++){
		a.a[i]+=b.a[i];
		a.a[i+1]+=a.a[i]/1000000000;
		a.a[i]%=1000000000;
		if(a.a[i]!=0)
			a.now=std::max(a.now,i);
        if(a.a[i+1]!=0)
			a.now=std::max(a.now,i+1);
	}
	return a;
}
big_num operator +(big_num b,int a){
	big_num aa;
	aa.now=0;
	while(a>0){
		aa.a[++aa.now]=a%1000000000;
		a=a/1000000000;
	}
	for(int i=1;i<=std::max(aa.now,b.now);i++){
		aa.a[i]+=b.a[i];
		aa.a[i+1]+=aa.a[i]/1000000000;
		aa.a[i]%=1000000000;
		if(aa.a[i]!=0)
			aa.now=std::max(aa.now,i);
        if(aa.a[i+1]!=0)
			aa.now=std::max(aa.now,i+1);
	}
	return aa;
}
big_num operator *(big_num b,big_num a){
	big_num aa;
	for(int i=1;i<=a.now;i++){
		for(int j=1;j<=b.now;j++){
			long long temp=a.a[i];
			temp*=b.a[j];
			temp+=aa.a[i+j-1];
			aa.a[i+j]+=temp/1000000000;
			aa.a[i+j-1]=temp%1000000000;
			if(aa.a[i+j]!=0)
				aa.now=std::max(aa.now,i+j);
			if(aa.a[i+j-1]!=0)
				aa.now=std::max(aa.now,i+j-1);
		}
	}
	return aa;
}
big_num operator ++(big_num b){
	return b+1;
}
int a[1005];
big_num inseq[1300];
big_num map[1005][1300];
int now=0;
char pritemp[305];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#endif
    int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	map[1][a[1]]=map[1][a[1]]+1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<1024;j++){
			map[i][j]=map[i-1][j];
		}
		for(int j=0;j<1024;j++){
			map[i][j^a[i]]=map[i][j^a[i]]+map[i-1][j];
		}
		map[i][a[i]]=map[i][a[i]]+1;
	}
	big_num ans;
	for(int i=n;i>=1;i--){
		for(int j=0;j<1024;j++){
			big_num aaa=map[i-1][j^a[i]];
			if((j^a[i])==0){
				map[i-1][j^a[i]]=map[i-1][j^a[i]]+1;
			}
			big_num teemp=inseq[j]*map[i-1][j^a[i]];
			ans=ans+teemp;
			map[i-1][j^a[i]]=aaa;
		}
		for(int j=0;j<1024;j++){
			inseq[j&a[i]]=inseq[j&a[i]]+inseq[j];
		}
		inseq[a[i]]=inseq[a[i]]+1;
	}
	ans.print();
	putchar('\n');
	return 0;
}
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


