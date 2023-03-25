#include <iostream>
#include <cstring>
using namespace std;
long long tem=0; 
int a[100005];
int temp[100005];
void sort(int *p,int l,int r);
int main(){
//	freopen("sort.in","r",stdin);
//	freopen("sort1.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,1,n);
	cout<<tem;
}
void sort(int *p,int l,int r){
	if(l==r){
		return;
	} 
	int mid=l+(r-l)/2;
	sort(p,l,mid);
	sort(p,mid+1,r);
	memset(p,sizeof(p),0);
	int i=l;
	int j=mid+1;
	int k=0;
	while(i<=mid&&j<=r){
		if(p[i]<p[j]){
			temp[++k]=p[i++];
		}else{
			temp[++k]=p[j++];
			ans+=mid-i+1;
		}
	}
	if(i<=mid){
		while(i<=mid){
			temp[++k]=p[i++];
		}
	}else{
		while(j<=r){
			temp[++k]=p[j++];
		}
	}
	for(int i=l;i<=r;i++){
		p[i]=temp[i-l+1];
	}
	return;
}