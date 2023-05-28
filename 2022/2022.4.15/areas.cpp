#include <iostream>
#include <cstdio>
using namespace std;
char b[20005];
int a[20005];
int Max[20005];
int Min[20005];
int main(){
//	freopen("areas.in","r",stdin);
//	freopen("areas.out","w",stdout);
	a[1]=20005;
	int n=1;
	char temp=getchar();
	while(temp!=EOF){
		n++;
		b[n-1]=temp;
		a[n]=a[n-1]+(temp=='/'?1:(temp=='_'?0:-1));
		temp=getchar();
	}
	a[n]=0;
	n--;
	int now=0;
	double totaal=0;
	int i=1;
	while(a[i]<=a[i+1])	i++;
	for(int i=1;i<=n;i++){
		Max[i]=max(Max[i-1],a[i]);
	}
	return 0;
}
