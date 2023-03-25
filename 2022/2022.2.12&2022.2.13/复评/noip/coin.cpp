
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool stcmp(char a[120],char b[120]){
	if(strlen(a)!=strlen(b)){
		return false;
	}
	for(int i=0;i<strlen(a);i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}
int have[120];
bool yes[120];
char a[4][120],b[4][120],c[4][120];
bool check(char ,int sa);
bool lh;//light(0) or heavy(1)
int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char _max=0;
		memset(yes,0,sizeof(yes));
		memset(have,0,sizeof(have));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int j=1;j<=3;j++){
			scanf("%s",a[j]);
			scanf("%s",b[j]);
			scanf("%s",c[j]);
//			for(int i=0;i<strlen(a[j]);i++){
//				_max=max(_max,a[j][i]);
//				_max=max(_max,b[j][i]);
//			}
		}
		bool have=1;
		for(char i='A';i<='L';i++){
			if(check(i,1)&&have){
				printf("%c is the counterfeit coin and it is light.\n",i);
				have=0;
			}
			if(check(i,3)&&have){
				printf("%c is the counterfeit coin and it is heavy.\n",i);
				have=0;
			}
		}
	}
	return 0;
}
bool check(char aa,int sa){
	int r,l,l2,r2;
	bool ans=1;
	for(int i=1;i<=3;i++){
		l=0,r=0;
		for(int j=0;j<strlen(a[i]);j++){
			if(a[i][j]!=aa)	l+=2;
			if(b[i][j]!=aa)	r+=2;
			if(a[i][j]==aa)	l+=sa;
			if(b[i][j]==aa)	r+=sa;
		}
		if(stcmp(c[i],"even")){
			if(l!=r){
				return false;
			}
		}else if(stcmp(c[i],"down")){
				if(l>=r){
					return false;
				}
			}
			else{
				if(l<=r){
					return false;
				}
			}
		
	}
	return true;
}
