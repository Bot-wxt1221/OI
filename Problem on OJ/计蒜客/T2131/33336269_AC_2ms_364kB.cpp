#include <iostream>
using namespace std;
int a[1010];
int main(){
	int n,num=0;
	cin>>n;
	int *temp=new int;
	for(int i=1;i<=n;i++){
		cin>>(*temp);
		a[(*temp)]++;
		if(a[(*temp)]==1){
			num++;
		}
	}
	delete temp;
	cout<<num<<endl;
	for(int i=1;i<=1000;i++){
		if(a[i]!=0){
			cout<<i<<' ';
		}
	}
	return 0;
}