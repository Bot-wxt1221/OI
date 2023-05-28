#include <iostream>
#include <cstdio>
using namespace std;
void ssort(int *a,int first,int last);
int a[100005];
int b[100005];
long long ans;
int main(){
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	int n,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ssort(a,1,n);
	cout<<ans;
}
void ssort(int *a,int first,int last){
	if(first>=last){
		return ;
	}
	ssort(a,first,(first+last)/2);
	ssort(a,(first+last)/2+1,last);
	int i=first,j=(first+last)/2+1,m=0;
	while(i<=(first+last)/2&&j<=last){
		if(a[i]<a[j]){
			b[++m]=a[i++];
		}else{
			b[++m]=a[j++];
		}
	}
	while(i<=(first+last)/2){
		b[++m]=a[i++];
	}
	while(j<=last){
		b[++m]=a[j++];
	}
	for(int i=first;i<=(first+last)/2;i++){
		for(int j=(first+last)/2+1;j<=last;j++){
			if(a[i]>a[j]){
				ans++;
			}else{
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		a[first+i-1]=b[i];
	}
	return ;
}
