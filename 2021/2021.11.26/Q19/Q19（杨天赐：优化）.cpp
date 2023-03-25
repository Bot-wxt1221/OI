#include<iostream> 
#include<cstdio>
using namespace std;
int n,p[101]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51,53,57},s[100001],tot;
int main(){
	scanf("%d",&n);
	int l=1,r=n;
	s[++tot]=2;
	while(l<r){
		s[++tot]=p[l];s[++tot]=p[l];
		s[++tot]=p[r];s[++tot]=p[r];
		++l;--r;
	}s[++tot]=p[l];
	int ax=-1;
	for(int i=1;i<tot;i+=2)
	ax=max(ax,s[i]*s[i+1]);
	printf("%d\n",ax);
	for(int i=1;i<tot;i+=2)
	printf("%d * %d = %d\n",s[i],s[i+1],s[i]*s[i+1]);
	return 0;
}

