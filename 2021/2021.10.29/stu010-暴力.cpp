#include<cstdio>
#include<iostream>
using namespace std;
int n,m,a,b,c,d;
bool get(void){
	if(a*b*c*d==m||
	a*b*(c*10+d)==m||
	a*(b*10+c)*d==m||
	(a*10+b)*c*d==m||
	(a*100+b*10+c)*d==m||
	a*(b*100+c*10+d)==m||
	(a*10+b)*(c*10+d)==m)
	return 1;
	return 0;
}
void co(void){
	if(a*b*c*d==m)printf("%d*%d*%d*%d\n",a,b,c,d);
	if(a*b*(c*10+d)==m)printf("%d*%d*%d%d\n",a,b,c,d);
	if(a*(b*10+c)*d==m)printf("%d*%d%d*%d\n",a,b,c,d);
	if((a*10+b)*c*d==m)printf("%d%d*%d*%d\n",a,b,c,d);
	if((a*10+b)*(c*10+d)==m)printf("%d%d*%d%d\n",a,b,c,d);
	if((a*100+b*10+c)*d==m)printf("%d*%d%d%d\n",a,b,c,d);
	if(a*(b*100+c*10+d)==m)printf("%d%d%d*%d\n",a,b,c,d);
	cout<<m<<endl;
}
int main(){
	for(n=1000;n<=9999;n++){
		a=n/1000,b=n/100%10,c=n/10%10,d=n%10,
		m=d*1000+c*100+b*10+a;
		if(get())co(),cout<<endl;
	}
	return 0;
}
