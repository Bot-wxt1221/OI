#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int i=floor(log2(m)+0.9)+1;
	int ans=0;
	for(int j=0;j<i;j++){
		int temp=1;
		for(int k=1;k<=j;k++){
			temp=temp*2;
		}
		ans+=temp;
	}
	if(ans>n-1){
		cout<<log2(n);
		return 0;
	}
	if((n-1-ans)%m!=0)
		cout<<floor((n-1-ans)/m+0.9)+i;
	else
		cout<<floor((n-1-ans)/m+0.9)+i+1;
	return 0;
}
