#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	char a=getchar();
	int f=1,x=0;
	while(a<'0'||a>'9'){
		(a=='-')?(f=-1):1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=x*10+(a-'0');
		a=getchar();
	}
	return x*f;
}
class node{
	public:
		int y,m,d;
};
bool da[13]={0,1,0,1,0,1,0,1,1,0,1,0,1};
bool run(int a){
	if(a%100!=0&&a%4==0){
		return 1;
	}
	if(a%400==0){
		return 1;
	}
	return 0;
}
node add(node i){
	i.d++;
	if(i.m==2){
		if(run(i.y)){
			if(i.d>29){
				i.d=1;
				i.m++;
			}
		}else{
			if(i.d>28){
				i.d=1;
				i.m++;
			}
		}
	}else if(da[i.m]){
		if(i.d>31){
			i.d=1;
			i.m++;
		}
	}else{
		if(i.d>30){
			i.d=1;
			i.m++;
		}
	}
	if(i.m>12){
		i.m=1;
		i.y++;
	}
	return i;
}
int main(){
	freopen("shower.in","r",stdin);
	freopen("shower.out","w",stdout);
	int n=read();
	node a;
	a.y=2013;
	a.m=9;
	a.d=1;
	for(int i=1;i<=n*7;i++){
		a=add(a);
	}
	printf("%d-",a.y);
	if(a.m<10){
		printf("0");
	}
	printf("%d-",a.m);
	if(a.d<10){
		printf("0");
	}
	printf("%d",a.d);
	return 0;
}

