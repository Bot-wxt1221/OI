#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	char a=getchar();
	int f=1,x=0;
	while('0'>a||a>'9'){
		(a=='-')?f=-1:0;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=(x<<3)+(x<<1)+(a-'0');
		a=getchar();
	}
	return f*x;
}
int ans;
int main(){
// 	freopen("title.in","r",stdin);
// 	freopen("title.out","w",stdout);
	char a=getchar();
	while(a!=EOF){
		if('a'<=a&&a<='z'){
			ans++;
		}
		if('A'<=a&&a<='Z'){
			ans++;
		}
		if('0'<=a&&a<='9'){
			ans++;
		}
		a=getchar();
	}
	printf("%d",ans);
	return 0;
}
