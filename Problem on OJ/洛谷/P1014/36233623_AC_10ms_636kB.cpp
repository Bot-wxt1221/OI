#include<iostream>
using namespace std;
int main(){
	int x,y,h=1,N,k; 
	cin>>N;
	while(N>h){ 
	    N=N-h;
	    h++;
	}
	k=N-1;
	if(h%2==0)x=1+k,y=h-k;
	else x=h-k,y=1+k;
	cout<<x<<"/"<<y;
	return 0;
}
