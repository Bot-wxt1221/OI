//数据问题，末尾没有-1 
#include <iostream>
#include <cstdio>
using namespace std;
long long wdp[31][31][31]={0};
long long w(int a,int b,int c);
int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	int a,b,c;
	while(cin>>a){
		cin>>b>>c;
		if(a==-1&&b==-1&&c==-1){
			break;
		}
		if(a<=0||b<=0||c<=0){
			printf("w(%d,%d,%d)=%d",a,b,c,1);
			return 0;
		}
		if(a>20||b>20||c>20){
			 printf("w(%d,%d,%d)=%d",a,b,c,w(20,20,20));
			 return 0;
		}
		printf("w(%d,%d,%d)=%d",a,b,c,w(a,b,c));
	}
	return 0;
}
long long w(int a,int b,int c){
	if(a<=0||b<=0||c<=0){
		return 1;
	}
	if(wdp[a][b][c]){
		return wdp[a][b][c];
	}
	if(a<b&&b<c){
		return wdp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	return wdp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
