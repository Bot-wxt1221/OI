#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int read(){
	int x=0,op=1;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		op=((temp=='-')?-1:1);
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return x*op;
}
int to[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
class nxt{
	public:
		int pos,num;
		int length=0;
		nxt(int a=0,int b=0,int c=0){
			pos=a;
			num=b;
			length=c;
		}
};
nxt mi[1000005][5];
class pos{
	public:
		int x,y;
		char kind;
		int ii;
		pos(int xx=0,int yy=0,char kk=0){
			x=xx;
			y=yy;
			kind=kk;
			return ;
		}
}mir[1000005];
bool cmp1(pos a,pos b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
bool cmp2(pos a,pos b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
int len[1000005][5];
char temp[50];
int xx[1000005];
int yy[1000004];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("mirror.in","r",stdin);
	freopen("mirror.out","w",stdout);
	#endif
	int n=read(),m,T;
	m=read();
	T=read();
	for(int i=1;i<=n;i++){
		xx[i]=mir[i].x=read();
		yy[i]=mir[i].y=read();
		scanf("%s",temp+1);
		mir[i].kind=temp[1];
		mir[i].ii=i;
	}
	mir[0].x=mir[0].y=-m-1;
	std::sort(mir+1,mir+n+1,cmp1);
	for(int i=1;i<=n;i++){
		if(mir[i].x==mir[i-1].x){
			if(mir[i].kind=='\\'){
				mi[mir[i].ii][3]=nxt(2,mir[i-1].ii,std::abs(yy[mir[i-1].ii]-yy[mir[i].ii]));
			}else{
				mi[mir[i].ii][4]=nxt(2,mir[i-1].ii,std::abs(yy[mir[i-1].ii]-yy[mir[i].ii]));
			}
		}else{
			if(mir[i].kind=='\\'){
				mi[mir[i].ii][3]=nxt(2,-1,-1);
			}else{
				mi[mir[i].ii][4]=nxt(2,-1,-1);
			}
		}
		if(mir[i].x==mir[i+1].x){
			if(mir[i].kind=='\\'){
				mi[mir[i].ii][4]=nxt(1,mir[i+1].ii,std::abs(yy[mir[i+1].ii]-yy[mir[i].ii]));
			}else{
				mi[mir[i].ii][3]=nxt(1,mir[i+1].ii,std::abs(yy[mir[i+1].ii]-yy[mir[i].ii]));
			}
		}else{
			if(mir[i].kind=='\\'){
				mi[mir[i].ii][4]=nxt(1,-1,-1);
			}else{
				mi[mir[i].ii][3]=nxt(1,-1,-1);
			}
		}
	}
	std::sort(mir+1,mir+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(mir[i].y==mir[i-1].y){
			if(mir[i].kind=='\\'){
				mi[mir[i].ii][1]=nxt(4,mir[i-1].ii,std::abs(xx[mir[i-1].ii]-xx[mir[i].ii]));
			}else{
				mi[mir[i].ii][2]=nxt(4,mir[i-1].ii,std::abs(xx[mir[i-1].ii]-xx[mir[i].ii]));
			}
		}else{
			if(mir[i].kind=='\\'){
				mi[mir[i].ii][1]=nxt(4,-1,-1);
			}else{
				mi[mir[i].ii][2]=nxt(4,-1,-1);
			}
		}
		if(mir[i].y==mir[i+1].y){
			if(mir[i].kind=='\\'){
				mi[mir[i].ii][2]=nxt(3,mir[i+1].ii,std::abs(xx[mir[i+1].ii]-xx[mir[i].ii]));
			}else{
				mi[mir[i].ii][1]=nxt(3,mir[i+1].ii,std::abs(xx[mir[i+1].ii]-xx[mir[i].ii]));
			}
		}else{
			if(mir[i].kind=='\\'){
				mi[mir[i].ii][2]=nxt(3,-1,-1);
			}else{
				mi[mir[i].ii][1]=nxt(3,-1,-1);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=4;j++){
//			printf("%d ",mi[i][j].num);
//		}
//		printf("\n");
//	}
	int choo=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(mir[i].y==0&&mir[i].x>0){
			choo=i;
			break;
		}
	}
	if(choo==0x3f3f3f3f){
		printf("%lld %d",T,0);
		return 0;
	}
	T-=mir[choo].x;
	int now=mir[choo].ii;
	int too=3;
	int length=mir[choo].x;
	while(T>0){
		int nxt=mi[now][too].num;
		int ntoo=mi[now][too].pos;
		if(nxt==-1){
			printf("%lld %lld",xx[now]+to[ntoo][0]*T,yy[now]+to[ntoo][1]*T);
			return 0;
		}
		if(T<=mi[now][too].length){
			printf("%lld %lld",xx[now]+to[ntoo][0]*T,yy[now]+to[ntoo][1]*T);
			return 0;
		}
		length+=mi[now][too].length;
		T-=mi[now][too].length;
		if(len[nxt][ntoo]!=0){
			T%=length-len[nxt][ntoo];
		}
		now=nxt;
		too=ntoo;
		len[nxt][ntoo]=length;
	}
	return 0;
}

