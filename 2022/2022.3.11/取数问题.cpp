#include <iostream>
#include <cstdio>
using namespace std;
int a[100];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	n*=2;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	int ans=0;
	for(int i=1;i<=n;i+=2){
		ans+=a[i];
	}
	int ans2=0; 
	for(int i=2;i<=n;i+=2){
		ans2+=a[i];
	}
	if(ans>ans2){
		int i=1,j=n;
		while(i<=j){
			if(i%2==1){
				cout<<a[i]<<endl;
				cout<<"R"<<' '<<a[j]<<endl;
			}else{
				cout<<a[j]<<endl;
				cout<<"L"<<' '<<a[i]<<endl;
			}
		}
		i++,j--;
	}else{
		int i=1,j=n;
		while(i<=j){
			if(i%2==0){
				cout<<a[i]<<endl;
				cout<<"L"<<' '<<a[j]<<endl;
			}else{
				cout<<a[j]<<endl;
				cout<<"R"<<' '<<a[i]<<endl;
			}
		}
		i++,j--;
	}
	return 0;
}

