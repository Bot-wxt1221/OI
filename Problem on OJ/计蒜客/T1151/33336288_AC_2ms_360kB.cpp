#include <iostream>
using namespace std;
int a[505];
int main(){
	int n,_max=0;
	cin>>n;
	int *temp=new int;
	for(int i=1;i<=n;i++){
		cin>>(*temp);
		a[(*temp)]++;
		if((*temp)%2==1){
			_max=max((*temp),_max);
		}
	}
	delete temp;
	for(int i=1;i<=n;i+=2){
		if(a[i]==0){
			continue;
		}
		if(i!=_max){
			for(int j=1;j<=a[i];j++){
				cout<<i<<",";
			}
		}else{
			for(int j=1;j<a[i];j++){
				cout<<i<<",";
			}
			cout<<i;
		}
	}
	return 0;
}